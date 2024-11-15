#pragma once
#include "stdafx.h"

class SpriteGo;
class Niko;
class Remocon;
class Computer;
class HitBox;

class Map001 : public Scene
{
protected:
	SpriteGo* map001;
	Animator animator;
	Niko* niko;
	Remocon* remocon;
	Computer* computer;

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

