#include "MatrixMath.h"

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

Matrix2x1 Math::Matrix::add(const Matrix2x1& a, const Matrix2x1& b)
{
	Matrix2x1 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r2c1 = a.r2c1 + b.r2c1;
	return rv;
}

Matrix2x2 Math::Matrix::add(const Matrix2x2& a, const Matrix2x2& b)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r1c2 = a.r1c2 + b.r1c2;
	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r2c2 = a.r2c2 + b.r2c2;
	return rv;
}

Matrix3x1 Math::Matrix::add(const Matrix3x1& a, const Matrix3x1& b)
{
	Matrix3x1 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r3c1 = a.r3c1 + b.r3c1;
	return rv;
}

Matrix3x3 Math::Matrix::add(const Matrix3x3& a, const Matrix3x3& b)
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

Matrix4x1 Math::Matrix::add(const Matrix4x1& a, const Matrix4x1& b)
{
	Matrix4x1 rv;
	rv.r1c1 = a.r1c1 + b.r1c1;
	rv.r2c1 = a.r2c1 + b.r2c1;
	rv.r3c1 = a.r3c1 + b.r3c1;
	rv.r4c1 = a.r4c1 + b.r4c1;
	return rv;
}

Matrix4x3 Math::Matrix::add(const Matrix4x3& a, const Matrix4x3& b)
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

Matrix4x4 Math::Matrix::add(const Matrix4x4& a, const Matrix4x4& b)
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

Matrix2x1 Math::Matrix::subtract(const Matrix2x1& a, const Matrix2x1& b)
{
	Matrix2x1 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r2c1 = a.r2c1 - b.r2c1;
	return rv;
}

Matrix2x2 Math::Matrix::subtract(const Matrix2x2& a, const Matrix2x2& b)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r1c2 = a.r1c2 - b.r1c2;
	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r2c2 = a.r2c2 - b.r2c2;
	return rv;
}

Matrix3x1 Math::Matrix::subtract(const Matrix3x1& a, const Matrix3x1& b)
{
	Matrix3x1 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r3c1 = a.r3c1 - b.r3c1;
	return rv;
}

Matrix3x3 Math::Matrix::subtract(const Matrix3x3& a, const Matrix3x3& b)
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

Matrix4x1 Math::Matrix::subtract(const Matrix4x1& a, const Matrix4x1& b)
{
	Matrix4x1 rv;
	rv.r1c1 = a.r1c1 - b.r1c1;
	rv.r2c1 = a.r2c1 - b.r2c1;
	rv.r3c1 = a.r3c1 - b.r3c1;
	rv.r4c1 = a.r4c1 - b.r4c1;

	return rv;
}

Matrix4x3 Math::Matrix::subtract(const Matrix4x3& a, const Matrix4x3& b)
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

Matrix4x4 Math::Matrix::subtract(const Matrix4x4& a, const Matrix4x4& b)
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

Matrix2x1 Math::Matrix::multiply(float scale, const Matrix2x1& a)
{
	Matrix2x1 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r2c1 = a.r2c1 * scale;
	return rv;
}

Matrix2x2 Math::Matrix::multiply(float scale, const Matrix2x2& a)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r1c2 = a.r1c2 * scale;
	rv.r2c1 = a.r2c1 * scale;
	rv.r2c2 = a.r2c2 * scale;
	return rv;
}

Matrix3x1 Math::Matrix::multiply(float scale, const Matrix3x1& a)
{
	Matrix3x1 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r2c1 = a.r2c1 * scale;
	rv.r3c1 = a.r3c1 * scale;
	return rv;
}

Matrix3x3 Math::Matrix::multiply(float scale, const Matrix3x3& a)
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

Matrix4x1 Math::Matrix::multiply(float scale, const Matrix4x1& a)
{
	Matrix4x1 rv;
	rv.r1c1 = a.r1c1 * scale;
	rv.r2c1 = a.r2c1 * scale;
	rv.r3c1 = a.r3c1 * scale;
	rv.r4c1 = a.r4c1 * scale;
	return rv;
}

Matrix4x3 Math::Matrix::multiply(float scale, const Matrix4x3& a)
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

Matrix4x4 Math::Matrix::multiply(float scale, const Matrix4x4& a)
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

Matrix2x1 Math::Matrix::multiply(const Matrix2x2& a, const Matrix2x1& b)
{
	Matrix2x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1);
	return rv;
}

Matrix2x2 Math::Matrix::multiply(const Matrix2x2& a, const Matrix2x2& b)
{
	Matrix2x2 rv;

	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1);
	rv.r1c2 = (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2);

	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1);
	rv.r2c2 = (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2);

	return rv;
}

Matrix3x1 Math::Matrix::multiply(const Matrix3x3& a, const Matrix3x1& b)
{
	Matrix3x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1);
	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1);
	return rv;
}

Matrix3x3 Math::Matrix::multiply(const Matrix3x3& a, const Matrix3x3& b)
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

Matrix4x1 Math::Matrix::multiply(const Matrix4x4& a, const Matrix4x1& b)
{
	Matrix4x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1) + (a.r1c4 * b.r4c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1) + (a.r2c4 * b.r4c1);
	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1) + (a.r3c4 * b.r4c1);
	rv.r4c1 = (a.r4c1 * b.r1c1) + (a.r4c2 * b.r2c1) + (a.r4c3 * b.r3c1) + (a.r4c4 * b.r4c1);

	return rv;
}

Matrix4x3 Math::Matrix::multiply(const Matrix4x4& a, const Matrix4x3& b)
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

Matrix4x4 Math::Matrix::multiply(const Matrix4x4& a, const Matrix4x4& b)
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

Matrix4x1 Math::Matrix::multiply(const Matrix4x3& a, const Matrix3x1& b)
{
	Matrix4x1 rv;
	rv.r1c1 = (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1);
	rv.r2c1 = (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1);
	rv.r3c1 = (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1);
	rv.r4c1 = (a.r4c1 * b.r1c1) + (a.r4c2 * b.r2c1) + (a.r4c3 * b.r3c1);
	return rv;
}

Matrix4x3 Math::Matrix::multiply(const Matrix4x3& a, const Matrix3x3& b)
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

float Math::Matrix::determinant(const Matrix2x2& a)
{
	return (a.r1c1 * a.r2c2) - (a.r1c2 * a.r2c1);
}

float Math::Matrix::determinant(const Matrix3x3& a)
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

float Math::Matrix::determinant(const Matrix4x4& a)
{
	const float PosA = a.r1c1 * a.r2c2 * a.r3c3 * a.r4c4;
	const float PosB = a.r1c2 * a.r2c3 * a.r3c4 * a.r4c1;
	const float PosC = a.r1c3 * a.r2c4 * a.r3c1 * a.r4c2;
	const float PosD = a.r1c4 * a.r2c1 * a.r3c2 * a.r4c3;

	const float NegA = a.r1c4 * a.r2c3 * a.r3c2 * a.r4c1;
	const float NegB = a.r1c3 * a.r2c2 * a.r3c1 * a.r4c4;
	const float NegC = a.r1c2 * a.r2c1 * a.r3c4 * a.r4c3;
	const float NegD = a.r1c1 * a.r2c4 * a.r3c3 * a.r4c2;

	return PosA + PosB + PosC + PosD
		 - NegA - NegB - NegC - NegD;
}

Matrix2x2 Math::Matrix::transpose(const Matrix2x2& a)
{
	Matrix2x2 rv;
	rv.r1c1 = a.r1c1;
	rv.r1c2 = a.r2c1;
	rv.r2c1 = a.r1c2;
	rv.r2c2 = a.r2c2;
	return rv;
}

Matrix3x3 Math::Matrix::transpose(const Matrix3x3& a)
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

Matrix4x4 Math::Matrix::transpose(const Matrix4x4& a)
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

Matrix2x2 Math::Matrix::inverse(const Matrix2x2& a)
{	
	Matrix2x2 toMul;
	toMul.r1c1 = a.r2c2;
	toMul.r2c2 = a.r1c1;
	toMul.r1c2 = 0.0f - a.r1c2;
	toMul.r2c1 = 0.0f - a.r2c1;

	float mul = 1.0f / determinant(a);
	return multiply(mul, toMul);

}

Matrix3x3 Math::Matrix::inverse(const Matrix3x3& a)
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

Matrix4x4 Math::Matrix::inverse(const Matrix4x4& a)
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

void Math::Matrix::makeIdentity(Matrix2x2& a)
{
	a = identity2x2();
}

void Math::Matrix::makeIdentity(Matrix3x3& a)
{
	a = identity3x3();
}

void Math::Matrix::makeIdentity(Matrix4x4& a)
{
	a = identity4x4();
}

Matrix2x2 Math::Matrix::identity2x2()
{
	Matrix2x2 m = zero2x2();
	m.r1c1 = 1.0f;
	m.r2c2 = 1.0f;
	return m;
}

Matrix3x3 Math::Matrix::identity3x3()
{
	Matrix3x3 m = zero3x3();
	m.r1c1 = 1.0f;
	m.r2c2 = 1.0f;
	m.r3c3 = 1.0f;
	return m;
}

Matrix4x4 Math::Matrix::identity4x4()
{
	Matrix4x4 m = zero4x4();
	m.r1c1 = 1.0f;
	m.r2c2 = 1.0f;
	m.r3c3 = 1.0f;
	m.r4c4 = 1.0f;
	return m;
}

Matrix2x2 Math::Matrix::zero2x2()
{
	Matrix2x2 m;
	std::memset(&m, 0, sizeof(Matrix2x2));
	return m;
}

Matrix3x3 Math::Matrix::zero3x3()
{
	Matrix3x3 m;
	std::memset(&m, 0, sizeof(Matrix3x3));
	return m;
}

Matrix4x4 Math::Matrix::zero4x4()
{
	Matrix4x4 m;
	std::memset(&m, 0, sizeof(Matrix4x4));
	return m;
}
