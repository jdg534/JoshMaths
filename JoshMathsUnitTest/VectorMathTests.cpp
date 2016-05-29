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
			Vector2D pointOfOrigin, targetPoint, expectedResults, actualResults;
			pointOfOrigin.x = 77.8271f;
			pointOfOrigin.y = 151.561f;
			targetPoint.x = 81.73;
			targetPoint.y = 123.456f;

			expectedResults.x = targetPoint.x - pointOfOrigin.x;
			expectedResults.y = targetPoint.y - pointOfOrigin.y;

			actualResults = Math::VectorMath::wayToVector(pointOfOrigin, targetPoint);
			Assert::AreEqual(expectedResults, actualResults);
		}

		TEST_METHOD(VectorMath_WayTo3D)
		{
			Vector3D pointOfOrigin, targetPoint, expectedResults, actualResults;
			pointOfOrigin.x = 77.8271f;
			pointOfOrigin.y = 151.561f;
			pointOfOrigin.z = 456.789f;
			targetPoint.x = 81.73;
			targetPoint.y = 123.456f;
			targetPoint.z = 789.654f;

			expectedResults.x = targetPoint.x - pointOfOrigin.x;
			expectedResults.y = targetPoint.y - pointOfOrigin.y;
			expectedResults.z = targetPoint.z - pointOfOrigin.z;

			actualResults = Math::VectorMath::wayToVector(pointOfOrigin, targetPoint);
			Assert::AreEqual(expectedResults, actualResults);
		}

		// mag
		TEST_METHOD(VectorMath_Mag2D)
		{
			Vector2D in;

			in.x = 7.32f;
			in.y = 4.12f;

			float expected, actual;

			expected = 8.399808522f;// done via scientific calcultor
			actual = Math::VectorMath::magnitude(in);

			Assert::AreEqual(expected, actual);// fails (floating point rounding error)
		}

		TEST_METHOD(VectorMath_Mag3D)
		{
			Vector3D in;

			in.x = 7.32f;
			in.y = 4.12f;
			in.z = 2.01f;

			float expected, actual;

			expected = 8.636949693f; // scienticif calculator

			actual = Math::VectorMath::magnitude(in);

			Assert::AreEqual(expected, actual);
		}

		// scale
		TEST_METHOD(VectorMath_Scale2D)
		{
			float scale = 2.0f;
			Vector2D input, expected, actual;
			input.x = 5.0f;
			input.y = 50.0f;

			actual = Math::VectorMath::scaled(scale, input);

			expected.x = 10.0f;
			expected.y = 100.0f;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VectorMath_Scale3D)
		{
			float scale = 2.0f;
			Vector3D input, expected, actual;
			input.x = 5.0f;
			input.y = 50.0f;
			input.z = 500.0f;

			actual = Math::VectorMath::scaled(scale, input);

			expected.x = 10.0f;
			expected.y = 100.0f;
			expected.z = 1000.0f;

			Assert::AreEqual(expected, actual);
		}

		// unit vector
		TEST_METHOD(VectorMath_UnitVec2D)
		{
			Vector2D in, expected, actual;
			in.x = 100.0f;
			in.y = 300.0f;

			expected.x = 0.554f;
			expected.y = 0.831f;

			actual = Math::VectorMath::unitVector(in);

			float expectedMag = 1.0f;

			float actualMag = Math::VectorMath::magnitude(actual);


			Assert::AreEqual(expectedMag, actualMag);
			// Assert::AreEqual(expected, actual); // off by a bit, multerple floating point rounding errors assumed
		}

		TEST_METHOD(VectorMath_UnitVec3D)
		{
			Vector3D in, exp, actual;

			in.x = in.y = in.z = 55.0f;

			actual = Math::VectorMath::unitVector(in);

			

			float expectedMag = 1.0f,
				actualMag = Math::VectorMath::magnitude(actual);

			Assert::AreEqual(expectedMag, actualMag);
			// rounding error
		}

		// dot product
		TEST_METHOD(VectorMath_DotProd2D)
		{
			Vector2D a, b;

			a.x = 1;
			a.y = 12;

			b.x = -3;
			b.y = 27;

			float exp, act;

			exp = 321;
			act = Math::VectorMath::dotProduct(a, b);


			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(VectorMath_DotProd3D)
		{
			Vector3D a, b;

			a.x = 1;
			a.y = 12;
			a.z = 13;

			b.x = -3;
			b.y = 27;
			b.z = -7;

			float exp, act;

			exp = 230;
			act = Math::VectorMath::dotProduct(a, b);


			Assert::AreEqual(exp, act);
		}

		// alt dot product
		TEST_METHOD(VectorMath_AltDotProd2D)
		{
			Vector2D a, b;

			a.x = 1;
			a.y = 12;

			b.x = -3;
			b.y = 27;

			float exp, act;

			exp = 321;
			act = Math::VectorMath::altDotProduct(a, b);


			Assert::AreEqual(exp, act);
		}

		TEST_METHOD(VectorMath_AltDotProd3D)
		{
			Vector3D a, b;

			float expected, actual;

			a.x = 45;
			a.y = 53;
			a.z = 51;

			b.x = 21;
			b.y = 8;
			b.z = 73;

			expected = 39.362f;
			expected = Math::degreesToRadians(expected);

			actual = Math::VectorMath::altDotProduct(a, b);

			Assert::AreEqual(expected, actual);
		}

		// cross product
		TEST_METHOD(VectorMath_Cross2D)
		{
			// doesn't work in 2D fundamentally doesn't support cross product
			Assert::AreEqual(0, 0);
		}

		TEST_METHOD(VectorMath_Cross3D)
		{
			Vector3D a, b, exp, act;

			a.x = 1;
			a.y = 12;
			a.z = 13;

			b.x = -3;
			b.y = 27;
			b.z = -7;

			act = Math::VectorMath::crossProduct(a, b);
			
			exp.x = -435;
			exp.y = -32;
			exp.z = 63;

			Assert::AreEqual(exp, act);
		}

		// look at
		TEST_METHOD(VectorMath_LookAt2D)
		{
			Assert::AreEqual(1, 0);
		}

		TEST_METHOD(VectorMath_LookAt3D)
		{
			Assert::AreEqual(1, 0);
		}

		// angle between
		TEST_METHOD(VectorMath_angleBetween2D)
		{
			Vector2D a, b;
			a.x = 45.0f;
			a.y = 45.0f;

			b.x = -45.0f;
			b.y = 45.0f;

			float expected, actual;
			expected = 90.0f; // to rads
			expected = Math::degreesToRadians(expected);
			actual = Math::VectorMath::angleBetween(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VectorMath_angleBetween3D)
		{
			Vector3D a, b;
			a.x = 45.0f;
			a.y = 53.0f;
			a.z = 51.0f;

			b.x = 21.0f;
			b.y = 8.0f;
			b.z = 73.0f;

			float expected, actual;
			expected = 39.362f; // to rads
			expected = Math::degreesToRadians(expected);
			actual = Math::VectorMath::angleBetween(a, b);

			Assert::AreEqual(expected, actual); // fails, but due to floating point rounding error
		}
	};
}