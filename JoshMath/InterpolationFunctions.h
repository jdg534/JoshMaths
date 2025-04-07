#pragma once

#include "MathTypes.h"

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
	namespace Interpolation
	{
		int intLerp(int a, int b, int targetPoint); // should be in range 0 - 100 inclusive
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
		// note this is note for accuracy. It's for running when without float arithmatic.
		int intInterpolationWeight(int min, int max, int x);

		float smoothStep(float min, float max, float x);
	}
}
