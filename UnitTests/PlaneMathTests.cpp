#include <gtest/gtest.h>
#include <string>
#include <JoshMath.h>

GTEST_TEST(PlaneMathTests, CreateValidPlaneWorks)
{
	const Plane Plane = Math::Planes::createPlane(Vector3D{0.0f, 1.0f, 0.0f}, -10.0f);

	EXPECT_FLOAT_EQ(Plane.normal.x, 0.0f);
	EXPECT_FLOAT_EQ(Plane.normal.y, 1.0f);
	EXPECT_FLOAT_EQ(Plane.normal.z, 0.0f);
	EXPECT_FLOAT_EQ(Plane.distanceFromOrigin, -10.0f);
}

GTEST_TEST(PlaneMathTests, PlaneDotProductAsVectorWorks)
{
	const Vector3D AVector{ 10.0f, -1.0f, 0.0f};
	const Plane APlane = Math::Planes::createPlane({0.0f, 1.0f, 0.0f}, 0.0f);
	const float Expected = (0.0f * 10.0f) + (1.0f * -1.0f) + (0.0f * 0.0f) + (0.0f * 0.0f);
	const float Actual = Math::Planes::dotProductAsVector(APlane, AVector);
	EXPECT_FLOAT_EQ(Expected, Actual);
}

GTEST_TEST(PlaneMathTests, PlaneDotProductAsPositionWorks)
{
	const Vector3D APosition{ 10.0f, -1.0f, 0.0f };
	const Plane APlane = Math::Planes::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const float Expected = (0.0f * 10.0f) + (1.0f * -1.0f) + (0.0f * 0.0f) + (0.0f * 1.0f);
	const float Actual = Math::Planes::dotProductAsPosition(APlane, APosition);
	EXPECT_FLOAT_EQ(Expected, Actual);
}

GTEST_TEST(PlaneMathTests, DistanceFromPlaneWorks)
{
	const Vector3D PositionToTest{ 0.0f, 10.0f, 0.0f };
	const Plane TestPlane = Math::Planes::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const float Expected = 10.0f;
	const float Actual = Math::Planes::distanceFromPlane(TestPlane, PositionToTest);
	EXPECT_FLOAT_EQ(Expected, Actual);
}

GTEST_TEST(PlaneMathTests, ReflectVectorWorks)
{
	const Vector3D VectorToTest{ 5.0f, -10.0f, 0.0f };
	const Plane TestPlane = Math::Planes::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const Vector3D Expected{ 5.0f, 10.0f, 0.0f };
	const Vector3D Actual = Math::Planes::reflectVector(VectorToTest, TestPlane);
	EXPECT_FLOAT_EQ(Expected.x, Actual.x);
	EXPECT_FLOAT_EQ(Expected.y, Actual.y);
	EXPECT_FLOAT_EQ(Expected.z, Actual.z);
}

GTEST_TEST(PlaneMathTests, ReflectPosition)
{
	const Vector3D VectorToTest{ 5.0f, -10.0f, 0.0f };
	const Plane TestPlane = Math::Planes::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const Vector3D Expected{ 5.0f, 10.0f, 0.0f };
	const Vector3D Actual = Math::Planes::reflectPosition(VectorToTest, TestPlane);
	EXPECT_FLOAT_EQ(Expected.x, Actual.x);
	EXPECT_FLOAT_EQ(Expected.y, Actual.y);
	EXPECT_FLOAT_EQ(Expected.z, Actual.z);
}
