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
	namespace Transform
	{
		void scale2D(Types::Matrix2x1& toScale, float xScale, float yScale);
		void scale3D(Types::Matrix3x1& toScale, float xScale, float yScale, float zScale);
		void scale4D(Types::Matrix4x1& toScale, float xScale, float yScale, float zScale, float wScale);
		void rotate2DClkWise(Types::Matrix2x1& toRot, float thetaRads);
		void rotate2DAntiClkWise(Types::Matrix2x1& toRot, float thetaRads);
		
		// 3d rotation matrix versions
		void rotate3DX(Types::Matrix3x1& toRotate, float thetaRads);
		void rotate3DY(Types::Matrix3x1& toRotate, float thetaRads);
		void rotate3DZ(Types::Matrix3x1& toRotate, float thetaRads);
		
		void rotateCustomAxis(const Types::Vector3D& axisUnitVector, float thetaRads, Types::Matrix3x1& toRotate);

		Types::Matrix2x2 get2dRotationMatrixClkWise(float thetaRads);
		Types::Matrix2x2 get2dRotationMatrixAntiClkWise(float thetaRads);

		Types::Matrix3x3 get3x3Rotate3DXMatrix(float thetaRads);
		Types::Matrix3x3 get3x3Rotate3DYMatrix(float thetaRads);
		Types::Matrix3x3 get3x3Rotate3DZMatrix(float thetaRads);

		Types::Matrix3x3 getRotationMatrixForCustomAxis(const Types::Vector3D& axisUnitVector, float thetaRads);
		Types::Matrix4x4 get4x4RotationMatrixForCustomAxis(const Types::Vector3D& axisUnitVector, float thetaRads);

		Types::Matrix2x2 get2x2ScalingMatrix(float x, float y);
		Types::Matrix3x3 get3x3ScalingMatrix(float x, float y, float z);
		Types::Matrix4x4 get4x4ScalingMatrix(float x, float y, float z, float w);
		
		Types::Matrix4x4 get4x4TranslationMatrix(const Types::Vector3D& translation);

	
		void translate2D(Types::Matrix2x1& toTranslate, const Types::Vector2D& translateBy);
		void translate3D(Types::Matrix3x1& toTranslate, const Types::Vector3D& translateBy);

		Types::Matrix4x4 RightHandViewMatrix(const Types::Vector3D& eye, const Types::Vector3D& up, const Types::Vector3D& at);
		Types::Matrix4x4 LeftHandViewMatrix(const Types::Vector3D& eye, const Types::Vector3D& up, const Types::Vector3D& at);
		Types::Matrix4x4 OrthographicProjectionMatrix(float width, float height, float nearZ, float farZ);
		Types::Matrix4x4 PerspectiveProjectionMatrix(float fovInYDirection, float aspectRatio, float nearDepth, float farDepth);
	}
}
