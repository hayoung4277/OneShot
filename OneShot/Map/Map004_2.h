#pragma once
#include "stdafx.h"
#include "Scene.h"

class Niko;
class Message;
class Bulb;

class Map004_2 : public Scene
{
protected:
	SpriteGo* map004_2;
	Niko* niko;
	Message* text;
	Bulb* bulb;

	bool isBulbOn = false;

	sf::RectangleShape rect[2];

	sf::Vector2f mapScale = { 2.f, 2.f };

public:
	Map004_2();
	~Map004_2() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

