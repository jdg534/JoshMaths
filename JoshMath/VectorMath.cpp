#include "VectorMath.h"

#include <cfloat>
#include <cmath>

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

float Math::Vector::dotProduct(const Vector2D& vecA, const Vector2D& vecB)
{
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
}

float Math::Vector::dotProduct(const Vector3D& vecA, const Vector3D& vecB)
{
	return (vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z);
}

float Math::Vector::altDotProduct(const Vector2D& vecA, const Vector2D& vecB)
{
	//  is |A| |B| cos(theta)
	float aMag = magnitude(vecA);
	float bMag = magnitude(vecB);

	// cos(theta) = (A.B)/|A| |B|
	float thetaRads = angleBetween(vecA, vecB);
	// float cosTheta = dotProduct(vecA, vecB) / (aMag + bMag);
	float cosTheta = cosf(thetaRads);
	return aMag * bMag * cosTheta;
}

float Math::Vector::altDotProduct(const Vector3D& vecA, const Vector3D& vecB)
{
	//  is |A| |B| cos(theta)
	float aMag = magnitude(vecA);
	float bMag = magnitude(vecB);

	// cos(theta) = (A.B)/|A| |B|
	float thetaRads = angleBetween(vecA, vecB);
	float cosTheta = cosf(thetaRads);

	// float cosTheta = dotProduct(vecA, vecB) / (aMag + bMag);

	return aMag * bMag * cosTheta;
}

Vector2D Math::Vector::crossProduct(const Vector2D& vecA, const Vector2D& vecB)
{
	Vector2D rv;
	rv.x = (vecA.y * 0.0f) - (0.0f * vecB.y);
	rv.y = (0.0f * vecB.x) - (vecA.x * 0.0f);
	return rv;
}

Vector3D Math::Vector::crossProduct(const Vector3D& vecA, const Vector3D& vecB)
{
	Vector3D rv;
	rv.x = (vecA.y * vecB.z) - (vecA.z * vecB.y);
	rv.y = (vecA.z * vecB.x) - (vecA.x * vecB.z);
	rv.z = (vecA.x * vecB.y) - (vecA.y * vecB.x);
	return rv;
}

float Math::Vector::angleBetween(const Vector2D& a, const Vector2D& b)
{
	float cosTheta = (dotProduct(a,b)) / (magnitude(a) * magnitude(b));
	return acosf(cosTheta);
}

float Math::Vector::angleBetween(const Vector3D& a, const Vector3D& b)
{
	float cosTheta = (dotProduct(a, b)) / (magnitude(a) * magnitude(b));
	return acosf(cosTheta);
}

Vector2D Math::Vector::add(const Vector2D& a, const Vector2D& b)
{
	Vector2D returnVal;
	returnVal.x = a.x + b.x;
	returnVal.y = a.y + b.y;
	return returnVal;
}

Vector2D Math::Vector::subtract(const Vector2D& a, const Vector2D& b)
{
	Vector2D rv;
	rv.x = a.x - b.x;
	rv.y = a.y - b.y;
	return rv;
}

Vector3D Math::Vector::add(const Vector3D& a, const Vector3D& b)
{
	Vector3D rv;
	rv.x = a.x + b.x;
	rv.y = a.y + b.y;
	rv.z = a.z + b.z;
	return rv;
}

Vector3D Math::Vector::subtract(const Vector3D& a, const Vector3D& b)
{
	Vector3D rv;
	rv.x = a.x - b.x;
	rv.y = a.y - b.y;
	rv.z = a.z - b.z;
	return rv;
}

Vector2D Math::Vector::wayToVector(const Vector2D& pointA, const Vector2D& pointB)
{
	return subtract(pointB, pointA);
}

Vector3D Math::Vector::wayToVector(const Vector3D& pointA, const Vector3D& pointB)
{
	return subtract(pointB, pointA);
}

float Math::Vector::magnitude(const Vector2D& a)
{
	float rv = (a.x * a.x) + (a.y * a.y);
	rv = sqrtf(rv);
	return rv;
}

float Math::Vector::magnitude(const Vector3D& a)
{
	float rv = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
	rv = sqrtf(rv);
	return rv;
}

float Math::Vector::magnitudeSquared(const Vector2D& a)
{
	return (a.x * a.x) + (a.y * a.y);
}

float Math::Vector::magnitudeSquared(const Vector3D& a)
{
	return (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
}

Vector2D Math::Vector::scaled(float scale, const Vector2D& toScale)
{
	Vector2D rv;
	rv.x = toScale.x * scale;
	rv.y = toScale.y * scale;
	return rv;
}

Vector3D Math::Vector::scaled(float scale, const Vector3D& toScale)
{
	Vector3D rv; // rv = Return Value
	rv.x = toScale.x * scale;
	rv.y = toScale.y * scale;
	rv.z = toScale.z * scale;
	return rv;
}

Vector2D Math::Vector::unitVector(const Vector2D& a)
{
	float mag = magnitude(a);
	float unitScale = 1.0f / mag;
	return scaled(unitScale, a);
}

Vector3D Math::Vector::unitVector(const Vector3D& a)
{
	float mag = magnitude(a);
	float unitScale = 1.0f / mag;
	return scaled(unitScale, a);
}

float Math::Vector::lookAt2D(const Vector2D& currentlyLookingAtPos, const Vector2D& toLookAtPos, const Vector2D& currentPos)
{
	// need unit vectors from eye position to currently facing position & eye position to position want to look at
	Vector2D eye2OldAt = wayToVector(currentPos, currentlyLookingAtPos);
	Vector2D eye2NewAt = wayToVector(currentPos, toLookAtPos);
	eye2OldAt = unitVector(eye2OldAt);
	eye2NewAt = unitVector(eye2NewAt);

	float dp = dotProduct(eye2OldAt, eye2NewAt);

	return acosf(dp);
}

Matrix4x4 Math::Vector::lookAt3D(const Vector3D & position, const Vector3D & targetPosition, const Vector3D & upVec)
{
	Vector3D zAxis = subtract(position, targetPosition);
	zAxis = unitVector(zAxis);

	Vector3D xAxis = crossProduct(upVec, zAxis);
	Vector3D yAxis = crossProduct(zAxis, xAxis);

	Matrix4x4 rv;

	rv.r1c1 = xAxis.x;
	rv.r2c1 = xAxis.y;
	rv.r3c1 = xAxis.z;
	rv.r4c1 = 0.0f;

	rv.r1c2 = yAxis.x;
	rv.r2c2 = yAxis.y;
	rv.r3c2 = yAxis.z;
	rv.r4c2 = 0.0f;

	rv.r1c3 = zAxis.x;
	rv.r2c3 = zAxis.y;
	rv.r3c3 = xAxis.z;
	rv.r4c3 = 0.0f;

	rv.r1c4 = position.x;
	rv.r2c4 = position.y;
	rv.r3c4 = position.z;
	rv.r4c4 = 1.0f;

	return rv;
}
