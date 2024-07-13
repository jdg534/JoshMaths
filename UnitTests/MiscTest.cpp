#include <gtest/gtest.h>
#include <JoshMath.h>

// just diff and the parabola function
GTEST_TEST(MiscTest, diffWorks)
{
	float a, b, expected, actual;
	a = 10.0f;
	b = 15.0f;

	expected = 5.0f;

	actual = Math::Miscellaneous::diff(a, b);
	EXPECT_FLOAT_EQ(expected, actual);
}
