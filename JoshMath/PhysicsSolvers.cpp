#include "PhysicsSolvers.h"
#include "VectorMath.h"

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

Vector2D Math::Physics::netForce(const Vector2D* forces, const unsigned int nForces)
{
	Vector2D results;
	results.x = results.y = 0.0f;
	for (unsigned int i = 0; i < nForces; ++i)
	{
		results.x += forces[i].x;
		results.y += forces[i].y;
	}
	return results;
}

Vector3D Math::Physics::netForce(const Vector3D* forces, const unsigned int nForces)
{
	Vector3D results;
	results.x = results.y = results.z = 0.0f;
	for (unsigned int i = 0; i < nForces; ++i)
	{
		results.x += forces[i].x;
		results.y += forces[i].y;
		results.z += forces[i].z;
	}
	return results;
}

Vector2D Math::Physics::acceleration(const Vector2D& netForce, float mass)
{
	Vector2D results;
	results.x = netForce.x / mass;
	results.y = netForce.y / mass;
	return results;
}

Vector3D Math::Physics::acceleration(const Vector3D& netForce, float mass)
{
	Vector3D results;
	results.x = netForce.x / mass;
	results.y = netForce.y / mass;
	results.z = netForce.z / mass;
	return results;
}

Vector2D Math::Physics::velocity(const Vector2D& previousVelocity, const Vector2D& acceleration, float time)
{
	Vector2D currentVelocity;
	currentVelocity.x = previousVelocity.x + (acceleration.x * time);
	currentVelocity.y = previousVelocity.y + (acceleration.y * time);
	return currentVelocity;
}

Vector3D Math::Physics::velocity(const Vector3D& previousVelocity, const Vector3D& acceleration, float time)
{
	Vector3D currentVelocity;
	currentVelocity.x = previousVelocity.x + (acceleration.x * time);
	currentVelocity.y = previousVelocity.y + (acceleration.y * time);
	currentVelocity.z = previousVelocity.z + (acceleration.z * time);
	return currentVelocity;
}

Vector2D Math::Physics::momentum(const Vector2D& velocity, float mass)
{
	Vector2D momentum;
	momentum.x = mass * velocity.x;
	momentum.y = mass * velocity.y;
	return momentum;
}

Vector3D Math::Physics::momentum(const Vector3D& velocity, float mass)
{
	Vector3D momentum;
	momentum.x = mass * velocity.x;
	momentum.y = mass * velocity.y;
	momentum.z = mass * velocity.z;
	return momentum;
}

float Math::Physics::speed(const Vector2D& velocity)
{
	return Math::Vector::magnitude(velocity);
}

float Math::Physics::speed(const Vector3D& velocity)
{
	return Math::Vector::magnitude(velocity);
}
