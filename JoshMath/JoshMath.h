#ifndef JOSH_MATH_SOL_H_
#define JOSH_MATH_SOL_H_

#include "MathTypes.h"

#include <cstdint>

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

namespace Math
{
	namespace Vector
	{
		float dotProduct(const Types::Vector2D& vecA, const Types::Vector2D& vecB);
		float dotProduct(const Types::Vector3D& vecA, const Types::Vector3D& vecB);

		float altDotProduct(const Types::Vector2D& vecA, const Types::Vector2D& vecB);
		float altDotProduct(const Types::Vector3D& vecA, const Types::Vector3D& vecB);

		Types::Vector2D crossProduct(const Types::Vector2D& vecA, const Types::Vector2D& vecB);
		Types::Vector3D crossProduct(const Types::Vector3D& vecA, const Types::Vector3D& vecB);

		float angleBetween(const Types::Vector2D& a, const Types::Vector2D& b);
		float angleBetween(const Types::Vector3D& a, const Types::Vector3D& b);

		Types::Vector2D add (const Types::Vector2D& a, const Types::Vector2D& b);
		Types::Vector2D subtract (const Types::Vector2D& a, const Types::Vector2D& b);

		Types::Vector3D add (const Types::Vector3D& a, const Types::Vector3D& b);
		Types::Vector3D subtract (const Types::Vector3D& a, const Types::Vector3D& b);

		Types::Vector2D wayToVector(const Types::Vector2D& pointA, const Types::Vector2D& pointB);
		Types::Vector3D wayToVector(const Types::Vector3D& pointA, const Types::Vector3D& pointB);

		float magnitude (const Types::Vector2D& a);
		float magnitude (const Types::Vector3D& a);

		float magnitudeSquared(const Types::Vector2D& a);
		float magnitudeSquared(const Types::Vector3D& a);

		Types::Vector2D scaled(float scale, const Types::Vector2D& toScale);
		Types::Vector3D scaled(float scale, const Types::Vector3D& toScale);

		Types::Vector2D unitVector(const Types::Vector2D& a);
		Types::Vector3D unitVector(const Types::Vector3D& a);

		float lookAt2D(const Types::Vector2D& currentlyLookingAtPos, const Types::Vector2D& toLookAtPos, const Types::Vector2D& currentPos);// return angle to rotate by in radians
		Types::Matrix4x4 lookAt3D(const Types::Vector3D& position, const Types::Vector3D& targetPosition, const Types::Vector3D& upVec);
	}

	float degreesToRadians(float valueInDegrees);
	float radiansToDegrees(float valueInRadians);

	namespace Conversion
	{
		Types::PolarCoordinate CartesianToPolar(const Types::Vector2D& cartVal);
		Types::Vector2D PolarToCartesian(const Types::PolarCoordinate& Polarval);
	}

	namespace Matrix
	{
		// addition
		Types::Matrix2x1 add(const Types::Matrix2x1& a, const Types::Matrix2x1& b);
		Types::Matrix2x2 add(const Types::Matrix2x2& a, const Types::Matrix2x2& b);
		Types::Matrix3x1 add(const Types::Matrix3x1& a, const Types::Matrix3x1& b);
		Types::Matrix3x3 add(const Types::Matrix3x3& a, const Types::Matrix3x3& b);
		Types::Matrix4x1 add(const Types::Matrix4x1& a, const Types::Matrix4x1& b);
		Types::Matrix4x3 add(const Types::Matrix4x3& a, const Types::Matrix4x3& b);
		Types::Matrix4x4 add(const Types::Matrix4x4& a, const Types::Matrix4x4& b);

		// subtraction
		Types::Matrix2x1 subtract(const Types::Matrix2x1& a, const Types::Matrix2x1& b);
		Types::Matrix2x2 subtract(const Types::Matrix2x2& a, const Types::Matrix2x2& b);
		Types::Matrix3x1 subtract(const Types::Matrix3x1& a, const Types::Matrix3x1& b);
		Types::Matrix3x3 subtract(const Types::Matrix3x3& a, const Types::Matrix3x3& b);
		Types::Matrix4x1 subtract(const Types::Matrix4x1& a, const Types::Matrix4x1& b);
		Types::Matrix4x3 subtract(const Types::Matrix4x3& a, const Types::Matrix4x3& b);
		Types::Matrix4x4 subtract(const Types::Matrix4x4& a, const Types::Matrix4x4& b);

		// multerplication, (with scaler value)

		Types::Matrix2x1 multiply(float scale, const Types::Matrix2x1& a);
		Types::Matrix2x2 multiply(float scale, const Types::Matrix2x2& a);
		Types::Matrix3x1 multiply(float scale, const Types::Matrix3x1& a);
		Types::Matrix3x3 multiply(float scale, const Types::Matrix3x3& a);
		Types::Matrix4x1 multiply(float scale, const Types::Matrix4x1& a);
		Types::Matrix4x3 multiply(float scale, const Types::Matrix4x3& a);
		Types::Matrix4x4 multiply(float scale, const Types::Matrix4x4& a);

		// matrix mul
		// 2x2 x 2x1 = 2x1
		// 2x2 x 2x2 = 2x2
		Types::Matrix2x1 multiply(const Types::Matrix2x2& a, const Types::Matrix2x1& b);
		Types::Matrix2x2 multiply(const Types::Matrix2x2& a, const Types::Matrix2x2& b);

		// 3x3 x 3x1 = 3x1
		// 3x3 x 3x3 = 3x3
		Types::Matrix3x1 multiply(const Types::Matrix3x3& a, const Types::Matrix3x1& b);
		Types::Matrix3x3 multiply(const Types::Matrix3x3& a, const Types::Matrix3x3& b);

		// 4x4 x 4x1 = 4x1
		// 4x4 x 4x3 = 4x3
		// 4x4 x 4x4 = 4x4
		// 4x3 x 3x1 = 4x1
		// 4x3 x 3x3 = 4x3

		Types::Matrix4x1 multiply(const Types::Matrix4x4& a, const Types::Matrix4x1& b);
		Types::Matrix4x3 multiply(const Types::Matrix4x4& a, const Types::Matrix4x3& b);
		Types::Matrix4x4 multiply(const Types::Matrix4x4& a, const Types::Matrix4x4& b);
		Types::Matrix4x1 multiply(const Types::Matrix4x3& a, const Types::Matrix3x1& b);
		Types::Matrix4x3 multiply(const Types::Matrix4x3& a, const Types::Matrix3x3& b);

		float determinant(const Types::Matrix2x2& a);
		float determinant(const Types::Matrix3x3& a);
		float determinant(const Types::Matrix4x4& a);

		// transpose
		Types::Matrix2x2 transpose(const Types::Matrix2x2& a);
		Types::Matrix3x3 transpose(const Types::Matrix3x3& a);
		Types::Matrix4x4 transpose(const Types::Matrix4x4& a);

		// inverse
		Types::Matrix2x2 inverse(const Types::Matrix2x2& a);
		Types::Matrix3x3 inverse(const Types::Matrix3x3& a);
		Types::Matrix4x4 inverse(const Types::Matrix4x4& a);

		// identity
		void makeIdentity(Types::Matrix2x2& a);
		void makeIdentity(Types::Matrix3x3& a);
		void makeIdentity(Types::Matrix4x4& a);

		Types::Matrix2x2 identity2x2();
		Types::Matrix3x3 identity3x3();
		Types::Matrix4x4 identity4x4();

		Types::Matrix2x2 zero2x2();
		Types::Matrix3x3 zero3x3();
		Types::Matrix4x4 zero4x4();
	}

	namespace Quaternion
	{
		Types::Quaternion create(float angle, const Types::Vector3D& axis);

		Types::Quaternion conjugate(const Types::Quaternion& original);

		Types::Quaternion normalise(Types::Quaternion& toNormalise);

		Types::Quaternion scale(const Types::Quaternion& toScale, float scale);

		Types::Quaternion multiply(const Types::Quaternion& a, const Types::Quaternion& b);

		Types::Quaternion add(const Types::Quaternion& a, const Types::Quaternion& b);

		Types::Quaternion subtract(const Types::Quaternion& a, const Types::Quaternion& b);

		void identityForMul(Types::Quaternion& a);

		void identityForAdd(Types::Quaternion& a);

		float norm(const Types::Quaternion& a);
		
		Types::Quaternion inverse(const Types::Quaternion& a);

		Types::Matrix4x4 toMatrix4x4(const Types::Quaternion& a);

		Types::Matrix3x3 toMatrix3x3(const Types::Quaternion& a);
	}

	namespace Plane
	{
		Types::Plane createPlane(const Types::Vector3D& axisAsUnit, float dictanceFromOrigin);
		float dotProductAsVector(const Types::Plane& plane, const Types::Vector3D& vector);
		float dotProductAsPosition(const Types::Plane& plane, const Types::Vector3D& vector);
		float distanceFromPlane(const Types::Plane& plane, const Types::Vector3D& point);
		Types::Vector3D reflectVector(const Types::Vector3D& vectorToReflect, const Types::Plane& reflectIn);
		Types::Vector3D reflectPosition(const Types::Vector3D& positionToReflect, const Types::Plane& reflectIn);
	}

	namespace Transform
	{
		void scale2D(Types::Matrix2x1& toScale, float xScale, float yScale);
		void scale3D(Types::Matrix3x1& toScale, float xScale, float yScale, float zScale);
		void scale4D(Types::Matrix4x1& toScale, float xScale, float yScale, float zScale, float wScale);
		void rotate2DClkWise(Types::Matrix2x1& toRot, float thetaRads);
		void rotate2DAntiClkWise(Types::Matrix2x1& toRot, float thetaRads);
		
		// 3d rotation matrix versions
		void rotate3DX(Types::Matrix3x1& toRotate, float thetaRads);
		void rotate3DY(Types::Matrix3x1& toRotate, float thetaRads);
		void rotate3DZ(Types::Matrix3x1& toRotate, float thetaRads);
		
		void rotateCustomAxis(const Types::Vector3D& axisUnitVector, float thetaRads, Types::Matrix3x1& toRotate);

		Types::Matrix2x2 get2dRotationMatrixClkWise(float thetaRads);
		Types::Matrix2x2 get2dRotationMatrixAntiClkWise(float thetaRads);

		Types::Matrix3x3 get3x3Rotate3DXMatrix(float thetaRads);
		Types::Matrix3x3 get3x3Rotate3DYMatrix(float thetaRads);
		Types::Matrix3x3 get3x3Rotate3DZMatrix(float thetaRads);

		Types::Matrix3x3 getRotationMatrixForCustomAxis(const Types::Vector3D& axisUnitVector, float thetaRads);
		Types::Matrix4x4 get4x4RotationMatrixForCustomAxis(const Types::Vector3D& axisUnitVector, float thetaRads);

		Types::Matrix2x2 get2x2ScalingMatrix(float x, float y);
		Types::Matrix3x3 get3x3ScalingMatrix(float x, float y, float z);
		Types::Matrix4x4 get4x4ScalingMatrix(float x, float y, float z, float w);
		
		Types::Matrix4x4 get4x4TranslationMatrix(const Types::Vector3D& translation);

	
		void translate2D(Types::Matrix2x1& toTranslate, const Types::Vector2D& translateBy);
		void translate3D(Types::Matrix3x1& toTranslate, const Types::Vector3D& translateBy);

		Types::Matrix4x4 RightHandViewMatrix(const Types::Vector3D& eye, const Types::Vector3D& up, const Types::Vector3D& at);
		Types::Matrix4x4 LeftHandViewMatrix(const Types::Vector3D& eye, const Types::Vector3D& up, const Types::Vector3D& at);
		Types::Matrix4x4 OrthographicProjectionMatrix(float width, float height, float nearZ, float farZ);
		Types::Matrix4x4 PerspectiveProjectionMatrix(float fovInYDirection, float aspectRatio, float nearDepth, float farDepth);
	}

	namespace Interpolation
	{
		float lerp(float valueA, float valueB, float targetPoint); // target point should be between 0.0f & 1.0f
		
		// vector lerp
		Types::Vector2D lerp(const Types::Vector2D& vectorA, const Types::Vector2D& vectorB, float targetPoint);
		Types::Vector3D lerp(const Types::Vector3D& vectorA, const Types::Vector3D& vectorB, float targetPoint);
		
		template <typename T>
		T lerp(T valueA, T valueB, float targetPoint)
		{
			return (1.0f - targetPoint) * valueA + targetPoint * valueB;
		}

		Types::Quaternion lerp(const Types::Quaternion& qa, const Types::Quaternion& qb, float targetPoint);

		Types::Quaternion slerp(const Types::Quaternion& a, const Types::Quaternion& b, float t);

		// biLerp
		/*
		b0--b1
		|	|
		a0--a1

		*/
		float biLerp(float a0, float a1, float b0, float b1, float tx, float ty);

		// triLerp
		/*
		front
		_010---_110
		|		|
		|		|
		_000---_100

		back
		_011---_111
		|		|
		|		|
		_001---_101
		*/
		float triLerp(float _000, float _100,
			float _010, float _110,

			float _001, float _101,
			float _011, float _111,

			float tx, float ty, float tz);

		float interpolationWeight(float min, float max, float x);

		float smoothStep(float min, float max, float x);
	}

	namespace VolumeIntersection
	{
		bool volumesOverlap(const Types::BoundingBox& a, const Types::BoundingBox& b);
		bool volumesOverlap(const Types::BoundingCircle& a, const Types::BoundingCircle& b);
		bool volumesOverlap(const Types::BoundingSphere& a, const Types::BoundingSphere& b);
		bool volumesOverlap(const Types::BoundingCube& a, const Types::BoundingCube& b);
		bool volumesOverlap(const Types::BoundingCapsule2D& a, const Types::BoundingCapsule2D& b, uint32_t numSegments = 10);
		bool volumesOverlap(const Types::BoundingCapsule3D& a, const Types::BoundingCapsule3D& b, uint32_t numSegments = 10);

		bool pointInBoundingVolume(const Types::Vector2D& a, const Types::BoundingBox& vol);
		bool pointInBoundingVolume(const Types::Vector2D& a, const Types::BoundingCircle& vol);
		bool pointInBoundingVolume(const Types::Vector3D& a, const Types::BoundingSphere& vol);
		bool pointInBoundingVolume(const Types::Vector3D& a, const Types::BoundingCube& vol);
		bool pointInBoundingVolume(const Types::Vector2D& a, const Types::BoundingCapsule2D& vol, uint32_t numSegments = 10);
		bool pointInBoundingVolume(const Types::Vector3D& a, const Types::BoundingCapsule3D& vol, uint32_t numSegments = 10);

		bool volumeInRayPath(const Types::Ray2D& r, const Types::BoundingBox& vol);
		bool volumeInRayPath(const Types::Ray2D& r, const Types::BoundingCircle& vol);
		bool volumeInRayPath(const Types::Ray3D& r, const Types::BoundingSphere& vol);
		bool volumeInRayPath(const Types::Ray3D& r, const Types::BoundingCube& vol);
		bool volumeInRayPath(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, uint32_t numSegments = 10);
		bool volumeInRayPath(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, uint32_t numSegments = 10);

		// below assume that a volume is in the ray path, (defermined via above functions)
		// these are designed for speed NOT percision
		float rayDistanceToCollisionFast(const Types::Ray2D& r, const Types::BoundingBox& vol);
		float rayDistanceToCollisionFast(const Types::Ray2D& r, const Types::BoundingCircle& vol);
		float rayDistanceToCollisionFast(const Types::Ray3D& r, const Types::BoundingSphere& vol);
		float rayDistanceToCollisionFast(const Types::Ray3D& r, const Types::BoundingCube& vol);
		float rayDistanceToCollisionFast(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, uint32_t numSegments = 10);
		float rayDistanceToCollisionFast(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, uint32_t numSegments = 10);

		// these are designed for percision (down to the user) at the cost speed
		// small step size = accurate & slow
		// lager step size = inaccurate & fast*
		float rayDistanceToCollisionReverseTrace(const Types::Ray2D& r, const Types::BoundingBox& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray2D& r, const Types::BoundingCircle& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray3D& r, const Types::BoundingSphere& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray3D& r, const Types::BoundingCube& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, float stepSize, uint32_t numSegments = 10);
		float rayDistanceToCollisionReverseTrace(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, float stepSize, uint32_t numSegments = 10);

		float rayDistanceToCollisionTrace(const Types::Ray2D& r, const Types::BoundingBox& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray2D& r, const Types::BoundingCircle& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray3D& r, const Types::BoundingSphere& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray3D& r, const Types::BoundingCube& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, float stepSize, float maxDist, uint32_t numSegments = 10);
		float rayDistanceToCollisionTrace(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, float stepSize, float maxDist, uint32_t numSegments = 10);
	}

	namespace Physics
	{
		// pratical model for now
		Types::Vector2D netForce(const Types::Vector2D* forces, const unsigned int nForces);
		Types::Vector3D netForce(const Types::Vector3D* forces, const unsigned int nForces);

		Types::Vector2D acceleration(const Types::Vector2D& netForce, float mass);
		Types::Vector3D acceleration(const Types::Vector3D& netForce, float mass);

		Types::Vector2D velocity(const Types::Vector2D& previousVelocity, const Types::Vector2D& acceleration, float time);
		Types::Vector3D velocity(const Types::Vector3D& previousVelocity, const Types::Vector3D& acceleration, float time);

		Types::Vector2D momentum(const Types::Vector2D& velocity, float mass);
		Types::Vector3D momentum(const Types::Vector3D& velocity, float mass);

		float speed(const Types::Vector2D& velocity);
		float speed(const Types::Vector3D& velocity);
	}

	namespace Miscellaneous
	{
		float diff(float x, float y);
	}
}

#endif