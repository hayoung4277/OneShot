#pragma once
#include "stdafx.h"

class SpriteGo;
class Neko;
class Remocon;
class HitBox;

class Map001 : public Scene
{
protected:
	SpriteGo* map001;
	Animator animator;
	Neko* niko;
	Remocon* remocon;

	float collisionDelay = 5.f;

	bool getRemocon = false;

	bool isCollision = false;

	sf::Vector2f mapScale = {2.f, 2.f};
	
public:
	Map001();
	~Map001() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

