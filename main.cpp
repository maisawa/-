#include <Novice.h>
#include "player.h"
#include "Enemy.h"
#include "bullet.h"
#include <iostream>
using namespace std;

const char kWindowTitle[] = "GC1B_14_マイサワ_ショウマ";

int Enemy::Alive;


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {


	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player({ 600,450 }, 25, 10);

	Enemy* enemy1 = new Enemy({ 200,100 }, 15, 10, 0);
	Enemy* enemy2 = new Enemy({ 200,300 }, 15, 10, 0);

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

		player->Update(keys, preKeys);
		enemy1->Update(keys, preKeys);
		enemy2->Update(keys, preKeys);

		int dis1 = player->bullet_->transform_.x - enemy1->transform_.x;
		int dis2 = player->bullet_->transform_.y - enemy1->transform_.y;
		int dis3 = player->bullet_->transform_.x - enemy2->transform_.x;
		int dis4 = player->bullet_->transform_.y - enemy2->transform_.y;
		int a = (int)sqrtf((float)dis1 * (float)dis1 + (float)dis2 * (float)dis2);
		int b = (int)sqrtf((float)dis3 * (float)dis3 + (float)dis4 * (float)dis4);

		if (a <= (player->bullet_->r_ + enemy1->radi_) || b <= (player->bullet_->r_ + enemy2->radi_)) {
			Enemy::Alive = true;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		enemy1->Draw();
		enemy2->Draw();

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
	delete player;
	delete enemy1;
	delete enemy2;
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}