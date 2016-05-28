#include "stdafx.h"
#include "CppUnitTest.h"


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
	TEST_CLASS(VectorMathsTestClass)
	{
	public:

		TEST_METHOD(VectorMath_AdditionWorksIn2D)
		{
			Vector2D a;
			Vector2D b;
			a.x = 25.0f;
			a.y = -25.0f;
			b.x = 50.0f;
			b.y = -100.0f;

			Vector2D results, expectedResults;

			expectedResults.x = 25.0f + 50.0f;
			expectedResults.y = -25.0f + -100.0f;

			results = Math::VectorMath::add(a, b);



			Assert::AreEqual(results, expectedResults);
		}

		TEST_METHOD(VectorMath_AdditionWorksIn3D)
		{
			Vector3D a;
			Vector3D b;
			a.x = 25.0f;
			a.y = -25.0f;
			a.z = 7.235f;
			b.x = 50.0f;
			b.y = -100.0f;
			b.z = 81.273f;

			Vector3D results, expectedResults;

			expectedResults.x = 25.0f + 50.0f;
			expectedResults.y = -25.0f + -100.0f;
		}

		/* TODO: (2D & 3D)
		subtraction
		dot product
		alt dot product
		cross product
		angle between
		*/

		// subtraction
		TEST_METHOD(VectorMath_Subtraction2D)
		{
			Vector2D a, b, actual, expected;
			a.x = b.x = 12.752f;
			a.y = b.y = 1324.43f;

			expected.x = expected.y = 0.0f;
			actual = Math::VectorMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VectorMath_Subtraction3D)
		{
			Vector3D a, b, actual, expected;
			a.x = b.x = 12.752f;
			a.y = b.y = 1324.43f;
			a.z = b.z = 534.123f;

			expected.x = expected.y = expected.z = 0.0f;
			actual = Math::VectorMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VectorMath_WayTo2D)
		{

		}

		TEST_METHOD(VectorMath_WayTo3D)
		{

		}

	};
}