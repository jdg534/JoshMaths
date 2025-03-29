#include "QuaternionMath.h"
#include "VectorMath.h"

#include <cmath>

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

Quaternion Math::Quaternion::create(float angle, const Vector3D& axis)
{
	Vector3D axisUnitVecForm = Math::Vector::unitVector(axis);

	float cosThetaOver2, sinThetaOver2;
	cosThetaOver2 = cosf(angle / 2.0f);
	sinThetaOver2 = sinf(angle / 2.0f);

	Types::Quaternion rv;
	rv.w = cosThetaOver2;
	rv.x = axisUnitVecForm.x * sinThetaOver2;
	rv.y = axisUnitVecForm.y * sinThetaOver2;
	rv.z = axisUnitVecForm.z * sinThetaOver2;
	return rv;
}

Quaternion Math::Quaternion::conjugate(const Types::Quaternion& original)
{
	Types::Quaternion rv;

	rv.w = original.w;
	rv.x = 0.0f - original.x;
	rv.y = 0.0f - original.y;
	rv.z = 0.0f - original.z;

	return rv;
}

Quaternion Math::Quaternion::normalise(Types::Quaternion& toNormalise)
{
	Types::Quaternion rv;
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

Quaternion Math::Quaternion::scale(const Types::Quaternion& toScale, float scale)
{
	Types::Quaternion rv;
	rv.x = toScale.x * scale;
	rv.y = toScale.y * scale;
	rv.z = toScale.z * scale;
	rv.w = toScale.w * scale;
	return rv;
}

Quaternion Math::Quaternion::multiply(const Types::Quaternion& a, const Types::Quaternion& b)
{
	Types::Quaternion rv;
	rv.w = (a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z);
	rv.x = (a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y);
	rv.y = (a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x);
	rv.z = (a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w);
	return rv;
}

Quaternion Math::Quaternion::add(const Types::Quaternion& a, const Types::Quaternion& b)
{
	Types::Quaternion rv;
	rv.w = a.w + b.w;
	rv.x = a.x + b.x;
	rv.y = a.y + b.y;
	rv.z = a.z + b.z;
	return rv;
}

Quaternion Math::Quaternion::subtract(const Types::Quaternion& a, const Types::Quaternion& b)
{
	Types::Quaternion rv;
	rv.w = a.w - b.w;
	rv.x = a.x - b.x;
	rv.y = a.y - b.y;
	rv.z = a.z - b.z;
	return rv;
}

void Math::Quaternion::identityForMul(Types::Quaternion& a)
{
	a.w = 1.0f;
	a.x = 0.0f;
	a.y = 0.0f;
	a.z = 0.0f;
}

void Math::Quaternion::identityForAdd(Types::Quaternion& a)
{
	a.w = 0.0f;
	a.x = 0.0f;
	a.y = 0.0f;
	a.z = 0.0f;
}

float Math::Quaternion::norm(const Types::Quaternion& a)
{
	return sqrtf(a.x * a.x
		+ a.y * a.y
		+ a.z * a.z
		+ a.w * a.w);
}

Quaternion Math::Quaternion::inverse(const Types::Quaternion& a)
{
	Types::Quaternion aConj = conjugate(a);
	float n = norm(aConj);
	return scale(aConj, 1.0f / n);
}

Matrix4x4 Math::Quaternion::toMatrix4x4(const Types::Quaternion& a)
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

Matrix3x3 Math::Quaternion::toMatrix3x3(const Types::Quaternion& a)
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
