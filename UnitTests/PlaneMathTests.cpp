#include <gtest/gtest.h>
#include <string>
#include "../JoshMath/JoshMath.h"

GTEST_TEST(PlaneMathTests, CreateValidPlaneWorks)
{
	const Plane Plane = Math::Planes::createPlane(Vector3D{0.0f, 1.0f, 0.0f}, -10.0f);

	EXPECT_FLOAT_EQ(Plane.normal.x, 0.0f);
	EXPECT_FLOAT_EQ(Plane.normal.y, 1.0f);
	EXPECT_FLOAT_EQ(Plane.normal.z, 0.0f);
	EXPECT_FLOAT_EQ(Plane.distanceFromOrigin, -10.0f);
}

GTEST_TEST(PlaneMathTests, CreatePlaneWithBadNormalFails)
{
	EXPECT_ANY_THROW(Math::Planes::createPlane({0.0f, 10.0f, 5.0f}, -10.0f));
}