#include "TransformationMath.h"
#include "VectorMath.h"
#include "MatrixMath.h"

#include <cmath>

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

void Math::Transform::scale2D(Matrix2x1& toScale, float xScale, float yScale)
{
	Matrix2x2 mul;
	Math::Matrix::makeIdentity(mul);
	mul.r1c1 = xScale;
	mul.r2c2 = yScale;
	toScale = Math::Matrix::multiply(mul, toScale);
}

void Math::Transform::scale3D(Matrix3x1& toScale, float xScale, float yScale, float zScale)
{
	Matrix3x3 mul;
	Math::Matrix::makeIdentity(mul);
	mul.r1c1 = xScale;
	mul.r2c2 = yScale;
	mul.r3c3 = zScale;
	toScale = Math::Matrix::multiply(mul, toScale);
}

void Math::Transform::scale4D(Matrix4x1& toScale, float xScale, float yScale, float zScale, float wScale)
{
	Matrix4x4 mul;
	Math::Matrix::makeIdentity(mul);
	// W = r4c4
	mul.r1c1 = xScale;
	mul.r2c2 = yScale;
	mul.r3c3 = zScale;
	mul.r4c4 = wScale;
	toScale = Math::Matrix::multiply(mul, toScale);
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
	toRot = Math::Matrix::multiply(rot, toRot);
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
	toRot = Math::Matrix::multiply(rot, toRot);
}

// 3d rotation matrix versions
void Math::Transform::rotate3DX(Matrix3x1& toRotate, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rot;
	Math::Matrix::makeIdentity(rot);
	rot.r2c2 = cosTheta;
	rot.r2c3 = negSinTheta;
	rot.r3c2 = sinTheta;
	rot.r3c3 = cosTheta;
	toRotate = Math::Matrix::multiply(rot, toRotate);
}

void Math::Transform::rotate3DY(Matrix3x1& toRotate, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rot;
	Math::Matrix::makeIdentity(rot);
	rot.r1c1 = cosTheta;
	rot.r1c3 = sinTheta;
	rot.r3c1 = negSinTheta;
	rot.r3c3 = cosTheta;
	toRotate = Math::Matrix::multiply(rot, toRotate);
}

void Math::Transform::rotate3DZ(Matrix3x1& toRotate, float thetaRads)
{
	float cosTheta = cosf(thetaRads);
	float sinTheta = sinf(thetaRads);
	float negSinTheta = 0.0f - sinTheta;
	Matrix3x3 rot;
	Math::Matrix::makeIdentity(rot);
	rot.r1c1 = cosTheta;
	rot.r1c2 = negSinTheta;
	rot.r2c1 = sinTheta;
	rot.r2c2 = cosTheta;
	toRotate = Math::Matrix::multiply(rot, toRotate);
}

void Math::Transform::rotateCustomAxis(const Vector3D& axisUnitVector, float thetaRads, Matrix3x1& toRotate)
{
	assert(Vector::magnitude(axisUnitVector) > 0.9999f && Vector::magnitude(axisUnitVector) < 1.1111f); // note not compiled in release.

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

	toRotate = Math::Matrix::multiply(rot, toRotate);
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
	Math::Matrix::makeIdentity(rv);
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
	Math::Matrix::makeIdentity(rv);
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
	Math::Matrix::makeIdentity(rv);
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
	Math::Matrix::makeIdentity(rv);
	rv.r1c1 = x;
	rv.r2c2 = y;
	return rv;
}

Matrix3x3 Math::Transform::get3x3ScalingMatrix(float x, float y, float z)
{
	Matrix3x3 rv;
	Math::Matrix::makeIdentity(rv);
	rv.r1c1 = x;
	rv.r2c2 = y;
	rv.r3c3 = z;
	return rv;
}

Matrix4x4 Math::Transform::get4x4ScalingMatrix(float x, float y, float z, float w)
{
	Matrix4x4 rv;
	Math::Matrix::makeIdentity(rv);
	rv.r1c1 = x;
	rv.r2c2 = y;
	rv.r3c3 = z;
	rv.r4c4 = w;
	return rv;
}

Matrix4x4 Math::Transform::get4x4TranslationMatrix(const Vector3D& translation)
{
	Matrix4x4 rv;
	Math::Matrix::makeIdentity(rv);
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

	Vector3D look = Vector::subtract(eye, at);
	Vector3D right = Vector::crossProduct(up, look);
	Vector3D camUp = Vector::crossProduct(look, right);

	float a, b, c;
	a = Vector::dotProduct(right, eye);
	b = Vector::dotProduct(camUp, eye);
	c = Vector::dotProduct(look, eye);

	Matrix4x4 rv;
	Matrix::makeIdentity(rv);
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

	Vector3D look = Vector::subtract(at, eye);
	Vector3D right = Vector::crossProduct(up, look);
	Vector3D camUp = Vector::crossProduct(look, right);

	float a, b, c;
	a = -Vector::dotProduct(right, eye);
	b = -Vector::dotProduct(camUp, eye);
	c = -Vector::dotProduct(look, eye);

	Matrix4x4 rv;
	Matrix::makeIdentity(rv);
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
	Math::Matrix::makeIdentity(rv);
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
	Math::Matrix::makeIdentity(rv);
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
