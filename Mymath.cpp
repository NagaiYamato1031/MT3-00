#include "Mymath.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

#include "Matrix4x4.h"

#include <cmath>
#include <cassert>

//using namespace Mymath;

#pragma region Vector

#pragma region Vector2

// 加算
Vector2 Mymath::Add(const Vector2& v1, const Vector2& v2) {
	return v1 + v2;
}

// 減算
Vector2 Mymath::Subtract(const Vector2& v1, const Vector2& v2) {
	return v1 - v2;
}

// スカラー倍
Vector2 Mymath::Multiply(float scalar, const Vector2& v) {
	return v * scalar;
}

// 内積
float Mymath::Dot(const Vector2& v1, const Vector2& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

// 長さ
float Mymath::Length(const Vector2& v) {
	return sqrtf(Dot(v, v));
}

// 正規化
Vector2 Mymath::Normalize(const Vector2& v) {
	float length = Length(v);
	Vector2 temp = v;
	if (length != 0) {
		temp.x /= length;
		temp.y /= length;
	}
	return temp;
}

Vector2 Mymath::Transform(const Vector2& vector, const Matrix3x3& matrix) {
	Vector3 temp = Multiply(Vector3{ vector.x,vector.y,1.0f }, matrix);
	assert(temp.z != 0.0f);
	temp.x /= temp.z;
	temp.y /= temp.z;
	temp.z /= temp.z;
	return Vector2{ temp.x,temp.y };
}



// End Vector2
#pragma endregion

#pragma region Vector3

// 加算
Vector3 Mymath::Add(const Vector3& v1, const Vector3& v2) {
	return v1 + v2;
}

// 減算
Vector3 Mymath::Subtract(const Vector3& v1, const Vector3& v2) {
	return v1 - v2;
}

// スカラー倍
Vector3 Mymath::Multiply(float scalar, const Vector3& v) {
	return v * scalar;
}

Vector3 Mymath::Multiply(const Vector3& v, const Matrix3x3& matrix) {
	float temp[4]{ 0,0,0,0 };
	float vf[4]{ v.x,v.y,v.z };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i] += vf[j] * matrix.m[j][i];
		}
	}
	return Vector3{ temp[0],temp[1],temp[2] };
}
// 内積
float Mymath::Dot(const Vector3& v1, const Vector3& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 長さ
float Mymath::Length(const Vector3& v) {
	return sqrtf(Dot(v, v));
}

// 正規化
Vector3 Mymath::Normalize(const Vector3& v) {
	float length = Length(v);
	Vector3 temp = v;
	if (length != 0) {
		temp.x /= length;
		temp.y /= length;
		temp.z /= length;
	}
	return temp;
}

Vector3 Mymath::Transform(const Vector3& vector, const Matrix4x4& matrix) {
	Vector4 temp = Multiply(Vector4{ vector.x,vector.y,vector.z,1.0f }, matrix);
	assert(temp.w != 0.0f);
	temp.x /= temp.w;
	temp.y /= temp.w;
	temp.z /= temp.w;
	return Vector3{ temp.x,temp.y,temp.z };
}

// End Vector3
#pragma endregion

#pragma region Vector4


// 加算
Vector4 Mymath::Add(const Vector4& v1, const Vector4& v2) {
	return v1 + v2;
}

// 減算
Vector4 Mymath::Subtract(const Vector4& v1, const Vector4& v2) {
	return v1 - v2;
}

// スカラー倍
Vector4 Mymath::Multiply(float scalar, const Vector4& v) {
	return v * scalar;
}

Vector4 Mymath::Multiply(const Vector4& v, const Matrix4x4& matrix) {
	float temp[4]{ 0,0,0,0 };
	float vf[4]{ v.x,v.y,v.z,v.w };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i] += vf[j] * matrix.m[j][i];
		}
	}
	return Vector4{ temp[0],temp[1],temp[2],temp[3] };
}

// 内積
float Mymath::Dot(const Vector4& v1, const Vector4& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

// 長さ
float Mymath::Length(const Vector4& v) {
	return sqrtf(Dot(v, v));
}

// 正規化
Vector4 Mymath::Normalize(const Vector4& v) {
	float length = Length(v);
	Vector4 temp = v;
	if (length != 0) {
		temp.x /= length;
		temp.y /= length;
		temp.z /= length;
		temp.w /= length;
	}
	return temp;
}
// End Vector4
#pragma endregion


// End Vector
#pragma endregion

#pragma region Matrix

#pragma region Matrix4x4

Matrix4x4 Mymath::Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 temp = m1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] += m2.m[i][j];
		}
	}
	return temp;
}

Matrix4x4 Mymath::Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 temp = m1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] -= m2.m[i][j];
		}
	}
	return temp;
}

Matrix4x4 Mymath::Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] = m1.m[i][0] * m2.m[0][j] + m1.m[i][1] * m2.m[1][j] + m1.m[i][2] * m2.m[2][j] + m1.m[i][3] * m2.m[3][j];
		}
	}
	return temp;
}

Matrix4x4 Mymath::Inverse(const Matrix4x4& matrix) {
	float det;
	det = matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3]
		+ matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1]
		+ matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2]

		- matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1]
		- matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3]
		- matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2]

		- matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3]
		- matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1]
		- matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2]

		+ matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1]
		+ matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3]
		+ matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2]

		+ matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3]
		+ matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1]
		+ matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2]

		- matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1]
		- matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3]
		- matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2]

		- matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0]
		- matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0]
		- matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0]

		+ matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0]
		+ matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0]
		+ matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0];

	float det11 = 1 / det * (
		+matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3]
		+ matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1]
		+ matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2]
		- matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1]
		- matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3]
		- matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2]
		);
	float det12 = 1 / det * (
		-matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][3]
		- matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][1]
		- matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][2]
		+ matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][1]
		+ matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][3]
		+ matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][2]
		);
	float det13 = 1 / det * (
		+matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][3]
		+ matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][1]
		+ matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][2]
		- matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][1]
		- matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][3]
		- matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][2]
		);
	float det14 = 1 / det * (
		-matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3]
		- matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1]
		- matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2]
		+ matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1]
		+ matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3]
		+ matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2]
		);

	float det21 = 1 / det * (
		-matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3]
		- matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0]
		- matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2]
		+ matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0]
		+ matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3]
		+ matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2]
		);

	float det22 = 1 / det * (
		+matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][3]
		+ matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][0]
		+ matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][2]
		- matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][0]
		- matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][3]
		- matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][2]
		);


	float det23 = 1 / det * (
		-matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][3]
		- matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][0]
		- matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][2]
		+ matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][0]
		+ matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][3]
		+ matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][2]
		);

	float det24 = 1 / det * (
		+matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3]
		+ matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0]
		+ matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2]
		- matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0]
		- matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3]
		- matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2]
		);

	float det31 = 1 / det * (
		+matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3]
		+ matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0]
		+ matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1]
		- matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0]
		- matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3]
		- matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1]
		);

	float det32 = 1 / det * (
		-matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][3]
		- matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][0]
		- matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][1]
		+ matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][0]
		+ matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][3]
		+ matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][1]
		);

	float det33 = 1 / det * (
		+matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][3]
		+ matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][0]
		+ matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][1]
		- matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][0]
		- matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][3]
		- matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][1]
		);

	float det34 = 1 / det * (
		-matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3]
		- matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0]
		- matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1]
		+ matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0]
		+ matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3]
		+ matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1]
		);

	float det41 = 1 / det * (
		-matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2]
		- matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0]
		- matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1]
		+ matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0]
		+ matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2]
		+ matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1]
		);

	float det42 = 1 / det * (
		+matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][2]
		+ matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][0]
		+ matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][1]
		- matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][0]
		- matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][2]
		- matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][1]
		);

	float det43 = 1 / det * (
		-matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][2]
		- matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][0]
		- matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][1]
		+ matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][0]
		+ matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][2]
		+ matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][1]
		);

	float det44 = 1 / det * (
		+matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2]
		+ matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0]
		+ matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1]
		- matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0]
		- matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2]
		- matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]
		);


	Matrix4x4 result = {
		det11, det12, det13, det14,
		det21, det22, det23, det24,
		det31, det32, det33, det34,
		det41, det42, det43, det44 };
	return result;
}

Matrix4x4 Mymath::Transpose(const Matrix4x4& matrix) {
	Matrix4x4 temp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp.m[i][j] = matrix.m[j][i];
		}
	}
	return temp;
}

Matrix4x4 Mymath::MakeIdentity4x4() {
	return Matrix4x4{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
}

Matrix4x4 Mymath::MakeTranslateMatrix(const Vector3& translate) {
	Matrix4x4 translateMatrix_ = {
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		translate.x,translate.y,translate.z,1
	};
	return translateMatrix_;
}

Matrix4x4 Mymath::MakeScaleMatrix(const Vector3& scale) {
	Matrix4x4 scaleMatrix_ = {
		scale.x,0,0,0,
		0,scale.y,0,0,
		0,0,scale.z,0,
		0,0,0,1
	};
	return scaleMatrix_;
}

Matrix4x4 Mymath::MakeRotateXMatrix(float radian) {
	Matrix4x4 rotX_ = {
		1,0,0,0,
		0,std::cosf(radian),std::sinf(radian),0,
		0,-std::sinf(radian),std::cosf(radian),0,
		0,0,0,1
	};
	return rotX_;
}

Matrix4x4 Mymath::MakeRotateYMatrix(float radian) {
	Matrix4x4 rotY_ = {
		std::cosf(radian),0,-std::sinf(radian),0,
		0,1,0,0,
		std::sinf(radian),0,std::cosf(radian),0,
		0,0,0,1
	};
	return rotY_;
}

Matrix4x4 Mymath::MakeRotateZMatrix(float radian) {
	Matrix4x4 rotZ_ = {
		std::cosf(radian),std::sinf(radian),0,0,
		-std::sinf(radian),std::cosf(radian),0,0,
		0,0,1,0,
		0,0,0,1
	};
	return rotZ_;
}

Matrix4x4 Mymath::MakeRotateXYZMatrix(const Vector3& radian) {
	Matrix4x4 rotX_ = MakeRotateXMatrix(radian.x);
	Matrix4x4 rotY_ = MakeRotateYMatrix(radian.y);
	Matrix4x4 rotZ_ = MakeRotateZMatrix(radian.z);
	return Multiply(Multiply(rotX_, rotY_), rotZ_);
}

Matrix4x4 Mymath::MakeAffineMatrix(const Vector3& scale, const Vector3& rot, const Vector3& translate) {

	Matrix4x4 scaleMatrix_ = MakeScaleMatrix(scale);

	
	Matrix4x4 rotateMatrix_ = MakeRotateXYZMatrix(rot);

	Matrix4x4 translateMatrix_ = MakeTranslateMatrix(translate);

	return Multiply(Multiply(scaleMatrix_, rotateMatrix_), translateMatrix_);
}
// End Matrix4x4
#pragma endregion

// End Matrix
#pragma endregion