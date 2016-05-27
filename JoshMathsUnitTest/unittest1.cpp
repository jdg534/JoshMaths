#include "stdafx.h"
#include "CppUnitTest.h"


#include "MathTypes.h"
#include "JoshMath.h"

#include <sstream>s
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{

			template<>
			static std::wstring ToString<PolarCoordinate>(const PolarCoordinate& v)
			{
				std::wstringstream wss;
				wss << "theta " << v.angle << " mag " << v.radius;
				return wss.str();
				//return L"Some string representing coordinate.";
			}

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
		/*
		TEST_METHOD(passTestExample)
		{
			Assert::AreEqual(1, 1); // always passes
		}
		*/

		/*
		TEST_METHOD(failTestExample)
		{
			Assert::AreEqual(1, 2); // always fails
		}
		*/

		TEST_METHOD(GeneralMath_ConvetionDegreesToRadians)
		{
			float degreeValue = 57.62f;

			float expectedResults = 1.0056587f;

			float actualResults = Math::degreesToRadians(degreeValue);

			Assert::AreEqual(expectedResults, actualResults);
		}

		TEST_METHOD(GeneralMath_ConvetionRadiansToDegrees)
		{
			float radianValue = 5.372f;

			float expectedValue = 307.79293f;

			float actualResults = Math::radiansToDegrees(radianValue);

			Assert::AreEqual(expectedValue, actualResults);
		}

		TEST_METHOD(PolarCoordinateMath_CartesianToPolar)
		{
			Vector2D input;
			PolarCoordinate expectedRes, actualRes;
			// angle in rads not degrees

			input.x = 12;
			input.y = 5;

			expectedRes.radius = 13;
			expectedRes.angle = 22.6f;// 
			expectedRes.angle = Math::degreesToRadians(expectedRes.angle);

			actualRes = Math::PolarCoordinateMath::CartesianToPolar(input);

			Assert::AreEqual(expectedRes, actualRes);
			// https://www.mathsisfun.com/polar-cartesian-coordinates.html
		}

		TEST_METHOD(PolarCoordinateMath_PolarToCartesian)
		{
			// angle in rads not degrees
			PolarCoordinate input;

			Vector2D expectedResults, actualResults;

			Assert::AreEqual(expectedResults, actualResults);

			// https://www.mathsisfun.com/polar-cartesian-coordinates.html

			input.radius = 13;
			input.angle = 22.6;

			expectedResults.x = 12;
			expectedResults.y = 5;

			actualResults = Math::PolarCoordinateMath::PolarToCartesian(input);

			Assert::AreEqual(expectedResults, actualResults);
		}
	};
}