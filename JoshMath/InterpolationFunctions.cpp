#include "InterpolationFunctions.h"
#include "QuaternionMath.h"

#include <cmath>

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

int Math::Interpolation::intLerp(int a, int b, int targetPoint)
{
	throw std::exception("not implemented");
	return -1;
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

Quaternion Math::Interpolation::lerp(const Types::Quaternion& qa, const Types::Quaternion& qb, float targetPoint)
{
	if(targetPoint <= 0.0f)
	{
		return qa;
	}
	else if(targetPoint >= 1.0f)
	{
		return qb;
	}

	Types::Quaternion rv;
	rv.w = lerp(qa.w, qb.w, targetPoint);
	rv.x = lerp(qa.x, qb.x, targetPoint);
	rv.y = lerp(qa.y, qb.y, targetPoint);
	rv.z = lerp(qa.z, qb.z, targetPoint);

	//rv = QuaternionMath::normalise(rv);

	return rv;
}

// slep
Quaternion Math::Interpolation::slerp(const Types::Quaternion& a, const Types::Quaternion& b, float t)
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

	Types::Quaternion rvA = Quaternion::scale(a, aScale);
	Types::Quaternion rvB = Quaternion::scale(b, bScale);
	Types::Quaternion rv = Quaternion::add(rvA, rvB);
	rv = Quaternion::normalise(rv);
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
	float clampedX = std::max(min, std::min(max, x));
	float normalisedX = (clampedX - min) / (max - min);
	return normalisedX * normalisedX * (3 - 2 * normalisedX);
}