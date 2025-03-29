#pragma once

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
}
