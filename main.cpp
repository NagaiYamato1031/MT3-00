#include <Novice.h>
#include <cstdint>
#include <cmath>
#include "imgui.h"

#include "Mymath.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix4x4.h"

const char kWindowTitle[] = "LE2A_12_ナガイ_ヤマト_MT3_00_確認課題";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

namespace NS_Vector3 {
	const int kRowHeight = 20;
	const int kColumnWidth = 60;
}

namespace NS_Matrix4x4 {
	const int kRowHeight = 20;
	const int kColumnWidth = 68;
}


void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%0.2f", vector.x);
	Novice::ScreenPrintf(x + NS_Vector3::kColumnWidth, y, "%0.2f", vector.y);
	Novice::ScreenPrintf(x + NS_Vector3::kColumnWidth * 2, y, "%0.2f", vector.z);
	Novice::ScreenPrintf(x + NS_Vector3::kColumnWidth * 3, y, "%s", label);
}

void Matrix4x4ScreenPrintf(int x, int y, Matrix4x4 matrix, const char* label) {
	Novice::ScreenPrintf(x, y, "%s", label);
	for (int row = 0; row < 4; row++) {
		for (int column = 0; column < 4; column++) {
			Novice::ScreenPrintf(
				x + column * NS_Matrix4x4::kColumnWidth, y + (row + 1) * NS_Matrix4x4::kRowHeight, "%6.02f",
				matrix.m[row][column]);
		}
	}
}

void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	// Grid 半分の幅
	const float kGridHalfWidth = 2.0f;
	// 分割数
	const uint32_t kSubdivision = 10;
	// 1 つ分の長さ
	const float kGridEvery = (kGridHalfWidth * 2) / float(kSubdivision);
	// 奥から手前への線を引いていく
	// 今回はローカル座標で宣言
	Vector3 xOrigin{ 0.0f,0.0f,0.0f };
	Vector3 xVector{ 0.0f,0.0f,kGridHalfWidth * 2.0f };
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex) {
		// 始点と終点
		//Vector3 xStart{ (kSubdivision / 2.0f - xIndex) * kGridEvery,0.0f,kSubdivision * kGridEvery };
		//Vector3 xEnd{ (kSubdivision / 2.0f - xIndex) * kGridEvery,0.0f,-float(kSubdivision) * kGridEvery };
		// スクリーン座標まで変換を掛ける
		//Matrix4x4 startWorldMatrix = Mymath::MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, xOrigin);
		//Matrix4x4 endWorldMatrix = Mymath::MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, xVector);
		Matrix4x4 worldMatrix = Mymath::MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { (kSubdivision / 2.0f - xIndex) * kGridEvery,0.0f,-kGridHalfWidth });
		Matrix4x4 worldViewProjectionMatrix = Mymath::Multiply(worldMatrix, viewProjectionMatrix);

		Vector3 kLocalVertices[2]{ xOrigin,xVector };
		Vector3 screenVertices[2];
		for (uint32_t i = 0; i < 2; ++i) {
			Vector3 ndcVertex = Mymath::Transform(kLocalVertices[i], worldViewProjectionMatrix);
			screenVertices[i] = Mymath::Transform(ndcVertex, viewportMatrix);
		}
		if (xIndex != kSubdivision / 2) {
			Novice::DrawLine(int(screenVertices[0].x), int(screenVertices[0].y), int(screenVertices[1].x), int(screenVertices[1].y), 0xAAAAAAFF);
		}
		else {
			Novice::DrawLine(int(screenVertices[0].x), int(screenVertices[0].y), int(screenVertices[1].x), int(screenVertices[1].y), 0x222222FF);
		}
	}
	// 左から右への線を引いていく
	// 今回はローカル座標で宣言
	Vector3 zOrigin{ 0.0f,0.0f,0.0f };
	Vector3 zVector{ kGridHalfWidth * 2.0f,0.0f,0.0f };
	for (uint32_t zIndex = 0; zIndex <= kSubdivision; ++zIndex) {
		// スクリーン座標まで変換を掛ける
		Matrix4x4 worldMatrix = Mymath::MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, { -kGridHalfWidth,0.0f,(kSubdivision / 2.0f - zIndex) * kGridEvery });
		Matrix4x4 worldViewProjectionMatrix = Mymath::Multiply(worldMatrix, viewProjectionMatrix);

		Vector3 kLocalVertices[2]{ zOrigin,zVector };
		Vector3 screenVertices[2];
		for (uint32_t i = 0; i < 2; ++i) {
			Vector3 ndcVertex = Mymath::Transform(kLocalVertices[i], worldViewProjectionMatrix);
			screenVertices[i] = Mymath::Transform(ndcVertex, viewportMatrix);
		}
		if (zIndex != kSubdivision / 2) {
			Novice::DrawLine(int(screenVertices[0].x), int(screenVertices[0].y), int(screenVertices[1].x), int(screenVertices[1].y), 0xAAAAAAFF);
		}
		else {
			Novice::DrawLine(int(screenVertices[0].x), int(screenVertices[0].y), int(screenVertices[1].x), int(screenVertices[1].y), 0x222222FF);
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

	// クロス積
	Vector3 v1{ 1.2f,-3.9f,2.5f };
	Vector3 v2{ 2.8f,0.4f,-1.3f };
	Vector3 cross = Mymath::Cross(v1, v2);

	// 三角形の回転
	Vector3 rotate{};
	Vector3 translate{};

	Vector3 cameraPosition{ 0.0f,1.9f,-6.49f };
	Vector3 cameraRotate{ 0.26f,0.0f,0.0f };


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

		rotate.y += 0.03f;
		float kTranslateMove = 0.03f;
		if (Novice::CheckHitKey(DIK_W)) {
			translate.z += kTranslateMove;
		}
		if (Novice::CheckHitKey(DIK_S)) {
			translate.z -= kTranslateMove;
		}
		if (Novice::CheckHitKey(DIK_A)) {
			translate.x -= kTranslateMove;
		}
		if (Novice::CheckHitKey(DIK_D)) {
			translate.x += kTranslateMove;
		}


		// 各種行列の計算
		Matrix4x4 worldMatrix = Mymath::MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		Matrix4x4 cameraMatrix = Mymath::MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraPosition);
		Matrix4x4 viewMatrix = Mymath::Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = Mymath::MakePerspectiveFovMatrix(0.45f, float(kWindowWidth) / float(kWindowHeight), 0.1f, 100.0f);
		// viewProjectionMatrix
		Matrix4x4 viewProjectionMatrix = Mymath::Multiply(viewMatrix, projectionMatrix);
		Matrix4x4 worldViewProjectionMatrix = Mymath::Multiply(worldMatrix, viewProjectionMatrix);
		Matrix4x4 viewportMatrix = Mymath::MakeViewportMatrix(0, 0, float(kWindowWidth), float(kWindowHeight), 0.0f, 1.0f);
		Vector3 kLocalVertices[3];
		// 左下
		kLocalVertices[0] = { -0.5f,-0.5f,0.0f };
		// 上
		kLocalVertices[1] = { 0.0f,0.5f,0.0f };
		// 右下
		kLocalVertices[2] = { 0.5f,-0.5f,0.0f };
		Vector3 screenVertices[3];
		for (uint32_t i = 0; i < 3; ++i) {
			Vector3 ndcVertex = Mymath::Transform(kLocalVertices[i], worldViewProjectionMatrix);
			screenVertices[i] = Mymath::Transform(ndcVertex, viewportMatrix);
		}



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		DrawGrid(viewProjectionMatrix, viewportMatrix);

		Vector3 triCross = Mymath::Cross(
			screenVertices[0] - screenVertices[1],
			screenVertices[1] - screenVertices[2]
		);

		VectorScreenPrintf(0, 0, cross, "Cross");
		if (Mymath::Dot(triCross, cameraPosition) <= 0.0f) {
			Novice::DrawTriangle(int(screenVertices[0].x), int(screenVertices[0].y), int(screenVertices[1].x), int(screenVertices[1].y),
				int(screenVertices[2].x), int(screenVertices[2].y), RED, kFillModeSolid);
		}

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

