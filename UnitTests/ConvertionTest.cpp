#include <gtest/gtest.h>
#include <JoshMath.h>

GTEST_TEST(Convetion, DegreesToRadians)
{
	float degreeValue = 57.62f;

	float expectedResults = 1.0056587f;

	float actualResults = Math::degreesToRadians(degreeValue);

	EXPECT_FLOAT_EQ(expectedResults, actualResults);
}

GTEST_TEST(Convetion, RadiansToDegrees)
{
	// not exactly the same, but close enough (floating point rounding issues)
	float radianValue = 5.372f;

	float expectedValue = 307.79293f;

	float actualResults = Math::radiansToDegrees(radianValue);

	EXPECT_FLOAT_EQ(expectedValue, actualResults);
}

GTEST_TEST(Convetion, CartesianToPolar)
{
	// not exactly the same, but close enough (floating point rounding issues)

	Vector2D input;
	PolarCoordinate expectedRes, actualRes;
	// angle in rads not degrees

	input.x = 3.53553f;
	input.y = 3.53553f;

	expectedRes.radius = 5.0f;
	expectedRes.angle = 45.0f;
	expectedRes.angle = Math::degreesToRadians(expectedRes.angle);

	actualRes = Math::PolarCoordinateMath::CartesianToPolar(input);

	// Assert::AreEqual(1, 1); // the below test only fails from floating point rounding errors, by the values are close enough
	//Assert::AreEqual(expectedRes, actualRes);
	EXPECT_FLOAT_EQ(expectedRes.angle, actualRes.angle);
	EXPECT_FLOAT_EQ(expectedRes.radius, actualRes.radius);
	// https://www.mathsisfun.com/polar-cartesian-coordinates.html
}

GTEST_TEST(Convetion, PolarToCartesian)
{
	// angle in rads not degrees
	PolarCoordinate input;

	Vector2D expectedResults, actualResults;

	input.angle = Math::degreesToRadians(45.0f);
	input.radius = 5.0f;

	expectedResults.x = 3.53553f;
	expectedResults.y = 3.53553f;

	actualResults = Math::PolarCoordinateMath::PolarToCartesian(input);

	// Assert::AreEqual(expectedResults, actualResults);
	// Assert::AreEqual(1, 1); // above failed due to floating point rounding errors
	EXPECT_FLOAT_EQ(expectedResults.x, actualResults.x);
	EXPECT_FLOAT_EQ(expectedResults.y, actualResults.y);
}