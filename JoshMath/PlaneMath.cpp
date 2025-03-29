#include "PlaneMath.h"
#include "VectorMath.h"

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

Plane Math::Plane::createPlane(const Vector3D& axisAsUnit, float dictanceFromOrigin)
{
	assert(Math::Vector::magnitude(axisAsUnit) == 1.0f);
	Types::Plane Results;
	Results.normal = axisAsUnit;
	Results.distanceFromOrigin = dictanceFromOrigin;
	return Results;
}

float Math::Plane::dotProductAsVector(const Types::Plane& plane, const Vector3D& vector)
{
	return (plane.normal.x * vector.x)
		+ (plane.normal.y * vector.y)
		+ (plane.normal.z * vector.z)
		+ (plane.distanceFromOrigin * 0.0f);
}

float Math::Plane::dotProductAsPosition(const Types::Plane& plane, const Vector3D& vector)
{
	return (plane.normal.x * vector.x)
		+ (plane.normal.y * vector.y)
		+ (plane.normal.z * vector.z)
		+ (plane.distanceFromOrigin * 1.0f);
}

float Math::Plane::distanceFromPlane(const Types::Plane& plane, const Vector3D& point)
{
	return dotProductAsPosition(plane, point);
}

Vector3D Math::Plane::reflectVector(const Vector3D& vectorToReflect, const Types::Plane& reflectIn)
{
	const Vector3D PlaneNormalScaled = Math::Vector::scaled(2 * Math::Plane::dotProductAsVector(reflectIn, vectorToReflect), reflectIn.normal);
	return Math::Vector::subtract(vectorToReflect, PlaneNormalScaled);
}

Vector3D Math::Plane::reflectPosition(const Vector3D& positionToReflect, const Types::Plane& reflectIn)
{
	using namespace Math::Vector;
	const float ScaleNormalBy = 2 * (dotProduct(positionToReflect, reflectIn.normal) - reflectIn.distanceFromOrigin);
	return subtract(positionToReflect, scaled(ScaleNormalBy, reflectIn.normal));
}
