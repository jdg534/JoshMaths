#include <JoshMath.h>

#include <gtest/gtest.h>

#include <cstring> // for std:memcpy

using namespace Math::Types;

// Additions
GTEST_TEST(Matrix, Addition2x1)
{
	Matrix2x1 a, b, expectedResults, actualResults;
	a.r1c1 = 5;
	a.r2c1 = 6;
	b.r1c1 = 7;
	b.r2c1 = 8;

	expectedResults.r1c1 = 5 + 7;
	expectedResults.r2c1 = 6 + 8;
	actualResults = Math::Matrix::add(a, b);
	
	float * expIter = &expectedResults.r1c1;
	float * actIter = &actualResults.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Addition2x2)
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
	actualResults = Math::Matrix::add(a, b);
	
	float * expIter = &expectedResults.r1c1;
	float * actIter = &actualResults.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x2) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Addition3x1)
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
	actualResults = Math::Matrix::add(a, b);
	
	float * expIter = &expectedResults.r1c1;
	float * actIter = &actualResults.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Addition3x3)
{
	Matrix3x3 a, b, expectedResults, actualResults;

	a.r1c1 = b.r1c1 = 1.1f;
	a.r1c2 = b.r1c2 = 1.2f;
	a.r1c3 = b.r1c3 = 1.3f;
	a.r2c1 = b.r2c1 = 2.1f;
	a.r2c2 = b.r2c2 = 2.2f;
	a.r2c3 = b.r2c3 = 2.3f;
	a.r3c1 = b.r3c1 = 3.1f;
	a.r3c2 = b.r3c2 = 3.2f;
	a.r3c3 = b.r3c3 = 3.3f;

	actualResults = Math::Matrix::add(a, b);
	expectedResults.r1c1 = 1.1f + 1.1f;
	expectedResults.r1c2 = 1.2f + 1.2f;
	expectedResults.r1c3 = 1.3f + 1.3f;
	expectedResults.r2c1 = 2.1f + 2.1f;
	expectedResults.r2c2 = 2.2f + 2.2f;
	expectedResults.r2c3 = 2.3f + 2.3f;
	expectedResults.r3c1 = 3.1f + 3.1f;
	expectedResults.r3c2 = 3.2f + 3.2f;
	expectedResults.r3c3 = 3.3f + 3.3f;

	EXPECT_FLOAT_EQ(actualResults.r1c1, expectedResults.r1c1);
	EXPECT_FLOAT_EQ(actualResults.r1c2, expectedResults.r1c2);
	EXPECT_FLOAT_EQ(actualResults.r1c3, expectedResults.r1c3);
	EXPECT_FLOAT_EQ(actualResults.r2c1, expectedResults.r2c1);
	EXPECT_FLOAT_EQ(actualResults.r2c2, expectedResults.r2c2);
	EXPECT_FLOAT_EQ(actualResults.r2c3, expectedResults.r2c3);
	EXPECT_FLOAT_EQ(actualResults.r3c1, expectedResults.r3c1);
	EXPECT_FLOAT_EQ(actualResults.r3c2, expectedResults.r3c2);
	EXPECT_FLOAT_EQ(actualResults.r3c3, expectedResults.r3c3);
}

GTEST_TEST(Matrix, Addition4x1)
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

	actual = Math::Matrix::add(a, b);
	
	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Addition4x3)
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

	actual = Math::Matrix::add(a, b);
	
	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Addition4x4)
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

	actual = Math::Matrix::add(a, b);
	
	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x4) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

// Subtraction
GTEST_TEST(Matrix, Subtract2x1)
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

	actual = Math::Matrix::subtract(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Subtract2x2)
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

	actual = Math::Matrix::subtract(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x2) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Subtract3x1)
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

	actual = Math::Matrix::subtract(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Subtract3x3)
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

	actual = Math::Matrix::subtract(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Subtract4x1)
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

	actual = Math::Matrix::subtract(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Subtract4x3)
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

	actual = Math::Matrix::subtract(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Subtract4x4)
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

	actual = Math::Matrix::subtract(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x4) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

// multiplication, (many functions to test)
// scaler mul
GTEST_TEST(Matrix, scale2x1Mat)
{
	Matrix2x1 a, expected, actual;
	float scale = 2.0f;
	a.r1c1 = 1.0f;
	a.r2c1 = 2.0f;

	expected.r1c1 = 2.0f;
	expected.r2c1 = 4.0f;

	actual = Math::Matrix::multiply(scale, a);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, scale2x2Mat)
{
	Matrix2x2 a, expected, actual;
	float scale = 2.0f;
	a.r1c1 = 1.1f;
	a.r1c2 = 1.2f;
	a.r2c1 = 2.1f;
	a.r2c2 = 2.2f;

	expected.r1c1 = 2.2f;
	expected.r1c2 = 2.4f;
	expected.r2c1 = 4.2f;
	expected.r2c2 = 4.4f;

	actual = Math::Matrix::multiply(scale, a);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x2) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, scale3x1Mat)
{
	Matrix3x1 a, expected, actual;
	float scale = 2.0f;
	a.r1c1 = 1.0f;
	a.r2c1 = 2.0f;
	a.r3c1 = 3.0f;

	expected.r1c1 = 2.0f;
	expected.r2c1 = 4.0f;
	expected.r3c1 = 6.0f;

	actual = Math::Matrix::multiply(scale, a);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, scale3x3Mat)
{
	Matrix3x3 a, expected, actual;
	float scale = 2.0f;
	a.r1c1 = 1.1f;
	a.r1c2 = 1.2f;
	a.r1c3 = 1.3f;
	a.r2c1 = 2.1f;
	a.r2c2 = 2.2f;
	a.r2c3 = 2.3f;
	a.r3c1 = 3.1f;
	a.r3c2 = 3.2f;
	a.r3c3 = 3.3f;

	expected.r1c1 = 2.2f;
	expected.r1c2 = 2.4f;
	expected.r1c3 = 2.6f;
	expected.r2c1 = 4.2f;
	expected.r2c2 = 4.4f;
	expected.r2c3 = 4.6f;
	expected.r3c1 = 6.2f;
	expected.r3c2 = 6.4f;
	expected.r3c3 = 6.6f;

	actual = Math::Matrix::multiply(scale, a);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, scale4x1Mat)
{
	Matrix4x1 a, expected, actual;
	float scale = 2.0f;
	a.r1c1 = 1.0f;
	a.r2c1 = 2.0f;
	a.r3c1 = 3.0f;
	a.r4c1 = 4.0f;

	expected.r1c1 = 2.0f;
	expected.r2c1 = 4.0f;
	expected.r3c1 = 6.0f;
	expected.r4c1 = 8.0f;

	actual = Math::Matrix::multiply(scale, a);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, scale4x3Mat)
{
	Matrix4x3 a, expected, actual;
	float scale = 2.0f;
	a.r1c1 = 1.1f;
	a.r1c2 = 1.2f;
	a.r1c3 = 1.3f;
	a.r2c1 = 2.1f;
	a.r2c2 = 2.2f;
	a.r2c3 = 2.3f;
	a.r3c1 = 3.1f;
	a.r3c2 = 3.2f;
	a.r3c3 = 3.3f;
	a.r4c1 = 4.1f;
	a.r4c2 = 4.2f;
	a.r4c3 = 4.3f;

	expected.r1c1 = 2.2f;
	expected.r1c2 = 2.4f;
	expected.r1c3 = 2.6f;
	expected.r2c1 = 4.2f;
	expected.r2c2 = 4.4f;
	expected.r2c3 = 4.6f;
	expected.r3c1 = 6.2f;
	expected.r3c2 = 6.4f;
	expected.r3c3 = 6.6f;
	expected.r4c1 = 8.2f;
	expected.r4c2 = 8.4f;
	expected.r4c3 = 8.6f;

	actual = Math::Matrix::multiply(scale, a);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, scale4x4Mat)
{
	Matrix4x4 a, expected, actual;
	float scale = 2.0f;
	a.r1c1 = 1.1f;
	a.r1c2 = 1.2f;
	a.r1c3 = 1.3f;
	a.r1c4 = 1.4f;
	a.r2c1 = 2.1f;
	a.r2c2 = 2.2f;
	a.r2c3 = 2.3f;
	a.r2c4 = 2.4f;
	a.r3c1 = 3.1f;
	a.r3c2 = 3.2f;
	a.r3c3 = 3.3f;
	a.r3c4 = 3.4f;
	a.r4c1 = 4.1f;
	a.r4c2 = 4.2f;
	a.r4c3 = 4.3f;
	a.r4c4 = 4.4f;

	expected.r1c1 = 2.2f;
	expected.r1c2 = 2.4f;
	expected.r1c3 = 2.6f;
	expected.r1c4 = 2.8f;
	expected.r2c1 = 4.2f;
	expected.r2c2 = 4.4f;
	expected.r2c3 = 4.6f;
	expected.r2c4 = 4.8f;
	expected.r3c1 = 6.2f;
	expected.r3c2 = 6.4f;
	expected.r3c3 = 6.6f;
	expected.r3c4 = 6.8f;
	expected.r4c1 = 8.2f;
	expected.r4c2 = 8.4f;
	expected.r4c3 = 8.6f;
	expected.r4c4 = 8.8f;

	actual = Math::Matrix::multiply(scale, a);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x4) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

// multi with matrix mul
GTEST_TEST(MartixMath, Mul2x2With2x1)
{
	Matrix2x2 a;
	Matrix2x1 b, expected, actual;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r2c1 = 3;
	a.r2c2 = 4;

	b.r1c1 = 5;
	b.r2c1 = 6;

	expected.r1c1 = 17;
	expected.r2c1 = 39;

	actual = Math::Matrix::multiply(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul2x2With2x2)
{
	Matrix2x2 a, b, expected, actual;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r2c1 = 3;
	a.r2c2 = 4;

	b.r1c1 = 5;
	b.r1c2 = 6;
	b.r2c1 = 7;
	b.r2c2 = 8;

	expected.r1c1 = 19;
	expected.r1c2 = 22;
	expected.r2c1 = 43;
	expected.r2c2 = 50;

	actual = Math::Matrix::multiply(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x2) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul3x3With3x1)
{
	Matrix3x3 a;
	Matrix3x1 b, expected, actual;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r2c1 = 4;
	a.r2c2 = 5;
	a.r2c3 = 6;
	a.r3c1 = 7;
	a.r3c2 = 8;
	a.r3c3 = 9;

	b.r1c1 = 10;
	b.r2c1 = 11;
	b.r3c1 = 12;

	expected.r1c1 = 68;
	expected.r2c1 = 167;
	expected.r3c1 = 266;

	actual = Math::Matrix::multiply(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul3x3With3x3)
{
	Matrix3x3 a, b, expected, actual;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r2c1 = 4;
	a.r2c2 = 5;
	a.r2c3 = 6;
	a.r3c1 = 7;
	a.r3c2 = 8;
	a.r3c3 = 9;

	b.r1c1 = 10;
	b.r1c2 = 11;
	b.r1c3 = 12;
	b.r2c1 = 13;
	b.r2c2 = 14;
	b.r2c3 = 15;
	b.r3c1 = 16;
	b.r3c2 = 17;
	b.r3c3 = 18;

	expected.r1c1 = 84;
	expected.r1c2 = 90;
	expected.r1c3 = 96;
	expected.r2c1 = 201;
	expected.r2c2 = 216;
	expected.r2c3 = 231;
	expected.r3c1 = 318;
	expected.r3c2 = 342;
	expected.r3c3 = 366;

	actual = Math::Matrix::multiply(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul4x4With4x1)
{
	Matrix4x4 a;
	Matrix4x1 b, expected, actual;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r1c4 = 4;
	a.r2c1 = 5;
	a.r2c2 = 6;
	a.r2c3 = 7;
	a.r2c4 = 8;
	a.r3c1 = 9;
	a.r3c2 = 10;
	a.r3c3 = 11;
	a.r3c4 = 12;
	a.r4c1 = 13;
	a.r4c2 = 14;
	a.r4c3 = 15;
	a.r4c4 = 16;

	b.r1c1 = 17;
	b.r2c1 = 18;
	b.r3c1 = 19;
	b.r4c1 = 20;

	expected.r1c1 = 190;
	expected.r2c1 = 486;
	expected.r3c1 = 782;
	expected.r4c1 = 1078;

	actual = Math::Matrix::multiply(a, b);

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul4x4With4x3)
{
	Matrix4x4 a;
	Matrix4x3 b, exp, act;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r1c4 = 4;
	a.r2c1 = 5;
	a.r2c2 = 6;
	a.r2c3 = 7;
	a.r2c4 = 8;
	a.r3c1 = 9;
	a.r3c2 = 10;
	a.r3c3 = 11;
	a.r3c4 = 12;
	a.r4c1 = 13;
	a.r4c2 = 14;
	a.r4c3 = 15;
	a.r4c4 = 16;

	b.r1c1 = 17;
	b.r1c2 = 18;
	b.r1c3 = 19;
	b.r2c1 = 20;
	b.r2c2 = 21;
	b.r2c3 = 22;
	b.r3c1 = 23;
	b.r3c2 = 24;
	b.r3c3 = 25;
	b.r4c1 = 26;
	b.r4c2 = 27;
	b.r4c3 = 28;

	exp.r1c1 = 230;
	exp.r1c2 = 240;
	exp.r1c3 = 250;
	exp.r2c1 = 574;
	exp.r2c2 = 600;
	exp.r2c3 = 626;
	exp.r3c1 = 918;
	exp.r3c2 = 960;
	exp.r3c3 = 1002;
	exp.r4c1 = 1262;
	exp.r4c2 = 1320;
	exp.r4c3 = 1378;

	act = Math::Matrix::multiply(a, b);

	float * expIter = &exp.r1c1;
	float * actIter = &act.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul4x4With4x4)
{
	Matrix4x4 a, b, exp, act;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r1c4 = 4;
	a.r2c1 = 5;
	a.r2c2 = 6;
	a.r2c3 = 7;
	a.r2c4 = 8;
	a.r3c1 = 9;
	a.r3c2 = 10;
	a.r3c3 = 11;
	a.r3c4 = 12;
	a.r4c1 = 13;
	a.r4c2 = 14;
	a.r4c3 = 15;
	a.r4c4 = 16;

	b.r1c1 = 17;
	b.r1c2 = 18;
	b.r1c3 = 19;
	b.r1c4 = 20;
	b.r2c1 = 21;
	b.r2c2 = 22;
	b.r2c3 = 23;
	b.r2c4 = 24;
	b.r3c1 = 25;
	b.r3c2 = 26;
	b.r3c3 = 27;
	b.r3c4 = 28;
	b.r4c1 = 29;
	b.r4c2 = 30;
	b.r4c3 = 31;
	b.r4c4 = 32;

	exp.r1c1 = 250;
	exp.r1c2 = 260;
	exp.r1c3 = 270;
	exp.r1c4 = 280;

	exp.r2c1 = 618;
	exp.r2c2 = 644;
	exp.r2c3 = 670;
	exp.r2c4 = 696;

	exp.r3c1 = 986;
	exp.r3c2 = 1028;
	exp.r3c3 = 1070;
	exp.r3c4 = 1112;

	exp.r4c1 = 1354;
	exp.r4c2 = 1412;
	exp.r4c3 = 1470;
	exp.r4c4 = 1528;

	act = Math::Matrix::multiply(a, b);

	float * expIter = &exp.r1c1;
	float * actIter = &act.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x4) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul4x3With3x1)
{
	Matrix4x3 a;
	Matrix3x1 b;
	Matrix4x1 exp, act;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;

	a.r2c1 = 4;
	a.r2c2 = 5;
	a.r2c3 = 6;

	a.r3c1 = 7;
	a.r3c2 = 8;
	a.r3c3 = 9;

	a.r4c1 = 10;
	a.r4c2 = 11;
	a.r4c3 = 12;

	b.r1c1 = 13;
	b.r2c1 = 14;
	b.r3c1 = 15;

	exp.r1c1 = 86;
	exp.r2c1 = 212;
	exp.r3c1 = 338;
	exp.r4c1 = 464;

	act = Math::Matrix::multiply(a, b);
	
	float * expIter = &exp.r1c1;
	float * actIter = &act.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x1) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Mul4x3With3x3)
{
	Matrix4x3 a, exp, act;
	Matrix3x3 b;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r2c1 = 4;
	a.r2c2 = 5;
	a.r2c3 = 6;
	a.r3c1 = 7;
	a.r3c2 = 8;
	a.r3c3 = 9;
	a.r4c1 = 10;
	a.r4c2 = 11;
	a.r4c3 = 12;

	b.r1c1 = 13;
	b.r1c2 = 14;
	b.r1c3 = 15;
	b.r2c1 = 16;
	b.r2c2 = 17;
	b.r2c3 = 18;
	b.r3c1 = 19;
	b.r3c2 = 20;
	b.r3c3 = 21;

	exp.r1c1 = 102;
	exp.r1c2 = 108;
	exp.r1c3 = 114;
	exp.r2c1 = 246;
	exp.r2c2 = 261;
	exp.r2c3 = 276;
	exp.r3c1 = 390;
	exp.r3c2 = 414;
	exp.r3c3 = 438;
	exp.r4c1 = 534;
	exp.r4c2 = 567;
	exp.r4c3 = 600;



	act = Math::Matrix::multiply(a, b);

	float * expIter = &exp.r1c1;
	float * actIter = &act.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

// determinant
GTEST_TEST(Matrix, determinant2x2)
{
	Matrix2x2 in;
	in.r1c1 = 1;
	in.r1c2 = 2;
	in.r2c1 = 3;
	in.r2c2 = 4;

	float expected = -2.0f;
	float actual = Math::Matrix::determinant(in);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(Matrix, determinant3x3)
{
	Matrix3x3 in;
	float expected, actual;
	in.r1c1 = 7;
	in.r1c2 = 8;
	in.r1c3 = 9;
	in.r2c1 = 50;
	in.r2c2 = 58;
	in.r2c3 = 81;
	in.r3c1 = 64;
	in.r3c2 = 21;
	in.r3c3 = 5;

	expected = 5637;

	actual = Math::Matrix::determinant(in);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(Matrix, determinant4x4)
{
	Matrix4x4 in;

	in.r1c1 = 1.0f; in.r1c2 = 2.0f; in.r1c3 = 3.0f; in.r1c4 = 4.0f;
	in.r2c1 = 5.0f; in.r2c2 = 6.0f; in.r2c3 = 7.0f; in.r2c4 = 8.0f;
	in.r3c1 = 9.0f; in.r3c2 = 10.0f; in.r3c3 = 11.0f; in.r3c4 = 12.0f;
	in.r4c1 = 13.0f; in.r4c2 = 14.0f; in.r4c3 = 15.0f; in.r4c4 = 16.0f;
	
	const float ExpectedPosA = in.r1c1 * in.r2c2 * in.r3c3 * in.r4c4;
	const float ExpectedPosB = in.r1c2 * in.r2c3 * in.r3c4 * in.r4c1;
	const float ExpectedPosC = in.r1c3 * in.r2c4 * in.r3c1 * in.r4c2;
	const float ExpectedPosD = in.r1c4 * in.r2c1 * in.r3c2 * in.r4c3;
	const float ExpectedNegA = in.r1c4 * in.r2c3 * in.r3c2 * in.r4c1;
	const float ExpectedNegB = in.r1c3 * in.r2c2 * in.r3c1 * in.r4c4;
	const float ExpectedNegC = in.r1c2 * in.r2c1 * in.r3c4 * in.r4c3;
	const float ExpectedNegD = in.r1c1 * in.r2c4 * in.r3c3 * in.r4c2;

	const float expected = ExpectedPosA + ExpectedPosB + ExpectedPosC + ExpectedPosD
		- ExpectedNegA -  ExpectedNegB - ExpectedNegC - ExpectedNegD;

	const float actual = Math::Matrix::determinant(in);
	EXPECT_FLOAT_EQ(expected, actual);
}

// transpose
GTEST_TEST(Matrix, Transpose2x2)
{
	Matrix2x2 a, exp, act;
	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r2c1 = 3;
	a.r2c2 = 4;

	exp.r1c1 = 1;
	exp.r1c2 = 3;
	exp.r2c1 = 2;
	exp.r2c2 = 4;

	act = Math::Matrix::transpose(a);

	float * expIter = &exp.r1c1;
	float * actIter = &act.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x2) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Transpose3x3)
{
	Matrix3x3 a, exp, act;
	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r2c1 = 4;
	a.r2c2 = 5;
	a.r2c3 = 6;
	a.r3c1 = 7;
	a.r3c2 = 8;
	a.r3c3 = 9;

	exp.r1c1 = 1;
	exp.r1c2 = 4;
	exp.r1c3 = 7;
	exp.r2c1 = 2;
	exp.r2c2 = 5;
	exp.r2c3 = 8;
	exp.r3c1 = 3;
	exp.r3c2 = 6;
	exp.r3c3 = 9;

	act = Math::Matrix::transpose(a);

	float * expIter = &exp.r1c1;
	float * actIter = &act.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Transpose4x4)
{
	Matrix4x4 a, exp, act;

	a.r1c1 = 1;
	a.r1c2 = 2;
	a.r1c3 = 3;
	a.r1c4 = 4;

	a.r2c1 = 5;
	a.r2c2 = 6;
	a.r2c3 = 7;
	a.r2c4 = 8;

	a.r3c1 = 9;
	a.r3c2 = 10;
	a.r3c3 = 11;
	a.r3c4 = 12;

	a.r4c1 = 13;
	a.r4c2 = 14;
	a.r4c3 = 15;
	a.r4c4 = 16;

	exp.r1c1 = 1;
	exp.r1c2 = 5;
	exp.r1c3 = 9;
	exp.r1c4 = 13;
	exp.r2c1 = 2;
	exp.r2c2 = 6;
	exp.r2c3 = 10;
	exp.r2c4 = 14;
	exp.r3c1 = 3;
	exp.r3c2 = 7;
	exp.r3c3 = 11;
	exp.r3c4 = 15;
	exp.r4c1 = 4;
	exp.r4c2 = 8;
	exp.r4c3 = 12;
	exp.r4c4 = 16;

	act = Math::Matrix::transpose(a);

	float * expIter = &exp.r1c1;
	float * actIter = &act.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x4) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

// inverse
GTEST_TEST(Matrix, Inverse2x2)
{
	Matrix2x2 in;

	Matrix2x2 expected, actual;

	in.r1c1 = 7;
	in.r1c2 = 5;
	in.r2c1 = 11;
	in.r2c2 = 21;

	actual = Math::Matrix::inverse(in);

	//expected.r1c1 = -21/92;
	//expected.r1c2 = -5 / 92;
	//expected.r2c1 = -11 / 92;
	//expected.r2c2 = 7 / 92;
	expected.r1c1 = 21.0f / 92.0f;
	expected.r1c2 = -5.0f / 92.0f;
	expected.r2c1 = -11.0f / 92.0f;
	expected.r2c2 = 7.0f / 92.0f;

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x2) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Inverse3x3)
{
	Matrix3x3 in, expected, actual;

	in.r1c1 = 7;
	in.r1c2 = 5;
	in.r1c3 = 6;
	in.r2c1 = 11;
	in.r2c2 = 21;
	in.r2c3 = 8;
	in.r3c1 = 9;
	in.r3c2 = 45;
	in.r3c3 = 78;

	actual = Math::Matrix::inverse(in);

	expected.r1c1 = 213.0f / 1142.0f;
	expected.r1c2 = -10.0f / 571.0f;
	expected.r1c3 = -43.0f / 3426.0f;

	expected.r2c1 = -131.0f / 1142.0f;
	expected.r2c2 = 41.0f / 571.0f;
	expected.r2c3 = 5.0f / 3426.0f;

	expected.r3c1 = 51.0f / 1142.0f;
	expected.r3c2 = -45.0f / 1142.0f;
	expected.r3c3 = 23.0f / 1713.0f;

	EXPECT_FLOAT_EQ(expected.r1c1, expected.r1c1);
	EXPECT_FLOAT_EQ(expected.r1c2, expected.r1c2);
	EXPECT_FLOAT_EQ(expected.r1c3, expected.r1c3);

	EXPECT_FLOAT_EQ(expected.r2c1, expected.r2c1);
	EXPECT_FLOAT_EQ(expected.r2c2, expected.r2c2);
	EXPECT_FLOAT_EQ(expected.r2c3, expected.r2c3);

	EXPECT_FLOAT_EQ(expected.r3c1, expected.r3c1);
	EXPECT_FLOAT_EQ(expected.r3c2, expected.r3c2);
	EXPECT_FLOAT_EQ(expected.r3c3, expected.r3c3);
}

// identy matrix
GTEST_TEST(Matrix, Identity2x2)
{
	Matrix2x2 expected, actual;
	Math::Matrix::makeIdentity(actual);

	expected.r1c1 = 1.0f;
	expected.r1c2 = 0.0f;
	expected.r2c1 = 0.0f;
	expected.r2c2 = 1.0f;
	
	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix2x2) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Identity3x3)
{
	Matrix3x3 expected, actual;
	Math::Matrix::makeIdentity(actual);

	expected.r1c1 = 1.0f;
	expected.r1c2 = 0.0f;
	expected.r1c3 = 0.0f;
	expected.r2c1 = 0.0f;
	expected.r2c2 = 1.0f;
	expected.r2c3 = 0.0f;
	expected.r3c1 = 0.0f;
	expected.r3c2 = 0.0f;
	expected.r3c3 = 1.0f;

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix3x3) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

GTEST_TEST(Matrix, Identity4x4)
{
	Matrix4x4 expected, actual;
	Math::Matrix::makeIdentity(actual);

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

	float * expIter = &expected.r1c1;
	float * actIter = &actual.r1c1;

	for (size_t i = 0; i < (sizeof(Matrix4x4) / sizeof(float)); ++i)
	{
		EXPECT_FLOAT_EQ(*expIter, *actIter);
		++expIter;
		++actIter;
	}
}

// get identity
GTEST_TEST(Matrix, GetIdentity2x2)
{
	const Matrix2x2 id = Math::Matrix::identity2x2();
	EXPECT_FLOAT_EQ(id.r1c1, 1.0f);
	EXPECT_FLOAT_EQ(id.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(id.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(id.r2c2, 1.0f);
}

GTEST_TEST(Matrix, GetIdentity3x3)
{
	const Matrix3x3 z = Math::Matrix::identity3x3();
	EXPECT_FLOAT_EQ(z.r1c1, 1.0f);
	EXPECT_FLOAT_EQ(z.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c3, 0.0f);

	EXPECT_FLOAT_EQ(z.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c2, 1.0f);
	EXPECT_FLOAT_EQ(z.r2c3, 0.0f);

	EXPECT_FLOAT_EQ(z.r3c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c3, 1.0f);
}

GTEST_TEST(Matrix, GetIdentity4x4)
{
	const Matrix4x4 z = Math::Matrix::identity4x4();
	EXPECT_FLOAT_EQ(z.r1c1, 1.0f);
	EXPECT_FLOAT_EQ(z.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c3, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c4, 0.0f);

	EXPECT_FLOAT_EQ(z.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c2, 1.0f);
	EXPECT_FLOAT_EQ(z.r2c3, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c4, 0.0f);

	EXPECT_FLOAT_EQ(z.r3c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c3, 1.0f);
	EXPECT_FLOAT_EQ(z.r3c4, 0.0f);

	EXPECT_FLOAT_EQ(z.r4c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r4c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r4c3, 0.0f);
	EXPECT_FLOAT_EQ(z.r4c4, 1.0f);
}

// get zero
GTEST_TEST(Matrix, GetZero2x2)
{
	const Matrix2x2 z = Math::Matrix::zero2x2();
	EXPECT_FLOAT_EQ(z.r1c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c2, 0.0f);

	EXPECT_FLOAT_EQ(z.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c2, 0.0f);
}

GTEST_TEST(Matrix, GetZero3x3)
{
	const Matrix3x3 z = Math::Matrix::zero3x3();
	EXPECT_FLOAT_EQ(z.r1c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c3, 0.0f);

	EXPECT_FLOAT_EQ(z.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c3, 0.0f);

	EXPECT_FLOAT_EQ(z.r3c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c3, 0.0f);
}

GTEST_TEST(Matrix, GetZero4x4)
{
	const Matrix4x4 z = Math::Matrix::zero4x4();
	EXPECT_FLOAT_EQ(z.r1c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c3, 0.0f);
	EXPECT_FLOAT_EQ(z.r1c4, 0.0f);

	EXPECT_FLOAT_EQ(z.r2c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c3, 0.0f);
	EXPECT_FLOAT_EQ(z.r2c4, 0.0f);
	
	EXPECT_FLOAT_EQ(z.r3c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c3, 0.0f);
	EXPECT_FLOAT_EQ(z.r3c4, 0.0f);

	EXPECT_FLOAT_EQ(z.r4c1, 0.0f);
	EXPECT_FLOAT_EQ(z.r4c2, 0.0f);
	EXPECT_FLOAT_EQ(z.r4c3, 0.0f);
	EXPECT_FLOAT_EQ(z.r4c4, 0.0f);
}
