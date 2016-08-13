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
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(PhysicsMath_2D_Acceleration)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(PhysicsMath_3D_Acceleration)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(PhysicsMath_2D_Velocity)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(PhysicsMath_3D_Velocity)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(PhysicsMath_2D_Monentum)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(PhysicsMath_3D_Monentum)
		{
			Assert::AreEqual(1, 2);
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
			Assert::AreEqual(1, 2);
		}
	};
}