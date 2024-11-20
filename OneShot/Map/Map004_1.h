#pragma once
#include "stdafx.h"
#include "Scene.h"

class Message;
class Niko;

class Map004_1 : public Scene
{
protected:
	SpriteGo* map004_1;
	Niko* niko;
	Message* text;

	sf::RectangleShape rect[2];

	sf::Vector2f mapScale = { 2.f, 2.f };

public:
	Map004_1();
	~Map004_1() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

