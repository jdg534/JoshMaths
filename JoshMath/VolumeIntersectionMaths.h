#pragma once

#include "MathTypes.h"

#include <cstdint>

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

namespace Math
{
	namespace VolumeIntersection
	{
		bool volumesOverlap(const Types::BoundingBox& a, const Types::BoundingBox& b);
		bool volumesOverlap(const Types::BoundingCircle& a, const Types::BoundingCircle& b);
		bool volumesOverlap(const Types::BoundingSphere& a, const Types::BoundingSphere& b);
		bool volumesOverlap(const Types::BoundingCube& a, const Types::BoundingCube& b);
		bool volumesOverlap(const Types::BoundingCapsule2D& a, const Types::BoundingCapsule2D& b, uint32_t numSegments = 10);
		bool volumesOverlap(const Types::BoundingCapsule3D& a, const Types::BoundingCapsule3D& b, uint32_t numSegments = 10);

		bool pointInBoundingVolume(const Types::Vector2D& a, const Types::BoundingBox& vol);
		bool pointInBoundingVolume(const Types::Vector2D& a, const Types::BoundingCircle& vol);
		bool pointInBoundingVolume(const Types::Vector3D& a, const Types::BoundingSphere& vol);
		bool pointInBoundingVolume(const Types::Vector3D& a, const Types::BoundingCube& vol);
		bool pointInBoundingVolume(const Types::Vector2D& a, const Types::BoundingCapsule2D& vol, uint32_t numSegments = 10);
		bool pointInBoundingVolume(const Types::Vector3D& a, const Types::BoundingCapsule3D& vol, uint32_t numSegments = 10);

		bool volumeInRayPath(const Types::Ray2D& r, const Types::BoundingBox& vol);
		bool volumeInRayPath(const Types::Ray2D& r, const Types::BoundingCircle& vol);
		bool volumeInRayPath(const Types::Ray3D& r, const Types::BoundingSphere& vol);
		bool volumeInRayPath(const Types::Ray3D& r, const Types::BoundingCube& vol);
		bool volumeInRayPath(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, uint32_t numSegments = 10);
		bool volumeInRayPath(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, uint32_t numSegments = 10);

		// below assume that a volume is in the ray path, (defermined via above functions)
		// these are designed for speed NOT percision
		float rayDistanceToCollisionFast(const Types::Ray2D& r, const Types::BoundingBox& vol);
		float rayDistanceToCollisionFast(const Types::Ray2D& r, const Types::BoundingCircle& vol);
		float rayDistanceToCollisionFast(const Types::Ray3D& r, const Types::BoundingSphere& vol);
		float rayDistanceToCollisionFast(const Types::Ray3D& r, const Types::BoundingCube& vol);
		float rayDistanceToCollisionFast(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, uint32_t numSegments = 10);
		float rayDistanceToCollisionFast(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, uint32_t numSegments = 10);

		// these are designed for percision (down to the user) at the cost speed
		// small step size = accurate & slow
		// lager step size = inaccurate & fast*
		float rayDistanceToCollisionReverseTrace(const Types::Ray2D& r, const Types::BoundingBox& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray2D& r, const Types::BoundingCircle& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray3D& r, const Types::BoundingSphere& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray3D& r, const Types::BoundingCube& vol, float stepSize);
		float rayDistanceToCollisionReverseTrace(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, float stepSize, uint32_t numSegments = 10);
		float rayDistanceToCollisionReverseTrace(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, float stepSize, uint32_t numSegments = 10);

		float rayDistanceToCollisionTrace(const Types::Ray2D& r, const Types::BoundingBox& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray2D& r, const Types::BoundingCircle& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray3D& r, const Types::BoundingSphere& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray3D& r, const Types::BoundingCube& vol, float stepSize, float maxDist);
		float rayDistanceToCollisionTrace(const Types::Ray2D& r, const Types::BoundingCapsule2D& vol, float stepSize, float maxDist, uint32_t numSegments = 10);
		float rayDistanceToCollisionTrace(const Types::Ray3D& r, const Types::BoundingCapsule3D& vol, float stepSize, float maxDist, uint32_t numSegments = 10);
	}
}
