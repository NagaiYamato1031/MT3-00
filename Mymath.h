#pragma once

//struct Matrix3x3 {
//	float m[3][3];
//};

namespace Mymath
{

	struct Matrix4x4;

	struct Vector2;
	struct Vector3;
	struct Vector4;

	//Matrix3x3 MakeAffineMatrix(const Vector2& scale, const Vector2& rotate, const Vector2& translate);
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

}