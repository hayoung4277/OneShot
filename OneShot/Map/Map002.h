#pragma once
#include "stdafx.h"
#include "Scene.h"

class Niko;
class ObjectHitBox;
class Message;
class Bath;
class DryFlower;
class Toilet;
class ToiletSink;

class Map002 : public Scene
{
protected:
	SpriteGo* map002;
	Animator animator;
	Niko* niko;
	Message* text;
	Bath* bath;
	DryFlower* dryflower;
	Toilet* toilet;
	ToiletSink* sink;

	bool getBranch = false;
	bool isTextVisible = false;

	sf::RectangleShape doorRect;

	HitBox hitbox[4];
	sf::RectangleShape hitboxRects[4];
	sf::FloatRect rects[4];

	sf::RectangleShape flowerRect;

	sf::Vector2f mapScale = { 1.f, 1.f };

public:
	Map002();
	~Map002() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

