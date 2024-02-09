#pragma once
#include "struct.h"

class Enemy {
protected:
public:
	static int Alive;

	Transform transform_;
	int radi_;
	int speed_;

	Enemy(Transform transform, int radi, int spd, int a);
	~Enemy();
	void Update(char* keys, char* preKeys);
	void Draw();
};