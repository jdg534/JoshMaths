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
}
