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
	namespace VectorMath
	{
		float dotProduct(const Vector2D& vecA, const Vector2D& vecB);
		float dotProduct(const Vector3D& vecA, const Vector3D& vecB);

		float altDotProduct(const Vector2D& vecA, const Vector2D& vecB);
		float altDotProduct(const Vector3D& vecA, const Vector3D& vecB);

		Vector2D crossProduct(const Vector2D& vecA, const Vector2D& vecB);
		Vector3D crossProduct(const Vector3D& vecA, const Vector3D& vecB);

		float angleBetween(const Vector2D& a, const Vector2D& b);
		float angleBetween(const Vector3D& a, const Vector3D& b);

		Vector2D add (const Vector2D& a, const Vector2D& b);
		Vector2D subtract (const Vector2D& a, const Vector2D& b);

		Vector3D add (const Vector3D& a, const Vector3D& b);
		Vector3D subtract (const Vector3D& a, const Vector3D& b);

		Vector2D wayToVector(const Vector2D& pointA, const Vector2D& pointB);
		Vector3D wayToVector(const Vector3D& pointA, const Vector3D& pointB);

		float magnitude (const Vector2D& a);
		float magnitude (const Vector3D& a);

		float magnitudeSquared(const Vector2D& a);
		float magnitudeSquared(const Vector3D& a);

		Vector2D scaled(float scale, const Vector2D& toScale);
		Vector3D scaled(float scale, const Vector3D& toScale);

		Vector2D unitVector(const Vector2D& a);
		Vector3D unitVector(const Vector3D& a);

		float lookAt2D(const Vector2D& currentlyLookingAtPos, const Vector2D& toLookAtPos, const Vector2D& currentPos);// return angle to rotate by in radians
		Matrix4x4 lookAt3D(const Vector3D& position, const Vector3D& targetPosition, const Vector3D& upVec);
	}

	float degreesToRadians(float valueInDegrees);
	float radiansToDegrees(float valueInRadians);

	namespace PolarCoordinateMath
	{
		PolarCoordinate CartesianToPolar(const Vector2D& cartVal);
		Vector2D PolarToCartesian(const PolarCoordinate& Polarval);
	}

	namespace MatrixMath
	{
		// addition
		Matrix2x1 add(const Matrix2x1& a, const Matrix2x1& b);
		Matrix2x2 add(const Matrix2x2& a, const Matrix2x2& b);
		Matrix3x1 add(const Matrix3x1& a, const Matrix3x1& b);
		Matrix3x3 add(const Matrix3x3& a, const Matrix3x3& b);
		Matrix4x1 add(const Matrix4x1& a, const Matrix4x1& b);
		Matrix4x3 add(const Matrix4x3& a, const Matrix4x3& b);
		Matrix4x4 add(const Matrix4x4& a, const Matrix4x4& b);

		// subtraction
		Matrix2x1 subtract(const Matrix2x1& a, const Matrix2x1& b);
		Matrix2x2 subtract(const Matrix2x2& a, const Matrix2x2& b);
		Matrix3x1 subtract(const Matrix3x1& a, const Matrix3x1& b);
		Matrix3x3 subtract(const Matrix3x3& a, const Matrix3x3& b);
		Matrix4x1 subtract(const Matrix4x1& a, const Matrix4x1& b);
		Matrix4x3 subtract(const Matrix4x3& a, const Matrix4x3& b);
		Matrix4x4 subtract(const Matrix4x4& a, const Matrix4x4& b);

		// multerplication, (with scaler value)

		Matrix2x1 multiply(float scale, const Matrix2x1& a);
		Matrix2x2 multiply(float scale, const Matrix2x2& a);
		Matrix3x1 multiply(float scale, const Matrix3x1& a);
		Matrix3x3 multiply(float scale, const Matrix3x3& a);
		Matrix4x1 multiply(float scale, const Matrix4x1& a);
		Matrix4x3 multiply(float scale, const Matrix4x3& a);
		Matrix4x4 multiply(float scale, const Matrix4x4& a);

		// matrix mul
		// 2x2 x 2x1 = 2x1
		// 2x2 x 2x2 = 2x2
		Matrix2x1 multiply(const Matrix2x2& a, const Matrix2x1& b);
		Matrix2x2 multiply(const Matrix2x2& a, const Matrix2x2& b);

		// 3x3 x 3x1 = 3x1
		// 3x3 x 3x3 = 3x3
		Matrix3x1 multiply(const Matrix3x3& a, const Matrix3x1& b);
		Matrix3x3 multiply(const Matrix3x3& a, const Matrix3x3& b);

		// 4x4 x 4x1 = 4x1
		// 4x4 x 4x3 = 4x3
		// 4x4 x 4x4 = 4x4
		// 4x3 x 3x1 = 4x1
		// 4x3 x 3x3 = 4x3

		Matrix4x1 multiply(const Matrix4x4& a, const Matrix4x1& b);
		Matrix4x3 multiply(const Matrix4x4& a, const Matrix4x3& b);
		Matrix4x4 multiply(const Matrix4x4& a, const Matrix4x4& b);
		Matrix4x1 multiply(const Matrix4x3& a, const Matrix3x1& b);
		Matrix4x3 multiply(const Matrix4x3& a, const Matrix3x3& b);

		float determinant(const Matrix2x2& a);
		float determinant(const Matrix3x3& a);
		float determinant(const Matrix4x4& a);

		// transpose
		Matrix2x2 transpose(const Matrix2x2& a);
		Matrix3x3 transpose(const Matrix3x3& a);
		Matrix4x4 transpose(const Matrix4x4& a);

		// inverse
		Matrix2x2 inverse(const Matrix2x2& a);
		Matrix3x3 inverse(const Matrix3x3& a);
		Matrix4x4 inverse(const Matrix4x4& a);

		// identity
		void makeIdentity(Matrix2x2& a);
		void makeIdentity(Matrix3x3& a);
		void makeIdentity(Matrix4x4& a);
	}

	namespace QuaternionMath
	{
		Quaternion create(float angle, const Vector3D& axis);

		Quaternion conjugate(const Quaternion& original);

		Quaternion normalise(Quaternion& toNormalise);

		Quaternion scale(const Quaternion& toScale, float scale);

		Quaternion multiply(const Quaternion& a, const Quaternion& b);

		Quaternion add(const Quaternion& a, const Quaternion& b);

		Quaternion subtract(const Quaternion& a, const Quaternion& b);

		void identityForMul(Quaternion& a);

		void identityForAdd(Quaternion& a);

		float norm(const Quaternion& a);
		
		Quaternion inverse(const Quaternion& a);

		Matrix4x4 toMatrix4x4(const Quaternion& a);

		Matrix3x3 toMatrix3x3(const Quaternion& a);
	}

	namespace Planes
	{
		Plane createPlane(const Vector3D& axisAsUnit, float dictanceFromOrigin);
		float dotProductAsVector(const Plane& plane, const Vector3D& vector);
		float dotProductAsPosition(const Plane& plane, const Vector3D& vector);
		float distanceFromPlane(const Plane& plane, const Vector3D& point);
		Vector3D reflectVector(const Vector3D& vectorToReflect, const Plane& reflectIn);
		Vector3D reflectPosition(const Vector3D& positionToReflect, const Plane& reflectIn);
	}

	namespace Transform
	{
		void scale2D(Matrix2x1& toScale, float xScale, float yScale);
		void scale3D(Matrix3x1& toScale, float xScale, float yScale, float zScale);
		void scale4D(Matrix4x1& toScale, float xScale, float yScale, float zScale, float wScale);
		void rotate2DClkWise(Matrix2x1& toRot, float thetaRads);
		void rotate2DAntiClkWise(Matrix2x1& toRot, float thetaRads);
		
		// 3d rotation matrix versions
		void rotate3DX(Matrix3x1& toRotate, float thetaRads);
		void rotate3DY(Matrix3x1& toRotate, float thetaRads);
		void rotate3DZ(Matrix3x1& toRotate, float thetaRads);
		
		void rotateCustomAxis(const Vector3D& axisUnitVector, float thetaRads, Matrix3x1 & toRotate);

		Matrix2x2 get2dRotationMatrixClkWise(float thetaRads);
		Matrix2x2 get2dRotationMatrixAntiClkWise(float thetaRads);

		Matrix3x3 get3x3Rotate3DXMatrix(float thetaRads);
		Matrix3x3 get3x3Rotate3DYMatrix(float thetaRads);
		Matrix3x3 get3x3Rotate3DZMatrix(float thetaRads);

		Matrix3x3 getRotationMatrixForCustomAxis(const Vector3D& axisUnitVector, float thetaRads);
		Matrix4x4 get4x4RotationMatrixForCustomAxis(const Vector3D& axisUnitVector, float thetaRads);

		Matrix2x2 get2x2ScalingMatrix(float x, float y);
		Matrix3x3 get3x3ScalingMatrix(float x, float y, float z);
		Matrix4x4 get4x4ScalingMatrix(float x, float y, float z, float w);
		
		Matrix4x4 get4x4TranslationMatrix(const Vector3D& translation);

	
		void translate2D(Matrix2x1& toTranslate, const Vector2D& translateBy);
		void translate3D(Matrix3x1& toTranslate, const Vector3D& translateBy);

		Matrix4x4 RightHandViewMatrix(const Vector3D& eye, const Vector3D& up, const Vector3D& at);
		Matrix4x4 LeftHandViewMatrix(const Vector3D& eye, const Vector3D& up, const Vector3D& at);
		Matrix4x4 OrthographicProjectionMatrix(float width, float height, float nearZ, float farZ);
		Matrix4x4 PerspectiveProjectionMatrix(float fovInYDirection, float aspectRatio, float nearDepth, float farDepth);
	}

	namespace Interpolation
	{
		float lerp(float valueA, float valueB, float targetPoint); // target point should be between 0.0f & 1.0f
		
		// vector lerp
		Vector2D lerp(const Vector2D& vectorA, const Vector2D& vectorB, float targetPoint);
		Vector3D lerp(const Vector3D& vectorA, const Vector3D& vectorB, float targetPoint);
		
		template <typename T>
		T lerp(T valueA, T valueB, float targetPoint)
		{
			return (1.0f - targetPoint) * valueA + targetPoint * valueB;
		}

		Quaternion lerp(const Quaternion& qa, const Quaternion& qb, float targetPoint);

		// slep
		Quaternion slerp(const Quaternion& a, const Quaternion& b, float t);

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
		bool volumesOverlap(const BoundingBox& a, const BoundingBox& b);
		bool volumesOverlap(const BoundingCircle& a, const BoundingCircle& b);
		bool volumesOverlap(const BoundingSphere& a, const BoundingSphere& b);
		bool volumesOverlap(const BoundingCube& a, const BoundingCube& b);
		bool volumesOverlap(const BoundingCapsule2D& a, const BoundingCapsule2D& b, uint32_t numSegments = 10);
		bool volumesOverlap(const BoundingCapsule3D& a, const BoundingCapsule3D& b, uint32_t numSegments = 10);

		bool pointInBoundingVolume(const Vector2D& a, const BoundingBox& vol);
		bool pointInBoundingVolume(const Vector2D& a, const BoundingCircle& vol);
		bool pointInBoundingVolume(const Vector3D& a, const BoundingSphere& vol);
		bool pointInBoundingVolume(const Vector3D& a, const BoundingCube& vol);
		bool pointInBoundingVolume(const Vector2D& a, const BoundingCapsule2D& vol, uint32_t numSegments = 10);
		bool pointInBoundingVolume(const Vector3D& a, const BoundingCapsule3D& vol, uint32_t numSegments = 10);

		bool volumeInRayPath(const Ray2D& r, const BoundingBox& vol);
		bool volumeInRayPath(const Ray2D& r, const BoundingCircle& vol);
		bool volumeInRayPath(const Ray3D& r, const BoundingSphere& vol);
		bool volumeInRayPath(const Ray3D& r, const BoundingCube& vol);
		bool volumeInRayPath(const Ray2D& r, const BoundingCapsule2D& vol, uint32_t numSegments = 10);
		bool volumeInRayPath(const Ray3D& r, const BoundingCapsule3D& vol, uint32_t numSegments = 10);

		// below assume that a volume is in the ray path, (defermined via above functions)
		// these are designed for speed NOT percision
		float rayDistanceToCollisionFast(const Ray2D& r, const BoundingBox& vol);
		float rayDistanceToCollisionFast(const Ray2D& r, const BoundingCircle& vol);
		float rayDistanceToCollisionFast(const Ray3D& r, const BoundingSphere& vol);
		float rayDistanceToCollisionFast(const Ray3D& r, const BoundingCube& vol);
		float rayDistanceToCollisionFast(const Ray2D& r, const BoundingCapsule2D& vol, uint32_t numSegments = 10);
		float rayDistanceToCollisionFast(const Ray3D& r, const BoundingCapsule3D& vol, uint32_t numSegments = 10);

		// these are designed for percision (down to the user) at the cost speed
		// small step size = accurate & slow
		// lager step size = inaccurate & fast*
		float rayDistanceToCollisionReverseTrace(const Ray2D& r, const BoundingBox& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Ray2D& r, const BoundingCircle& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Ray3D& r, const BoundingSphere& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Ray3D& r, const BoundingCube& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Ray2D& r, const BoundingCapsule2D& vol, float stepSize, uint32_t numSegments = 10);
		float rayDistanceToCollisionReverseTrace(const Ray3D& r, const BoundingCapsule3D& vol, float stepSize, uint32_t numSegments = 10);

		float rayDistanceToCollisionTrace(const Ray2D& r, const BoundingBox& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Ray2D& r, const BoundingCircle& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Ray3D& r, const BoundingSphere& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Ray3D& r, const BoundingCube& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Ray2D& r, const BoundingCapsule2D& vol, float stepSize, float maxDist, uint32_t numSegments = 10);
		float rayDistanceToCollisionTrace(const Ray3D& r, const BoundingCapsule3D& vol, float stepSize, float maxDist, uint32_t numSegments = 10);
	}

	namespace Physics
	{
		// pratical model for now
		Vector2D netForce(const Vector2D* forces, const unsigned int nForces);
		Vector3D netForce(const Vector3D* forces, const unsigned int nForces);

		Vector2D acceleration(const Vector2D& netForce, float mass);
		Vector3D acceleration(const Vector3D& netForce, float mass);

		Vector2D velocity(const Vector2D& previousVelocity, const Vector2D& acceleration, float time);
		Vector3D velocity(const Vector3D& previousVelocity, const Vector3D& acceleration, float time);

		Vector2D momentum(const Vector2D& velocity, float mass);
		Vector3D momentum(const Vector3D& velocity, float mass);

		float speed(const Vector2D& velocity);
		float speed(const Vector3D& velocity);
	}

	namespace Miscellaneous
	{
		float diff(float x, float y);
	}
}

#endif