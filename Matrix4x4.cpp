#include "Matrix4x4.h"

Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 temp = m1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] += m2.m[i][j];
		}
	}
	return temp;
}

Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 temp = m1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] -= m2.m[i][j];
		}
	}
	return temp;
}

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] = m1.m[i][0] * m2.m[0][j] + m1.m[i][1] * m2.m[1][j] + m1.m[i][2] * m2.m[2][j] + m1.m[i][3] * m2.m[3][j];
		}
	}
	return temp;
}

Matrix4x4 Inverse(const Matrix4x4& m1) {
	float det;
	det = m1.m[0][0] * m1.m[1][1] * m1.m[2][2] * m1.m[3][3]
		+ m1.m[0][0] * m1.m[1][2] * m1.m[2][3] * m1.m[3][1]
		+ m1.m[0][0] * m1.m[1][3] * m1.m[2][1] * m1.m[3][2]

		- m1.m[0][0] * m1.m[1][3] * m1.m[2][2] * m1.m[3][1]
		- m1.m[0][0] * m1.m[1][2] * m1.m[2][1] * m1.m[3][3]
		- m1.m[0][0] * m1.m[1][1] * m1.m[2][1] * m1.m[3][2]

		- m1.m[0][1] * m1.m[1][0] * m1.m[2][2] * m1.m[3][3]
		- m1.m[0][2] * m1.m[1][0] * m1.m[2][1] * m1.m[3][1]
		- m1.m[0][3] * m1.m[1][0] * m1.m[2][1] * m1.m[3][2]

		+ m1.m[0][3] * m1.m[1][0] * m1.m[2][2] * m1.m[3][1]
		+ m1.m[0][2] * m1.m[1][0] * m1.m[2][1] * m1.m[3][3]
		+ m1.m[0][1] * m1.m[1][0] * m1.m[2][3] * m1.m[3][2]

		+ m1.m[0][1] * m1.m[1][2] * m1.m[2][0] * m1.m[3][3]
		+ m1.m[0][2] * m1.m[1][3] * m1.m[2][0] * m1.m[3][1]
		+ m1.m[0][3] * m1.m[1][1] * m1.m[2][0] * m1.m[3][2]

		- m1.m[0][3] * m1.m[1][2] * m1.m[2][0] * m1.m[3][1]
		- m1.m[0][2] * m1.m[1][1] * m1.m[2][0] * m1.m[3][3]
		- m1.m[0][1] * m1.m[1][3] * m1.m[2][0] * m1.m[3][2]

		- m1.m[0][1] * m1.m[1][2] * m1.m[2][3] * m1.m[3][0]
		- m1.m[0][2] * m1.m[1][3] * m1.m[2][2] * m1.m[3][0]
		- m1.m[0][3] * m1.m[1][1] * m1.m[2][1] * m1.m[3][0]

		+ m1.m[0][3] * m1.m[1][2] * m1.m[2][1] * m1.m[3][0]
		+ m1.m[0][2] * m1.m[1][1] * m1.m[2][3] * m1.m[3][0]
		+ m1.m[0][1] * m1.m[1][3] * m1.m[2][2] * m1.m[3][0];

	float det11 = 1 / det * (
		+ m1.m[1][1] * m1.m[2][2] * m1.m[3][3]
		+ m1.m[1][2] * m1.m[2][3] * m1.m[3][1]
		+ m1.m[1][3] * m1.m[2][1] * m1.m[3][2]
		- m1.m[1][3] * m1.m[2][2] * m1.m[3][1]
		- m1.m[1][2] * m1.m[2][1] * m1.m[3][3]
		- m1.m[1][1] * m1.m[2][3] * m1.m[3][2]
		);
	float det12 = 1 / det * (
		- m1.m[0][1] * m1.m[2][2] * m1.m[3][3]
		- m1.m[0][2] * m1.m[2][3] * m1.m[3][1]
		- m1.m[0][3] * m1.m[2][1] * m1.m[3][2]
		+ m1.m[0][3] * m1.m[2][2] * m1.m[3][1]
		+ m1.m[0][2] * m1.m[2][1] * m1.m[3][3]
		+ m1.m[0][1] * m1.m[2][3] * m1.m[3][2]
		);
	float det13 = 1 / det * (
		+ m1.m[0][1] * m1.m[1][2] * m1.m[3][3]
		+ m1.m[0][2] * m1.m[1][3] * m1.m[3][1]
		+ m1.m[0][3] * m1.m[1][1] * m1.m[3][2]
		- m1.m[0][3] * m1.m[1][2] * m1.m[3][1]
		- m1.m[0][2] * m1.m[1][1] * m1.m[3][3]
		- m1.m[0][1] * m1.m[1][3] * m1.m[3][2]
		);
	float det14 = 1 / det * (
		- m1.m[0][1] * m1.m[1][2] * m1.m[2][3]
		- m1.m[0][2] * m1.m[1][3] * m1.m[2][1]
		- m1.m[0][3] * m1.m[1][1] * m1.m[2][2]
		+ m1.m[0][3] * m1.m[1][2] * m1.m[2][1]
		+ m1.m[0][2] * m1.m[1][1] * m1.m[2][3]
		+ m1.m[0][1] * m1.m[1][3] * m1.m[2][2]
		);
	
	float det21 = 1 / det * (
		- m1.m[1][0] * m1.m[2][2] * m1.m[3][3]
		- m1.m[1][2] * m1.m[2][3] * m1.m[3][0]
		- m1.m[1][3] * m1.m[2][0] * m1.m[3][2]
		+ m1.m[1][3] * m1.m[2][2] * m1.m[3][0]
		+ m1.m[1][2] * m1.m[2][0] * m1.m[3][3]
		+ m1.m[1][0] * m1.m[2][3] * m1.m[3][2]
		);
	
	float det22 = 1 / det * (
		+ m1.m[0][0] * m1.m[2][2] * m1.m[3][3]
		+ m1.m[0][2] * m1.m[2][3] * m1.m[3][0]
		+ m1.m[0][3] * m1.m[2][0] * m1.m[3][2]
		- m1.m[0][3] * m1.m[2][2] * m1.m[3][0]
		- m1.m[0][2] * m1.m[2][0] * m1.m[3][3]
		- m1.m[0][0] * m1.m[2][3] * m1.m[3][2]
		);
	
	
	float det23 = 1 / det * (
		- m1.m[0][0] * m1.m[1][2] * m1.m[3][3]
		- m1.m[0][2] * m1.m[1][3] * m1.m[3][0]
		- m1.m[0][3] * m1.m[1][0] * m1.m[3][2]
		+ m1.m[0][3] * m1.m[1][2] * m1.m[3][0]
		+ m1.m[0][2] * m1.m[1][0] * m1.m[3][3]
		+ m1.m[0][0] * m1.m[1][3] * m1.m[3][2]
		);
	
	float det24 = 1 / det * (
		+ m1.m[0][0] * m1.m[1][2] * m1.m[2][3]
		+ m1.m[0][2] * m1.m[1][3] * m1.m[2][0]
		+ m1.m[0][3] * m1.m[1][0] * m1.m[2][2]
		- m1.m[0][3] * m1.m[1][2] * m1.m[2][0]
		- m1.m[0][2] * m1.m[1][0] * m1.m[2][3]
		- m1.m[0][0] * m1.m[1][3] * m1.m[2][2]
		);
	
	float det31 = 1 / det * (
		+ m1.m[1][0] * m1.m[2][1] * m1.m[3][3]
		+ m1.m[1][1] * m1.m[2][3] * m1.m[3][0]
		+ m1.m[1][3] * m1.m[2][0] * m1.m[3][1]
		- m1.m[1][3] * m1.m[2][1] * m1.m[3][0]
		- m1.m[1][1] * m1.m[2][0] * m1.m[3][3]
		- m1.m[1][0] * m1.m[2][3] * m1.m[3][1]
		);
	
	float det32 = 1 / det * (
		- m1.m[0][0] * m1.m[2][1] * m1.m[3][3]
		- m1.m[0][1] * m1.m[2][3] * m1.m[3][0]
		- m1.m[0][3] * m1.m[2][0] * m1.m[3][1]
		+ m1.m[0][3] * m1.m[2][1] * m1.m[3][0]
		+ m1.m[0][1] * m1.m[2][0] * m1.m[3][3]
		+ m1.m[0][0] * m1.m[2][3] * m1.m[3][1]
		);
	
	float det33 = 1 / det * (
		+ m1.m[0][0] * m1.m[1][1] * m1.m[3][3]
		+ m1.m[0][1] * m1.m[1][3] * m1.m[3][0]
		+ m1.m[0][3] * m1.m[1][0] * m1.m[3][1]
		- m1.m[0][3] * m1.m[1][1] * m1.m[3][0]
		- m1.m[0][1] * m1.m[1][0] * m1.m[3][3]
		- m1.m[0][0] * m1.m[1][3] * m1.m[3][1]
		);
	
	float det34 = 1 / det * (
		- m1.m[0][0] * m1.m[1][1] * m1.m[2][3]
		- m1.m[0][1] * m1.m[1][3] * m1.m[2][0]
		- m1.m[0][3] * m1.m[1][0] * m1.m[2][1]
		+ m1.m[0][3] * m1.m[1][1] * m1.m[2][0]
		+ m1.m[0][1] * m1.m[1][0] * m1.m[2][3]
		+ m1.m[0][0] * m1.m[1][3] * m1.m[2][1]
		);
	
	float det41 = 1 / det * (
		- m1.m[1][0] * m1.m[2][1] * m1.m[3][2]
		- m1.m[1][1] * m1.m[2][2] * m1.m[3][0]
		- m1.m[1][2] * m1.m[2][0] * m1.m[3][1]
		+ m1.m[1][2] * m1.m[2][1] * m1.m[3][0]
		+ m1.m[1][1] * m1.m[2][0] * m1.m[3][2]
		+ m1.m[1][0] * m1.m[2][2] * m1.m[3][1]
		);
	
	float det42 = 1 / det * (
		+ m1.m[0][0] * m1.m[2][1] * m1.m[3][2]
		+ m1.m[0][1] * m1.m[2][2] * m1.m[3][0]
		+ m1.m[0][2] * m1.m[2][0] * m1.m[3][1]
		- m1.m[0][2] * m1.m[2][1] * m1.m[3][0]
		- m1.m[0][1] * m1.m[2][0] * m1.m[3][2]
		- m1.m[0][0] * m1.m[2][2] * m1.m[3][1]
		);
	
	float det43 = 1 / det * (
		- m1.m[0][0] * m1.m[1][1] * m1.m[3][2]
		- m1.m[0][1] * m1.m[1][2] * m1.m[3][0]
		- m1.m[0][2] * m1.m[1][0] * m1.m[3][1]
		+ m1.m[0][2] * m1.m[1][1] * m1.m[3][0]
		+ m1.m[0][1] * m1.m[1][0] * m1.m[3][2]
		+ m1.m[0][0] * m1.m[1][2] * m1.m[3][1]
		);
	
	float det44 = 1 / det * (
		+ m1.m[0][0] * m1.m[1][1] * m1.m[2][2]
		+ m1.m[0][1] * m1.m[1][2] * m1.m[2][0]
		+ m1.m[0][2] * m1.m[1][0] * m1.m[2][1]
		- m1.m[0][2] * m1.m[1][1] * m1.m[2][0]
		- m1.m[0][1] * m1.m[1][0] * m1.m[2][2]
		- m1.m[0][0] * m1.m[1][2] * m1.m[2][1]
		);


	Matrix4x4 result = {
		det11, det12, det13, det14,
		det21, det22, det23, det24,
		det31, det32, det33, det34,
		det41, det42, det43, det44 };
	return result;
}

Matrix4x4 Transpose(const Matrix4x4& m1) {
	Matrix4x4 temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] = m1.m[j][i];
		}
	}
	return temp;
}