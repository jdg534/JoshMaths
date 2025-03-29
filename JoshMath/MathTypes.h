#ifndef MATH_TYPES_H_
#define MATH_TYPES_H_

/*
Copyright (c) 2015 Joshua Gibson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <string>

namespace Math
{
	namespace Types
	{
		struct Vector2D
		{
			float x, y;

			// operators
			// bool operator==(const Vector2D & a, const Vector2D & b)
			friend bool operator==(const Vector2D& a, const Vector2D& b)
			{
				return a.x == b.x &&
					a.y == b.y;
			}
		};

		struct Vector3D
		{
			float x, y, z;
			friend bool operator==(const Vector3D& a, const Vector3D& b)
			{
				return a.x == b.x
					&& a.y == b.y
					&& a.z == b.z;
			}
		};

		struct Quaternion
		{
			// w != theta
			float w = 0.0f, x = 0.0f, y = 0.0f, z = 0.0f;

			friend bool operator==(const Quaternion& a, const Quaternion& b)
			{
				return a.x == b.x
					&& a.y == b.y
					&& a.z == b.z
					&& a.w == b.w;
			}
		};

		struct PolarCoordinate
		{
			float angle;
			float radius;

			friend bool operator==(const PolarCoordinate& a, const PolarCoordinate& b)
			{
				return a.angle == b.angle
					&& a.radius == b.radius;
			}
		};

		// 4x4 matrix max, (num rows)x(num columns)

		// 2x1
		struct Matrix2x1
		{
			float r1c1;
			float r2c1;
			// x, y
			friend bool operator==(const Matrix2x1& a, const Matrix2x1& b)
			{
				return a.r1c1 == b.r1c1
					&& a.r2c1 == b.r2c1;
			}
		};

		// 2x2
		struct Matrix2x2
		{
			float r1c1, r1c2;
			float r2c1, r2c2;
			friend bool operator==(Matrix2x2 a, Matrix2x2 b) // this isn't effecent
			{
				float* aPtr, * bPtr;
				aPtr = reinterpret_cast<float*>(&a);
				bPtr = reinterpret_cast<float*>(&b);

				int maxI = sizeof(Matrix2x2) / sizeof(float);
				for (int i = 0; i < maxI; i++)
				{
					if (aPtr[i] != bPtr[i])
						return false;
				}
				return true;
			}
		};

		// 3x1
		struct Matrix3x1
		{
			float r1c1, r2c1, r3c1;
			// x, y, z
			friend bool operator==(Matrix3x1 a, Matrix3x1 b) // this isn't effecent
			{
				float* aPtr, * bPtr;
				aPtr = reinterpret_cast<float*>(&a);
				bPtr = reinterpret_cast<float*>(&b);

				int maxI = sizeof(Matrix3x1) / sizeof(float);
				for (int i = 0; i < maxI; i++)
				{
					if (aPtr[i] != bPtr[i])
						return false;
				}
				return true;
			}
		};

		// 3x3
		struct Matrix3x3
		{
			float r1c1, r2c1, r3c1;
			float r1c2, r2c2, r3c2;
			float r1c3, r2c3, r3c3;
			friend bool operator==(Matrix3x3 a, Matrix3x3 b) // this isn't effecent
			{
				float* aPtr, * bPtr;
				aPtr = reinterpret_cast<float*>(&a);
				bPtr = reinterpret_cast<float*>(&b);

				int maxI = sizeof(Matrix3x3) / sizeof(float);
				for (int i = 0; i < maxI; i++)
				{
					if (aPtr[i] != bPtr[i])
						return false;
				}
				return true;
			}
		};

		// 4x1
		struct Matrix4x1
		{
			float r1c1, r2c1, r3c1, r4c1;
			friend bool operator==(Matrix4x1 a, Matrix4x1 b) // this isn't effecent
			{
				float* aPtr, * bPtr;
				aPtr = reinterpret_cast<float*>(&a);
				bPtr = reinterpret_cast<float*>(&b);

				int maxI = sizeof(Matrix4x1) / sizeof(float);
				for (int i = 0; i < maxI; i++)
				{
					if (aPtr[i] != bPtr[i])
						return false;
				}
				return true;
			}
		};

		// 4x3
		struct Matrix4x3
		{
			float r1c1, r2c1, r3c1, r4c1;
			float r1c2, r2c2, r3c2, r4c2;
			float r1c3, r2c3, r3c3, r4c3;
			friend bool operator==(Matrix4x3 a, Matrix4x3 b) // this isn't effecent
			{
				float* aPtr, * bPtr;
				aPtr = reinterpret_cast<float*>(&a);
				bPtr = reinterpret_cast<float*>(&b);

				int maxI = sizeof(Matrix4x3) / sizeof(float);
				for (int i = 0; i < maxI; i++)
				{
					if (aPtr[i] != bPtr[i])
						return false;
				}
				return true;
			}
		};

		// 4x4
		struct Matrix4x4
		{
			float r1c1, r2c1, r3c1, r4c1;
			float r1c2, r2c2, r3c2, r4c2;
			float r1c3, r2c3, r3c3, r4c3;
			float r1c4, r2c4, r3c4, r4c4;
			friend bool operator==(Matrix4x4 a, Matrix4x4 b) // this isn't effecent
			{
				float* aPtr, * bPtr;
				aPtr = reinterpret_cast<float*>(&a);
				bPtr = reinterpret_cast<float*>(&b);

				int maxI = sizeof(Matrix4x4) / sizeof(float);
				for (int i = 0; i < maxI; i++)
				{
					if (aPtr[i] != bPtr[i])
						return false;
				}
				return true;
			}
		};

		struct Plane
		{
			Vector3D normal;
			float distanceFromOrigin;
		};

		// bounding volumes, ray object intersection tests to be done, via maths library
		// won't deal with BVH yet

		struct Ray2D
		{
			Vector2D pointOfOrigin;
			Vector2D direction; // this MUST be a unit vector
		};

		struct Ray3D
		{
			Vector3D pointOfOrigin;
			Vector3D direction; // MUST be a unit vector
		};

		enum BoundingVolumeType
		{
			BVT_UNDEFINED = 0,
			BVT_BOX,
			BVT_CUBE,
			BVT_CIRCLE,
			BVT_SPHERE,
			BVT_CAPULE_2D,
			BVT_CAPULE_3D
		};

		struct BoundingVolumeBase
		{
			BoundingVolumeType bvType;
			BoundingVolumeBase()
			{
				bvType = BVT_UNDEFINED;
			}
		};

		struct BoundingBox : public BoundingVolumeBase
		{
			float left, right, top, bottom;
			BoundingBox()
			{
				bvType = BVT_BOX;
			}
		};

		struct BoundingCube : public BoundingBox
		{
			float front, back;
			BoundingCube()
			{
				bvType = BVT_CUBE;
			}
		};

		struct BoundingCircle : public BoundingVolumeBase
		{
			Vector2D position;
			float radius;
			BoundingCircle()
			{
				bvType = BVT_CIRCLE;
			}
		};

		struct BoundingSphere : public BoundingVolumeBase
		{
			Vector3D position;
			float radius;
			BoundingSphere()
			{
				bvType = BVT_SPHERE;
			}
		};

		struct BoundingCapsule2D : public BoundingVolumeBase
		{
			Vector2D start, finish;
			float radius;
			BoundingCapsule2D()
			{
				bvType = BVT_CAPULE_2D;
				start = finish = { 0.0f,0.0f };
				radius = 0.0f;
			}
		};

		struct BoundingCapsule3D : public BoundingVolumeBase
		{
			Vector3D start, finish;
			float radius;
			BoundingCapsule3D()
			{
				bvType = BVT_CAPULE_3D;
				start = finish = { 0.0f,0.0f, 0.0f };
				radius = 0.0f;
			}
		};


		// start of graph theory stuff
		enum GraphNodeTypes
		{
			GRAPH_NODE_UNKNOWN_TYPE = 0,
			GRAPH_NODE_2D,
			GRAPH_NODE_3D
		};

		struct GraphNodeBase
		{
			GraphNodeTypes nodeType;
			std::string nodeID;
			GraphNodeBase()
			{
				nodeType = GRAPH_NODE_UNKNOWN_TYPE;
				nodeID = "";
			}
		};

		struct GraphNode2D : public GraphNodeBase
		{
			Vector2D position;

			GraphNode2D()
			{
				nodeType = GRAPH_NODE_2D;
				nodeID = "";
				position.x = position.y = 0.0f;
			}
		};

		struct GraphNode3D : public GraphNodeBase
		{
			Vector3D position;

			GraphNode3D()
			{
				nodeType = GRAPH_NODE_3D;
				nodeID = "";
				position.x = position.y = position.z = 0.0f;
			}
		};

		struct Graph
		{
			unsigned int numGraphNodes;
			GraphNodeBase** nodes;
		};
	}
}

#endif
