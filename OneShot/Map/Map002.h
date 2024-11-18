#pragma once
#include "stdafx.h"
#include "Scene.h"

class Niko;
class ObjectHitBox;
class Message;

class Map002 : public Scene
{
protected:
	SpriteGo* map002;
	Animator animator;
	Niko* niko;
	ObjectHitBox* hitbox;
	Message* text;

	bool isCollision = false;
	bool getBranch = false;

	static sf::RectangleShape nikoRect;
	static sf::RectangleShape flowerRect;
	static sf::RectangleShape sinkRect;
	static sf::RectangleShape toiletRect;
	static sf::RectangleShape bathRect;
	static sf::RectangleShape rect;

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

