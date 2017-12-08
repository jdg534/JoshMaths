#include <gtest/gtest.h>
#include "../JoshMath/JoshMath.h"

// just diff and the parabola function
TEST(MiscTest, diffWorks)
{
	float a, b, expected, actual;
	a = 10.0f;
	b = 15.0f;

	expected = 5.0f;

	actual = Math::Miscellaneous::diff(a, b);
	EXPECT_FLOAT_EQ(expected, actual);
}

TEST(MiscTest, parabolaWorks)
{
	float expected, actual;

	Vector2D point, parabolaCentre;

	float parabolaRadius = 10.0f;

	point.x = point.y = 5.0f;

	parabolaCentre.x = parabolaCentre.y = 0.0f;

	actual = Math::Miscellaneous::parabola(point, parabolaCentre, parabolaRadius);

	expected = 0.5f;

	EXPECT_FLOAT_EQ(expected, actual);
}