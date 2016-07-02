#include "stdafx.h"
#include "CppUnitTest.h"
#include "CppUnitTestAssert.h"

#include "MathTypes.h"
#include "JoshMath.h"

#include <sstream>
#include <string>


namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{

			template<>
			static std::wstring ToString<Vector2D>(const Vector2D& v)
			{
				std::wstringstream wss;
				wss << "[" << v.x << ", " << v.y << "]";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

			template<>
			static std::wstring ToString<Vector3D>(const Vector3D& v)
			{
				std::wstringstream wss;
				wss << "[" << v.x << ", " << v.y << ", " << v.z << "]";
				return wss.str();
				//return L"Some string representing coordinate.";
			}

		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace JoshMathsUnitTest
{
	TEST_CLASS(VolumeIntersectionTestClass)
	{
	public:
		/*
		Volume Types:
		2D
		Bounding Box (Axis Aligned)
		Bounding Circle
		3D
		Bounding Cube (Axis Aligned)
		Bounding Sphere
		*/

		// need to test, will collide and won't collide scenarios (for each collision check func)
		TEST_METHOD(VolIntersect_BoxCheckWorks)
		{
			BoundingBox a, b;
			bool expected, actual;
			a.left = 111.0f;
			a.right= 268.0f;
			a.top = 88.0f;
			a.bottom = 212.0f;

			b.top = 175.0f;
			b.bottom = 304.0f;
			b.left = 230.0f;
			b.right = 430.0f;

			actual = Math::VolumeIntersection::volumesOverlap(a, b);

			expected = true;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VolIntersect_BoxCheckWorksWithYAxisGoingUp)
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

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VolIntersect_BoxCheckNoFalsePositive)
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

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VolIntersect_CircleCheckWorks)
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

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VolIntersect_CircleCheckNoFalsePositive)
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

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(VolIntersect_CubeCheckWorks)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(VolIntersect_CubeCheckNoFalsePositive)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(VolIntersect_SphereCheckWorks)
		{
			Assert::AreEqual(1, 2);
		}

		TEST_METHOD(VolIntersect_SphereCheckNoFalsePositive)
		{
			Assert::AreEqual(1, 2);
		}
	};
}