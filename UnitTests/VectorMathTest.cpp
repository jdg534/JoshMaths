#include <gtest/gtest.h>
#include "../JoshMath/Math.h"

TEST(VectorMathTest, AddingWorks2D)
{
	Vector2D a, b;
	Vector2D results;

	a.x = 1.1f;
	a.y = 2.2f;
	b.x = 3.3f;
	b.y = 4.4f;

	results = Math::VectorMath::add(a, b);


	EXPECT_FLOAT_EQ(results.x, 4.4f);
	EXPECT_FLOAT_EQ(results.y, 6.6f);
}

TEST(VectorMathTest, AddingWorks3D)
{
	Vector3D a, b;
	Vector3D results;

	a.x = 1.1f;
	a.y = 2.2f;
	a.z = 5.5f;
	b.x = 3.3f;
	b.y = 4.4f;
	b.z = 6.6f;

	results = Math::VectorMath::add(a, b);


	EXPECT_FLOAT_EQ(results.x, 4.4f);
	EXPECT_FLOAT_EQ(results.y, 6.6f);
	EXPECT_FLOAT_EQ(results.z, 12.1f);
}