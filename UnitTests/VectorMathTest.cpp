#include <gtest/gtest.h>
#include <JoshMath.h>

using namespace Math::Types;

GTEST_TEST(VectorTest, Adding2D)
{
	Vector2D a, b;
	Vector2D results;

	a.x = 1.1f;
	a.y = 2.2f;
	b.x = 3.3f;
	b.y = 4.4f;

	results = Math::Vector::add(a, b);


	EXPECT_FLOAT_EQ(4.4f, results.x);
	EXPECT_FLOAT_EQ(6.6f, results.y);
}

GTEST_TEST(VectorTest, Adding3D)
{
	Vector3D a, b;
	Vector3D results;

	a.x = 1.1f;
	a.y = 2.2f;
	a.z = 5.5f;
	b.x = 3.3f;
	b.y = 4.4f;
	b.z = 6.6f;

	results = Math::Vector::add(a, b);


	EXPECT_FLOAT_EQ(4.4f, results.x);
	EXPECT_FLOAT_EQ(6.6f, results.y);
	EXPECT_FLOAT_EQ(12.1f, results.z);
}

GTEST_TEST(VectorTest, Subtraction2D)
{
	Vector2D a, b, actual, expected;
	a.x = b.x = 12.752f;
	a.y = b.y = 1324.43f;

	expected.x = expected.y = 0.0f;
	actual = Math::Vector::subtract(a, b);

	EXPECT_FLOAT_EQ(expected.x, actual.x);
	EXPECT_FLOAT_EQ(expected.y, actual.y);
}

GTEST_TEST(VectorTest, Subtraction3D)
{
	Vector3D a, b, actual, expected;
	a.x = b.x = 12.752f;
	a.y = b.y = 1324.43f;
	a.z = b.z = 534.123f;

	expected.x = expected.y = expected.z = 0.0f;
	actual = Math::Vector::subtract(a, b);

	EXPECT_FLOAT_EQ(expected.x, actual.x);
	EXPECT_FLOAT_EQ(expected.y, actual.y);
	EXPECT_FLOAT_EQ(expected.z, actual.z);
}

GTEST_TEST(VectorTest, WayTo2D)
{
	Vector2D pointOfOrigin, targetPoint, expectedResults, actualResults;
	pointOfOrigin.x = 77.8271f;
	pointOfOrigin.y = 151.561f;
	targetPoint.x = 81.73f;
	targetPoint.y = 123.456f;

	expectedResults.x = targetPoint.x - pointOfOrigin.x;
	expectedResults.y = targetPoint.y - pointOfOrigin.y;

	actualResults = Math::Vector::wayToVector(pointOfOrigin, targetPoint);
	EXPECT_FLOAT_EQ(expectedResults.x, actualResults.x);
	EXPECT_FLOAT_EQ(expectedResults.y, actualResults.y);
}

GTEST_TEST(VectorTest, WayTo3D)
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

	actualResults = Math::Vector::wayToVector(pointOfOrigin, targetPoint);
	
	EXPECT_FLOAT_EQ(expectedResults.x, actualResults.x);
	EXPECT_FLOAT_EQ(expectedResults.y, actualResults.y);
	EXPECT_FLOAT_EQ(expectedResults.z, actualResults.z);
}

// mag
GTEST_TEST(VectorTest, Mag2D)
{
	Vector2D in;

	in.x = 7.32f;
	in.y = 4.12f;

	float expected, actual;

	expected = 8.399808522f;// done via scientific calcultor
	actual = Math::Vector::magnitude(in);

	// Assert::AreEqual(expected, actual);// fails (floating point rounding error)
	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(VectorTest, Mag3D)
{
	Vector3D in;

	in.x = 7.32f;
	in.y = 4.12f;
	in.z = 2.01f;

	float expected, actual;

	expected = 8.636949693f; // scienticif calculator

	actual = Math::Vector::magnitude(in);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(VectorTest, MagSqurd2D)
{
	Vector2D in;

	in.x = 7.32f;
	in.y = 4.12f;

	float expected, actual;

	expected = 70.5568f;

	actual = Math::Vector::magnitudeSquared(in);


	// Assert::AreEqual(expected, actual);// fails (floating point rounding error)
	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(VectorTest, MagSqurd3D)
{
	Vector3D in;

	in.x = 7.32f;
	in.y = 4.12f;
	in.z = 2.01f;

	float expected, actual;

	expected = 74.5969f;

	actual = Math::Vector::magnitudeSquared(in);

	EXPECT_FLOAT_EQ(expected, actual);
}

// scale
GTEST_TEST(VectorTest, Scale2D)
{
	float scale = 2.0f;
	Vector2D input, expected, actual;
	input.x = 5.0f;
	input.y = 50.0f;

	actual = Math::Vector::scaled(scale, input);

	expected.x = 10.0f;
	expected.y = 100.0f;

	EXPECT_FLOAT_EQ(expected.x, actual.x);
	EXPECT_FLOAT_EQ(expected.y, actual.y);
}

GTEST_TEST(VectorTest, Scale3D)
{
	float scale = 2.0f;
	Vector3D input, expected, actual;
	input.x = 5.0f;
	input.y = 50.0f;
	input.z = 500.0f;

	actual = Math::Vector::scaled(scale, input);

	expected.x = 10.0f;
	expected.y = 100.0f;
	expected.z = 1000.0f;

	EXPECT_FLOAT_EQ(expected.x, actual.x);
	EXPECT_FLOAT_EQ(expected.y, actual.y);
	EXPECT_FLOAT_EQ(expected.z, actual.z);
}

// unit vector
GTEST_TEST(VectorTest, UnitVec2D)
{
	Vector2D in, expected, actual;
	in.x = 100.0f;
	in.y = 300.0f;

	// calculated with notepad++ & windows calculator
	expected.x = 0.316227766016837933199889354443;
	expected.y = 0.948683298050513799599668063329;

	actual = Math::Vector::unitVector(in);

	float expectedMag = 1.0f;

	float actualMag = Math::Vector::magnitude(actual);


	EXPECT_FLOAT_EQ(expectedMag, actualMag);
	EXPECT_FLOAT_EQ(expected.x, actual.x);
	EXPECT_FLOAT_EQ(expected.y, actual.y);
}

GTEST_TEST(VectorTest, UnitVec3D)
{
	Vector3D in, exp, actual;

	in.x = in.y = in.z = 55.0f;

	actual = Math::Vector::unitVector(in);
	
	// // calculated with notepad++ & windows calculator
	exp.x = exp.y = exp.z = 0.57735026918962576450914878050215;

	float expectedMag = 1.0f,
		actualMag = Math::Vector::magnitude(actual);

	EXPECT_FLOAT_EQ(expectedMag, actualMag);
	EXPECT_FLOAT_EQ(exp.x, actual.x);
	EXPECT_FLOAT_EQ(exp.y, actual.y);
	EXPECT_FLOAT_EQ(exp.z, actual.z);
}

// dot product
GTEST_TEST(VectorTest, DotProd2D)
{
	Vector2D a, b;

	a.x = 1;
	a.y = 12;

	b.x = -3;
	b.y = 27;

	float exp, act;

	exp = 321;
	act = Math::Vector::dotProduct(a, b);


	EXPECT_FLOAT_EQ(exp, act);
}

GTEST_TEST(VectorTest, DotProd3D)
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
	act = Math::Vector::dotProduct(a, b);


	EXPECT_FLOAT_EQ(exp, act);
}

/* un comment once merged the altDotProduct back into this branch
// alt dot product
GTEST_TEST(VectorTest, AltDotProd2D)
{
	Vector2D a, b;

	a.x = 1;
	a.y = 12;

	b.x = -3;
	b.y = 27;

	float exp, act;

	exp = 321;
	act = Math::Vector::altDotProduct(a, b);


	EXPECT_FLOAT_EQ(exp, act);
}

GTEST_TEST(Vector_AltDotProd3D)
{
	Vector3D a, b;

	float expected, actual;

	a.x = 10;
	a.y = 27;
	a.z = 32;

	b.x = 5;
	b.y = 3;
	b.z = 4;

	expected = 259.0f;
	// expected = Math::degreesToRadians(expected);

	actual = Math::Vector::altDotProduct(a, b);

	Assert::AreEqual(expected, actual);
}
*/

// cross product
GTEST_TEST(VectorTest, Cross3D)
{
	Vector3D a, b, exp, act;

	a.x = 2.0f;
	a.y = 2.0f;
	a.z = 1.0f;

	b.x = 1.0f;
	b.y = -2.0f;
	b.z = 0.0f;

	act = Math::Vector::crossProduct(a, b);

	exp.x = 2.0f;
	exp.y = 1.0f;
	exp.z = -6.0f;

	EXPECT_FLOAT_EQ(exp.x, act.x);
	EXPECT_FLOAT_EQ(exp.y, act.y);
	EXPECT_FLOAT_EQ(exp.z, act.z);
}


// look at
GTEST_TEST(VectorTest, LookAt2D)
{
	Vector2D lookFromPoint, currentLookAtPoint, nextLookAtPoint;

	float expected, actual;

	lookFromPoint.x = lookFromPoint.y = 0.0f;

	currentLookAtPoint.x = 90.0f;
	currentLookAtPoint.y = 0.0f;

	nextLookAtPoint.x = 0.0f;
	nextLookAtPoint.y = 90.0f;

	expected = 90.0f; // need to convert to radians
	expected = Math::Conversion::degreesToRadians(expected);

	actual = Math::Vector::lookAt2D(currentLookAtPoint, nextLookAtPoint, lookFromPoint);

	EXPECT_FLOAT_EQ(expected, actual);
}

/*  add these once the main Math code has been moved back into this branch
TEST_METHOD(Vector_LookAt3D)
{
	Assert::AreEqual(1, 0);
}

// angle between
TEST_METHOD(Vector_angleBetween2D)
{
	Vector2D a, b;
	a.x = 45.0f;
	a.y = 45.0f;

	b.x = -45.0f;
	b.y = 45.0f;

	float expected, actual;
	expected = 90.0f; // to rads
	expected = Math::degreesToRadians(expected);
	actual = Math::Vector::angleBetween(a, b);

	Assert::AreEqual(expected, actual);
}

TEST_METHOD(Vector_angleBetween3D)
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
	actual = Math::Vector::angleBetween(a, b);

	// Assert::AreEqual(expected, actual); // fails, but due to floating point rounding error
	Assert::AreEqual(1, 1); // the above fails due to floating point rounding errors
}
*/