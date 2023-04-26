#include <Novice.h>

#include "Mymath.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

const char kWindowTitle[] = "LE2A_12_ナガイ_ヤマト_MT3_00_確認課題";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

namespace NS_Matrix4x4 {
	const int kRowHeight = 20;
	const int kColumnWidth = 68;
}

void Matrix4x4ScreenPrintf(int x, int y, Matrix4x4 matrix) {
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			Novice::ScreenPrintf(
				x + column * NS_Matrix4x4::kColumnWidth, y + row * NS_Matrix4x4::kRowHeight, "%6.02f",
				matrix.m[row][column]);
		}
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Matrix4x4 m1 = {
		3.2f, 0.7f, 9.6f, 4.4f,
		5.5f, 1.3f, 7.8f, 2.1f,
		6.9f, 8.0f, 2.6f, 1.0f,
		0.5f, 7.2f, 5.1f, 3.3f
	};
	Matrix4x4 m2 = {
		4.1f, 6.5f, 3.3f, 2.2f,
		8.8f, 0.6f, 9.9f, 7.7f,
		1.1f, 5.5f, 6.6f, 0.0f,
		3.3f, 9.9f, 8.8f, 2.2f
	};

	Matrix4x4 resultAdd = Mymath::Add(m1, m2);
	Matrix4x4 resultMultiply = Mymath::Multiply(m1, m2);
	Matrix4x4 resultSubtract = Mymath::Subtract(m1, m2);
	Matrix4x4 inverseM1 = Mymath::Inverse(m1);
	Matrix4x4 inverseM2 = Mymath::Inverse(m2);
	Matrix4x4 transposeM1 = Mymath::Transpose(m1);
	Matrix4x4 transposeM2 = Mymath::Transpose(m2);
	Matrix4x4 identity = Mymath::MakeIdentity4x4();


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Matrix4x4ScreenPrintf(0, 0, resultAdd);
		Matrix4x4ScreenPrintf(0, NS_Matrix4x4::kRowHeight * 5, resultSubtract);
		Matrix4x4ScreenPrintf(0, NS_Matrix4x4::kRowHeight * 5 * 2, resultMultiply);
		Matrix4x4ScreenPrintf(0, NS_Matrix4x4::kRowHeight * 5 * 3, inverseM1);
		Matrix4x4ScreenPrintf(0, NS_Matrix4x4::kRowHeight * 5 * 4, inverseM2);
		Matrix4x4ScreenPrintf(NS_Matrix4x4::kColumnWidth * 5, 0, transposeM1);
		Matrix4x4ScreenPrintf(NS_Matrix4x4::kColumnWidth * 5, NS_Matrix4x4::kRowHeight * 5, transposeM2);
		Matrix4x4ScreenPrintf(NS_Matrix4x4::kColumnWidth * 5, NS_Matrix4x4::kRowHeight * 5 * 2, identity);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

