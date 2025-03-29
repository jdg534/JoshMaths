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
	namespace Physics
	{
		// pratical model for now
		Types::Vector2D netForce(const Types::Vector2D* forces, const unsigned int nForces);
		Types::Vector3D netForce(const Types::Vector3D* forces, const unsigned int nForces);

		Types::Vector2D acceleration(const Types::Vector2D& netForce, float mass);
		Types::Vector3D acceleration(const Types::Vector3D& netForce, float mass);

		Types::Vector2D velocity(const Types::Vector2D& previousVelocity, const Types::Vector2D& acceleration, float time);
		Types::Vector3D velocity(const Types::Vector3D& previousVelocity, const Types::Vector3D& acceleration, float time);

		Types::Vector2D momentum(const Types::Vector2D& velocity, float mass);
		Types::Vector3D momentum(const Types::Vector3D& velocity, float mass);

		float speed(const Types::Vector2D& velocity);
		float speed(const Types::Vector3D& velocity);
	}
}
