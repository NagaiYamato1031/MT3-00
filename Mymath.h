#pragma once

//struct Matrix3x3 {
//	float m[3][3];
//};


struct Vector2;
struct Vector3;
struct Vector4;

struct Matrix3x3
{
	float m[3][3];
};
struct Matrix4x4;

namespace Mymath
{

#pragma region Vector

#pragma region Vector2



	// End Vector2
#pragma endregion

#pragma region Vector3

	/// <summary>
	/// �x�N�g���̉��Z
	/// </summary>
	/// <param name="v1">�x�N�g���P</param>
	/// <param name="v2">�x�N�g���Q</param>
	/// <returns>���Z���ꂽ�x�N�g��</returns>
	Vector3 Add(const Vector3& v1, const Vector3& v2);

	/// <summary>
	/// �x�N�g���̌��Z
	/// </summary>
	/// <param name="v1">�x�N�g���P</param>
	/// <param name="v2">�x�N�g���Q</param>
	/// <returns>���Z���ꂽ�x�N�g��</returns>
	Vector3 Subtract(const Vector3& v1, const Vector3& v2);

	/// <summary>
	/// �x�N�g���̏�Z
	/// </summary>
	/// <param name="scalar">�X�J���[</param>
	/// <param name="v">�x�N�g��</param>
	/// <returns>��Z���ꂽ�x�N�g��</returns>
	Vector3 Multiply(float scalar, const Vector3& v);

	/// <summary>
	/// �x�N�g���̓���
	/// </summary>
	/// <param name="v1">�x�N�g���P</param>
	/// <param name="v2">�x�N�g���Q</param>
	/// <returns>����</returns>
	float Dot(const Vector3& v1, const Vector3& v2);

	/// <summary>
	/// �x�N�g���̒���
	/// </summary>
	/// <param name="v">�x�N�g��</param>
	/// <returns>�x�N�g���̒���</returns>
	float Length(const Vector3& v);

	/// <summary>
	/// �x�N�g���̐��K��
	/// </summary>
	/// <param name="v">�x�N�g��</param>
	/// <returns>���K�����ꂽ�x�N�g��</returns>
	Vector3 Normalize(const Vector3& v);

	// End Vector3
#pragma endregion

#pragma region Vecotor4

	/// <summary>
	/// �x�N�g���̉��Z
	/// </summary>
	/// <param name="v1">�x�N�g���P</param>
	/// <param name="v2">�x�N�g���Q</param>
	/// <returns>���Z���ꂽ�x�N�g��</returns>
	Vector4 Add(const Vector4& v1, const Vector4& v2);

	/// <summary>
	/// �x�N�g���̌��Z
	/// </summary>
	/// <param name="v1">�x�N�g���P</param>
	/// <param name="v2">�x�N�g���Q</param>
	/// <returns>���Z���ꂽ�x�N�g��</returns>
	Vector4 Subtract(const Vector4& v1, const Vector4& v2);

	/// <summary>
	/// �x�N�g���̏�Z
	/// </summary>
	/// <param name="scalar">�X�J���[</param>
	/// <param name="v">�x�N�g��</param>
	/// <returns>��Z���ꂽ�x�N�g��</returns>
	Vector4 Multiply(float scalar, const Vector4& v);

	/// <summary>
	/// �x�N�g���̓���
	/// </summary>
	/// <param name="v1">�x�N�g���P</param>
	/// <param name="v2">�x�N�g���Q</param>
	/// <returns>����</returns>
	float Dot(const Vector4& v1, const Vector4& v2);

	/// <summary>
	/// �x�N�g���̒���
	/// </summary>
	/// <param name="v">�x�N�g��</param>
	/// <returns>�x�N�g���̒���</returns>
	float Length(const Vector4& v);

	/// <summary>
	/// �x�N�g���̐��K��
	/// </summary>
	/// <param name="v">�x�N�g��</param>
	/// <returns>���K�����ꂽ�x�N�g��</returns>
	Vector4 Normalize(const Vector4& v);

	// End Vecotr4
#pragma endregion

	// End Vector
#pragma endregion


#pragma region Matrix

#pragma region Matrix3x3



	// End Matrix3x3
#pragma endregion


#pragma region Matrix4x4

	/// <summary>
	/// �s��̉��Z
	/// </summary>
	/// <param name="m1">�s��P</param>
	/// <param name="m2">�s��Q</param>
	/// <returns>���Z���ꂽ�s��</returns>
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// �s��̌��Z
	/// </summary>
	/// <param name="m1">�s��P</param>
	/// <param name="m2">�s��Q</param>
	/// <returns>���Z���ꂽ�s��</returns>
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// �s��̏�Z
	/// </summary>
	/// <param name="m1">�s��P</param>
	/// <param name="m2">�s��Q</param>
	/// <returns><��Z���ꂽ�s��/returns>
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	/// <summary>
	/// �t�s��
	/// </summary>
	/// <param name="matrix">�s��</param>
	/// <returns>�t�s��</returns>
	Matrix4x4 Inverse(const Matrix4x4& matrix);

	/// <summary>
	/// �]�u�s��
	/// </summary>
	/// <param name="matrix">�s��</param>
	/// <returns>�]�u�s��</returns>
	Matrix4x4 Transpose(const Matrix4x4& matrix);

	/// <summary>
	/// 4x4 �P�ʍs��
	/// </summary>
	/// <returns>4x4 �P�ʍs��</returns>
	Matrix4x4 MakeIdentity4x4();

	/// <summary>
	/// 4x4 �A�t�B���s��
	/// </summary>
	/// <param name="scale">�X�P�[��</param>
	/// <param name="rotate">��]</param>
	/// <param name="translate">�ړ�</param>
	/// <returns>4x4 �A�t�B���s��</returns>
	Matrix4x4 MakeAffineMatrix4x4(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

	// End Matrix4x4
#pragma endregion

	// End Matrix
#pragma endregion

}