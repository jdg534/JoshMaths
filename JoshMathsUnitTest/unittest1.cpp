#include "stdafx.h"
#include "CppUnitTest.h"

//#include <cassert> // needed?, NO!!!

#include <JoshMath.h>

#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

		}
	}
}

namespace JoshMathsUnitTest
{		
	

	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(passTestExample)
		{
			Assert::AreEqual(1, 1); // always passes
		}

		TEST_METHOD(failTestExample)
		{
			Assert::AreEqual(1, 2); // always fails
		}


		


	};

	// now for the actual unit tests
	// first the vector maths
	TEST_CLASS(VectorMathsTestClass)
	{
		TEST_METHOD(VectorAdditionWorksIn2D)
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

			Assert::AreEqual(results, expectedResults);
		}
	};

	// second the matrix maths

	// third the Quaternion maths

	// interpolation maths
}