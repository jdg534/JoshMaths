#include "VolumeIntersectionMaths.h"
#include "VectorMath.h"
#include "InterpolationFunctions.h"
#include "MiscellaneousFunctions.h"

#include <cassert>
#include <cfloat>

/*
Copyright (c) 2015 Joshua Gibson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

using namespace Math::Types;

bool Math::VolumeIntersection::volumesOverlap(const BoundingBox& a, const BoundingBox& b)
{
	// use the top and bottom to determine if y axis points down or up

	bool yAxisPointsUp = a.top > a.bottom;
	// bottom would have higher value, if y axis pointed down wards
	// asuming that x axis always points to the right


	if (yAxisPointsUp)
	{
		if (a.left > b.right)
		{
			return false;
		}
		else if (a.right < b.left)
		{
			return false;
		}
		else if (a.top < b.bottom)
		{
			return false;
		}
		else if (a.bottom > b.top)
		{
			return false;
		}
		// would return true if this point is reached
	}
	else
	{
		if (a.left > b.right)
		{
			return false;
		}
		else if (a.right < b.left)
		{
			return false;
		}
		else if (a.top > b.bottom)
		{
			return false;
		}
		else if (a.bottom < b.top)
		{
			return false;
		}
	}
	return true;
}

bool Math::VolumeIntersection::volumesOverlap(const BoundingCircle& a, const BoundingCircle& b)
{
	Vector2D aToB = Math::Vector::wayToVector(a.position, b.position);
	float distSqurd = Math::Vector::magnitudeSquared(aToB);
	float combinedRadiusSqurd = a.radius * a.radius + b.radius * b.radius;
	return combinedRadiusSqurd > distSqurd; // if combined radius is larger than the distance, then there must be an over lap (collision)
}

bool Math::VolumeIntersection::volumesOverlap(const BoundingSphere& a, const BoundingSphere& b)
{
	// same logic as 2D, just using 3D vectors instead
	Vector3D aToB = Math::Vector::wayToVector(a.position, b.position);
	float distSqurd = Math::Vector::magnitudeSquared(aToB);
	float combinedRadiusSqurd = a.radius * a.radius + b.radius * b.radius;
	return combinedRadiusSqurd > distSqurd; // if combined radius is larger than the distance, then there must be an over lap (collision)
}

bool Math::VolumeIntersection::volumesOverlap(const BoundingCube& a, const BoundingCube& b)
{
	// use the front and back of the cube to determine is it's right handed or left handed
	bool isLeftHanded = a.front < a.back; // the front would have a higher value if in RH coord sys

	if (isLeftHanded)
	{
		if (a.left > b.right)
		{
			return false;
		}
		else if (a.right < b.left)
		{
			return false;
		}
		else if (a.top < b.bottom)
		{
			return false;
		}
		else if (a.bottom > b.top)
		{
			return false;
		}
		else if (a.front > b.back)
		{
			return false;
		}
		else if (a.back < b.front)
		{
			return false;
		}
	}
	else
	{
		// Right handed coords
		// assuming X & Y axis remain the same
		if (a.left > b.right)
		{
			return false;
		}
		else if (a.right < b.left)
		{
			return false;
		}
		else if (a.top < b.bottom)
		{
			return false;
		}
		else if (a.bottom > b.top)
		{
			return false;
		}
		else if (a.back > b.front)
		{
			return false;
		}
		else if (a.front < b.back)
		{
			return false;
		}

	}
	return true;
}

bool Math::VolumeIntersection::volumesOverlap(const BoundingCapsule2D& a, const BoundingCapsule2D& b, uint32_t numSegments)
{
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float collisionRadiiSquared = (a.radius + b.radius) * (a.radius + b.radius);
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	Vector2D testPointA = {0.0f,0.0f}; // done to avoid thrashing the stack
	float aWeight = 0.0f, bWeight = 0.0f;
	float pointToPointSquaredDistance = 0.0f;
	for (uint32_t aSeg = 0; aSeg <= numSegments; ++aSeg, aWeight = std::min(aWeight + lerpWeightStepSize, 1.0f))
	{
		testPointA = Math::Interpolation::lerp(a.start, a.finish, aWeight);
		bWeight = 0.0f;
		for (uint32_t bSeg = 0; bSeg <= numSegments; ++bSeg, bWeight = std::min(bWeight + lerpWeightStepSize, 1.0f))
		{
			pointToPointSquaredDistance = magnitudeSquared(wayToVector(testPointA, Math::Interpolation::lerp(b.start, b.finish, bWeight)));
			if (collisionRadiiSquared > pointToPointSquaredDistance)
			{
				return true;
			}
		}
	}
	return false;
}

bool Math::VolumeIntersection::volumesOverlap(const BoundingCapsule3D& a, const BoundingCapsule3D& b, uint32_t numSegments)
{
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float collisionRadiiSquared = (a.radius + b.radius) * (a.radius + b.radius);
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	Vector3D testPointA = { 0.0f,0.0f, 0.0f }; // done to avoid thrashing the stack
	float aWeight = 0.0f, bWeight = 0.0f;
	float pointToPointSquaredDistance = 0.0f;
	for (uint32_t aSeg = 0; aSeg <= numSegments; ++aSeg, aWeight = std::min(aWeight + lerpWeightStepSize, 1.0f))
	{
		testPointA = Math::Interpolation::lerp(a.start, a.finish, aWeight);
		bWeight = 0.0f;
		for (uint32_t bSeg = 0; bSeg <= numSegments; ++bSeg, bWeight = std::min(bWeight + lerpWeightStepSize, 1.0f))
		{
			pointToPointSquaredDistance = magnitudeSquared(wayToVector(testPointA, Math::Interpolation::lerp(b.start, b.finish, bWeight)));
			if (collisionRadiiSquared > pointToPointSquaredDistance)
			{
				return true;
			}
		}
	}
	return false;
}

bool Math::VolumeIntersection::pointInBoundingVolume(const Vector2D& a, const BoundingBox& vol)
{
	// figure out Y axis up or down
	bool yAxisPointsUp = vol.top > vol.bottom;

	bool inVolXAxis = false,
		inVolYAxis = false;

	if (a.x < vol.right
		&& a.x > vol.left)
	{
		inVolXAxis = true;
	}

	if (yAxisPointsUp)
	{
		if (a.y > vol.bottom
			&& a.y < vol.top)
		{
			inVolYAxis = true;
		}
	}
	else
	{
		if (a.y > vol.top
			&& a.y < vol.bottom)
		{
			inVolYAxis = true;
		}
	}
	return inVolXAxis && inVolYAxis;
}

bool Math::VolumeIntersection::pointInBoundingVolume(const Vector2D& a, const BoundingCircle& vol)
{
	Vector2D aToVol = Math::Vector::wayToVector(a, vol.position);
	float magSqurd = Math::Vector::magnitudeSquared(aToVol),
		radiusSqurd = vol.radius * vol.radius;
	return radiusSqurd > magSqurd;
}

bool Math::VolumeIntersection::pointInBoundingVolume(const Vector3D& a, const BoundingSphere& vol)
{
	Vector3D aToVol = Math::Vector::wayToVector(a, vol.position);
	float magSqurd = Math::Vector::magnitudeSquared(aToVol),
		radiusSqurd = vol.radius * vol.radius;
	return radiusSqurd > magSqurd;
}

bool Math::VolumeIntersection::pointInBoundingVolume(const Vector3D& a, const BoundingCube& vol)
{
	// figure out RH or LH
	bool aInVolXAxis = false,
		aInVolYAxis = aInVolXAxis,
		aInVolZAxis = aInVolYAxis;

	// asumes X & Y axis same in RH & LH
	aInVolXAxis = a.x > vol.left && a.x < vol.right;
	aInVolYAxis = a.y > vol.bottom && a.y < vol.top;

	bool isLH = vol.back > vol.front;
	if (isLH)
	{
		aInVolZAxis = a.z > vol.front
			&& a.z < vol.back;
	}
	else
	{
		aInVolZAxis = a.z < vol.front
			&& a.z > vol.back;
	}

	return aInVolXAxis && aInVolYAxis && aInVolZAxis;
}

bool Math::VolumeIntersection::pointInBoundingVolume(const Vector2D& a, const BoundingCapsule2D& vol, uint32_t numSegments)
{
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float collisionRadiiSquared = vol.radius * vol.radius;
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	float weight = 0.0;
	float pointToPointSquaredDistance = 0.0f;
	for (uint32_t aSeg = 0; aSeg <= numSegments; ++aSeg, weight = std::min(weight + lerpWeightStepSize, 1.0f))
	{
		pointToPointSquaredDistance = magnitudeSquared(wayToVector(a, Math::Interpolation::lerp(vol.start, vol.finish, weight)));
		if (collisionRadiiSquared > pointToPointSquaredDistance)
		{
			return true;
		}
	}
	return false;
}

bool Math::VolumeIntersection::pointInBoundingVolume(const Vector3D& a, const BoundingCapsule3D& vol, uint32_t numSegments)
{
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float collisionRadiiSquared = vol.radius * vol.radius;
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	float weight = 0.0;
	float pointToPointSquaredDistance = 0.0f;
	for (uint32_t aSeg = 0; aSeg <= numSegments; ++aSeg, weight = std::min(weight + lerpWeightStepSize, 1.0f))
	{
		pointToPointSquaredDistance = magnitudeSquared(wayToVector(a, Math::Interpolation::lerp(vol.start, vol.finish, weight)));
		if (collisionRadiiSquared > pointToPointSquaredDistance)
		{
			return true;
		}
	}
	return false;
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray2D& r, const BoundingBox& vol)
{
	Vector2D volumeMidPoint;
	volumeMidPoint.x = Math::Interpolation::lerp(vol.left, vol.right, 0.5f);
	volumeMidPoint.y = Math::Interpolation::lerp(vol.top, vol.bottom, 0.5f);
	Vector2D distFromRayOriginToVolMidPoint = Math::Vector::wayToVector(r.pointOfOrigin, volumeMidPoint);
	
	float scaleRayBy = Math::Vector::magnitude(distFromRayOriginToVolMidPoint); // this will be the slowest point in the code (squr root calc computationally expencive)
	
	Vector2D rayDirScaledToVolMidPointDist = Math::Vector::scaled(scaleRayBy, r.direction);
	Vector2D testPoint = Math::Vector::add(r.pointOfOrigin, rayDirScaledToVolMidPointDist);
	return pointInBoundingVolume(testPoint, vol);
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray2D& r, const BoundingCircle& vol)
{
	using namespace Math::Vector;

	Vector2D fromRayPOToBCPos = wayToVector(r.pointOfOrigin, vol.position);

	float scaleDirBy = magnitude(fromRayPOToBCPos);
	Vector2D dirScaled = scaled(scaleDirBy, r.direction);
	Vector2D testPoint = add(r.pointOfOrigin, dirScaled);
	return pointInBoundingVolume(testPoint, vol);
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray3D& r, const BoundingSphere& vol)
{
	using namespace Math::Vector;

	Vector3D fromRayPOToBCPos = wayToVector(r.pointOfOrigin, vol.position);

	float scaleDirBy = magnitude(fromRayPOToBCPos);
	Vector3D dirScaled = scaled(scaleDirBy, r.direction);
	Vector3D testPoint = add(r.pointOfOrigin, dirScaled);
	return pointInBoundingVolume(testPoint, vol);
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray3D& r, const BoundingCube& vol)
{
	Vector3D volumeMidPoint;
	volumeMidPoint.x = Math::Interpolation::lerp(vol.left, vol.right, 0.5f);
	volumeMidPoint.y = Math::Interpolation::lerp(vol.top, vol.bottom, 0.5f);
	volumeMidPoint.z = Math::Interpolation::lerp(vol.front, vol.back, 0.5f);


	Vector3D distFromRayOriginToVolMidPoint = Math::Vector::wayToVector(r.pointOfOrigin, volumeMidPoint);

	float scaleRayBy = Math::Vector::magnitude(distFromRayOriginToVolMidPoint); // this will be the slowest point in the code (squr root calc computationally expencive)

	Vector3D rayDirScaledToVolMidPointDist = Math::Vector::scaled(scaleRayBy, r.direction);
	Vector3D testPoint = Math::Vector::add(r.pointOfOrigin, rayDirScaledToVolMidPointDist);
	return pointInBoundingVolume(testPoint, vol);
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray2D& r, const BoundingCapsule2D& vol, uint32_t numSegments)
{
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float radiusSquared = vol.radius * vol.radius;
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	float weight = 0.0;
	float pointToPointSquaredDistance = 0.0f;
	Vector2D capsuleTestPoint = vol.start;
	Vector2D rayTestPoint = r.pointOfOrigin;
	float rayOriginDistanceFromCapsuleTestPoint = 0.0f; magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
	for (uint32_t segment = 0; segment <= numSegments; ++segment, weight = std::min(weight + lerpWeightStepSize, 1.0f))
	{
		capsuleTestPoint = lerp(vol.start, vol.finish, weight);
		rayOriginDistanceFromCapsuleTestPoint = magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
		rayTestPoint = add(r.pointOfOrigin, scaled(rayOriginDistanceFromCapsuleTestPoint, r.direction));
		if (radiusSquared > magnitudeSquared(wayToVector(capsuleTestPoint, rayTestPoint)))
		{
			return true;
		}
	}
	return false;
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray3D& r, const BoundingCapsule3D& vol, uint32_t numSegments)
{
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float radiusSquared = vol.radius * vol.radius;
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	float weight = 0.0;
	float pointToPointSquaredDistance = 0.0f;
	Vector3D capsuleTestPoint = vol.start;
	Vector3D rayTestPoint = r.pointOfOrigin;
	float rayOriginDistanceFromCapsuleTestPoint = 0.0f; magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
	for (uint32_t segment = 0; segment <= numSegments; ++segment, weight = std::min(weight + lerpWeightStepSize, 1.0f))
	{
		capsuleTestPoint = lerp(vol.start, vol.finish, weight);
		rayOriginDistanceFromCapsuleTestPoint = magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
		rayTestPoint = add(r.pointOfOrigin, scaled(rayOriginDistanceFromCapsuleTestPoint, r.direction));
		if (radiusSquared > magnitudeSquared(wayToVector(capsuleTestPoint, rayTestPoint)))
		{
			return true;
		}
	}
	return false;
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray2D& r, const BoundingBox& vol)
{
	using namespace Math::Interpolation;
	using namespace Math::Miscellaneous;
	using namespace Math::Vector;
	// 1. determine radius of the BV
	// 2. get vector to the Ray Point of Origin
	// 3. scale the vector to be of the length on the radius of the BV
	// 4. get vector from ray origin to vector in step 3
	// 5. return the magnitude of vector calculated in step 4
	Vector2D BBMidPoint;
	BBMidPoint.x = lerp(vol.left, vol.right, 0.5f);
	BBMidPoint.y = lerp(vol.top, vol.bottom, 0.5f);

	float destFromCentre[4];
	destFromCentre[0] = diff(vol.left, BBMidPoint.x);
	destFromCentre[1] = diff(vol.right, BBMidPoint.x);
	destFromCentre[2] = diff(vol.top, BBMidPoint.y);
	destFromCentre[3] = diff(vol.bottom, BBMidPoint.y);

	float destToCompair = 0.0f;
	for (int i = 0; i < 4; i++)
	{
		if (destToCompair < destFromCentre[i])
		{
			destToCompair = destFromCentre[i];
		}
	}
	Vector2D volMidPointToRayOri = wayToVector(BBMidPoint, r.pointOfOrigin);
	volMidPointToRayOri = unitVector(volMidPointToRayOri);// unit vector
	volMidPointToRayOri = scaled(destToCompair, volMidPointToRayOri); // to approx vol radius
	Vector2D toVolRadius = wayToVector(r.pointOfOrigin, volMidPointToRayOri);
	return magnitude(toVolRadius); // returns the dist to
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray2D& r, const BoundingCircle& vol)
{
	using namespace Math::Vector;


	Vector2D toRayOri = wayToVector(vol.position, r.pointOfOrigin);
	toRayOri = unitVector(toRayOri);
	toRayOri = scaled(vol.radius, toRayOri);
	Vector2D toAproximateIntersectionPoint = wayToVector(r.pointOfOrigin, toRayOri);
	return magnitude(toAproximateIntersectionPoint);
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray3D& r, const BoundingSphere& vol)
{
	using namespace Math::Vector;


	Vector3D toRayOri = wayToVector(vol.position, r.pointOfOrigin);
	toRayOri = unitVector(toRayOri);
	toRayOri = scaled(vol.radius, toRayOri);
	Vector3D toAproximateIntersectionPoint = wayToVector(r.pointOfOrigin, toRayOri);
	return magnitude(toAproximateIntersectionPoint);
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray3D& r, const BoundingCube& vol)
{
	using namespace Math::Interpolation;
	using namespace Math::Miscellaneous;
	using namespace Math::Vector;
	// 1. determine radius of the BV
	// 2. get vector to the Ray Point of Origin
	// 3. scale the vector to be of the length on the radius of the BV
	// 4. get vector from ray origin to vector in step 3
	// 5. return the magnitude of vector calculated in step 4
	Vector3D BBMidPoint;
	BBMidPoint.x = lerp(vol.left, vol.right, 0.5f);
	BBMidPoint.y = lerp(vol.top, vol.bottom, 0.5f);
	BBMidPoint.z = lerp(vol.front, vol.back, 0.5f);
	float destFromCentre[6];
	destFromCentre[0] = diff(vol.left, BBMidPoint.x);
	destFromCentre[1] = diff(vol.right, BBMidPoint.x);
	destFromCentre[2] = diff(vol.top, BBMidPoint.y);
	destFromCentre[3] = diff(vol.bottom, BBMidPoint.y);
	destFromCentre[4] = diff(vol.front, BBMidPoint.z);
	destFromCentre[5] = diff(vol.back, BBMidPoint.z);

	float destToCompair = 0.0f;
	for (int i = 0; i < 6; i++)
	{
		if (destToCompair < destFromCentre[i])
		{
			destToCompair = destFromCentre[i];
		}
	}
	Vector3D volMidPointToRayOri = wayToVector(BBMidPoint, r.pointOfOrigin);
	volMidPointToRayOri = unitVector(volMidPointToRayOri);// unit vector
	volMidPointToRayOri = scaled(destToCompair, volMidPointToRayOri); // to approx vol radius
	Vector3D toVolRadius = wayToVector(r.pointOfOrigin, volMidPointToRayOri);
	return magnitude(toVolRadius); // returns the dist to
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray2D& r, const BoundingCapsule2D& vol, uint32_t numSegments)
{
	// assumes will hit
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float radiusSquared = vol.radius * vol.radius;
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	float weight = 0.0;
	float pointToPointSquaredDistance = 0.0f;
	Vector2D capsuleTestPoint = vol.start;
	Vector2D rayTestPoint = r.pointOfOrigin;
	float rayOriginDistanceFromCapsuleTestPoint = 0.0f; magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
	float closestDistance = FLT_MAX; // refactor to numeric_limits
	for (uint32_t segment = 0; segment <= numSegments; ++segment, weight = std::min(weight + lerpWeightStepSize, 1.0f))
	{
		capsuleTestPoint = lerp(vol.start, vol.finish, weight);
		rayOriginDistanceFromCapsuleTestPoint = magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
		rayTestPoint = add(r.pointOfOrigin, scaled(rayOriginDistanceFromCapsuleTestPoint, r.direction));
		if (radiusSquared > magnitudeSquared(wayToVector(capsuleTestPoint, rayTestPoint)))
		{
			closestDistance = std::min(closestDistance, rayOriginDistanceFromCapsuleTestPoint);
		}
	}
	return closestDistance;
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray3D& r, const BoundingCapsule3D& vol, uint32_t numSegments)
{
	// assumes will hit
	using namespace Math::Interpolation;
	using namespace Math::Vector; // refactor to Math::Vector
	assert(numSegments > 0);
	const float radiusSquared = vol.radius * vol.radius;
	const float lerpWeightStepSize = 1.0f / static_cast<float>(numSegments);
	float weight = 0.0;
	float pointToPointSquaredDistance = 0.0f;
	Vector3D capsuleTestPoint = vol.start;
	Vector3D rayTestPoint = r.pointOfOrigin;
	float rayOriginDistanceFromCapsuleTestPoint = 0.0f; magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
	float closestDistance = FLT_MAX; // refactor to numeric_limits
	for (uint32_t segment = 0; segment <= numSegments; ++segment, weight = std::min(weight + lerpWeightStepSize, 1.0f))
	{
		capsuleTestPoint = lerp(vol.start, vol.finish, weight);
		rayOriginDistanceFromCapsuleTestPoint = magnitude(wayToVector(capsuleTestPoint, r.pointOfOrigin));
		rayTestPoint = add(r.pointOfOrigin, scaled(rayOriginDistanceFromCapsuleTestPoint, r.direction));
		if (radiusSquared > magnitudeSquared(wayToVector(capsuleTestPoint, rayTestPoint)))
		{
			closestDistance = std::min(closestDistance, rayOriginDistanceFromCapsuleTestPoint);
		}
	}
	return closestDistance;
}

float Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(const Ray2D& r, const BoundingBox& vol, float stepSize)
{
	using namespace Math::Vector;
	using namespace Math::Interpolation;

	Vector2D volMidPoint;
	volMidPoint.x = lerp(vol.left, vol.right, 0.5f);
	volMidPoint.y = lerp(vol.top, vol.bottom, 0.5f);

	float distToVolMidPoint = magnitude(wayToVector(r.pointOfOrigin, volMidPoint));

	Vector2D testPoint, dirScaled;

	dirScaled = scaled(distToVolMidPoint, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);

	// determine if to ray is in the boulding volume
	if (!pointInBoundingVolume(testPoint, vol))
	{
		return -1.0f; // the ray wouldn't hit the bounding volume
	}

	float distForCurrentStep = distToVolMidPoint;
	while (distForCurrentStep > 0.0f)
	{
		distForCurrentStep -= stepSize;
		dirScaled = scaled(distForCurrentStep, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
		if (!pointInBoundingVolume(testPoint, vol))
		{
			return distForCurrentStep + stepSize;
		}
	}
	return 0.0f; // the ray's starting point is in the bounding volume
}

float Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(const Ray2D& r, const BoundingCircle& vol, float stepSize)
{
	using namespace Math::Vector;
	using namespace Math::Interpolation;

	float distToVolMidPoint = magnitude(wayToVector(r.pointOfOrigin, vol.position));

	Vector2D testPoint, dirScaled;

	dirScaled = scaled(distToVolMidPoint, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);

	// determine if to ray is in the boulding volume
	if (!pointInBoundingVolume(testPoint, vol))
	{
		return -1.0f; // the ray wouldn't hit the bounding volume
	}

	float distForCurrentStep = distToVolMidPoint;
	while (distForCurrentStep > 0.0f)
	{
		distForCurrentStep -= stepSize;
		dirScaled = scaled(distForCurrentStep, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
		if (!pointInBoundingVolume(testPoint, vol))
		{
			return distForCurrentStep + stepSize;
		}
	}
	return 0.0f; // the ray's starting point is in the bounding volume
}

float Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(const Ray3D& r, const BoundingSphere& vol, float stepSize)
{
	using namespace Math::Vector;
	using namespace Math::Interpolation;

	float distToVolMidPoint = magnitude(wayToVector(r.pointOfOrigin, vol.position));

	Vector3D testPoint, dirScaled;

	dirScaled = scaled(distToVolMidPoint, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);

	// determine if to ray is in the boulding volume
	if (!pointInBoundingVolume(testPoint, vol))
	{
		return -1.0f; // the ray wouldn't hit the bounding volume
	}

	float distForCurrentStep = distToVolMidPoint;
	while (distForCurrentStep > 0.0f)
	{
		distForCurrentStep -= stepSize;
		dirScaled = scaled(distForCurrentStep, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
		if (!pointInBoundingVolume(testPoint, vol))
		{
			return distForCurrentStep + stepSize;
		}
	}
	return 0.0f; // the ray's starting point is in the bounding volume
}

float Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(const Ray3D& r, const BoundingCube& vol, float stepSize)
{
	using namespace Math::Vector;
	using namespace Math::Interpolation;

	Vector3D volMidPoint;
	volMidPoint.x = lerp(vol.left, vol.right, 0.5f);
	volMidPoint.y = lerp(vol.top, vol.bottom, 0.5f);
	volMidPoint.z = lerp(vol.front, vol.back, 0.5f);


	float distToVolMidPoint = magnitude(wayToVector(r.pointOfOrigin, volMidPoint));

	Vector3D testPoint, dirScaled;

	dirScaled = scaled(distToVolMidPoint, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);

	// determine if to ray is in the boulding volume
	if (!pointInBoundingVolume(testPoint, vol))
	{
		return -1.0f; // the ray wouldn't hit the bounding volume
	}

	float distForCurrentStep = distToVolMidPoint;
	while (distForCurrentStep > 0.0f)
	{
		distForCurrentStep -= stepSize;
		dirScaled = scaled(distForCurrentStep, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
		if (!pointInBoundingVolume(testPoint, vol))
		{
			return distForCurrentStep + stepSize;
		}
	}
	return 0.0f; // the ray's starting point is in the bounding volume
}

float Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(const Ray2D& r, const BoundingCapsule2D& vol, float stepSize, uint32_t numSegments)
{
	using namespace std;
	using namespace Vector; // refactor.
	assert(volumeInRayPath(r, vol, numSegments));
	// back trace unti we get a hit, from furtherest distance, then keep walking back until we're outside of the bounds.
	float distance = std::max(magnitude(wayToVector(r.pointOfOrigin, vol.start)),
		magnitude(wayToVector(r.pointOfOrigin, vol.finish)));
	Vector2D testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));

	// step back into the capsule
	while (!pointInBoundingVolume(testPoint, vol, numSegments))
	{
		distance -= stepSize;
		testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
	}
	// point will be in the bounding volume.
	while (distance > 0.0f)
	{
		distance -= stepSize;
		testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
		if (!pointInBoundingVolume(testPoint, vol, numSegments))
		{
			return distance + stepSize;
		}
	}
	return -1.0f;
}

float Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(const Ray3D& r, const BoundingCapsule3D& vol, float stepSize, uint32_t numSegments)
{
	using namespace std;
	using namespace Vector; // refactor.
	assert(volumeInRayPath(r, vol, numSegments));
	// back trace unti we get a hit, from furtherest distance, then keep walking back until we're outside of the bounds.
	float distance = std::max(magnitude(wayToVector(r.pointOfOrigin, vol.start)),
		magnitude(wayToVector(r.pointOfOrigin, vol.finish)));
	Vector3D testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));

	// step back into the capsule
	while (!pointInBoundingVolume(testPoint, vol, numSegments))
	{
		distance -= stepSize;
		testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
	}
	// point will be in the bounding volume.
	while (distance > 0.0f)
	{
		distance -= stepSize;
		testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
		if (!pointInBoundingVolume(testPoint, vol, numSegments))
		{
			return distance + stepSize;
		}
	}
	return -1.0f;
}

float Math::VolumeIntersection::rayDistanceToCollisionTrace(const Ray2D& r, const BoundingBox& vol, float stepSize, float maxDist)
{
	using namespace Math::Vector;
	// the normal raycasting approach
	float traceDist = stepSize;
	Vector2D dirScaled, testPoint;
	dirScaled = scaled(traceDist, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);

	while (traceDist < maxDist)
	{
		if (pointInBoundingVolume(testPoint, vol))
		{
			return traceDist;
		}
		traceDist += stepSize;
		dirScaled = scaled(traceDist, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
	}
	return -1.0f;
}

float Math::VolumeIntersection::rayDistanceToCollisionTrace(const Ray2D& r, const BoundingCircle& vol, float stepSize, float maxDist)
{
	using namespace Math::Vector;
	// the normal raycasting approach
	float traceDist = stepSize;
	Vector2D dirScaled, testPoint;
	dirScaled = scaled(traceDist, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);


	while (traceDist < maxDist)
	{
		if (pointInBoundingVolume(testPoint, vol))
		{
			return traceDist;
		}
		traceDist += stepSize;
		dirScaled = scaled(traceDist, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
	}
	return -1.0f;
}

float Math::VolumeIntersection::rayDistanceToCollisionTrace(const Ray3D& r, const BoundingSphere& vol, float stepSize, float maxDist)
{
	using namespace Math::Vector;
	// the normal raycasting approach
	float traceDist = stepSize;
	Vector3D dirScaled, testPoint;
	dirScaled = scaled(traceDist, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);


	while (traceDist < maxDist)
	{
		if (pointInBoundingVolume(testPoint, vol))
		{
			return traceDist;
		}
		traceDist += stepSize;
		dirScaled = scaled(traceDist, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
	}
	return -1.0f;
}

float Math::VolumeIntersection::rayDistanceToCollisionTrace(const Ray3D& r, const BoundingCube& vol, float stepSize, float maxDist)
{
	using namespace Math::Vector;
	// the normal raycasting approach
	float traceDist = stepSize;
	Vector3D dirScaled, testPoint;
	dirScaled = scaled(traceDist, r.direction);
	testPoint = add(r.pointOfOrigin, dirScaled);


	while (traceDist < maxDist)
	{
		if (pointInBoundingVolume(testPoint, vol))
		{
			return traceDist;
		}
		traceDist += stepSize;
		dirScaled = scaled(traceDist, r.direction);
		testPoint = add(r.pointOfOrigin, dirScaled);
	}
	return -1.0f;
}

float Math::VolumeIntersection::rayDistanceToCollisionTrace(const Ray2D& r, const BoundingCapsule2D& vol, float stepSize, float maxDist, uint32_t numSegments)
{
	using namespace Math::Vector;
	float distance = stepSize;
	Vector2D testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
	while (distance < maxDist)
	{
		if (pointInBoundingVolume(testPoint, vol, numSegments))
		{
			return distance;
		}
		distance += stepSize;
		testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
	}
	return -1.0f;
}

float Math::VolumeIntersection::rayDistanceToCollisionTrace(const Ray3D& r, const BoundingCapsule3D& vol, float stepSize, float maxDist, uint32_t numSegments)
{
	using namespace Math::Vector;
	float distance = stepSize;
	Vector3D testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
	while (distance < maxDist)
	{
		if (pointInBoundingVolume(testPoint, vol, numSegments))
		{
			return distance;
		}
		distance += stepSize;
		testPoint = add(r.pointOfOrigin, scaled(distance, r.direction));
	}
	return -1.0f;
}