#include "Novice.h"
#include "Enemy.h"

Enemy::Enemy(Transform transform, int rds, int spe, int a) {
	transform_ = transform;
	radi_ = rds;
	speed_ = spe;
	Alive = a;
}

Enemy::~Enemy() {

}

void Enemy::Update(char* keys, char* preKeys) {
	transform_.x += speed_;
	if (Alive == 0) {
		if (transform_.x < radi_) {
			speed_ = 10;
		}
		if (transform_.x > 1280 - radi_) {
			speed_ -= 10;
		}
	}
	if (keys[DIK_R] && preKeys[DIK_R]) {
		Alive = false;
	}
}

void Enemy::Draw() {
	if (Alive == false) {
		Novice::DrawEllipse(transform_.x, transform_.y, radi_, radi_, 0.0f, RED, kFillModeSolid);
	}
}