#include "JoshMath.h"
#include <cmath>

#include <cassert>

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

float Math::VectorMath::dotProduct(const Vector2D& vecA, const Vector2D& vecB)
{
	return (vecA.x * vecB.x) + (vecA.y * vecB.y);
}

float Math::VectorMath::dotProduct(const Vector3D& vecA, const Vector3D& vecB)
{
	return (vecA.x * vecB.x) + (vecA.y * vecB.y) + (vecA.z * vecB.z);
}

float Math::VectorMath::altDotProduct(const Vector2D& vecA, const Vector2D& vecB)
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

float Math::VectorMath::altDotProduct(const Vector3D& vecA, const Vector3D& vecB)
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

Vector2D Math::VectorMath::crossProduct(const Vector2D& vecA, const Vector2D& vecB)
{
	Vector2D rv;
	rv.x = (vecA.y * 0.0f) - (0.0f * vecB.y);
	rv.y = (0.0f * vecB.x) - (vecA.x * 0.0f);
	return rv;
}

Vector3D Math::VectorMath::crossProduct(const Vector3D& vecA, const Vector3D& vecB)
{
	Vector3D rv;
	rv.x = (vecA.y * vecB.z) - (vecA.z * vecB.y);
	rv.y = (vecA.z * vecB.x) - (vecA.x * vecB.z);
	rv.z = (vecA.x * vecB.y) - (vecA.y * vecB.x);
	return rv;
}

float Math::VectorMath::angleBetween(const Vector2D& a, const Vector2D& b)
{
	float cosTheta = (dotProduct(a,b)) / (magnitude(a) * magnitude(b));
	return acosf(cosTheta);
}

float Math::VectorMath::angleBetween(const Vector3D& a, const Vector3D& b)
{
	float cosTheta = (dotProduct(a, b)) / (magnitude(a) * magnitude(b));
	return acosf(cosTheta);
}

Vector2D Math::VectorMath::add (const Vector2D& a, const Vector2D& b)
{
	Vector2D returnVal;
	returnVal.x = a.x + b.x;
	returnVal.y = a.y + b.y;
	return returnVal;
}

Vector2D Math::VectorMath::subtract (const Vector2D& a, const Vector2D& b)
{
	Vector2D rv;
	rv.x = a.x - b.x;
	rv.y = a.y - b.y;
	return rv;
}

Vector3D Math::VectorMath::add (const Vector3D& a, const Vector3D& b)
{
	Vector3D rv;
	rv.x = a.x + b.x;
	rv.y = a.y + b.y;
	rv.z = a.z + b.z;
	return rv;
}

Vector3D Math::VectorMath::subtract (const Vector3D& a, const Vector3D& b)
{
	Vector3D rv;
	rv.x = a.x - b.x;
	rv.y = a.y - b.y;
	rv.z = a.z - b.z;
	return rv;
}

Vector2D Math::VectorMath::wayToVector(const Vector2D& pointA, const Vector2D& pointB)
{
	return subtract(pointB, pointA);
}

Vector3D Math::VectorMath::wayToVector(const Vector3D& pointA, const Vector3D& pointB)
{
	return subtract(pointB, pointA);
}

float Math::VectorMath::magnitude (const Vector2D& a)
{
	float rv = (a.x * a.x) + (a.y * a.y);
	rv = sqrtf(rv);
	return rv;
}

float Math::VectorMath::magnitude (const Vector3D& a)
{
	float rv = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
	rv = sqrtf(rv);
	return rv;
}

float Math::VectorMath::magnitudeSquared(const Vector2D& a)
{
	return (a.x * a.x) + (a.y * a.y);
}

float Math::VectorMath::magnitudeSquared(const Vector3D& a)
{
	return (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
}

Vector2D Math::VectorMath::scaled(float scale, const Vector2D& toScale)
{
	Vector2D rv;
	rv.x = toScale.x * scale;
	rv.y = toScale.y * scale;
	return rv;
}

Vector3D Math::VectorMath::scaled(float scale, const Vector3D& toScale)
{
	Vector3D rv; // rv = Return Value
	rv.x = toScale.x * scale;
	rv.y = toScale.y * scale;
	rv.z = toScale.z * scale;
	return rv;
}

Vector2D Math::VectorMath::unitVector(const Vector2D& a)
{
	float mag = magnitude(a);
	float unitScale = 1.0f / mag;
	return scaled(unitScale, a);
}

Vector3D Math::VectorMath::unitVector(const Vector3D& a)
{
	float mag = magnitude(a);
	float unitScale = 1.0f / mag;
	return scaled(unitScale, a);
}

float Math::VectorMath::lookAt2D(const Vector2D& currentlyLookingAtPos, const Vector2D& toLookAtPos, const Vector2D& currentPos)
{
	// need unit vectors from eye position to currently facing position & eye position to position want to look at
	Vector2D eye2OldAt = wayToVector(currentPos, currentlyLookingAtPos);
	Vector2D eye2NewAt = wayToVector(currentPos, toLookAtPos);
	eye2OldAt = unitVector(eye2OldAt);
	eye2NewAt = unitVector(eye2NewAt);

	float dp = dotProduct(eye2OldAt, eye2NewAt);

	return acosf(dp);
}

Matrix4x4 Math::VectorMath::lookAt3D(const Vector3D & position, const Vector3D & targetPosition, const Vector3D & upVec)
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

float Math::degreesToRadians(float valueInDegrees)
{
	return valueInDegrees * (3.14159265359 / 180);
}

float Math::radiansToDegrees(float valueInRadians)
{
	return valueInRadians * (180 / 3.14159265359);
}

PolarCoordinate Math::PolarCoordinateMath::CartesianToPolar(const Vector2D& cartVal)
{
	PolarCoordinate rv;
	rv.radius = VectorMath::magnitude(cartVal);
	rv.angle = atanf(cartVal.x / cartVal.y);
	// rv.angle = radiansToDegrees(rv.angle); // rads only
	return rv;
}

Vector2D Math::PolarCoordinateMath::PolarToCartesian(const PolarCoordinate& PolarVal)
{
	Vector2D rv;
	// float angleAsRads = degreesToRadians(PolarVal.angle); 
	// angle should be in rads
	rv.x = PolarVal.radius * cosf(PolarVal.angle);
	rv.y = PolarVal.radius * sinf(PolarVal.angle);
	return rv;
}

Matrix2x1 Math::MatrixMath::add(const Matrix2x1& a, const Matrix2x1& b)
{
	Matrix2x1 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r2c1 = a.r2c1 + b.r2c1;
	return rv;
}

Matrix2x2 Math::MatrixMath::add(const Matrix2x2& a, const Matrix2x2& b)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r1c2 = a.r1c2 + b.r1c2;
	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r2c2 = a.r2c2 + b.r2c2;
	return rv;
}

Matrix3x1 Math::MatrixMath::add(const Matrix3x1& a, const Matrix3x1& b)
{
	Matrix3x1 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r3c1 = a.r3c1 + b.r3c1;
	return rv;
}

Matrix3x3 Math::MatrixMath::add(const Matrix3x3& a, const Matrix3x3& b)
{
	Matrix3x3 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r1c2 = a.r1c2 + b.r1c2;
	rv.r1c3 = a.r1c3 + b.r1c3;

	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r2c2 = a.r2c2 + b.r2c2;
	rv.r2c3 = a.r2c3 + b.r2c3;

	rv.r3c1 = a.r3c1 + b.r3c1;
	rv.r3c2 = a.r3c2 + b.r3c2;
	rv.r3c3 = a.r3c3 + b.r3c3;
	return rv;
}

Matrix4x1 Math::MatrixMath::add(const Matrix4x1& a, const Matrix4x1& b)
{
	Matrix4x1 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r3c1 = a.r3c1 + b.r3c1;
	rv.r4c1 = a.r4c1 + b.r4c1;
	return rv;
}

Matrix4x3 Math::MatrixMath::add(const Matrix4x3& a, const Matrix4x3& b)
{
	Matrix4x3 rv;

	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r1c2 = a.r1c2 + b.r1c2;
	rv.r1c3 = a.r1c3 + b.r1c3;

	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r2c2 = a.r2c2 + b.r2c2;
	rv.r2c3 = a.r2c3 + b.r2c3;

	rv.r3c1 = a.r3c1 + b.r3c1;
	rv.r3c2 = a.r3c2 + b.r3c2;
	rv.r3c3 = a.r3c3 + b.r3c3;

	rv.r4c1 = a.r4c1 + b.r4c1;
	rv.r4c2 = a.r4c2 + b.r4c2;
	rv.r4c3 = a.r4c3 + b.r4c3;

	return rv;
}

Matrix4x4 Math::MatrixMath::add(const Matrix4x4& a, const Matrix4x4& b)
{
	Matrix4x4 rv;

	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r1c2 = a.r1c2 + b.r1c2;
	rv.r1c3 = a.r1c3 + b.r1c3;
	rv.r1c4 = a.r1c4 + b.r1c4;

	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r2c2 = a.r2c2 + b.r2c2;
	rv.r2c3 = a.r2c3 + b.r2c3;
	rv.r2c4 = a.r2c4 + b.r2c4;

	rv.r3c1 = a.r3c1 + b.r3c1;
	rv.r3c2 = a.r3c2 + b.r3c2;
	rv.r3c3 = a.r3c3 + b.r3c3;
	rv.r3c4 = a.r3c4 + b.r3c4;

	rv.r4c1 = a.r4c1 + b.r4c1;
	rv.r4c2 = a.r4c2 + b.r4c2;
	rv.r4c3 = a.r4c3 + b.r4c3;
	rv.r4c4 = a.r4c4 + b.r4c4;

	return rv;
}

Matrix2x1 Math::MatrixMath::subtract(const Matrix2x1& a, const Matrix2x1& b)
{
	Matrix2x1 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r2c1 = a.r2c1 - b.r2c1;
	return rv;
}

Matrix2x2 Math::MatrixMath::subtract(const Matrix2x2& a, const Matrix2x2& b)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r1c2 = a.r1c2 - b.r1c2;
	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r2c2 = a.r2c2 - b.r2c2;
	return rv;
}

Matrix3x1 Math::MatrixMath::subtract(const Matrix3x1& a, const Matrix3x1& b)
{
	Matrix3x1 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r3c1 = a.r3c1 - b.r3c1;
	return rv;
}

Matrix3x3 Math::MatrixMath::subtract(const Matrix3x3& a, const Matrix3x3& b)
{
	Matrix3x3 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r1c2 = a.r1c2 - b.r1c2;
	rv.r1c3 = a.r1c3 - b.r1c3;

	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r2c2 = a.r2c2 - b.r2c2;
	rv.r2c3 = a.r2c3 - b.r2c3;

	rv.r3c1 = a.r3c1 - b.r3c1;
	rv.r3c2 = a.r3c2 - b.r3c2;
	rv.r3c3 = a.r3c3 - b.r3c3;

	return rv;
}

Matrix4x1 Math::MatrixMath::subtract(const Matrix4x1& a, const Matrix4x1& b)
{
	Matrix4x1 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r3c1 = a.r3c1 - b.r3c1;
	rv.r4c1 = a.r4c1 - b.r4c1;

	return rv;
}

Matrix4x3 Math::MatrixMath::subtract(const Matrix4x3& a, const Matrix4x3& b)
{
	Matrix4x3 rv;

	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r1c2 = a.r1c2 - b.r1c2;
	rv.r1c3 = a.r1c3 - b.r1c3;

	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r2c2 = a.r2c2 - b.r2c2;
	rv.r2c3 = a.r2c3 - b.r2c3;

	rv.r3c1 = a.r3c1 - b.r3c1;
	rv.r3c2 = a.r3c2 - b.r3c2;
	rv.r3c3 = a.r3c3 - b.r3c3;

	rv.r4c1 = a.r4c1 - b.r4c1;
	rv.r4c2 = a.r4c2 - b.r4c2;
	rv.r4c3 = a.r4c3 - b.r4c3;

	return rv;
}

Matrix4x4 Math::MatrixMath::subtract(const Matrix4x4& a, const Matrix4x4& b)
{
	Matrix4x4 rv;

	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r1c2 = a.r1c2 - b.r1c2;
	rv.r1c3 = a.r1c3 - b.r1c3;
	rv.r1c4 = a.r1c4 - b.r1c4;

	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r2c2 = a.r2c2 - b.r2c2;
	rv.r2c3 = a.r2c3 - b.r2c3;
	rv.r2c4 = a.r2c4 - b.r2c4;

	rv.r3c1 = a.r3c1 - b.r3c1;
	rv.r3c2 = a.r3c2 - b.r3c2;
	rv.r3c3 = a.r3c3 - b.r3c3;
	rv.r3c4 = a.r3c4 - b.r3c4;

	rv.r4c1 = a.r4c1 - b.r4c1;
	rv.r4c2 = a.r4c2 - b.r4c2;
	rv.r4c3 = a.r4c3 - b.r4c3;
	rv.r4c4 = a.r4c4 - b.r4c4;

	return rv;
}

Matrix2x1 Math::MatrixMath::multiply(float scale, const Matrix2x1 & a)
{
	Matrix2x1 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r2c1 = a.r2c1 * scale;
	return rv;
}

Matrix2x2 Math::MatrixMath::multiply(float scale, const Matrix2x2 & a)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r1c2 = a.r1c2 * scale;
	rv.r2c1 = a.r2c1 * scale;
	rv.r2c2 = a.r2c2 * scale;
	return rv;
}

Matrix3x1 Math::MatrixMath::multiply(float scale, const Matrix3x1 & a)
{
	Matrix3x1 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r2c1 = a.r2c1 * scale;
	rv.r3c1 = a.r3c1 * scale;
	return rv;
}

Matrix3x3 Math::MatrixMath::multiply(float scale, const Matrix3x3 & a)
{
	Matrix3x3 rv;

	rv.r1c1 = a.r1c1 * scale;
	rv.r1c2 = a.r1c2 * scale;
	rv.r1c3 = a.r1c3 * scale;

	rv.r2c1 = a.r2c1 * scale;
	rv.r2c2 = a.r2c2 * scale;
	rv.r2c3 = a.r2c3 * scale;

	rv.r3c1 = a.r3c1 * scale;
	rv.r3c2 = a.r3c2 * scale;
	rv.r3c3 = a.r3c3 * scale;

	return rv;
}

Matrix4x1 Math::MatrixMath::multiply(float scale, const Matrix4x1 & a)
{
	Matrix4x1 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r2c1 = a.r2c1 * scale;
	rv.r3c1 = a.r3c1 * scale;
	rv.r4c1 = a.r4c1 * scale;
	return rv;
}

Matrix4x3 Math::MatrixMath::multiply(float scale, const Matrix4x3 & a)
{
	Matrix4x3 rv;

	rv.r1c1 = a.r1c1 * scale;
	rv.r1c2 = a.r1c2 * scale;
	rv.r1c3 = a.r1c3 * scale;

	rv.r2c1 = a.r2c1 * scale;
	rv.r2c2 = a.r2c2 * scale;
	rv.r2c3 = a.r2c3 * scale;

	rv.r3c1 = a.r3c1 * scale;
	rv.r3c2 = a.r3c2 * scale;
	rv.r3c3 = a.r3c3 * scale;

	rv.r4c1 = a.r4c1 * scale;
	rv.r4c2 = a.r4c2 * scale;
	rv.r4c3 = a.r4c3 * scale;

	return rv;
}

Matrix4x4 Math::MatrixMath::multiply(float scale, const Matrix4x4 & a)
{
	Matrix4x4 rv;

	rv.r1c1 = a.r1c1 * scale;
	rv.r1c2 = a.r1c2 * scale;
	rv.r1c3 = a.r1c3 * scale;
	rv.r1c4 = a.r1c4 * scale;

	rv.r2c1 = a.r2c1 * scale;
	rv.r2c2 = a.r2c2 * scale;
	rv.r2c3 = a.r2c3 * scale;
	rv.r2c4 = a.r2c4 * scale;

	rv.r3c1 = a.r3c1 * scale;
	rv.r3c2 = a.r3c2 * scale;
	rv.r3c3 = a.r3c3 * scale;
	rv.r3c4 = a.r3c4 * scale;

	rv.r4c1 = a.r4c1 * scale;
	rv.r4c2 = a.r4c2 * scale;
	rv.r4c3 = a.r4c3 * scale;
	rv.r4c4 = a.r4c4 * scale;

	return rv;
}

Matrix2x1 Math::MatrixMath::multiply(const Matrix2x2 & a, const Matrix2x1 & b)
{
	Matrix2x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1);
	return rv;
}

Matrix2x2 Math::MatrixMath::multiply(const Matrix2x2 & a, const Matrix2x2 & b)
{
	Matrix2x2 rv;

	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1);
	rv.r1c2 = (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2);

	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1);
	rv.r2c2 = (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2);

	return rv;
}

Matrix3x1 Math::MatrixMath::multiply(const Matrix3x3 & a, const Matrix3x1 & b)
{
	Matrix3x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1);
	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1);
	return rv;
}

Matrix3x3 Math::MatrixMath::multiply(const Matrix3x3 & a, const Matrix3x3 & b)
{
	Matrix3x3 rv;

	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1);
	rv.r1c2 = (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2) + (a.r1c3 * b.r3c2);
	rv.r1c3 = (a.r1c1 * b.r1c3) + (a.r1c2 * b.r2c3) + (a.r1c3 * b.r3c3);

	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1);
	rv.r2c2 = (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2) + (a.r2c3 * b.r3c2);
	rv.r2c3 = (a.r2c1 * b.r1c3) + (a.r2c2 * b.r2c3) + (a.r2c3 * b.r3c3);

	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1);
	rv.r3c2 = (a.r3c1 * b.r1c2) + (a.r3c2 * b.r2c2) + (a.r3c3 * b.r3c2);
	rv.r3c3 = (a.r3c1 * b.r1c3) + (a.r3c2 * b.r2c3) + (a.r3c3 * b.r3c3);

	return rv;
}

Matrix4x1 Math::MatrixMath::multiply(const Matrix4x4 & a, const Matrix4x1 & b)
{
	Matrix4x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1) + (a.r1c4 * b.r4c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1) + (a.r2c4 * b.r4c1);
	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1) + (a.r3c4 * b.r4c1);
	rv.r4c1 = (a.r4c1 * b.r1c1) + (a.r4c2 * b.r2c1) + (a.r4c3 * b.r3c1) + (a.r4c4 * b.r4c1);

	return rv;
}

Matrix4x3 Math::MatrixMath::multiply(const Matrix4x4 & a, const Matrix4x3 & b)
{
	Matrix4x3 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1) + (a.r1c4 * b.r4c1);
	rv.r1c2 = (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2) + (a.r1c3 * b.r3c2) + (a.r1c4 * b.r4c2);
	rv.r1c3 = (a.r1c1 * b.r1c3) + (a.r1c2 * b.r2c3) + (a.r1c3 * b.r3c3) + (a.r1c4 * b.r4c3);

	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1) + (a.r2c4 * b.r4c1);
	rv.r2c2 = (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2) + (a.r2c3 * b.r3c2) + (a.r2c4 * b.r4c2);
	rv.r2c3 = (a.r2c1 * b.r1c3) + (a.r2c2 * b.r2c3) + (a.r2c3 * b.r3c3) + (a.r2c4 * b.r4c3);

	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1) + (a.r3c4 * b.r4c1);
	rv.r3c2 = (a.r3c1 * b.r1c2) + (a.r3c2 * b.r2c2) + (a.r3c3 * b.r3c2) + (a.r3c4 * b.r4c2);
	rv.r3c3 = (a.r3c1 * b.r1c3) + (a.r3c2 * b.r2c3) + (a.r3c3 * b.r3c3) + (a.r3c4 * b.r4c3);

	rv.r4c1 = (a.r4c1 * b.r1c1) + (a.r4c2 * b.r2c1) + (a.r4c3 * b.r3c1) + (a.r4c4 * b.r4c1);
	rv.r4c2 = (a.r4c1 * b.r1c2) + (a.r4c2 * b.r2c2) + (a.r4c3 * b.r3c2) + (a.r4c4 * b.r4c2);
	rv.r4c3 = (a.r4c1 * b.r1c3) + (a.r4c2 * b.r2c3) + (a.r4c3 * b.r3c3) + (a.r4c4 * b.r4c3);

	return rv;
}

Matrix4x4 Math::MatrixMath::multiply(const Matrix4x4 & a, const Matrix4x4 & b)
{
	Matrix4x4 rv;

	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1) + (a.r1c4 * b.r4c1);
	rv.r1c2 = (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2) + (a.r1c3 * b.r3c2) + (a.r1c4 * b.r4c2);
	rv.r1c3 = (a.r1c1 * b.r1c3) + (a.r1c2 * b.r2c3) + (a.r1c3 * b.r3c3) + (a.r1c4 * b.r4c3);
	rv.r1c4 = (a.r1c1 * b.r1c4) + (a.r1c2 * b.r2c4) + (a.r1c3 * b.r3c4) + (a.r1c4 * b.r4c4);

	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1) + (a.r2c4 * b.r4c1);
	rv.r2c2 = (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2) + (a.r2c3 * b.r3c2) + (a.r2c4 * b.r4c2);
	rv.r2c3 = (a.r2c1 * b.r1c3) + (a.r2c2 * b.r2c3) + (a.r2c3 * b.r3c3) + (a.r2c4 * b.r4c3);
	rv.r2c4 = (a.r2c1 * b.r1c4) + (a.r2c2 * b.r2c4) + (a.r2c3 * b.r3c4) + (a.r2c4 * b.r4c4);

	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1) + (a.r3c4 * b.r4c1);
	rv.r3c2 = (a.r3c1 * b.r1c2) + (a.r3c2 * b.r2c2) + (a.r3c3 * b.r3c2) + (a.r3c4 * b.r4c2);
	rv.r3c3 = (a.r3c1 * b.r1c3) + (a.r3c2 * b.r2c3) + (a.r3c3 * b.r3c3) + (a.r3c4 * b.r4c3);
	rv.r3c4 = (a.r3c1 * b.r1c4) + (a.r3c2 * b.r2c4) + (a.r3c3 * b.r3c4) + (a.r3c4 * b.r4c4);

	rv.r4c1 = (a.r4c1 * b.r1c1) + (a.r4c2 * b.r2c1) + (a.r4c3 * b.r3c1) + (a.r4c4 * b.r4c1);
	rv.r4c2 = (a.r4c1 * b.r1c2) + (a.r4c2 * b.r2c2) + (a.r4c3 * b.r3c2) + (a.r4c4 * b.r4c2);
	rv.r4c3 = (a.r4c1 * b.r1c3) + (a.r4c2 * b.r2c3) + (a.r4c3 * b.r3c3) + (a.r4c4 * b.r4c3);
	rv.r4c4 = (a.r4c1 * b.r1c4) + (a.r4c2 * b.r2c4) + (a.r4c3 * b.r3c4) + (a.r4c4 * b.r4c4);

	return rv;
}

Matrix4x1 Math::MatrixMath::multiply(const Matrix4x3 & a, const Matrix3x1 & b)
{
	Matrix4x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1);
	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1);
	rv.r4c1 = (a.r4c1 * b.r1c1) + (a.r4c2 * b.r2c1) + (a.r4c3 * b.r3c1);
	return rv;
}

Matrix4x3 Math::MatrixMath::multiply(const Matrix4x3 & a, const Matrix3x3 & b)
{
	Matrix4x3 rv;

	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1);
	rv.r1c2 = (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2) + (a.r1c3 * b.r3c2);
	rv.r1c3 = (a.r1c1 * b.r1c3) + (a.r1c2 * b.r2c3) + (a.r1c3 * b.r3c3);

	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1);
	rv.r2c2 = (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2) + (a.r2c3 * b.r3c2);
	rv.r2c3 = (a.r2c1 * b.r1c3) + (a.r2c2 * b.r2c3) + (a.r2c3 * b.r3c3);

	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1);
	rv.r3c2 = (a.r3c1 * b.r1c2) + (a.r3c2 * b.r2c2) + (a.r3c3 * b.r3c2);
	rv.r3c3 = (a.r3c1 * b.r1c3) + (a.r3c2 * b.r2c3) + (a.r3c3 * b.r3c3);

	rv.r4c1 = (a.r4c1 * b.r1c1) + (a.r4c2 * b.r2c1) + (a.r4c3 * b.r3c1);
	rv.r4c2 = (a.r4c1 * b.r1c2) + (a.r4c2 * b.r2c2) + (a.r4c3 * b.r3c2);
	rv.r4c3 = (a.r4c1 * b.r1c3) + (a.r4c2 * b.r2c3) + (a.r4c3 * b.r3c3);

	return rv;
}

float Math::MatrixMath::determinant(const Matrix2x2 & a)
{
	return (a.r1c1 * a.r2c2) - (a.r1c2 * a.r2c1);
}

float Math::MatrixMath::determinant(const Matrix3x3 & a)
{
	float aa, ab, ac, ba,bb, bc;

	aa = a.r1c1 * a.r2c2 * a.r3c3;
	ab = a.r1c2 * a.r2c3 * a.r3c1;
	ac = a.r1c3 * a.r2c1 * a.r3c2;

	ba = a.r1c3 * a.r2c2 * a.r3c1;
	bb = a.r1c2 * a.r2c1 * a.r3c3;
	bc = a.r1c1 * a.r2c3 * a.r3c2;

	return (aa + ab + ac) - (ba + bb + bc);
}

float Math::MatrixMath::determinant(const Matrix4x4 & a)
{
	// https://www.khanacademy.org/math/linear-algebra/matrix_Transformations/determinant_depth/v/linear-algebra--simpler-4x4-determinant
	float aa, ab, ac, ad,
		ba, bb, bc, bd;
	aa = a.r1c1 * a.r2c2 * a.r3c3 * a.r4c4;
	ab = a.r1c2 * a.r2c3 * a.r3c4 * a.r4c1;
	ac = a.r1c3 * a.r2c4 * a.r3c1 * a.r4c2;
	ad = a.r1c4 * a.r2c1 * a.r3c2 * a.r4c3;

	ba = a.r1c4 * a.r2c3 * a.r3c2 * a.r4c1;
	bb = a.r1c3 * a.r2c2 * a.r3c1 * a.r4c4;
	bc = a.r1c2 * a.r2c1 * a.r3c4 * a.r4c3;
	bd = a.r1c1 * a.r2c4 * a.r3c3 * a.r4c2;
	return (aa + ab + ac + ad) - (ba + bb + bc + bd);
}

Matrix2x2 Math::MatrixMath::transpose(const Matrix2x2 & a)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1;
	rv.r1c2 = a.r2c1;
	rv.r2c1 = a.r1c2;
	rv.r2c2 = a.r2c2;
	return rv;
}

Matrix3x3 Math::MatrixMath::transpose(const Matrix3x3 & a)
{
	Matrix3x3 rv;
	rv.r1c1 = a.r1c1;
	rv.r1c2 = a.r2c1;
	rv.r1c3 = a.r3c1;

	rv.r2c1 = a.r1c2;
	rv.r2c2 = a.r2c2;
	rv.r2c3 = a.r3c2;

	rv.r3c1 = a.r1c3;
	rv.r3c2 = a.r2c3;
	rv.r3c3 = a.r3c3;

	return rv;
}

Matrix4x4 Math::MatrixMath::transpose(const Matrix4x4 & a)
{
	Matrix4x4 rv;
	rv.r1c1 = a.r1c1;
	rv.r1c2 = a.r2c1;
	rv.r1c3 = a.r3c1;
	rv.r1c4 = a.r4c1;

	rv.r2c1 = a.r1c2;
	rv.r2c2 = a.r2c2;
	rv.r2c3 = a.r3c2;
	rv.r2c4 = a.r4c2;

	rv.r3c1 = a.r1c3;
	rv.r3c2 = a.r2c3;
	rv.r3c3 = a.r3c3;
	rv.r3c4 = a.r4c3;

	rv.r4c1 = a.r1c4;
	rv.r4c2 = a.r2c4;
	rv.r4c3 = a.r3c4;
	rv.r4c4 = a.r4c4;

	return rv;
}

Matrix2x2 Math::MatrixMath::inverse(const Matrix2x2 & a)
{	
	Matrix2x2 toMul;
	toMul.r1c1 = a.r2c2;
	toMul.r2c2 = a.r1c1;
	toMul.r1c2 = 0.0f - a.r1c2;
	toMul.r2c1 = 0.0f - a.r2c1;

	float mul = 1.0f / determinant(a);
	return multiply(mul, toMul);

}

Matrix3x3 Math::MatrixMath::inverse(const Matrix3x3 & a)
{
	Matrix3x3 toMul;
	toMul.r1c1 = (a.r2c2 * a.r3c3) - (a.r2c3 * a.r3c2);
	toMul.r1c2 = (a.r1c3 * a.r3c2) - (a.r1c2 * a.r3c3);
	toMul.r3c3 = (a.r1c2 * a.r2c3) - (a.r1c3 * a.r2c2);

	toMul.r2c1 = (a.r2c3 * a.r3c1) - (a.r2c1 * a.r3c3);
	toMul.r2c2 = (a.r1c1 * a.r3c3) - (a.r1c3 * a.r3c1);
	toMul.r2c3 = (a.r1c3 * a.r2c1) - (a.r1c1 * a.r2c3);

	toMul.r3c1 = (a.r2c1 * a.r3c2) - (a.r2c2 * a.r3c1);
	toMul.r3c2 = (a.r1c2 * a.r3c1) - (a.r1c1 * a.r3c2);
	toMul.r3c3 = (a.r1c1 * a.r2c2) - (a.r1c2 * a.r2c1);
	float mul = 1.0f / determinant(a);
	return multiply(mul, toMul);
}

Matrix4x4 Math::MatrixMath::inverse(const Matrix4x4 & a)
{
	float mul = 1.0f / determinant(a);
	Matrix4x4 b;

	b.r1c1 = (a.r2c2 * a.r3c3 * a.r4c4) + (a.r2c3 * a.r3c4 * a.r4c2) + (a.r2c4 * a.r3c2 * a.r4c3)
		- (a.r2c2 * a.r3c4 * a.r4c3) - (a.r2c3 * a.r3c2 * a.r4c4) - (a.r2c4 * a.r3c3 * a.r4c2);
	b.r1c2 = (a.r1c2 * a.r3c4 * a.r4c3) + (a.r1c3 * a.r3c2 * a.r4c4) + (a.r1c4 * a.r3c3 * a.r4c2)
		- (a.r1c2 * a.r3c3 * a.r4c4) - (a.r1c3 * a.r3c4 * a.r4c2) - (a.r1c4 * a.r3c2 * a.r4c3);
	b.r1c3 = (a.r1c2 * a.r2c3 * a.r4c4) + (a.r1c3 * a.r2c4 * a.r4c2) + (a.r1c4 * a.r2c2 * a.r4c3)
		- (a.r1c2 * a.r2c4 * a.r4c3) - (a.r1c3 * a.r2c2 * a.r4c4) - (a.r1c4 * a.r2c3 * a.r4c2);
	b.r1c4 = (a.r1c2 * a.r2c4 * a.r3c3) + (a.r1c3 * a.r2c2 * a.r3c4) + (a.r1c4 * a.r2c3 * a.r3c2)
		- (a.r1c2 * a.r2c3 * a.r3c4) - (a.r1c3 * a.r2c4 * a.r3c2) - (a.r1c4 * a.r2c2 * a.r3c3);

	b.r2c1 = (a.r2c1 * a.r3c4 * a.r4c3) + (a.r2c3 * a.r3c1 * a.r4c4) + (a.r2c4 * a.r3c3 * a.r4c1)
		- (a.r2c1 * a.r3c3 * a.r4c4) - (a.r2c3 * a.r3c4 * a.r4c1) - (a.r2c4 * a.r3c1 * a.r4c3);
	b.r2c2 = (a.r1c1 * a.r3c3 * a.r4c4) + (a.r1c3 * a.r3c4 * a.r4c1) + (a.r1c4 * a.r3c1 * a.r4c3)
		- (a.r1c1 * a.r3c4 * a.r4c3) - (a.r1c3 * a.r3c1 * a.r4c4) - (a.r1c4 * a.r3c3 * a.r4c1);
	b.r2c3 = (a.r1c1 * a.r2c4 * a.r4c3) + (a.r1c3 * a.r2c1 * a.r4c4) + (a.r1c4 * a.r2c3 * a.r4c1)
		- (a.r1c1 * a.r2c3 * a.r4c4) - (a.r1c3 * a.r2c4 * a.r4c1) - (a.r1c4 * a.r2c1 * a.r4c3);
	b.r2c4 = (a.r1c1 * a.r2c3 * a.r3c4) + (a.r1c3 * a.r2c4 * a.r3c1) + (a.r1c4 * a.r2c1 * a.r3c3)
		- (a.r1c1 * a.r2c4 * a.r3c3) - (a.r1c3 * a.r2c1 * a.r3c4) - (a.r1c4 * a.r2c3 * a.r3c1);

	b.r3c1 = (a.r2c1 * a.r3c2 * a.r4c4) + (a.r2c2 * a.r3c4 * a.r4c1) + (a.r2c4 * a.r3c1 * a.r4c2)
		- (a.r2c1 * a.r3c4 * a.r4c2) - (a.r2c2 * a.r3c1 * a.r4c4) - (a.r2c4 * a.r3c2 * a.r4c1);
	b.r3c2 = (a.r1c1 * a.r3c4 * a.r4c2) + (a.r1c2 * a.r3c1 * a.r4c4) + (a.r1c4 * a.r3c2 * a.r4c1)
		- (a.r1c1 * a.r3c2 * a.r4c4) - (a.r1c2 * a.r3c4 * a.r4c1) - (a.r1c4 * a.r3c1 * a.r4c2);
	b.r3c3 = (a.r1c1 * a.r2c2 * a.r4c4) + (a.r1c2 * a.r2c4 * a.r4c1) + (a.r1c4 * a.r2c1 * a.r4c2)
		- (a.r1c1 * a.r2c4 * a.r4c2) - (a.r1c2 * a.r2c1 * a.r4c4) - (a.r1c4 * a.r2c2 * a.r4c1);
	b.r3c4 = (a.r1c1 * a.r2c4 * a.r3c2) + (a.r1c2 * a.r2c1 * a.r3c4) + (a.r1c4 * a.r2c2 * a.r3c1)
		- (a.r1c1 * a.r2c2 * a.r3c4) - (a.r1c2 * a.r2c4 * a.r3c1) - (a.r1c4 * a.r2c1 * a.r3c2);

	b.r4c1 = (a.r2c1 * a.r3c3 * a.r4c2) + (a.r2c2 * a.r3c1 * a.r4c3) + (a.r2c3 * a.r3c2 * a.r4c1)
		- (a.r2c1 * a.r3c2 * a.r4c3) - (a.r2c2 * a.r3c3 * a.r4c1) - (a.r2c3 * a.r3c1 * a.r4c2);
	b.r4c2 = (a.r1c1 * a.r3c2 * a.r4c3) + (a.r1c2 * a.r3c3 * a.r4c1) + (a.r1c3 * a.r3c1 * a.r4c2)
		- (a.r1c1 * a.r3c3 * a.r4c2) - (a.r1c2 * a.r3c1 * a.r4c3) - (a.r1c3 * a.r3c2 * a.r4c1);
	b.r4c3 = (a.r1c1 * a.r2c3 * a.r4c2) + (a.r1c2 * a.r2c1 * a.r4c3) + (a.r1c3 * a.r2c2 * a.r4c1)
		- (a.r1c1 * a.r2c2 * a.r4c3) - (a.r1c2 * a.r2c3 * a.r4c1) - (a.r1c3 * a.r2c1 * a.r4c2);
	b.r4c4 = (a.r1c1 * a.r2c2 * a.r3c3) + (a.r1c2 * a.r2c3 * a.r3c1) + (a.r1c3 * a.r2c1 * a.r3c2)
		- (a.r1c1 * a.r2c3 * a.r3c2) - (a.r1c2 * a.r2c1 * a.r3c3) - (a.r1c3 * a.r2c2 * a.r3c1);

	return multiply(mul, b);
}

void Math::MatrixMath::makeIdentity(Matrix2x2 & a)
{
	a.r1c1 = 1.0f; a.r1c2 = 0.0f;
	a.r2c1 = 0.0f; a.r2c2 = 1.0f;
}

void Math::MatrixMath::makeIdentity(Matrix3x3 & a)
{
	a.r1c1 = 1.0f; a.r1c2 = 0.0f; a.r1c3 = 0.0f;
	a.r2c1 = 0.0f; a.r2c2 = 1.0f; a.r2c3 = 0.0f;
	a.r3c1 = 0.0f; a.r3c2 = 0.0f; a.r3c3 = 1.0f;
}

void Math::MatrixMath::makeIdentity(Matrix4x4 & a)
{
	a.r1c1 = 1.0f; a.r1c2 = 0.0f; a.r1c3 = 0.0f; a.r1c4 = 0.0f;
	a.r2c1 = 0.0f; a.r2c2 = 1.0f; a.r2c3 = 0.0f; a.r2c4 = 0.0f;
	a.r3c1 = 0.0f; a.r3c2 = 0.0f; a.r3c3 = 1.0f; a.r3c4 = 0.0f;
	a.r4c1 = 0.0f; a.r4c2 = 0.0f; a.r4c3 = 0.0f; a.r4c4 = 1.0f;
}

Quaternion Math::QuaternionMath::create(float angle, const Vector3D& axis)
{
	Vector3D axisUnitVecForm = Math::VectorMath::unitVector(axis);

	float cosThetaOver2, sinThetaOver2;
	cosThetaOver2 = cosf(angle / 2.0f);
	sinThetaOver2 = sinf(angle / 2.0f);

	Quaternion rv;
	rv.w = cosThetaOver2;
	rv.x = axisUnitVecForm.x * sinThetaOver2;
	rv.y = axisUnitVecForm.y * sinThetaOver2;
	rv.z = axisUnitVecForm.z * sinThetaOver2;
	return rv;
}

Quaternion Math::QuaternionMath::conjugate(const Quaternion & original)
{
	Quaternion rv;

	rv.w = original.w;
	rv.x = 0.0f - original.x;
	rv.y = 0.0f - original.y;
	rv.z = 0.0f - original.z;

	return rv;
}

Quaternion Math::QuaternionMath::normalise(Quaternion & toNormalise)
{
	Quaternion rv;
	float normVal = norm(toNormalise);
	if (normVal == 0.0f)
	{
		rv.x = 0.0f;
		rv.y = 0.0f;
		rv.z = 0.0f;
		rv.w = 1.0f;
	}
	else
	{
		float scale = 1.0f / normVal;
		rv.x = toNormalise.x * scale;
		rv.y = toNormalise.y * scale;
		rv.z = toNormalise.z * scale;
	}

	// rv.theta = toNormalise.theta * dev;
	return rv;
}

Quaternion Math::QuaternionMath::scale(const Quaternion & toScale, float scale)
{
	Quaternion rv;
	rv.x = toScale.x * scale;
	rv.y = toScale.y * scale;
	rv.z = toScale.z * scale;
	rv.w = toScale.w * scale;
	return rv;
}

Quaternion Math::QuaternionMath::multiply(const Quaternion & a, const Quaternion & b)
{
	Quaternion rv;
	rv.w = (a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z);
	rv.x = (a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y);
	rv.y = (a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x);
	rv.z = (a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w);
	return rv;
}

Quaternion Math::QuaternionMath::add(const Quaternion & a, const Quaternion & b)
{
	Quaternion rv;
	rv.w = a.w + b.w;
	rv.x = a.x + b.x;
	rv.y = a.y + b.y;
	rv.z = a.z + b.z;
	return rv;
}

Quaternion Math::QuaternionMath::subtract(const Quaternion & a, const Quaternion & b)
{
	Quaternion rv;
	rv.w = a.w - b.w;
	rv.x = a.x - b.x;
	rv.y = a.y - b.y;
	rv.z = a.z - b.z;
	return rv;
}

void Math::QuaternionMath::identityForMul(Quaternion & a)
{
	a.w = 1.0f;
	a.x = 0.0f;
	a.y = 0.0f;
	a.z = 0.0f;
}

void Math::QuaternionMath::identityForAdd(Quaternion & a)
{
	a.w = 0.0f;
	a.x = 0.0f;
	a.y = 0.0f;
	a.z = 0.0f;
}

float Math::QuaternionMath::norm(const Quaternion& a)
{
	return sqrtf(a.x * a.x
		+ a.y * a.y
		+ a.z * a.z
		+ a.w * a.w);
}

Quaternion Math::QuaternionMath::inverse(const Quaternion& a)
{
	Quaternion aConj = conjugate(a);
	float n = norm(aConj);
	return scale(aConj, 1.0f / n);
}

Matrix4x4 Math::QuaternionMath::toMatrix4x4(const Quaternion& a)
{
	Matrix4x4 rv;
	float wx, wy, wz, xx, yy, yz, xy, xz, zz;
	xx = a.x * a.x;
	xy = a.x * a.y;
	xz = a.x * a.z;
	yy = a.y * a.y;
	zz = a.z * a.z;
	yz = a.y * a.z;
	wx = a.w * a.x;
	wy = a.w * a.y;
	wz = a.w * a.z;

	rv.r1c1 = 1.0f - (2.0f * yy) - (2.0f * zz);
	rv.r1c2 = 2.0f * xy - 2.0f * wz;
	rv.r1c3 = 2.0f * xz + 2.0f * wy;
	
	rv.r2c1 = 2.0f * xy + 2.0f * wz;
	rv.r2c2 = 1.0f - (2.0f * xx) - (2.0f * zz);
	rv.r2c3 = 2.0f * yz - 2.0f * wx;

	rv.r3c1 = 2.0f * xz - 2.0f * wy;
	rv.r3c2 = 2.0f * yz + 2.0f *wx;
	rv.r3c3 = 1.0f - (2.0f * xx) - (2.0f * yy);

	rv.r4c1 = 0.0f;
	rv.r4c2 = 0.0f;
	rv.r4c3 = 0.0;
	rv.r1c4 = 0.0f;
	rv.r2c4 = 0.0f;
	rv.r3c4 = 0.0f;
	rv.r4c4 = 1.0f;

	return rv;
}

Matrix3x3 Math::QuaternionMath::toMatrix3x3(const Quaternion& a)
{
	Matrix3x3 rv;

	float wx, wy, wz, xx, yy, yz, xy, xz, zz;
	xx = a.x * a.x;
	xy = a.x * a.y;
	xz = a.x * a.z;
	yy = a.y * a.y;
	zz = a.z * a.z;
	yz = a.y * a.z;
	wx = a.w * a.x;
	wy = a.w * a.y;
	wz = a.w * a.z;

	rv.r1c1 = 1.0f - (2.0f * yy) - (2.0f * zz);
	rv.r1c2 = 2.0f * xy - 2.0f * wz;
	rv.r1c3 = 2.0f * xz + 2.0f * wy;

	rv.r2c1 = 2.0f * xy + 2.0f * wz;
	rv.r2c2 = 1.0f - (2.0f * xx) - (2.0f * zz);
	rv.r2c3 = 2.0f * yz - 2.0f * wx;

	rv.r3c1 = 2.0f * xz - 2.0f * wy;
	rv.r3c2 = 2.0f * yz + 2.0f *wx;
	rv.r3c3 = 1.0f - (2.0f * xx) - (2.0f * yy);
	return rv;
}

Plane Math::Planes::createPlane(const Vector3D& axisAsUnit, float dictanceFromOrigin)
{
	assert(Math::VectorMath::magnitude(axisAsUnit) == 1.0f);
	Plane Results;
	Results.normal = axisAsUnit;
	Results.distanceFromOrigin = dictanceFromOrigin;
	return Results;
}

float Math::Planes::dotProductAsVector(const Plane& plane, const Vector3D& vector)
{
	return (plane.normal.x * vector.x)
		+ (plane.normal.y * vector.y)
		+ (plane.normal.z * vector.z)
		+ (plane.distanceFromOrigin * 0.0f);
}

float Math::Planes::dotProductAsPosition(const Plane& plane, const Vector3D& vector)
{
	return (plane.normal.x * vector.x)
		+ (plane.normal.y * vector.y)
		+ (plane.normal.z * vector.z)
		+ (plane.distanceFromOrigin * 1.0f);
}

float Math::Planes::distanceFromPlane(const Plane& plane, const Vector3D& point)
{
	return dotProductAsPosition(plane, point);
}

Vector3D Math::Planes::reflectVector(const Vector3D& vectorToReflect, const Plane& reflectIn)
{
	const Vector3D PlaneNormalScaled = Math::VectorMath::scaled(2 * Math::Planes::dotProductAsVector(reflectIn, vectorToReflect), reflectIn.normal);
	return Math::VectorMath::subtract(vectorToReflect, PlaneNormalScaled);
}

Vector3D Math::Planes::reflectPosition(const Vector3D& positionToReflect, const Plane& reflectIn)
{
	using namespace Math::VectorMath;
	const float ScaleNormalBy = 2 * (dotProduct(positionToReflect, reflectIn.normal) - reflectIn.distanceFromOrigin);
	return subtract(positionToReflect, scaled(ScaleNormalBy, reflectIn.normal));
}

void Math::Transform::scale2D(Matrix2x1& toScale, float xScale, float yScale)
{
	Matrix2x2 mul;
	Math::MatrixMath::makeIdentity(mul);
	mul.r1c1 = xScale;
	mul.r2c2 = yScale;
	toScale = Math::MatrixMath::multiply(mul, toScale);
}

void Math::Transform::scale3D(Matrix3x1& toScale, float xScale, float yScale, float zScale)
{
	Matrix3x3 mul;
	Math::MatrixMath::makeIdentity(mul);
	mul.r1c1 = xScale;
	mul.r2c2 = yScale;
	mul.r3c3 = zScale;
	toScale = Math::MatrixMath::multiply(mul, toScale);
}

void Math::Transform::scale4D(Matrix4x1& toScale, float xScale, float yScale, float zScale, float wScale)
{
	Matrix4x4 mul;
	Math::MatrixMath::makeIdentity(mul);
	// W = r4c4
	mul.r1c1 = xScale;
	mul.r2c2 = yScale;
	mul.r3c3 = zScale;
	mul.r4c4 = wScale;
	toScale = Math::MatrixMath::multiply(mul, toScale);
}

void Math::Transform::rotate2DClkWise(Matrix2x1& toRot, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negitiveSinTheta = 0.0f - sinTheta;
	Matrix2x2 rot;
	rot.r1c1 = cosTheta;
	rot.r1c2 = sinTheta;
	rot.r2c1 = negitiveSinTheta;
	rot.r2c2 = cosTheta;
	toRot = Math::MatrixMath::multiply(rot, toRot);
}

void Math::Transform::rotate2DAntiClkWise(Matrix2x1& toRot, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negitiveSinTheta = 0.0f - sinTheta;
	Matrix2x2 rot;
	rot.r1c1 = cosTheta;
	rot.r1c2 = negitiveSinTheta;
	rot.r2c1 = sinTheta;
	rot.r2c2 = cosTheta;
	toRot = Math::MatrixMath::multiply(rot, toRot);
}

// 3d rotation matrix versions
void Math::Transform::rotate3DX(Matrix3x1& toRotate, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rot;
	Math::MatrixMath::makeIdentity(rot);
	rot.r2c2 = cosTheta;
	rot.r2c3 = negSinTheta;
	rot.r3c2 = sinTheta;
	rot.r3c3 = cosTheta;
	toRotate = Math::MatrixMath::multiply(rot, toRotate);
}

void Math::Transform::rotate3DY(Matrix3x1& toRotate, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rot;
	Math::MatrixMath::makeIdentity(rot);
	rot.r1c1 = cosTheta;
	rot.r1c3 = sinTheta;
	rot.r3c1 = negSinTheta;
	rot.r3c3 = cosTheta;
	toRotate = Math::MatrixMath::multiply(rot, toRotate);
}

void Math::Transform::rotate3DZ(Matrix3x1& toRotate, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rot;
	Math::MatrixMath::makeIdentity(rot);
	rot.r1c1 = cosTheta;
	rot.r1c2 = negSinTheta;
	rot.r2c1 = sinTheta;
	rot.r2c2 = cosTheta;
	toRotate = Math::MatrixMath::multiply(rot, toRotate);
}

void Math::Transform::rotateCustomAxis(const Vector3D& axisUnitVector, float thetaRads, Matrix3x1 & toRotate)
{
	// TODO: add assert for axisUnitVector being an unit vector.

	float cosTheta, sinTheta;
	Matrix3x3 rot;
	cosTheta = cosf(thetaRads);
	sinTheta = sinf(thetaRads);
	rot.r1c1 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.x);
	rot.r1c2 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.y) - (sinTheta * axisUnitVector.z);
	rot.r1c3 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.z) + (sinTheta * axisUnitVector.y);

	rot.r2c1 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.y) + (sinTheta * axisUnitVector.z);
	rot.r2c2 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.y);
	rot.r2c3 = (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.z) - (sinTheta * axisUnitVector.z);

	rot.r3c1 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.z) - (sinTheta * axisUnitVector.y);
	rot.r3c2 = (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.z) + (sinTheta * axisUnitVector.x);
	rot.r3c3 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.z * axisUnitVector.z);

	toRotate = Math::MatrixMath::multiply(rot, toRotate);
}

Matrix2x2 Math::Transform::get2dRotationMatrixClkWise(float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negitiveSinTheta = 0.0f - sinTheta;
	Matrix2x2 rv;
	rv.r1c1 = cosTheta;
	rv.r1c2 = sinTheta;
	rv.r2c1 = negitiveSinTheta;
	rv.r2c2 = cosTheta;
	return rv;
}

Matrix2x2 Math::Transform::get2dRotationMatrixAntiClkWise(float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negitiveSinTheta = 0.0f - sinTheta;
	Matrix2x2 rv;
	rv.r1c1 = cosTheta;
	rv.r1c2 = negitiveSinTheta;
	rv.r2c1 = sinTheta;
	rv.r2c2 = cosTheta;
	return rv;
}

Matrix3x3 Math::Transform::get3x3Rotate3DXMatrix(float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r2c2 = cosTheta;
	rv.r2c3 = negSinTheta;
	rv.r3c2 = sinTheta;
	rv.r3c3 = cosTheta;
	return rv;
}

Matrix3x3 Math::Transform::get3x3Rotate3DYMatrix(float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r1c1 = cosTheta;
	rv.r1c3 = sinTheta;
	rv.r3c1 = negSinTheta;
	rv.r3c3 = cosTheta;
	return rv;
}

Matrix3x3 Math::Transform::get3x3Rotate3DZMatrix(float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r1c1 = cosTheta;
	rv.r1c2 = negSinTheta;
	rv.r2c1 = sinTheta;
	rv.r2c2 = cosTheta;
	return rv;
}

Matrix3x3 Math::Transform::getRotationMatrixForCustomAxis(const Vector3D& axisUnitVector, float thetaRads)
{
	// TODO: Add assert that axisUnitVector is a unit vector.

	float cosTheta, sinTheta;
	Matrix3x3 rot;
	cosTheta = cosf(thetaRads);
	sinTheta = sinf(thetaRads);

	rot.r1c1 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.x);
	rot.r1c2 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.y) - (sinTheta * axisUnitVector.z);
	rot.r1c3 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.z) + (sinTheta * axisUnitVector.y);

	rot.r2c1 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.y) + (sinTheta * axisUnitVector.z);
	rot.r2c2 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.y);
	rot.r2c3 = (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.z) - (sinTheta * axisUnitVector.z);

	rot.r3c1 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.z) - (sinTheta * axisUnitVector.y);
	rot.r3c2 = (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.z) + (sinTheta * axisUnitVector.x);
	rot.r3c3 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.z * axisUnitVector.z);

	return rot;
}

Matrix4x4 Math::Transform::get4x4RotationMatrixForCustomAxis(const Vector3D& axisUnitVector, float thetaRads)
{
	// TODO: Add assert that axisUnitVector is a unit vector.

	Matrix4x4 rv;
	float cosTheta, sinTheta;
	cosTheta = cosf(thetaRads);
	sinTheta = sinf(thetaRads);

	rv.r1c1 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.x);
	rv.r1c2 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.y) - (sinTheta * axisUnitVector.z);
	rv.r1c3 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.z) + (sinTheta * axisUnitVector.y);
	rv.r1c4 = 0.0f;

	rv.r2c1 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.y) + (sinTheta * axisUnitVector.z);
	rv.r2c2 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.y);
	rv.r2c3 = (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.z) - (sinTheta * axisUnitVector.z);
	rv.r2c4 = 0.0f;

	rv.r3c1 = (1.0f - cosTheta) * (axisUnitVector.x * axisUnitVector.z) - (sinTheta * axisUnitVector.y);
	rv.r3c2 = (1.0f - cosTheta) * (axisUnitVector.y * axisUnitVector.z) + (sinTheta * axisUnitVector.x);
	rv.r3c3 = cosTheta + (1.0f - cosTheta) * (axisUnitVector.z * axisUnitVector.z);
	rv.r3c4 = 0.0f;

	rv.r4c1 = 0.0f;
	rv.r4c2 = 0.0f;
	rv.r4c3 = 0.0f;
	rv.r4c4 = 1.0f;
	return rv;
}

Matrix2x2 Math::Transform::get2x2ScalingMatrix(float x, float y)
{
	Matrix2x2 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r1c1 = x;
	rv.r2c2 = y;
	return rv;
}

Matrix3x3 Math::Transform::get3x3ScalingMatrix(float x, float y, float z)
{
	Matrix3x3 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r1c1 = x;
	rv.r2c2 = y;
	rv.r3c3 = z;
	return rv;
}

Matrix4x4 Math::Transform::get4x4ScalingMatrix(float x, float y, float z, float w)
{
	Matrix4x4 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r1c1 = x;
	rv.r2c2 = y;
	rv.r3c3 = z;
	rv.r4c4 = w;
	return rv;
}

Matrix4x4 Math::Transform::get4x4TranslationMatrix(const Vector3D& translation)
{
	Matrix4x4 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r1c4 = translation.x;
	rv.r2c4 = translation.y;
	rv.r3c4 = translation.z;
	return rv;
}

void Math::Transform::translate2D(Matrix2x1& toTranslate, const Vector2D& translateBy)
{
	toTranslate.r1c1 += translateBy.x;
	toTranslate.r2c1 += translateBy.y;
}

void Math::Transform::translate3D(Matrix3x1& toTranslate, const Vector3D& translateBy)
{
	toTranslate.r1c1 += translateBy.x;
	toTranslate.r2c1 += translateBy.y;
	toTranslate.r3c1 += translateBy.z;
}

Matrix4x4 Math::Transform::RightHandViewMatrix(const Vector3D& eye, const Vector3D& up, const Vector3D& at)
{
	// http://www.gamedev.net/page/resources/_/technical/graphics-programming-and-theory/perspective-projections-in-lh-and-rh-systems-r3598

	// first calc 3 Vector3: look, right, up

	Vector3D look = VectorMath::subtract(eye, at);
	Vector3D right = VectorMath::crossProduct(up, look);
	Vector3D camUp = VectorMath::crossProduct(look, right);

	float a, b, c;
	a = VectorMath::dotProduct(right, eye);
	b = VectorMath::dotProduct(camUp, eye);
	c = VectorMath::dotProduct(look, eye);

	Matrix4x4 rv;
	MatrixMath::makeIdentity(rv);
	rv.r1c1 = right.x;
	rv.r2c1 = right.y;
	rv.r3c1 = right.z;
	rv.r4c1 = a;

	rv.r1c2 = camUp.x;
	rv.r2c2 = camUp.y;
	rv.r3c2 = camUp.z;
	rv.r4c2 = b;

	rv.r1c3 = look.x;
	rv.r2c3 = look.y;
	rv.r3c3 = look.z;
	rv.r4c3 = c;

	return rv;
}

Matrix4x4 Math::Transform::LeftHandViewMatrix(const Vector3D& eye, const Vector3D& up, const Vector3D& at)
{
	// http://www.gamedev.net/page/resources/_/technical/graphics-programming-and-theory/perspective-projections-in-lh-and-rh-systems-r3598

	Vector3D look = VectorMath::subtract(at, eye);
	Vector3D right = VectorMath::crossProduct(up, look);
	Vector3D camUp = VectorMath::crossProduct(look, right);

	float a, b, c;
	a = -VectorMath::dotProduct(right, eye);
	b = -VectorMath::dotProduct(camUp, eye);
	c = -VectorMath::dotProduct(look, eye);

	Matrix4x4 rv;
	MatrixMath::makeIdentity(rv);
	rv.r1c1 = right.x;
	rv.r2c1 = right.y;
	rv.r3c1 = right.z;
	rv.r4c1 = a;

	rv.r1c2 = camUp.x;
	rv.r2c2 = camUp.y;
	rv.r3c2 = camUp.z;
	rv.r4c2 = b;

	rv.r1c3 = look.x;
	rv.r2c3 = look.y;
	rv.r3c3 = look.z;
	rv.r4c3 = c;

	return rv;
}


Matrix4x4 Math::Transform::OrthographicProjectionMatrix(float width, float height, float nearZ, float farZ)
{
	// http://www.codinglabs.net/article_world_view_projection_matrix.aspx
	Matrix4x4 rv;
	Math::MatrixMath::makeIdentity(rv);
	rv.r1c1 = 1.0f / width;
	rv.r2c2 = 1.0f / height;
	rv.r3c3 = -(2.0f / (farZ - nearZ));
	rv.r3c4 = -((farZ + nearZ) / (farZ - nearZ));
	return rv;
}

Matrix4x4 Math::Transform::PerspectiveProjectionMatrix(float fovInYDirection, float aspectRatio, float nearDepth, float farDepth)
{
	// see: https://www.opengl.org/sdk/docs/man2/xhtml/gluPerspective.xml
	// and http://www.sparknotes.com/testprep/books/sat2/math2c/chapter9section2.rhtml
	// or: http://www.codinglabs.net/article_world_view_projection_matrix.aspx

	Matrix4x4 rv;
	Math::MatrixMath::makeIdentity(rv);
	// based on 3DCG wk2 L2 slide 30

	float& a = fovInYDirection;
	float& f = farDepth;
	float& n = nearDepth;
	float& r = aspectRatio;
	
	rv.r1c1 = 1.0f / (r * tanf(a / 2.0f));
	rv.r2c2 = 1.0f / tanf(a / 2.0f);
	rv.r3c3 = (f) / (f - n);
	rv.r3c4 = 1.0f;
	rv.r4c3 = (-(n * f)) / (f - n);
	rv.r4c4 = 0.0f;
	return rv;
}

float Math::Interpolation::lerp(float valueA, float valueB, float targetPoint) // target point should be between 0.0f & 1.0f
{
	return (1.0f - targetPoint) * valueA + targetPoint * valueB;
}

Vector2D Math::Interpolation::lerp(const Vector2D& vectorA, const Vector2D& vectorB, float targetPoint)
{
	if (targetPoint <= 0.0f)
	{
		return vectorA;
	}
	else if(targetPoint >= 1.0f)
	{
		return vectorB;
	}
	Vector2D rv;
	rv.x = lerp(vectorA.x, vectorB.x, targetPoint);
	rv.y = lerp(vectorA.y, vectorB.y, targetPoint);
	return rv;
}

Vector3D Math::Interpolation::lerp(const Vector3D& vectorA, const Vector3D& vectorB, float targetPoint)
{
	if (targetPoint <= 0.0f)
	{
		return vectorA;
	}
	else if (targetPoint >= 1.0f)
	{
		return vectorB;
	}
	Vector3D rv;
	rv.x = lerp(vectorA.x, vectorB.x, targetPoint);
	rv.y = lerp(vectorA.y, vectorB.y, targetPoint);
	rv.z = lerp(vectorA.z, vectorB.z, targetPoint);
	return rv;
}

Quaternion Math::Interpolation::lerp(const Quaternion& qa, const Quaternion& qb, float targetPoint)
{
	if(targetPoint <= 0.0f)
	{
		return qa;
	}
	else if(targetPoint >= 1.0f)
	{
		return qb;
	}

	Quaternion rv;
	rv.w = lerp(qa.w, qb.w, targetPoint);
	rv.x = lerp(qa.x, qb.x, targetPoint);
	rv.y = lerp(qa.y, qb.y, targetPoint);
	rv.z = lerp(qa.z, qb.z, targetPoint);

	//rv = QuaternionMath::normalise(rv);

	return rv;
}

// slep
Quaternion Math::Interpolation::slerp(const Quaternion& a, const Quaternion& b, float t)
{
	if (t <= 0.0f)
	{
		return a;
	}
	else if(t >= 1.0f)
	{
		return b;
	}


	float dotProduct;
	dotProduct = a.x * b.x
		+ a.y * b.y
		+ a.z * b.z
		+ a.w * b.w;
	float omega = acosf(dotProduct);
	float sinO;
	float sinTO;
	float sinOneSubTByO;

	sinO = sinf(omega);
	sinTO = sinf(t * omega);
	sinOneSubTByO = sinf((1.0f - t) * omega);

	float aScale, bScale;
	aScale = sinOneSubTByO / sinO;
	bScale = sinTO / sinO;

	Quaternion rvA = QuaternionMath::scale(a, aScale);
	Quaternion rvB = QuaternionMath::scale(b, bScale);
	Quaternion rv = QuaternionMath::add(rvA, rvB);
	rv = QuaternionMath::normalise(rv);
	return rv;
}

float Math::Interpolation::biLerp(float a0, float a1, float b0, float b1, float tx, float ty)
{
	float ax = lerp(a0, a1, tx);
	float bx = lerp(b0, b1, tx);

	return lerp(ax, bx, ty);
}

float Math::Interpolation::triLerp(float _000, float _100,
	float _010, float _110,

	float _001, float _101,
	float _011, float _111,

	float tx, float ty, float tz)
{
	float frontAx = lerp(_000, _100, tx);
	float frontBx = lerp(_010, _110, tx);

	float backAx = lerp(_001, _101, tx);
	float backBx = lerp(_011, _111, tx);

	float frontPoint = lerp(frontAx, frontBx, ty);
	float backPoint = lerp(backAx, backBx, ty);

	return lerp(frontPoint, backPoint, tz);
}

float Math::Interpolation::interpolationWeight(float min, float max, float x)
{
	float diffMinMax = max - min;
	float diffMinX = x - min;
	if (diffMinMax == 0.0f)
	{
		return 1.0f;
	}
	return diffMinX / diffMinMax;
}

float Math::Interpolation::smoothStep(float min, float max, float x)
{
	return 0.0f; // CODE ME!
}

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
	Vector2D aToB = Math::VectorMath::wayToVector(a.position, b.position);
	float distSqurd = Math::VectorMath::magnitudeSquared(aToB);
	float combinedRadiusSqurd = a.radius * a.radius + b.radius * b.radius;
	return combinedRadiusSqurd > distSqurd; // if combined radius is larger than the distance, then there must be an over lap (collision)
}

bool Math::VolumeIntersection::volumesOverlap(const BoundingSphere& a, const BoundingSphere& b)
{
	// same logic as 2D, just using 3D vectors instead
	Vector3D aToB = Math::VectorMath::wayToVector(a.position, b.position);
	float distSqurd = Math::VectorMath::magnitudeSquared(aToB);
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
	Vector2D aToVol = Math::VectorMath::wayToVector(a, vol.position);
	float magSqurd = Math::VectorMath::magnitudeSquared(aToVol),
		radiusSqurd = vol.radius * vol.radius;
	return radiusSqurd > magSqurd;
}

bool Math::VolumeIntersection::pointInBoundingVolume(const Vector3D& a, const BoundingSphere& vol)
{
	Vector3D aToVol = Math::VectorMath::wayToVector(a, vol.position);
	float magSqurd = Math::VectorMath::magnitudeSquared(aToVol),
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

bool Math::VolumeIntersection::volumeInRayPath(const Ray2D& r, const BoundingBox& vol)
{
	Vector2D volumeMidPoint;
	volumeMidPoint.x = Math::Interpolation::lerp(vol.left, vol.right, 0.5f);
	volumeMidPoint.y = Math::Interpolation::lerp(vol.top, vol.bottom, 0.5f);
	Vector2D distFromRayOriginToVolMidPoint = Math::VectorMath::wayToVector(r.pointOfOrigin, volumeMidPoint);
	
	float scaleRayBy = Math::VectorMath::magnitude(distFromRayOriginToVolMidPoint); // this will be the slowest point in the code (squr root calc computationally expencive)
	
	Vector2D rayDirScaledToVolMidPointDist = Math::VectorMath::scaled(scaleRayBy, r.direction);
	Vector2D testPoint = Math::VectorMath::add(r.pointOfOrigin, rayDirScaledToVolMidPointDist);
	return pointInBoundingVolume(testPoint, vol);
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray2D& r, const BoundingCircle& vol)
{
	using namespace Math::VectorMath;

	Vector2D fromRayPOToBCPos = wayToVector(r.pointOfOrigin, vol.position);

	float scaleDirBy = magnitude(fromRayPOToBCPos);
	Vector2D dirScaled = scaled(scaleDirBy, r.direction);
	Vector2D testPoint = add(r.pointOfOrigin, dirScaled);
	return pointInBoundingVolume(testPoint, vol);
}

bool Math::VolumeIntersection::volumeInRayPath(const Ray3D& r, const BoundingSphere& vol)
{
	using namespace Math::VectorMath;

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


	Vector3D distFromRayOriginToVolMidPoint = Math::VectorMath::wayToVector(r.pointOfOrigin, volumeMidPoint);

	float scaleRayBy = Math::VectorMath::magnitude(distFromRayOriginToVolMidPoint); // this will be the slowest point in the code (squr root calc computationally expencive)

	Vector3D rayDirScaledToVolMidPointDist = Math::VectorMath::scaled(scaleRayBy, r.direction);
	Vector3D testPoint = Math::VectorMath::add(r.pointOfOrigin, rayDirScaledToVolMidPointDist);
	return pointInBoundingVolume(testPoint, vol);
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray2D& r, const BoundingBox& vol)
{
	using namespace Math::Interpolation;
	using namespace Math::Miscellaneous;
	using namespace Math::VectorMath;
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
	using namespace Math::VectorMath;


	Vector2D toRayOri = wayToVector(vol.position, r.pointOfOrigin);
	toRayOri = unitVector(toRayOri);
	toRayOri = scaled(vol.radius, toRayOri);
	Vector2D toAproximateIntersectionPoint = wayToVector(r.pointOfOrigin, toRayOri);
	return magnitude(toAproximateIntersectionPoint);
}

float Math::VolumeIntersection::rayDistanceToCollisionFast(const Ray3D& r, const BoundingSphere& vol)
{
	using namespace Math::VectorMath;


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
	using namespace Math::VectorMath;
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

float Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(const Ray2D& r, const BoundingBox& vol, float stepSize)
{
	using namespace Math::VectorMath;
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
	using namespace Math::VectorMath;
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
	using namespace Math::VectorMath;
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
	using namespace Math::VectorMath;
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

float Math::VolumeIntersection::rayDistanceToCollisionTrace(const Ray2D& r, const BoundingBox& vol, float stepSize, float maxDist)
{
	using namespace Math::VectorMath;
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
	using namespace Math::VectorMath;
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
	using namespace Math::VectorMath;
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
	using namespace Math::VectorMath;
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

Vector2D Math::Physics::netForce(const Vector2D* forces, const unsigned int nForces)
{
	Vector2D results;
	results.x = results.y = 0.0f;
	for (unsigned int i = 0; i < nForces; ++i)
	{
		results.x += forces[i].x;
		results.y += forces[i].y;
	}
	return results;
}

Vector3D Math::Physics::netForce(const Vector3D* forces, const unsigned int nForces)
{
	Vector3D results;
	results.x = results.y = results.z = 0.0f;
	for (unsigned int i = 0; i < nForces; ++i)
	{
		results.x += forces[i].x;
		results.y += forces[i].y;
		results.z += forces[i].z;
	}
	return results;
}

Vector2D Math::Physics::acceleration(const Vector2D& netForce, float mass)
{
	Vector2D results;
	results.x = netForce.x / mass;
	results.y = netForce.y / mass;
	return results;
}

Vector3D Math::Physics::acceleration(const Vector3D& netForce, float mass)
{
	Vector3D results;
	results.x = netForce.x / mass;
	results.y = netForce.y / mass;
	results.z = netForce.z / mass;
	return results;
}

Vector2D Math::Physics::velocity(const Vector2D& previousVelocity, const Vector2D& acceleration, float time)
{
	Vector2D currentVelocity;
	currentVelocity.x = previousVelocity.x + (acceleration.x * time);
	currentVelocity.y = previousVelocity.y + (acceleration.y * time);
	return currentVelocity;
}

Vector3D Math::Physics::velocity(const Vector3D& previousVelocity, const Vector3D& acceleration, float time)
{
	Vector3D currentVelocity;
	currentVelocity.x = previousVelocity.x + (acceleration.x * time);
	currentVelocity.y = previousVelocity.y + (acceleration.y * time);
	currentVelocity.z = previousVelocity.z + (acceleration.z * time);
	return currentVelocity;
}

Vector2D Math::Physics::momentum(const Vector2D& velocity, float mass)
{
	Vector2D momentum;
	momentum.x = mass * velocity.x;
	momentum.y = mass * velocity.y;
	return momentum;
}

Vector3D Math::Physics::momentum(const Vector3D& velocity, float mass)
{
	Vector3D momentum;
	momentum.x = mass * velocity.x;
	momentum.y = mass * velocity.y;
	momentum.z = mass * velocity.z;
	return momentum;
}

float Math::Physics::speed(const Vector2D& velocity)
{
	return Math::VectorMath::magnitude(velocity);
}

float Math::Physics::speed(const Vector3D& velocity)
{
	return Math::VectorMath::magnitude(velocity);
}

float Math::Miscellaneous::parabola(const Vector2D& questionCoord, const Vector2D& parabolaCentrePoint, float parabolaRadius)
{
	Vector2D toCentrePoint = VectorMath::wayToVector(questionCoord, parabolaCentrePoint);
	float magSqurd = VectorMath::magnitudeSquared(toCentrePoint);

	return parabolaRadius * parabolaRadius - magSqurd;
}

float Math::Miscellaneous::diff(float x, float y)
{
	if (x > y)
	{
		return x - y;
	}
	return y - x;
}