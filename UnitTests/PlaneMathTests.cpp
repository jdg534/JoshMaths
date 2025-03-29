#include <gtest/gtest.h>
#include <string>
#include <JoshMath.h>

using namespace Math::Types;

GTEST_TEST(PlaneMathTests, CreateValidPlaneWorks)
{
	const Plane Plane = Math::Plane::createPlane(Vector3D{0.0f, 1.0f, 0.0f}, -10.0f);

	EXPECT_FLOAT_EQ(Plane.normal.x, 0.0f);
	EXPECT_FLOAT_EQ(Plane.normal.y, 1.0f);
	EXPECT_FLOAT_EQ(Plane.normal.z, 0.0f);
	EXPECT_FLOAT_EQ(Plane.distanceFromOrigin, -10.0f);
}

GTEST_TEST(PlaneMathTests, PlaneDotProductAsVectorWorks)
{
	const Vector3D AVector{ 10.0f, -1.0f, 0.0f};
	const Plane APlane = Math::Plane::createPlane({0.0f, 1.0f, 0.0f}, 0.0f);
	const float Expected = (0.0f * 10.0f) + (1.0f * -1.0f) + (0.0f * 0.0f) + (0.0f * 0.0f);
	const float Actual = Math::Plane::dotProductAsVector(APlane, AVector);
	EXPECT_FLOAT_EQ(Expected, Actual);
}

GTEST_TEST(PlaneMathTests, PlaneDotProductAsPositionWorks)
{
	const Vector3D APosition{ 10.0f, -1.0f, 0.0f };
	const Plane APlane = Math::Plane::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const float Expected = (0.0f * 10.0f) + (1.0f * -1.0f) + (0.0f * 0.0f) + (0.0f * 1.0f);
	const float Actual = Math::Plane::dotProductAsPosition(APlane, APosition);
	EXPECT_FLOAT_EQ(Expected, Actual);
}

GTEST_TEST(PlaneMathTests, DistanceFromPlaneWorks)
{
	const Vector3D PositionToTest{ 0.0f, 10.0f, 0.0f };
	const Plane TestPlane = Math::Plane::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const float Expected = 10.0f;
	const float Actual = Math::Plane::distanceFromPlane(TestPlane, PositionToTest);
	EXPECT_FLOAT_EQ(Expected, Actual);
}

GTEST_TEST(PlaneMathTests, ReflectVectorWorks)
{
	const Vector3D VectorToTest{ 5.0f, -10.0f, 0.0f };
	const Plane TestPlane = Math::Plane::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const Vector3D Expected{ 5.0f, 10.0f, 0.0f };
	const Vector3D Actual = Math::Plane::reflectVector(VectorToTest, TestPlane);
	EXPECT_FLOAT_EQ(Expected.x, Actual.x);
	EXPECT_FLOAT_EQ(Expected.y, Actual.y);
	EXPECT_FLOAT_EQ(Expected.z, Actual.z);
}

GTEST_TEST(PlaneMathTests, ReflectPosition)
{
	const Vector3D VectorToTest{ 5.0f, -10.0f, 0.0f };
	const Plane TestPlane = Math::Plane::createPlane({ 0.0f, 1.0f, 0.0f }, 0.0f);
	const Vector3D Expected{ 5.0f, 10.0f, 0.0f };
	const Vector3D Actual = Math::Plane::reflectPosition(VectorToTest, TestPlane);
	EXPECT_FLOAT_EQ(Expected.x, Actual.x);
	EXPECT_FLOAT_EQ(Expected.y, Actual.y);
	EXPECT_FLOAT_EQ(Expected.z, Actual.z);
}
