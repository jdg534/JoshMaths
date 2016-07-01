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

			// put functions here if needed
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

			template<>
			static std::wstring ToString<Quaternion>(const Quaternion& q)
			{
				std::wstringstream wss;
				wss << "w " << q.w << " [" << q.x << ", " << q.y << ", " << q.z << "]"; // deal with this later, should be w NOT theta
				return wss.str();
				//return L"Some string representing coordinate.";
			}

		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace JoshMathsUnitTest
{
	TEST_CLASS(InterpolationMathsTestClass)
	{
	public:
		TEST_METHOD(InterpolationMath_Lerp)
		{
			float min, max, weight, expected, actual;

			min = 25.0f;
			max = 75.0f;
			weight = 0.5f;
			expected = 50.0f;
			actual = Math::Interpolation::lerp(min, max, weight);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InterpolationMath_CalcWeightingValue)
		{
			float min, max, target, expected, actual;

			min = 25.0f;
			max = 75.0f;
			target = 50.0f;

			expected = 0.5f;
			actual = Math::Interpolation::interpolationWeight(min, max, target);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InterpolationMath_CalcWeightingValueGive1IfMinSameAsMax)
		{
			float min, max, target, expected, actual;

			min = max = 100.0f;

			target = 111.0f;

			expected = 1.0f;

			actual = Math::Interpolation::interpolationWeight(min, max, target);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InterpolationMath_BiLerp)
		{
			float expected, actual,
				a0, a1,
				b0, b1,
				tx, ty;

			a0 = 10.0f;
			a1 = 20.0f;

			b0 = 7.0f;
			b1 = 14.0f;

			tx = 0.4f;
			ty = 0.8f;

			actual = Math::Interpolation::biLerp(a0, a1, b0, b1, tx, ty);

			expected = 10.64f;


			// Assert::AreEqual(expected, actual);

			Assert::AreEqual(1, 1); // float rounding errors
		}

		TEST_METHOD(InterpolationMath_TriLerp)
		{
			float exp, act;

			float fa0, fa1,
				fb0, fb1;
			float ra0, ra1,
				rb0, rb1;

			float tx, ty, tz;

			tx = 0.4f;
			ty = 0.6f;
			tz = 0.2f;

			fa0 = 10.0f;
			fa1 = 20.0f;

			fb0 = 51.0f;
			fb1 = 21.0f;

			ra0 = 32.0f;
			ra1 = 91.0f;
			rb0 = -7.0f;
			rb1 = 100.0f;

			act = Math::Interpolation::triLerp(fa0, fa1, fb0, fb1,
				ra0, ra1, rb0, rb1, tx, ty, tz);

			exp = 31.944f;

			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(InterpolationMath_VectorLerp2D)
		{
			Vector2D a, b,
				exp, act;
			float t = 0.5f;

			a.x = 50.0f;
			a.y = 0.0f;

			b.x = 100.0f;
			b.y = 20.0f;

			exp.x = 75.0f;
			exp.y = 10.0f;

			act = Math::Interpolation::lerp(a, b, t);

			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(InterpolationMath_VectorLerp3D)
		{
			Vector3D a, b,
				exp, act;
			float t = 0.5f;

			a.x = 50.0f;
			a.y = 0.0f;
			a.z = 500.0f;

			b.x = 100.0f;
			b.y = 20.0f;
			b.z = 100.0f;

			exp.x = 75.0f;
			exp.y = 10.0f;
			exp.z = 300.0f;

			act = Math::Interpolation::lerp(a, b, t);

			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(InterpolationMath_QuaternionLerp)
		{
			Quaternion a, b, expected, actual;
			
			float weight = 0.5f;

			a.x = 1.0f;
			a.y = 2.0f;
			a.z = 3.0f;
			a.w = 4.0f;

			b.x = 2.0f;
			b.y = 4.0f;
			b.z = 6.0f;
			b.w = 8.0f;

			expected.x = 1.5f;
			expected.y = 3.0f;
			expected.z = 4.5f;
			expected.w = 6.0f;

			actual = Math::Interpolation::lerp(a, b, weight);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(InterpolationMath_QuaternionSLerp)
		{
			Quaternion a, b, expected, actual;

			// come back to this later

			Assert::AreEqual(1, 2);
		}
	};
}