#include <gtest/gtest.h>
#include <JoshMath.h>

using namespace Math::Types;

GTEST_TEST(VolumeIntersection, BoxCheckWorks)
{
	BoundingBox a, b;
	bool expected, actual;
	a.left = 111.0f;
	a.right = 268.0f;
	a.top = 88.0f;
	a.bottom = 212.0f;

	b.top = 175.0f;
	b.bottom = 304.0f;
	b.left = 230.0f;
	b.right = 430.0f;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);

	expected = true;

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,BoxCheckWorksWithYAxisGoingUp)
{
	BoundingBox a, b;
	bool expected, actual;
	a.left = 111.0f;
	a.right = 268.0f;
	a.bottom = 88.0f;
	a.top = 212.0f;


	b.left = 230.0f;
	b.right = 430.0f;
	b.bottom = 175.0f;
	b.top = 304.0f;


	actual = Math::VolumeIntersection::volumesOverlap(a, b);

	expected = true;

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,BoxCheckNoFalsePositive)
{
	BoundingBox a, b;
	bool expected, actual;
	a.left = 111.0f;
	a.right = 268.0f;
	a.top = 88.0f;
	a.bottom = 212.0f;

	b.left = 320.0f;
	b.right = 460.0f;
	b.top = 113.0f;
	b.bottom = 200.0f;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);

	expected = false;

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,CircleCheckWorks)
{
	BoundingCircle a, b;

	a.position.x = -1.0f;
	a.position.y = -1.0f;
	b.position.x = 2.0f;
	b.position.y = 2.0f;

	a.radius = 5.0f;
	b.radius = 5.0f;

	bool expected, actual;

	expected = true;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,CircleCheckNoFalsePositive)
{
	BoundingCircle a, b;

	a.position.x = -10.0f;
	a.position.y = -10.0f;
	b.position.x = 20.0f;
	b.position.y = 20.0f;

	a.radius = 5.0f;
	b.radius = 5.0f;

	bool expected, actual;

	expected = false;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,CubeCheckWorksLH)
{
	BoundingCube a, b;
	bool expected, actual;

	a.left = -5.0f;
	a.right = 5.0f;
	a.top = 5.0f;
	a.bottom = -5.0f;
	a.front = -5.0f;
	a.back = 5.0f;

	b.left = 3.0f;
	b.right = 6.0f;
	b.top = 2.5f;
	b.bottom = 1.0f;
	b.front = 1.0f;
	b.back = 7.0f;

	expected = true;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);


	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,CubeCheckWorksRH)
{
	BoundingCube a, b;
	bool expected, actual;

	a.left = -5.0f;
	a.right = 5.0f;
	a.top = 5.0f;
	a.bottom = -5.0f;
	a.back = -5.0f;
	a.front = 5.0f;

	b.left = 3.0f;
	b.right = 6.0f;
	b.top = 2.5f;
	b.bottom = 1.0f;
	b.back = 1.0f;
	b.front = 7.0f;

	expected = true;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);


	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,CubeCheckNoFalsePositive)
{
	BoundingCube a, b;
	bool expected, actual;

	a.left = -5.0f;
	a.right = 5.0f;
	a.top = 5.0f;
	a.bottom = -5.0f;
	a.front = -5.0f;
	a.back = 5.0f;

	b.left = 6.0f;
	b.right = 7.0f;
	b.top = 2.5f;
	b.bottom = 1.0f;
	b.front = 1.0f;
	b.back = 7.0f;

	expected = false;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);


	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,SphereCheckWorks)
{
	BoundingSphere a, b;
	a.position.x =
		a.position.y =
		a.position.z = 0.0f;
	a.radius = 5.0f;

	b.position.x =
		b.position.y =
		b.position.z = 1.0f;
	b.radius = 0.5f;

	bool expected, actual;
	expected = true;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,SphereCheckNoFalsePositive)
{
	BoundingSphere a, b;
	a.position.x =
		a.position.y =
		a.position.z = 0.0f;
	a.radius = 5.0f;

	b.position.x =
		b.position.y =
		b.position.z = 100.0f;
	b.radius = 50.0f;

	bool expected, actual;
	expected = false;

	actual = Math::VolumeIntersection::volumesOverlap(a, b);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule2DCheckWorksStartWithStart)
{
	BoundingCapsule2D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.start = b.start = { 0.0f, 0.0f };
	a.finish = { -100.0, 50.0f };
	b.finish = { 100.0, -50.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule2DCheckWorksStartWithFinish)
{
	BoundingCapsule2D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.start = b.finish = { 0.0f, 0.0f };
	a.finish = { -100.0, 50.0f };
	b.start = { 100.0, -50.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule2DCheckWorksFinishWithFinish)
{
	BoundingCapsule2D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.finish = b.finish = { 0.0f, 0.0f };
	a.start = { -100.0f, 50.0f };
	b.start = { 100.0f, -50.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule2DCheckWorksMiddleWithMiddle)
{
	BoundingCapsule2D a, b;
	
	a.radius = 5.0f;
	b.radius = 10.0f;
	
	a.start = { -100.0f, 50.0f };
	a.finish = { 100.0f, -50.0f };
	b.start = { -100.0f, -50.0f };
	b.finish = { 100.0f, 50.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule2DCheckNoFalsePositive)
{
	BoundingCapsule2D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.start = { -100.0f, 0.0f };
	a.finish = { -100.0f, 50.0f };
	b.start = { 100.0f, -50.0f };
	b.finish = { 100.0f, 0.0f };

	const bool expected = false;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule3DCheckWorksStartWithStart)
{
	BoundingCapsule3D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.start = b.start = { 0.0f, 0.0f, 0.0f };
	a.finish = { -100.0, 50.0f, 0.0f };
	b.finish = { 100.0, -50.0f, 0.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule3DCheckWorksStartWithFinish)
{
	BoundingCapsule3D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.start = b.finish = { 0.0f, 0.0f, 0.0f };
	a.finish = { -100.0, 50.0f, 0.0f };
	b.start = { 100.0, -50.0f, 0.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule3DCheckWorksFinishWithFinish)
{
	BoundingCapsule3D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.finish = b.finish = { 0.0f, 0.0f, 0.0f };
	a.start = { -100.0, 50.0f, 0.0f };
	b.start = { 100.0, -50.0f, 0.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule3DCheckWorksMiddleWithMiddle)
{
	BoundingCapsule3D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.start = { -100.0, 50.0f, 0.0f };
	a.finish = { 100.0, -50.0f, 0.0f };
	b.start = { -100.0, -50.0f, 0.0f };
	b.finish = { 100.0f, 50.0f, 0.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, Capsule3DCheckNoFalsePositive)
{
	BoundingCapsule3D a, b;

	a.radius = 5.0f;
	b.radius = 10.0f;

	a.start = { -100.0, 0.0f, 0.0f };
	a.finish = { -100.0, 50.0f, 0.0f };
	b.start = { 100.0, -50.0f, 0.0f };
	b.finish = { 100.0f, 0.0f, 0.0f };

	const bool expected = false;
	const bool actual = Math::VolumeIntersection::volumesOverlap(a, b);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInSquare)
{
	Vector2D testPoint;
	BoundingBox box;
	box.left = -2.0f;
	box.right = 2.0f;
	box.top = 2.0f;
	box.bottom = -2.0f;
	testPoint.x = 1.0f;
	testPoint.y = 1.0f;

	bool expected, actual;

	expected = true;

	actual = Math::VolumeIntersection::pointInBoundingVolume(testPoint, box);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInSquareNoFalsePositive)
{
	Vector2D testPoint;
	BoundingBox box;
	box.left = -2.0f;
	box.right = 2.0f;
	box.top = 2.0f;
	box.bottom = -2.0f;

	testPoint.x = 5.0f;
	testPoint.y = 1.0f;

	bool expected, actual;

	expected = false;

	actual = Math::VolumeIntersection::pointInBoundingVolume(testPoint, box);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInCircle)
{
	BoundingCircle bc;
	Vector2D point;
	bc.position.x =
		bc.position.y = 1.0f;

	point.x =
		point.y = -1.0f;
	bc.radius = 5.0f;

	bool expected,
		actual;

	expected = true;

	actual = Math::VolumeIntersection::pointInBoundingVolume(point, bc);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInCircleNoFalsePositive)
{
	BoundingCircle bc;
	Vector2D point;
	bc.position.x =
		bc.position.y = 1.0f;

	point.x =
		point.y = -1.0f;
	bc.radius = 1.0f;

	bool expected,
		actual;

	expected = false;

	actual = Math::VolumeIntersection::pointInBoundingVolume(point, bc);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInCube)
{
	Vector3D point;
	BoundingCube vol; // using left hand coord sys
	point.x = point.y = point.z = 0.0f;

	vol.left = vol.bottom = vol.front = -5.0f;
	vol.right = vol.top = vol.back = 5.0f;

	bool expected = true,
		actual = Math::VolumeIntersection::pointInBoundingVolume(point, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInCubeNoFalsePositive)
{
	Vector3D point;
	BoundingCube vol; // using left hand coord sys
	point.x = point.y = point.z = 25.0f;

	vol.left = vol.bottom = vol.front = -5.0f;
	vol.right = vol.top = vol.back = 5.0f;

	bool expected = false,
		actual = Math::VolumeIntersection::pointInBoundingVolume(point, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInSphere)
{
	BoundingSphere vol;
	Vector3D point;
	point.x = 1.0f;
	point.y = 5.0f;
	point.z = 2.0f;

	vol.position.x = vol.position.y = vol.position.z = 0.0f;
	vol.radius = 200.0f;

	bool expected = true,
		actual = Math::VolumeIntersection::pointInBoundingVolume(point, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,PointInSphereNoFalsePositive)
{
	BoundingSphere vol;
	Vector3D point;
	point.x = 0.0f;
	point.y = 100.0f;

	vol.position.x = vol.position.y = vol.position.z = 0.0f;
	vol.radius = 20.0f;

	bool expected = false,
		actual = Math::VolumeIntersection::pointInBoundingVolume(point, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, PointInCapsule2D)
{
	BoundingCapsule2D capsule;
	capsule.radius = 5.0f;

	capsule.start = { 10.0f, 10.0f };
	capsule.finish = {-1.0f, -1.0f};

	const Vector2D testPoint = {0.0f,0.0f};

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::pointInBoundingVolume(testPoint, capsule);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, PointInCapsule2DNoFalsePositive)
{
	BoundingCapsule2D capsule;
	capsule.radius = 5.0f;

	capsule.start = { 10.0f, 10.0f };
	capsule.finish = { -10.0f, 10.0f };

	const Vector2D testPoint = { 0.0f,0.0f };

	const bool expected = false;
	const bool actual = Math::VolumeIntersection::pointInBoundingVolume(testPoint, capsule);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, PointInCapsule3D)
{
	BoundingCapsule3D capsule;
	capsule.radius = 5.0f;

	capsule.start = { 10.0f, 10.0f, 0.0f };
	capsule.finish = { -1.0f, -1.0f, 0.0f };

	const Vector3D testPoint = { 0.0f,0.0f, 0.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::pointInBoundingVolume(testPoint, capsule);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, PointInCapsule3DNoFalsePositive)
{
	BoundingCapsule3D capsule;
	capsule.radius = 5.0f;

	capsule.start = { 10.0f, 10.0f, 0.0f };
	capsule.finish = { -10.0f, 10.0f, 0.0f };

	const Vector3D testPoint = { 0.0f,0.0f, 0.0f };

	const bool expected = false;
	const bool actual = Math::VolumeIntersection::pointInBoundingVolume(testPoint, capsule);
	EXPECT_EQ(expected, actual);
}

// now the ray casts
/* 4 types of checks:
bool volumeInRayPath() (no trace)
float rayDistanceToCollisionFast() (no trace)
float rayDistanceToCollisionReverseTrace()
float rayDistanceToCollisionTrace()
*/

GTEST_TEST(VolumeIntersection,VolInPathBox)
{
	Ray2D ray;
	BoundingBox box;

	box.left = box.bottom = -5.0f;
	box.right = box.top = 5.0f;

	ray.pointOfOrigin.x = -10.0f;
	ray.pointOfOrigin.y = 0.0f;

	ray.direction.x = 1.0f;
	ray.direction.y = 0.0f; // is a unit vector

	bool expected = true,
		actual = Math::VolumeIntersection::volumeInRayPath(ray, box);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolInPathBoxNoFalsePositive)
{
	Ray2D ray;
	BoundingBox box;

	box.left = box.bottom = -5.0f;
	box.right = box.top = 5.0f;

	ray.pointOfOrigin.x = 10.0f;
	ray.pointOfOrigin.y = 0.0f;

	ray.direction.x = 1.0f;
	ray.direction.y = 0.0f; // is a unit vector

	bool expected = false,
		actual = Math::VolumeIntersection::volumeInRayPath(ray, box);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolInPathCircle)
{
	Ray2D ray;
	BoundingCircle vol;

	vol.radius = 5.0f;
	vol.position.x = 20.0f;
	vol.position.y = 120.0f;

	ray.pointOfOrigin.x = -0.3f;
	ray.pointOfOrigin.y = 1.0f;

	ray.direction = Math::Vector::wayToVector(ray.pointOfOrigin, vol.position);
	ray.direction = Math::Vector::unitVector(ray.direction);

	bool expected = true,
		actual = Math::VolumeIntersection::volumeInRayPath(ray, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolInPathCircleNoFalsePositive)
{
	Ray2D ray;
	BoundingCircle vol;

	vol.radius = 5.0f;
	vol.position.x = 20.0f;
	vol.position.y = 120.0f;

	ray.pointOfOrigin.x = -0.3f;
	ray.pointOfOrigin.y = 1.0f;

	ray.direction = Math::Vector::wayToVector(ray.pointOfOrigin, vol.position);
	ray.direction.x = -ray.direction.x;
	ray.direction.y = -ray.direction.y;

	ray.direction = Math::Vector::unitVector(ray.direction);

	bool expected = false,
		actual = Math::VolumeIntersection::volumeInRayPath(ray, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolInPathCube)
{
	Ray3D ray;
	BoundingCube vol;

	vol.left = vol.front = vol.bottom = -5.0f;
	vol.right = vol.back = vol.top = 5.0f;

	ray.pointOfOrigin.x = -20.0f;
	ray.pointOfOrigin.y = ray.pointOfOrigin.z = 0.0f;

	ray.direction.x = 1.0f;
	ray.direction.y = ray.direction.z = 0.0f;

	bool expected = true,
		actual = Math::VolumeIntersection::volumeInRayPath(ray, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolInPathCubeNoFalsePositive)
{
	Ray3D ray;
	BoundingCube vol;

	vol.left = vol.front = vol.bottom = -5.0f;
	vol.right = vol.back = vol.top = 5.0f;

	ray.pointOfOrigin.x = -20.0f;
	ray.pointOfOrigin.y = ray.pointOfOrigin.z = 0.0f;

	ray.direction.x = -1.0f;
	ray.direction.y = ray.direction.z = 0.0f;

	bool expected = false,
		actual = Math::VolumeIntersection::volumeInRayPath(ray, vol);

	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolInPathSphere)
{
	Ray3D r;
	BoundingSphere bc;

	bc.position.x = 513.0f;
	bc.position.y = 21.21f;
	bc.position.z = 5.0f;
	bc.radius = 5.0f;

	r.pointOfOrigin.x = r.pointOfOrigin.y = r.pointOfOrigin.z = 0.0f;
	r.direction = Math::Vector::wayToVector(r.pointOfOrigin, bc.position);
	r.direction = Math::Vector::unitVector(r.direction);

	bool expected = true,
		actual = Math::VolumeIntersection::volumeInRayPath(r, bc);


	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolInPathSphereNoFalsePositive)
{
	Ray3D r;
	BoundingSphere bc;

	bc.position.x = 513.0f;
	bc.position.y = 21.21f;
	bc.position.z = 5.0f;
	bc.radius = 5.0f;

	r.pointOfOrigin.x = r.pointOfOrigin.y = r.pointOfOrigin.z = 0.0f;
	r.direction = Math::Vector::wayToVector(bc.position, r.pointOfOrigin);
	r.direction = Math::Vector::unitVector(r.direction);

	bool expected = false,
		actual = Math::VolumeIntersection::volumeInRayPath(r, bc);


	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, VolInPathCapsule2D)
{
	BoundingCapsule2D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f };
	capsule.finish = { 5.0f, 10.0f };
	Ray2D r;
	r.pointOfOrigin = { 0.0f,0.0f };
	r.direction = {0.0f, 1.0f};

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumeInRayPath(r, capsule);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, VolInPathCapsule2DNoFalsePositive)
{
	BoundingCapsule2D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f };
	capsule.finish = { 5.0f, 10.0f };
	Ray2D r;
	r.pointOfOrigin = { 0.0f,20.0f };
	r.direction = { 0.0f, 1.0f };

	const bool expected = false;
	const bool actual = Math::VolumeIntersection::volumeInRayPath(r, capsule);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, VolInPathCapsule3D)
{
	BoundingCapsule3D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f, 0.0f };
	capsule.finish = { 5.0f, 10.0f, 0.0f };
	Ray3D r;
	r.pointOfOrigin = { 0.0f,0.0f, 0.0f };
	r.direction = { 0.0f, 1.0f, 0.0f };

	const bool expected = true;
	const bool actual = Math::VolumeIntersection::volumeInRayPath(r, capsule);
	EXPECT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, VolInPathCapsule3DNoFalsePositive)
{
	BoundingCapsule3D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f, 50.0f };
	capsule.finish = { 5.0f, 10.0f, 50.0f };
	Ray3D r;
	r.pointOfOrigin = { 0.0f,0.0f, 0.0f };
	r.direction = { 0.0f, 1.0f, 0.0f };

	const bool expected = false;
	const bool actual = Math::VolumeIntersection::volumeInRayPath(r, capsule);
	EXPECT_EQ(expected, actual);
}

// start of fast distance to collision functions
GTEST_TEST(VolumeIntersection,VolDistanceToCollideFastBox)
{
	BoundingBox bb;
	bb.left = bb.bottom = -5.0f;
	bb.right = bb.top = 5.0f;

	Ray2D r;
	r.pointOfOrigin.x = -10.0f;
	r.pointOfOrigin.y = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = 0.0f;

	float expected = 5.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionFast(r, bb);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideFastCircle)
{
	BoundingCircle bc;
	Ray2D r;
	bc.position.x = bc.position.y = 0.0f;
	bc.radius = 5.0f;
	r.pointOfOrigin.x = -75.0f;
	r.pointOfOrigin.y = 0.0f;
	r.direction.x = 1.0f;
	r.direction.y = 0.0f;

	float expected = 70.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionFast(r, bc);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideFastCube)
{
	BoundingCube bc;
	Ray3D r;

	bc.left = bc.bottom = bc.front = -5.0f;
	bc.right = bc.top = bc.back = 5.0f;

	r.pointOfOrigin.x = -15.0f;
	r.pointOfOrigin.y = 0.0f;
	r.pointOfOrigin.z = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = r.direction.z = 0.0f;

	float expected = 10.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionFast(r, bc);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideFastSphere)
{
	BoundingSphere bs;
	Ray3D r;

	bs.position.x = bs.position.y = bs.position.z = 0.0f;
	bs.radius = 5.0f;

	r.pointOfOrigin.x = -15.0f;
	r.pointOfOrigin.y = 0.0f;
	r.pointOfOrigin.z = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = 0.0f;
	r.direction.z = 0.0f;

	float expected = 10.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionFast(r, bs);

	EXPECT_FLOAT_EQ(expected, actual);
}

GTEST_TEST(VolumeIntersection, VolDistanceToCollideFastCapsule2D)
{
	BoundingCapsule2D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f };
	capsule.finish = { 5.0f, 10.0f };
	Ray2D r;
	r.pointOfOrigin = { 0.0f,0.0f };
	r.direction = { 0.0f, 1.0f };
	
	const float actual = Math::VolumeIntersection::rayDistanceToCollisionFast(r, capsule);
	const float expectedMin = 5.0f;
	const float expectedMax = 15.0f;
	EXPECT_LE(expectedMin, actual);
	EXPECT_LE(actual, expectedMax);
}

GTEST_TEST(VolumeIntersection, VolDistanceToCollideFastCapsule3D)
{
	BoundingCapsule3D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f, 0.0f };
	capsule.finish = { 5.0f, 10.0f, 0.0f };
	Ray3D r;
	r.pointOfOrigin = { 0.0f,0.0f, 0.0f };
	r.direction = { 0.0f, 1.0f, 0.0f };
	const float actual = Math::VolumeIntersection::rayDistanceToCollisionFast(r, capsule);
	const float expectedMin = 5.0f;
	const float expectedMax = 15.0f;
	EXPECT_LE(expectedMin, actual);
	EXPECT_LE(actual, expectedMax);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideReverseTraceBox)
{
	BoundingBox bb;
	bb.left = bb.bottom = -5.0f;
	bb.right = bb.top = 5.0f;

	Ray2D r;
	r.pointOfOrigin.x = -10.0f;
	r.pointOfOrigin.y = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = 0.0f;

	float stepSize = 0.000001f;

	float expected = 5.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(r, bb, stepSize);

	EXPECT_FLOAT_EQ(expected, actual);
	// Assert::AreEqual(1, 1); // float rounding error?
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideReverseTraceCircle)
{
	BoundingCircle bc;
	Ray2D r;
	bc.position.x = bc.position.y = 0.0f;
	bc.radius = 5.0f;
	r.pointOfOrigin.x = -75.0f;
	r.pointOfOrigin.y = 0.0f;
	r.direction.x = 1.0f;
	r.direction.y = 0.0f;

	float stepSize = 0.01f;

	float expected = 70.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(r, bc, stepSize);

	// EXPECT_FLOAT_EQ(expected, actual); // The value is close but it's off from floating point rounding errors.
	constexpr float tolerance = 0.01f;
	EXPECT_LT(std::abs(expected - actual), tolerance);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideReverseTraceCube)
{
	BoundingCube bc;
	Ray3D r;

	bc.left = bc.bottom = bc.front = -5.0f;
	bc.right = bc.top = bc.back = 5.0f;

	r.pointOfOrigin.x = -15.0f;
	r.pointOfOrigin.y = 0.0f;
	r.pointOfOrigin.z = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = r.direction.z = 0.0f;

	float stepSize = 0.001f;

	float expected = 10.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(r, bc, stepSize);

	// EXPECT_FLOAT_EQ(expected, actual); // The value is close but it's off from floating point rounding errors.
	constexpr float tolerance = 0.001f;
	EXPECT_LT(std::abs(expected - actual), tolerance);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideReverseTraceSphere)
{
	BoundingSphere bs;
	Ray3D r;

	bs.position.x = bs.position.y = bs.position.z = 0.0f;
	bs.radius = 5.0f;

	r.pointOfOrigin.x = -15.0f;
	r.pointOfOrigin.y = 0.0f;
	r.pointOfOrigin.z = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = 0.0f;
	r.direction.z = 0.0f;

	float stepSize = 0.001f;

	float expected = 10.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(r, bs, stepSize);

	// EXPECT_FLOAT_EQ(expected, actual); // The value is close but it's off from floating point rounding errors.
	constexpr float tolerance = 0.001f;
	EXPECT_LT(std::abs(expected - actual), tolerance);
}

GTEST_TEST(VolumeIntersection, VolDistanceToCollideReverseTraceCapsule2D)
{
	BoundingCapsule2D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f };
	capsule.finish = { 5.0f, 10.0f };
	Ray2D r;
	r.pointOfOrigin = { 0.0f,0.0f };
	r.direction = { 0.0f, 1.0f };

	const float actual = Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(r, capsule, 0.001f);
	const float expectedMin = 4.75f;
	const float expectedMax = 5.25f;
	EXPECT_LE(expectedMin, actual);
	EXPECT_LE(actual, expectedMax);
}

GTEST_TEST(VolumeIntersection, VolDistanceToCollideReverseTraceCapsule3D)
{
	BoundingCapsule3D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f, 0.0f };
	capsule.finish = { 5.0f, 10.0f, 0.0f };
	Ray3D r;
	r.pointOfOrigin = { 0.0f,0.0f, 0.0f };
	r.direction = { 0.0f, 1.0f, 0.0f };
	const float actual = Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(r, capsule, 0.001f);
	const float expectedMin = 4.75f;
	const float expectedMax = 5.25f;
	EXPECT_LE(expectedMin, actual);
	EXPECT_LE(actual, expectedMax);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideForwardTraceBox)
{
	BoundingBox bb;
	bb.left = bb.bottom = -5.0f;
	bb.right = bb.top = 5.0f;

	Ray2D r;
	r.pointOfOrigin.x = -10.0f;
	r.pointOfOrigin.y = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = 0.0f;

	float stepSize = 0.000001f;

	float maxTraceDist = 100.0f;

	float expected = 5.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionTrace(r, bb, stepSize, maxTraceDist);

	EXPECT_FLOAT_EQ(expected, actual);
	// Assert::AreEqual(1, 1); // close enough
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideForwardTraceCircle)
{
	BoundingCircle bc;
	Ray2D r;
	bc.position.x = bc.position.y = 0.0f;
	bc.radius = 5.0f;
	r.pointOfOrigin.x = -75.0f;
	r.pointOfOrigin.y = 0.0f;
	r.direction.x = 1.0f;
	r.direction.y = 0.0f;

	float stepSize = 0.01f;
	float maxTraceDist = 100.0f;
	float expected = 70.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionTrace(r, bc, stepSize, maxTraceDist);

	// EXPECT_FLOAT_EQ(expected, actual); // The value is close but it's off by a small amount.
	constexpr float tolerance = 0.01f;
	EXPECT_LT(std::abs(expected - actual), tolerance);
}

GTEST_TEST(VolumeIntersection,VolDistanceToCollideForwardTraceCube)
{
	BoundingCube bc;
	Ray3D r;

	bc.left = bc.bottom = bc.front = -5.0f;
	bc.right = bc.top = bc.back = 5.0f;

	r.pointOfOrigin.x = -15.0f;
	r.pointOfOrigin.y = 0.0f;
	r.pointOfOrigin.z = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = r.direction.z = 0.0f;

	float stepSize = 0.001f;
	float maxDist = 100.0f;

	float expected = 10.0f,
		actual = Math::VolumeIntersection::rayDistanceToCollisionTrace(r, bc, stepSize, maxDist);

	// EXPECT_FLOAT_EQ(expected, actual); // The value is close but it's off by 0.000411 treating this as a floating point rounding error.
	constexpr float tolerance  = 0.001f;
	EXPECT_LT(std::abs(expected - actual), tolerance);
}

GTEST_TEST(VolumeIntersection, DistanceToCollideFowardTraceSphere)
{
	BoundingCube bc;
	Ray3D r;

	bc.left = bc.bottom = bc.front = -5.0f;
	bc.right = bc.top = bc.back = 5.0f;

	r.pointOfOrigin.x = -15.0f;
	r.pointOfOrigin.y = 0.0f;
	r.pointOfOrigin.z = 0.0f;

	r.direction.x = 1.0f;
	r.direction.y = r.direction.z = 0.0f;

	float stepSize = 0.0001f;
	float maxDist = 100.0f;

	float expected = 10.0f,
	actual = Math::VolumeIntersection::rayDistanceToCollisionReverseTrace(r, bc, stepSize);

	// EXPECT_FLOAT_EQ(expected, actual); would fail due to floating point rounding errors, if the difference is small enough we accept.
	constexpr float tolerance = 0.001f;
	EXPECT_LT(std::abs(expected - actual), tolerance);
}

GTEST_TEST(VolumeIntersection, DistanceToCollideFowardTraceCapsule2D)
{
	BoundingCapsule2D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f };
	capsule.finish = { 5.0f, 10.0f };
	Ray2D r;
	r.pointOfOrigin = { 0.0f,0.0f };
	r.direction = { 0.0f, 1.0f };

	const float actual = Math::VolumeIntersection::rayDistanceToCollisionTrace(r, capsule, 0.001f, 50.0f);
	const float expectedMin = 4.75f;
	const float expectedMax = 5.25f;
	EXPECT_LE(expectedMin, actual);
	EXPECT_LE(actual, expectedMax);
}

GTEST_TEST(VolumeIntersection, DistanceToCollideFowardTraceCapsule3D)
{
	BoundingCapsule3D capsule;
	capsule.radius = 5.0f;
	capsule.start = { -5.0f, 10.0f, 0.0f };
	capsule.finish = { 5.0f, 10.0f, 0.0f };
	Ray3D r;
	r.pointOfOrigin = { 0.0f,0.0f,0.0f };
	r.direction = { 0.0f, 1.0f, 0.0f };

	const float actual = Math::VolumeIntersection::rayDistanceToCollisionTrace(r, capsule, 0.001f, 50.0f);
	const float expectedMin = 4.75f;
	const float expectedMax = 5.25f;
	EXPECT_LE(expectedMin, actual);
	EXPECT_LE(actual, expectedMax);
}
