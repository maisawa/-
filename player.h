#pragma once
#include "bullet.h"

class Player {
public:
	Bullet* bullet_;
	Transform transform_;
	int radius_;
	int speed_;

public:
	Player(Transform transform, int radius, int speed);
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
};