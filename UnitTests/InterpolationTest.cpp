#include <gtest/gtest.h>

#include <JoshMath.h>

GTEST_TEST(Interpolation, Lerp)
{
	float min, max, weight, expected, actual;

	min = 25.0f;
	max = 75.0f;
	weight = 0.5f;
	expected = 50.0f;
	actual = Math::Interpolation::lerp(min, max, weight);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(Interpolation, CalcWeightingValue)
{
	float min, max, target, expected, actual;

	min = 25.0f;
	max = 75.0f;
	target = 50.0f;

	expected = 0.5f;
	actual = Math::Interpolation::interpolationWeight(min, max, target);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(Interpolatio, CalcWeightingValueGive1IfMinSameAsMax)
{
	float min, max, target, expected, actual;

	min = max = 100.0f;

	target = 111.0f;

	expected = 1.0f;

	actual = Math::Interpolation::interpolationWeight(min, max, target);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(Interpolation, BiLerp)
{
	float expected, actual,
		a0, a1,
		b0, b1,
		tx, ty;

	a0 = 10.0f;
	a1 = 20.0f;

	b0 = 7.0f;
	b1 = 14.0f;

	tx = 0.4f;
	ty = 0.8f;

	actual = Math::Interpolation::biLerp(a0, a1, b0, b1, tx, ty);

	expected = 10.64f;


	EXPECT_FLOAT_EQ(expected, actual);

	// Assert::AreEqual(1, 1); // float rounding errors
}

GTEST_TEST(Interpolation, TriLerp)
{
	float exp, act;

	float fa0, fa1,
		fb0, fb1;
	float ra0, ra1,
		rb0, rb1;

	float tx, ty, tz;

	tx = 0.4f;
	ty = 0.6f;
	tz = 0.2f;

	fa0 = 10.0f;
	fa1 = 20.0f;

	fb0 = 51.0f;
	fb1 = 21.0f;

	ra0 = 32.0f;
	ra1 = 91.0f;
	rb0 = -7.0f;
	rb1 = 100.0f;

	act = Math::Interpolation::triLerp(fa0, fa1, fb0, fb1,
		ra0, ra1, rb0, rb1, tx, ty, tz);

	exp = 31.944f;

	EXPECT_FLOAT_EQ(exp, act);
}

GTEST_TEST(Interpolation, VectorLerp2D)
{
	Vector2D a, b,
		exp, act;
	float t = 0.5f;

	a.x = 50.0f;
	a.y = 0.0f;

	b.x = 100.0f;
	b.y = 20.0f;

	exp.x = 75.0f;
	exp.y = 10.0f;

	act = Math::Interpolation::lerp(a, b, t);

	EXPECT_FLOAT_EQ(exp.x, act.x);
	EXPECT_FLOAT_EQ(exp.y, act.y);
}

GTEST_TEST(Interpolation, VectorLerp3D)
{
	Vector3D a, b,
		exp, act;
	float t = 0.5f;

	a.x = 50.0f;
	a.y = 0.0f;
	a.z = 500.0f;

	b.x = 100.0f;
	b.y = 20.0f;
	b.z = 100.0f;

	exp.x = 75.0f;
	exp.y = 10.0f;
	exp.z = 300.0f;

	act = Math::Interpolation::lerp(a, b, t);

	EXPECT_FLOAT_EQ(exp.x, act.x);
	EXPECT_FLOAT_EQ(exp.y, act.y);
	EXPECT_FLOAT_EQ(exp.z, act.z);
}

GTEST_TEST(Interpolation, QuaternionLerp)
{
	Quaternion a, b, expected, actual;

	float weight = 0.5f;

	a.x = 1.0f;
	a.y = 2.0f;
	a.z = 3.0f;
	a.w = 4.0f;

	b.x = 2.0f;
	b.y = 4.0f;
	b.z = 6.0f;
	b.w = 8.0f;

	expected.x = 1.5f;
	expected.y = 3.0f;
	expected.z = 4.5f;
	expected.w = 6.0f;

	actual = Math::Interpolation::lerp(a, b, weight);

	EXPECT_FLOAT_EQ(expected.w, actual.w);
	EXPECT_FLOAT_EQ(expected.x, actual.x);
	EXPECT_FLOAT_EQ(expected.y, actual.y);
	EXPECT_FLOAT_EQ(expected.z, actual.z);
}

GTEST_TEST(Interpolation, SmoothstepClampsMin)
{
	const float x = -5.0f;
	const float min = 0.0f;
	const float max = 1.0f;
	const float xSmoothStep = Math::Interpolation::smoothStep(min, max, x);
	EXPECT_TRUE(xSmoothStep >= min);
}

GTEST_TEST(Interpolation, SmoothstepClampsMax)
{
	const float x = -5.0f;
	const float min = 0.0f;
	const float max = 1.0f;
	const float xSmoothStep = Math::Interpolation::smoothStep(min, max, x);
	EXPECT_TRUE(xSmoothStep <= max);
}

GTEST_TEST(Interpolation, SmoothstepLessThanLerpPreMidPoint)
{
	const float x = 0.25f;
	const float min = 0.0f;
	const float max = 1.0f;
	const float xSmoothStep = Math::Interpolation::smoothStep(min, max, x);
	const float xLerp = Math::Interpolation::lerp(min, max, x);
	EXPECT_TRUE(xSmoothStep < xLerp);
}

GTEST_TEST(Interpolation, SmoothstepGreaterThanLerpPostMidPoint)
{
	const float x = 0.75f;
	const float min = 0.0f;
	const float max = 1.0f;
	const float xSmoothStep = Math::Interpolation::smoothStep(min, max, x);
	const float xLerp = Math::Interpolation::lerp(min, max, x);
	EXPECT_TRUE(xSmoothStep > xLerp);
}
