#include "stdafx.h"
#include "CppUnitTest.h"
#include "CppUnitTestAssert.h"

#include "MathTypes.h"

#include "JoshMath.h"

#include <sstream>
#include <string>


namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{

			template<>
			static std::wstring ToString<Vector2D>(const Vector2D& v)
			{
				std::wstringstream wss;
				wss << "[" << v.x << ", " << v.y << "]";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

			template<>
			static std::wstring ToString<Vector3D>(const Vector3D& v)
			{
				std::wstringstream wss;
				wss << "[" << v.x << ", " << v.y << ", " << v.z << "]";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace JoshMathsUnitTest
{
	TEST_CLASS(PhysicsMathsTestClass)
	{
	public:

		TEST_METHOD(PhysicsMath_2D_NetForce)
		{
			const unsigned int inNForces = 5;

			Vector2D inForces[inNForces];

			Vector2D expected, actual;

			expected.x = expected.y = 0.0f;

			for (int i = 0; i < inNForces; i++)
			{
				inForces[i].x = 5.0f;
				inForces[i].y = 3.0f;

				expected.x += inForces[i].x;
				expected.y += inForces[i].y;
			}

			actual = Math::Physics::netForce(inForces, inNForces);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_3D_NetForce)
		{
			const unsigned int numForces = 7;
			Vector3D forces[numForces];
			Vector3D expected, actual;
			expected.x = expected.y = expected.z = 0.0f;
			for (unsigned int i = 0; i < numForces; i++)
			{
				forces[i].x = 541.251f;
				forces[i].y = -123.456;
				forces[i].z = 98741.1f;
				expected.x += forces[i].x;
				expected.y += forces[i].y;
				expected.z += forces[i].z;
			}
			actual = Math::Physics::netForce(forces, numForces);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_2D_Acceleration)
		{
			Vector2D netForce;
			float mass = 0.5f;

			netForce.x = 10.0f;
			netForce.y = 20.0f;

			Vector2D expected, actual;

			expected.x = 20.0f;
			expected.y = 40.0f;

			actual = Math::Physics::acceleration(netForce, mass);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_3D_Acceleration)
		{
			Vector3D netForce;
			float mass = 0.5f;

			netForce.x = 10.0f;
			netForce.y = 20.0f;
			netForce.z = 30.0f;

			Vector3D expected, actual;

			expected.x = 20.0f;
			expected.y = 40.0f;
			expected.z = 60.0f;

			actual = Math::Physics::acceleration(netForce, mass);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_2D_Velocity)
		{
			Vector2D initalVel, accel;
			float time = 0.5f;

			initalVel.x = initalVel.y = 0.0f;
			accel.x = 1.0f;
			accel.y = 15.0f;

			Vector2D expected, actual;
			expected.x = 0.5f;
			expected.y = 7.5f;
			actual = Math::Physics::velocity(initalVel, accel, time);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_3D_Velocity)
		{
			Vector3D initalVel, accel;
			float time = 0.5f;

			initalVel.x = initalVel.y = initalVel.z = 0.0f;
			accel.x = 1.0f;
			accel.y = 15.0f;
			accel.z = 30.0f;

			Vector3D expected, actual;
			expected.x = 0.5f;
			expected.y = 7.5f;
			expected.z = 15.0f;
			actual = Math::Physics::velocity(initalVel, accel, time);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_2D_Momentum)
		{
			Vector2D vel;
			vel.x = 1.0f;
			vel.y = 5.0f;

			float mass = 5.0f;

			Vector2D expected, actual;

			expected.x = 5.0f;
			expected.y = 25.0f;

			actual = Math::Physics::momentum(vel, mass);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_3D_Momentum)
		{
			Vector3D vel;
			vel.x = 1.0f;
			vel.y = 5.0f;
			vel.z = 10.0f;
			float mass = 5.0f;

			Vector3D expected, actual;

			expected.x = 5.0f;
			expected.y = 25.0f;
			expected.z = 50.0f;

			actual = Math::Physics::momentum(vel, mass);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_2D_Speed)
		{
			Vector2D testVel;
			testVel.x = 0.0f;
			testVel.y = 1.0f;

			float expected, actual = 0.0f;
			expected = 1.0f;
			// actual = Math::Physics::speed(testVel);
			actual = Math::Physics::speed(testVel);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(PhysicsMath_3D_Speed)
		{
			Vector3D testVel;
			testVel.x = 0.0f;
			testVel.y = 1.0f;
			testVel.z = 0.0f;
			float expected, actual = 0.0f;
			expected = 1.0f;
			// actual = Math::Physics::speed(testVel);
			actual = Math::Physics::speed(testVel);
			Assert::AreEqual(expected, actual);
		}
	};
}