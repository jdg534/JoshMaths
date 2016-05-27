#include "stdafx.h"
#include "CppUnitTest.h"


#include "MathTypes.h"
#include "JoshMath.h"

#include <sstream>
#include <string>

#include <memory> // needed for std::memcpy

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{

			template<>
			static std::wstring ToString<Matrix2x1>(const Matrix2x1& v)
			{
				std::wstringstream wss;
				wss << "|" << v.r1c1 << "|\n|" << v.r2c1 << "|";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

			template<>
			static std::wstring ToString<Matrix2x2>(const Matrix2x2& v)
			{
				std::wstringstream wss;
				wss << "|" << v.r1c1 << ", " << v.r1c2 << "|\n";
				wss	<< "|" << v.r2c1 << ", " << v.r2c2 << "|";
				return wss.str();
				//return L"Some string representing coordinate.";
			}
			
			template<>
			static std::wstring ToString<Matrix3x1>(const Matrix3x1& v)
			{
				std::wstringstream wss;
				wss << "|" << v.r1c1 << "|\n";
				wss << "|" << v.r2c1 << "|\n";
				wss << "|" << v.r3c1 << "|";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

			template<>
			static std::wstring ToString<Matrix3x3>(const Matrix3x3& v)
			{
				std::wstringstream wss;
				wss << "|" << v.r1c1 << ", " << v.r1c2 << ", " << v.r1c3 << "|\n";
				wss << "|" << v.r2c1 << ", " << v.r2c2 << ", " << v.r2c3 << "|\n";
				wss << "|" << v.r3c1 << ", " << v.r3c2 << ", " << v.r3c3 << "|";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

			template<>
			static std::wstring ToString<Matrix4x1>(const Matrix4x1& v)
			{
				std::wstringstream wss;
				wss << "|" << v.r1c1 << "|\n";
				wss << "|" << v.r2c1 << "|\n";
				wss << "|" << v.r3c1 << "|\n";
				wss << "|" << v.r4c1 << "|";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

			template<>
			static std::wstring ToString<Matrix4x3>(const Matrix4x3& v)
			{
				std::wstringstream wss;
				wss << "|" << v.r1c1 << ", " << v.r1c2 << ", " << v.r1c3 << "|\n";
				wss << "|" << v.r2c1 << ", " << v.r2c2 << ", " << v.r2c3 << "|\n";
				wss << "|" << v.r3c1 << ", " << v.r3c2 << ", " << v.r3c3 << "|\n";
				wss << "|" << v.r4c1 << ", " << v.r4c2 << ", " << v.r4c3 << "|\n";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

			template<>
			static std::wstring ToString<Matrix4x4>(const Matrix4x4& v)
			{
				std::wstringstream wss;
				wss << "|" << v.r1c1 << ", " << v.r1c2 << ", " << v.r1c3 << ", " << v.r1c4 <<"|\n";
				wss << "|" << v.r2c1 << ", " << v.r2c2 << ", " << v.r2c3 << ", " << v.r2c4 << "|\n";
				wss << "|" << v.r3c1 << ", " << v.r3c2 << ", " << v.r3c3 << ", " << v.r3c4 << "|\n";
				wss << "|" << v.r4c1 << ", " << v.r4c2 << ", " << v.r4c3 << ", " << v.r4c4 << "|\n";
				return wss.str();
				//return L"Some string representing coordinate.";
			}
		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace JoshMathsUnitTest
{
	TEST_CLASS(MatrixMathsTestClass)
	{
	public:
		/*
		TODO: 
		matrices can be compaired
		addition
		subtraction
		multerplication
		determinant
		transpose
		inverse
		identity
		*/
		TEST_METHOD(MatrixMath_Comparisons2x1)
		{
			Matrix2x1 a, b;
			a.r1c1 = b.r1c1 = 1.1f;
			a.r2c1 = b.r2c1 = 2.2f;

			Assert::AreEqual(a, b);
		}
		
		TEST_METHOD(MatrixMath_Comparisons2x2)
		{
			Matrix2x2 a, b;
			a.r1c1 = b.r1c1 = 1.1f;
			a.r1c2 = b.r1c2 = 1.2f;
			a.r2c1 = b.r2c1 = 2.1f;
			a.r2c2 = b.r2c2 = 2.2f;

			Assert::AreEqual(a, b);
		}

		TEST_METHOD(MatrixMath_Comparisons3x1)
		{
			Matrix3x1 a, b;
			a.r1c1 = b.r1c1 = 1.1f;
			//a.r1c2 = b.r1c2 = 1.2f;
			a.r2c1 = b.r2c1 = 2.1f;
			//a.r2c2 = b.r2c2 = 2.2f;
			a.r3c1 = b.r3c1 = 3.1f;
			Assert::AreEqual(a, b);
		}

		TEST_METHOD(MatrixMath_Comparisons3x3)
		{
			Matrix3x3 a, b;
			a.r1c1 = b.r1c1 = 1.1f;
			a.r1c2 = b.r1c2 = 1.2f;
			a.r1c3 = b.r1c3 = 1.3f;
			a.r2c1 = b.r2c1 = 2.1f;
			a.r2c2 = b.r2c2 = 2.2f;
			a.r2c3 = b.r2c3 = 2.3f;
			a.r3c1 = b.r3c1 = 3.1f;
			a.r3c2 = b.r3c2 = 3.2f;
			a.r3c3 = b.r3c3 = 3.3f;

			Assert::AreEqual(a, b);
		}

		TEST_METHOD(MatrixMath_Comparisons4x1)
		{
			Matrix4x1 a, b;
			a.r1c1 = b.r1c1 = 1.1f;
			//a.r1c2 = b.r1c2 = 1.2f;
			a.r2c1 = b.r2c1 = 2.1f;
			//a.r2c2 = b.r2c2 = 2.2f;
			a.r3c1 = b.r3c1 = 3.1f;
			a.r4c1 = b.r4c1 = 4.1f;
			Assert::AreEqual(a, b);
		}

		TEST_METHOD(MatrixMath_Comparisons4x3)
		{
			Matrix4x3 a, b;
			a.r1c1 = b.r1c1 = 1.1f;
			a.r1c2 = b.r1c2 = 1.2f;
			a.r1c3 = b.r1c3 = 1.3f;
			a.r2c1 = b.r2c1 = 2.1f;
			a.r2c2 = b.r2c2 = 2.2f;
			a.r2c3 = b.r2c3 = 2.3f;
			a.r3c1 = b.r3c1 = 3.1f;
			a.r3c2 = b.r3c2 = 3.2f;
			a.r3c3 = b.r3c3 = 3.3f;
			a.r4c1 = b.r4c1 = 4.1f;
			a.r4c2 = b.r4c2 = 4.2f;
			a.r4c3 = b.r4c3 = 4.3f;
			Assert::AreEqual(a, b);
		}

		TEST_METHOD(MatrixMath_Comparisons4x4)
		{
			Matrix4x4 a, b;
			a.r1c1 = b.r1c1 = 1.1f;
			a.r1c2 = b.r1c2 = 1.2f;
			a.r1c3 = b.r1c3 = 1.3f;
			a.r1c4 = b.r1c4 = 1.4f;
			a.r2c1 = b.r2c1 = 2.1f;
			a.r2c2 = b.r2c2 = 2.2f;
			a.r2c3 = b.r2c3 = 2.3f;
			a.r2c4 = b.r2c4 = 2.4f;
			a.r3c1 = b.r3c1 = 3.1f;
			a.r3c2 = b.r3c2 = 3.2f;
			a.r3c3 = b.r3c3 = 3.3f;
			a.r3c4 = b.r3c4 = 3.4f;
			a.r4c1 = b.r4c1 = 4.1f;
			a.r4c2 = b.r4c2 = 4.2f;
			a.r4c3 = b.r4c3 = 4.3f;
			a.r4c4 = b.r4c4 = 4.4f;
			Assert::AreEqual(a, b);
		}

		// Additions
		TEST_METHOD(MatrixMath_Addition2x1)
		{
			Matrix2x1 a, b, expectedResults, actualResults;
			a.r1c1 = 5;
			a.r2c1 = 6;
			b.r1c1 = 7;
			b.r2c1 = 8;

			expectedResults.r1c1 = 5 + 7;
			expectedResults.r2c1 = 6 + 8;
			actualResults = Math::MatrixMath::add(a, b);
			Assert::AreEqual(expectedResults, actualResults);
		}

		TEST_METHOD(MatrixMath_Addition2x2)
		{
			Matrix2x2 a, b, expectedResults, actualResults;
			a.r1c1 = b.r1c1 = 5;
			a.r1c2 = b.r1c2 = 6;
			a.r2c1 = b.r2c1 = 7;
			a.r2c2 = b.r2c2 = 8;

			expectedResults.r1c1 = 5 + 5;
			expectedResults.r1c2 = 6 + 6;
			expectedResults.r2c1 = 7 + 7;
			expectedResults.r2c2 = 8 + 8;
			actualResults = Math::MatrixMath::add(a, b);
			Assert::AreEqual(expectedResults, actualResults);
		}

		TEST_METHOD(MatrixMath_Addition3x1)
		{
			Matrix3x1 a, b, expectedResults, actualResults;
			a.r1c1 = 5;
			a.r2c1 = 6;
			a.r3c1 = 9;
			b.r1c1 = 7;
			b.r2c1 = 8;
			b.r3c1 = 10;
			expectedResults.r1c1 = 5 + 7;
			expectedResults.r2c1 = 6 + 8;
			expectedResults.r3c1 = 9 + 10;
			actualResults = Math::MatrixMath::add(a, b);
			Assert::AreEqual(expectedResults, actualResults);
		}

		TEST_METHOD(MatrixMath_Addition3x3)
		{
			Matrix3x3 a, b, expected, actual;

			const int nVals = sizeof(Matrix3x3) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] + setB[i];
			}
			
			// use memcpy to move the array values into the matrices
			std::memcpy(&a, setA, sizeof(Matrix3x3));
			std::memcpy(&b, setB, sizeof(Matrix3x3));
			std::memcpy(&expected, expectedSet, sizeof(Matrix3x3));

			actual = Math::MatrixMath::add(a, b);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Addition4x1)
		{
			Matrix4x1 a, b, expected, actual;

			const int nVals = sizeof(Matrix4x1) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] + setB[i];
			}

			// use memcpy to move the array values into the matrices
			std::memcpy(&a, setA, sizeof(Matrix4x1));
			std::memcpy(&b, setB, sizeof(Matrix4x1));
			std::memcpy(&expected, expectedSet, sizeof(Matrix4x1));

			actual = Math::MatrixMath::add(a, b);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Addition4x3)
		{
			Matrix4x3 a, b, expected, actual;

			const int nVals = sizeof(Matrix4x3) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] + setB[i];
			}

			// use memcpy to move the array values into the matrices
			std::memcpy(&a, setA, sizeof(Matrix4x3));
			std::memcpy(&b, setB, sizeof(Matrix4x3));
			std::memcpy(&expected, expectedSet, sizeof(Matrix4x3));

			actual = Math::MatrixMath::add(a, b);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Addition4x4)
		{
			Matrix4x4 a, b, expected, actual;

			const int nVals = sizeof(Matrix4x4) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] + setB[i];
			}

			// use memcpy to move the array values into the matrices
			std::memcpy(&a, setA, sizeof(Matrix4x4));
			std::memcpy(&b, setB, sizeof(Matrix4x4));
			std::memcpy(&expected, expectedSet, sizeof(Matrix4x4));

			actual = Math::MatrixMath::add(a, b);
			Assert::AreEqual(expected, actual);
		}

		// Subtraction
		TEST_METHOD(MatrixMath_Subtract2x1)
		{
			Matrix2x1 a, b, expected, actual;

			const int nVals = sizeof(Matrix2x1) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] - setB[i];
			}

			std::memcpy(&a, setA, sizeof(Matrix2x1));
			std::memcpy(&b, setB, sizeof(Matrix2x1));
			std::memcpy(&expected, expectedSet, sizeof(Matrix2x1));

			actual = Math::MatrixMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Subtract2x2)
		{
			Matrix2x2 a, b, expected, actual;

			const int nVals = sizeof(Matrix2x2) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] - setB[i];
			}

			std::memcpy(&a, setA, sizeof(Matrix2x2));
			std::memcpy(&b, setB, sizeof(Matrix2x2));
			std::memcpy(&expected, expectedSet, sizeof(Matrix2x2));

			actual = Math::MatrixMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Subtract3x1)
		{
			Matrix3x1 a, b, expected, actual;

			const int nVals = sizeof(Matrix3x1) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] - setB[i];
			}

			std::memcpy(&a, setA, sizeof(Matrix3x1));
			std::memcpy(&b, setB, sizeof(Matrix3x1));
			std::memcpy(&expected, expectedSet, sizeof(Matrix3x1));

			actual = Math::MatrixMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Subtract3x3)
		{
			Matrix3x3 a, b, expected, actual;

			const int nVals = sizeof(Matrix3x3) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] - setB[i];
			}

			std::memcpy(&a, setA, sizeof(Matrix3x3));
			std::memcpy(&b, setB, sizeof(Matrix3x3));
			std::memcpy(&expected, expectedSet, sizeof(Matrix3x3));

			actual = Math::MatrixMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Subtract4x1)
		{
			Matrix4x1 a, b, expected, actual;

			const int nVals = sizeof(Matrix4x1) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] - setB[i];
			}

			std::memcpy(&a, setA, sizeof(Matrix4x1));
			std::memcpy(&b, setB, sizeof(Matrix4x1));
			std::memcpy(&expected, expectedSet, sizeof(Matrix4x1));

			actual = Math::MatrixMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Subtract4x3)
		{
			Matrix4x3 a, b, expected, actual;

			const int nVals = sizeof(Matrix4x3) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] - setB[i];
			}

			std::memcpy(&a, setA, sizeof(Matrix4x3));
			std::memcpy(&b, setB, sizeof(Matrix4x3));
			std::memcpy(&expected, expectedSet, sizeof(Matrix4x3));

			actual = Math::MatrixMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Subtract4x4)
		{
			Matrix4x4 a, b, expected, actual;

			const int nVals = sizeof(Matrix4x4) / sizeof(float);

			float setA[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setA[i] = i;
			}

			float setB[nVals];
			for (int i = 0; i < nVals; i++)
			{
				setB[i] = setA[i] * i;
			}

			float expectedSet[nVals];
			for (int i = 0; i < nVals; i++)
			{
				expectedSet[i] = setA[i] - setB[i];
			}

			std::memcpy(&a, setA, sizeof(Matrix4x4));
			std::memcpy(&b, setB, sizeof(Matrix4x4));
			std::memcpy(&expected, expectedSet, sizeof(Matrix4x4));

			actual = Math::MatrixMath::subtract(a, b);

			Assert::AreEqual(expected, actual);
		}

		// multiplication, (many functions to test)


		// identifit matrix
		TEST_METHOD(MatrixMath_Identity2x2)
		{
			Matrix2x2 expected, actual;
			Math::MatrixMath::makeIdentity(actual);

			expected.r1c1 = 1.0f;
			expected.r1c2 = 0.0f;
			expected.r2c1 = 0.0f;
			expected.r2c2 = 1.0f;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Identity3x3)
		{
			Matrix3x3 expected, actual;
			Math::MatrixMath::makeIdentity(actual);

			expected.r1c1 = 1.0f;
			expected.r1c2 = 0.0f;
			expected.r1c3 = 0.0f;
			expected.r2c1 = 0.0f;
			expected.r2c2 = 1.0f;
			expected.r2c3 = 0.0f;
			expected.r3c1 = 0.0f;
			expected.r3c2 = 0.0f;
			expected.r3c3 = 1.0f;


			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(MatrixMath_Identity4x4)
		{
			Matrix4x4 expected, actual;
			Math::MatrixMath::makeIdentity(actual);

			expected.r1c1 = 1.0f;
			expected.r1c2 = 0.0f;
			expected.r1c3 = 0.0f;
			expected.r1c4 = 0.0f;
			expected.r2c1 = 0.0f;
			expected.r2c2 = 1.0f;
			expected.r2c3 = 0.0f;
			expected.r2c4 = 0.0f;
			expected.r3c1 = 0.0f;
			expected.r3c2 = 0.0f;
			expected.r3c3 = 1.0f;
			expected.r3c4 = 0.0f;
			expected.r4c1 = 0.0f;
			expected.r4c2 = 0.0f;
			expected.r4c3 = 0.0f;
			expected.r4c4 = 1.0f;


			Assert::AreEqual(expected, actual);
		}
	};
}