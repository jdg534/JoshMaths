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

	//Assert::AreEqual(expectedRes, actualRes); // test only fails from floating point rounding errors, by the values are close enough
	constexpr float tolerance = 0.001f;
	EXPECT_LT(std::abs(expectedRes.angle - actualRes.angle), tolerance);
	EXPECT_LT(std::abs(expectedRes.radius - actualRes.radius), tolerance);
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

	// EXPECT_FLOAT_EQ(expectedResults.x, actualResults.x); // test only fails from floating point rounding errors, by the values are close enough
	// EXPECT_FLOAT_EQ(expectedResults.y, actualResults.y); // test only fails from floating point rounding errors, by the values are close enough
	constexpr float tolerance = 0.001f;
	
	EXPECT_LT(std::abs(expectedResults.x - actualResults.x), tolerance);
	EXPECT_LT(std::abs(expectedResults.y - actualResults.y), tolerance);
}