#include "ConversionFunctions.h"
#include "VectorMath.h"

#include <cfloat>
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

float Math::Conversion::degreesToRadians(float valueInDegrees)
{
	return valueInDegrees * (3.14159265359f / 180.0f);
}

float Math::Conversion::radiansToDegrees(float valueInRadians)
{
	return valueInRadians * (180.0f / 3.14159265359f);
}

PolarCoordinate Math::Conversion::CartesianToPolar(const Vector2D& cartVal)
{
	PolarCoordinate rv;
	rv.radius = Math::Vector::magnitude(cartVal);
	rv.angle = atanf(cartVal.x / cartVal.y);
	return rv;
}

Vector2D Math::Conversion::PolarToCartesian(const PolarCoordinate& PolarVal)
{
	Vector2D rv; // Note angle is meant to be in radians.
	rv.x = PolarVal.radius * cosf(PolarVal.angle);
	rv.y = PolarVal.radius * sinf(PolarVal.angle);
	return rv;
}
