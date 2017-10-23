#include <iostream>
#include "MathTypes.h"
#include "Math.h"

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

// main.cpp is only used for testing

bool yesNo();
int main();
void writeMatrix(std::ostream & output, Matrix4x4 & toWrite);
void writeMatrix(std::ostream & output, Matrix4x1 & toWrite);
void writeMatrix(std::ostream & output, Matrix4x3 & toWrite);
void writeMatrix(std::ostream & output, Matrix3x3 & toWrite);
void writeMatrix(std::ostream & output, Matrix3x1 & toWrite);
void writeMatrix(std::ostream & output, Matrix2x2 & toWrite);
void writeMatrix(std::ostream & output, Matrix2x1 & toWrite);
void testTranslation();
void testScaling();
void testRotation();
void testMatrixMulterplications();

bool yesNo()
{
	std::cout << "Y/N: ";
	char ans = '1';
	std::cin >> ans;
	if (ans == 'y' || ans == 'Y')
	{
		return true;
	}
	else if(ans == 'n' || ans == 'N')
	{
		return false;
	}
	return yesNo();
}

int main()
{
	/*
	Matrix4x4 identity;
	Math::MatrixMath::makeIdentity(identity);
	writeMatrix(std::cout, identity);
	*/
	// testMatrixMulterplications(); // tested it works

	testTranslation(); // works
	// testScaling(); // works
	testRotation();


	std::cout << "Done: ";
	char ec;
	std::cin >> ec;
	return 0;
}

void writeMatrix(std::ostream & output, Matrix4x4 & toWrite)
{
	output << "4x4 Matrix:\n";
	output << "|" << toWrite.r1c1 << ", " << toWrite.r1c2 << ", " << toWrite.r1c3 << ", " << toWrite.r1c4 << "|\n";
	output << "|" << toWrite.r2c1 << ", " << toWrite.r2c2 << ", " << toWrite.r2c3 << ", " << toWrite.r2c4 << "|\n";
	output << "|" << toWrite.r3c1 << ", " << toWrite.r3c2 << ", " << toWrite.r3c3 << ", " << toWrite.r3c4 << "|\n";
	output << "|" << toWrite.r4c1 << ", " << toWrite.r4c2 << ", " << toWrite.r4c3 << ", " << toWrite.r4c4 << "|\n";
}

void writeMatrix(std::ostream & output, Matrix4x1 & toWrite)
{
	output << "4x1 Matrix:\n";
	output << "|" << toWrite.r1c1 << "|\n";
	output << "|" << toWrite.r2c1 << "|\n";
	output << "|" << toWrite.r3c1 << "|\n";
	output << "|" << toWrite.r4c1 << "|\n";
}

void writeMatrix(std::ostream & output, Matrix4x3 & toWrite)
{
	output << "4x3 Matrix:\n";
	output << "|" << toWrite.r1c1 << ", " << toWrite.r1c2 << ", " << toWrite.r1c3 << "|\n";
	output << "|" << toWrite.r2c1 << ", " << toWrite.r2c2 << ", " << toWrite.r2c3 << "|\n";
	output << "|" << toWrite.r3c1 << ", " << toWrite.r3c2 << ", " << toWrite.r3c3 << "|\n";
	output << "|" << toWrite.r4c1 << ", " << toWrite.r4c2 << ", " << toWrite.r4c3 << "|\n";
}

void writeMatrix(std::ostream & output, Matrix3x3 & toWrite)
{
	output << "3x3 Matrix:\n";
	output << "|" << toWrite.r1c1 << ", " << toWrite.r1c2 << ", " << toWrite.r1c3 << "|\n";
	output << "|" << toWrite.r2c1 << ", " << toWrite.r2c2 << ", " << toWrite.r2c3 << "|\n";
	output << "|" << toWrite.r3c1 << ", " << toWrite.r3c2 << ", " << toWrite.r3c3 << "|\n";
}

void writeMatrix(std::ostream & output, Matrix3x1 & toWrite)
{
	output << "3x1 Matrix:\n";
	output << "|" << toWrite.r1c1 << "|\n";
	output << "|" << toWrite.r2c1 << "|\n";
	output << "|" << toWrite.r3c1 << "|\n";
}

void writeMatrix(std::ostream & output, Matrix2x2 & toWrite)
{
	output << "2x2 Matrix:\n";
	output << "|" << toWrite.r1c1 << ", " << toWrite.r1c2 << "|\n";
	output << "|" << toWrite.r2c1 << ", " << toWrite.r2c2 << "|\n";
}

void writeMatrix(std::ostream & output, Matrix2x1 & toWrite)
{
	output << "2x1 Matrix:\n";
	output << "|" << toWrite.r1c1 << "|\n";
	output << "|" << toWrite.r2c1 << "|\n";
}

void testTranslation()
{
	std::cout << "TRANSLATION TEST\n\n";

	Vector3D start, end, moveBy;
	start.x = 5.5f;
	start.y = 3.3f;
	start.z = 4.4f;

	/*
	moveBy.x = 10.0f;
	moveBy.y = 20.0f;
	moveBy.z = 30.0f;
	*/
	moveBy.x = 0.0f;
	moveBy.y = 0.0f;
	moveBy.z = 0.0f;
	

	end = Math::VectorMath::add(start, moveBy);
	Matrix4x4 startMat, endMat;

	Matrix4x4 transMat = Math::transform::get4x4TranslationMatrix(moveBy);
	Math::MatrixMath::makeIdentity(startMat);
	
	startMat.r1c4 = start.x;
	startMat.r2c4 = start.y;
	startMat.r3c4 = start.z;
	
	std::cout << "Matrix storing the starting posistion\n";
	writeMatrix(std::cout, startMat);


	std::cout << "Matrix used for performing the translation:" << std::endl;
	writeMatrix(std::cout, transMat);

	endMat = Math::MatrixMath::multiply(transMat, startMat);
	std::cout << "Final position via vector math: " << end.x << ", " << end.y << ", " << end.z << std::endl;

	std::cout << "Final Matrix Position:\n";
	writeMatrix(std::cout, endMat);

}

void testScaling()
{
	std::cout << "SCALING TEST\n";
	
	Matrix4x1 toScaleMat;
	toScaleMat.r1c1 = 2.0f;
	toScaleMat.r2c1 = 3.0f;
	toScaleMat.r3c1 = 4.0f;
	toScaleMat.r4c1 = 5.0f;
	std::cout << "Values to scale" << std::endl;
	writeMatrix(std::cout, toScaleMat);

	Matrix4x4 resultingScalingMatrix;
	resultingScalingMatrix = Math::transform::get4x4ScalingMatrix(2.0f, 2.0f, 2.0f, 2.0);
	std::cout << "Scaling Matrix" << std::endl;
	writeMatrix(std::cout, resultingScalingMatrix);
	
	Matrix4x1 res = Math::MatrixMath::multiply(resultingScalingMatrix, toScaleMat);
	std::cout << "Scaled matrix" << std::endl;
	writeMatrix(std::cout, res);	
}

void testRotation()
{
	using namespace std;
	
	/*
	// 2D
	// clock wise
	// anti clockwise
	float rotationAngleDegrees = 45.0f;
	float rotationAngleRadians = Math::degreesToRadians(rotationAngleDegrees);
	Matrix2x1 originalPoint2D;
	originalPoint2D.r1c1 = 1.0f;
	originalPoint2D.r2c1 = 1.0f;

	Matrix2x2 clockWise2d = Math::transform::get2dRotationMatrixClkWise(rotationAngleRadians);
	Matrix2x2 antiClockWide2d = Math::transform::get2dRotationMatrixAntiClkWise(rotationAngleRadians);

	Matrix2x1 rotatedClockWise = Math::MatrixMath::multiply(clockWise2d, originalPoint2D);
	Matrix2x1 rotatedAntiClockWide = Math::MatrixMath::multiply(antiClockWide2d, originalPoint2D);

	cout << "2D Clockwise rotation test.\n";
	cout << "Matrix storing point to rotate: ";
	writeMatrix(cout, originalPoint2D);
	cout << "Angle to rotate by (degrees): " << rotationAngleDegrees << " (in radians: " << rotationAngleRadians << ")\n";

	cout << "Clock wise rotation matrix: ";
	writeMatrix(cout, clockWise2d);
	cout << "point rotated clock wise by " << rotationAngleRadians << " radians: ";
	writeMatrix(cout, rotatedClockWise);
	cout << "Values correct?\n";
	if (!yesNo())
	{
		return;
	}

	cout << "Matrix storing point to rotate: ";
	writeMatrix(cout, originalPoint2D);
	cout << "Angle to rotate by (degrees): " << rotationAngleDegrees << " (in radians: " << rotationAngleRadians << ")\n";

	cout << "Anti clock wise rotation matrix: ";
	writeMatrix(cout, antiClockWide2d);
	cout << "point rotated anti clock wise by " << rotationAngleRadians << " radians: ";
	writeMatrix(cout, rotatedAntiClockWide);
	cout << "Values correct?\n";
	if (!yesNo())
	{
		return;
	}

	// 3D
	float deg90 = 90.0f;
	float deg90Rads = Math::degreesToRadians(deg90);
	// X
	Matrix3x1 originalPoint3D;
	originalPoint3D.r1c1 = 1.0f;
	originalPoint3D.r2c1 = 1.0f;
	originalPoint3D.r3c1 = 1.0f;

	Matrix3x3 xRotMat = Math::transform::get3x3Rotate3DXMatrix(deg90Rads);

	cout << "Point to rotate: ";
	writeMatrix(cout, originalPoint3D);
	cout << "Rotation matrix for rotating by " << deg90Rads << " radians in X axis: ";
	writeMatrix(cout, xRotMat);
	cout << "Original point rotated by " << deg90Rads << " radians in the X axis: ";
	Matrix3x1 ori3dRotedX = Math::MatrixMath::multiply(xRotMat, originalPoint3D);
	writeMatrix(cout, ori3dRotedX);
	cout << "Values correct?\n";
	if (!yesNo())
	{
		return;
	}

	// Y
	Matrix3x3 yRotMat = Math::transform::get3x3Rotate3DYMatrix(deg90Rads);

	cout << "Point to rotate: ";
	writeMatrix(cout, originalPoint3D);
	cout << "Rotation matrix for rotating by " << deg90Rads << " radians in Y axis: ";
	writeMatrix(cout, yRotMat);
	cout << "Original point rotated by " << deg90Rads << " radians in the Y axis: ";
	Matrix3x1 ori3dRotedY = Math::MatrixMath::multiply(yRotMat, originalPoint3D);
	writeMatrix(cout, ori3dRotedY);
	cout << "Values correct?\n";
	if (!yesNo())
	{
		return;
	}


	// Z
	Matrix3x3 zRotMat = Math::transform::get3x3Rotate3DZMatrix(deg90Rads);

	cout << "Point to rotate: ";
	writeMatrix(cout, originalPoint3D);
	cout << "Rotation matrix for rotating by " << deg90Rads << " radians in Z axis: ";
	writeMatrix(cout, zRotMat);
	cout << "Original point rotated by " << deg90Rads << " radians in the Z axis: ";
	Matrix3x1 ori3dRotedZ = Math::MatrixMath::multiply(zRotMat, originalPoint3D);
	writeMatrix(cout, ori3dRotedZ);
	cout << "Values correct?\n";
	if (!yesNo())
	{
		return;
	}
	*/

	// custom axis
	// 3x3
	Vector3D rotationAxis;
	rotationAxis.x = 1.0f;
	rotationAxis.y = 0.0f;
	rotationAxis.z = 0.0f;

	Matrix3x1 originalPoint3D;
	originalPoint3D.r1c1 = 1.0f;
	originalPoint3D.r2c1 = 1.0f;
	originalPoint3D.r3c1 = 1.0f;

	cout << "TEST for matrix to rotate around custom axis\n";
	cout << "X component of vector to rotate around: ";
	cin >> rotationAxis.x;
	cout << "Y component of vector to rotate around: ";
	cin >> rotationAxis.y;
	cout << "Z component of vector to rotate around: ";
	cin >> rotationAxis.z;
	cout << "Axis to rotate around: " << rotationAxis.x << "i " << rotationAxis.y << "j " << rotationAxis.z << "k\n";

	rotationAxis = Math::VectorMath::unitVector(rotationAxis);
	cout << "Axis to rotate around (unit vector): " << rotationAxis.x << "i " << rotationAxis.y << "j " << rotationAxis.z << "k\n";
	float d180 = 180.0f;
	float d180Rads = Math::degreesToRadians(d180);
	Matrix3x3 mat3x3RotCustAxis = Math::transform::getRotationMatrixForCustomAxis(rotationAxis, d180Rads);
	cout << "Matrix for roting by " << d180Rads << " radians: ";
	writeMatrix(cout, mat3x3RotCustAxis);
	cout << "To rotate: ";
	writeMatrix(cout, originalPoint3D);
	Matrix3x1 rotatedCustomAxis = Math::MatrixMath::multiply(mat3x3RotCustAxis, originalPoint3D);
	cout << "The rotated matrix: ";
	writeMatrix(cout, rotatedCustomAxis);
	cout << "Values correct?\n";
	if (!yesNo())
	{
		return;
	}

	// 4x4
	cout << "TEST FOR 4x4 matrix version";
	cout << "Axis to rotate around: " << rotationAxis.x << "i " << rotationAxis.y << "j " << rotationAxis.z << "k\n";

	rotationAxis = Math::VectorMath::unitVector(rotationAxis);
	cout << "Axis to rotate around (unit vector): " << rotationAxis.x << "i " << rotationAxis.y << "j " << rotationAxis.z << "k\n";
	Matrix4x4 mat4x4RotCustAxis = Math::transform::get4x4RotationMatrixForCustomAxis(rotationAxis, d180Rads);
	cout << "Matrix for rotating by: ";
	writeMatrix(cout, mat4x4RotCustAxis);
	cout << "To rotate: ";
	Matrix4x1 original4d;
	original4d.r1c1 = originalPoint3D.r1c1;
	original4d.r2c1 = originalPoint3D.r2c1;
	original4d.r3c1 = originalPoint3D.r3c1;
	original4d.r4c1 = 0.0f;
	writeMatrix(cout, original4d);
	cout << "The rotated matrix: ";
	Matrix4x1 rotatedMatrix = Math::MatrixMath::multiply(mat4x4RotCustAxis, original4d);
	writeMatrix(cout, rotatedMatrix);

	cout << "Values correct?\n";
	if (!yesNo())
	{
		return;
	}

}

void testMatrixMulterplications()
{
	using namespace std;
	// 2x2 x 2x1
	Matrix2x2 t1a;
	Matrix2x1 t1b;
	t1a.r1c1 = 1.1f;
	t1a.r1c2 = 1.2f;
	t1a.r2c1 = 2.1f;
	t1a.r2c2 = 2.2f;

	t1b.r1c1 = 3.1f;
	t1b.r2c1 = 4.1f;

	Matrix2x1 t1results = Math::MatrixMath::multiply(t1a, t1b);
	cout << "2x2 x 2x1 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t1a);
	cout << "B ";
	writeMatrix(cout, t1b);
	cout << "Results ";
	writeMatrix(cout, t1results);
	cout << "Results correct?" << endl;
	bool keepGoing;
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}
	// 2x2 x 2x2
	Matrix2x2 t2b;
	t2b.r1c1 = 3.1f;
	t2b.r1c2 = 3.2f;
	t2b.r2c1 = 4.1f;
	t2b.r2c2 = 4.2f;

	Matrix2x2 t2results = Math::MatrixMath::multiply(t1a, t2b);
	cout << "2x2 x 2x2 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t1a);
	cout << "B ";
	writeMatrix(cout, t2b);
	cout << "Results ";
	writeMatrix(cout, t2results);
	cout << "Results correct?" << endl;
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}


	// 3x3 x 3x1
	// 3x3 x 3x3
	Matrix3x3 t3a;
	Matrix3x1 t3b;
	t3a.r1c1 = 1.1f;
	t3a.r1c2 = 1.2f;
	t3a.r1c3 = 1.3f;
	t3a.r2c1 = 2.1f;
	t3a.r2c2 = 2.2f;
	t3a.r2c3 = 2.3f;
	t3a.r3c1 = 3.1f;
	t3a.r3c2 = 3.2f;
	t3a.r3c3 = 3.3f;
	
	t3b.r1c1 = 4.1f;
	t3b.r2c1 = 5.1f;
	t3b.r3c1 = 6.1f;

	Matrix3x1 t3results = Math::MatrixMath::multiply(t3a, t3b);
	cout << "3x3 x 3x1 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t3a);
	cout << "B ";
	writeMatrix(cout, t3b);
	cout << "Results ";
	writeMatrix(cout, t3results);
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}

	Matrix3x3 t4b;
	t4b.r1c1 = 4.1f;
	t4b.r1c2 = 4.2f;
	t4b.r1c3 = 4.3f;
	t4b.r2c1 = 5.1f;
	t4b.r2c2 = 5.2f;
	t4b.r2c3 = 5.3f;
	t4b.r3c1 = 6.1f;
	t4b.r3c2 = 6.2f;
	t4b.r3c3 = 6.3f;

	Matrix3x3 t4results = Math::MatrixMath::multiply(t3a, t4b);
	cout << "3x3 x 3x3 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t3a);
	cout << "B ";
	writeMatrix(cout, t4b);
	cout << "Results ";
	writeMatrix(cout, t4results);
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}
	
	// 4x3 x 3x1
	// 4x3 x 3x3
	Matrix4x3 t5a;
	Matrix3x1 t5b;
	t5a.r1c1 = 1.1f;
	t5a.r1c2 = 1.2f;
	t5a.r1c3 = 1.3f;
	t5a.r2c1 = 2.1f;
	t5a.r2c2 = 2.2f;
	t5a.r2c3 = 2.3f;
	t5a.r3c1 = 3.1f;
	t5a.r3c2 = 3.2f;
	t5a.r3c3 = 3.3f;
	t5a.r4c1 = 4.1f;
	t5a.r4c2 = 4.2f;
	t5a.r4c3 = 4.3f;

	t5b.r1c1 = 5.1f;
	t5b.r2c1 = 6.1f;
	t5b.r3c1 = 7.1f;
	Matrix4x1 t5results = Math::MatrixMath::multiply(t5a, t5b);
	cout << "4x3 x 3x1 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t5a);
	cout << "B ";
	writeMatrix(cout, t5b);
	cout << "Results ";
	writeMatrix(cout, t5results);
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}

	Matrix3x3 t6b;
	t6b.r1c1 = 5.1f;
	t6b.r1c2 = 5.2f;
	t6b.r1c3 = 5.3f;
	t6b.r2c1 = 6.1f;
	t6b.r2c2 = 6.2f;
	t6b.r2c3 = 6.3f;
	t6b.r3c1 = 7.1f;
	t6b.r3c2 = 7.2f;
	t6b.r3c3 = 7.3f;
	Matrix4x3 t6results = Math::MatrixMath::multiply(t5a, t6b);
	cout << "4x3 x 3x3 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t5a);
	cout << "B ";
	writeMatrix(cout, t6b);
	cout << "Results ";
	writeMatrix(cout, t6results);
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}

	// 4x4 x 4x1
	// 4x4 x 4x4
	// 4x4 x 4x3
	Matrix4x4 t7a;
	t7a.r1c1 = 1.1f;
	t7a.r1c2 = 1.2f;
	t7a.r1c3 = 1.3f;
	t7a.r1c4 = 1.4f;
	t7a.r2c1 = 2.1f;
	t7a.r2c2 = 2.2f;
	t7a.r2c3 = 2.3f;
	t7a.r2c4 = 2.4f;
	t7a.r3c1 = 3.1f;
	t7a.r3c2 = 3.2f;
	t7a.r3c3 = 3.3f;
	t7a.r3c4 = 3.4f;
	t7a.r4c1 = 4.1f;
	t7a.r4c2 = 4.2f;
	t7a.r4c3 = 4.3f;
	t7a.r4c4 = 4.4f;

	Matrix4x1 t7b;
	t7b.r1c1 = 5.1f;
	t7b.r2c1 = 6.1f;
	t7b.r3c1 = 7.1f;
	t7b.r4c1 = 8.1f;

	Matrix4x1 t7results = Math::MatrixMath::multiply(t7a, t7b);
	cout << "4x4 x 4x1 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t7a);
	cout << "B ";
	writeMatrix(cout, t7b);
	cout << "Results ";
	writeMatrix(cout, t7results);
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}

	Matrix4x3 t8b;
	t8b.r1c1 = 5.1f;
	t8b.r1c2 = 5.2f;
	t8b.r1c3 = 5.3f;
	t8b.r2c1 = 6.1f;
	t8b.r2c2 = 6.2f;
	t8b.r2c3 = 6.3f;
	t8b.r3c1 = 7.1f;
	t8b.r3c2 = 7.2f;
	t8b.r3c3 = 7.3f;
	t8b.r4c1 = 8.1f;
	t8b.r4c2 = 8.2f;
	t8b.r4c3 = 8.3f;

	Matrix4x3 t8results = Math::MatrixMath::multiply(t7a, t8b);
	cout << "4x4 x 4x3 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t7a);
	cout << "B ";
	writeMatrix(cout, t8b);
	cout << "Results ";
	writeMatrix(cout, t8results);
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}

	Matrix4x4 t9b;
	t9b.r1c1 = 5.1f;
	t9b.r1c2 = 5.2f;
	t9b.r1c3 = 5.3f;
	t9b.r1c4 = 5.4f;
	t9b.r2c1 = 6.1f;
	t9b.r2c2 = 6.2f;
	t9b.r2c3 = 6.3f;
	t9b.r2c4 = 6.4f;
	t9b.r3c1 = 7.1f;
	t9b.r3c2 = 7.2f;
	t9b.r3c3 = 7.3f;
	t9b.r3c4 = 7.4f;
	t9b.r4c1 = 8.1f;
	t9b.r4c2 = 8.2f;
	t9b.r4c3 = 8.3f;
	t9b.r4c4 = 8.4f;
	
	Matrix4x4 t9results = Math::MatrixMath::multiply(t7a, t9b);
	cout << "4x4 x 4x4 multerplication test" << endl;
	cout << "A ";
	writeMatrix(cout, t7a);
	cout << "B ";
	writeMatrix(cout, t9b);
	cout << "Results ";
	writeMatrix(cout, t9results);
	keepGoing = yesNo();
	if (!keepGoing)
	{
		return;
	}
}