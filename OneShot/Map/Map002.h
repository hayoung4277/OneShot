#pragma once
#include "stdafx.h"
#include "Scene.h"

class Niko;

class Map002 : public Scene
{
protected:
	SpriteGo* map002;
	Animator animator;
	Niko* niko;

	float collisionDelay = 5.f;

	bool getRemocon = false;

	bool isCollision = false;

	sf::Vector2f mapScale = { 2.f, 2.f };

public:
	Map002();
	~Map002() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

