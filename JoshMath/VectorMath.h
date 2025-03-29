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
}

#endif