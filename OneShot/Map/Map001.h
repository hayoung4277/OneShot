#pragma once
#include "stdafx.h"
#include "Scene.h"

class Niko;
class Remocon;
class Computer;
class BookCase;
class ObjectHitBox;
class HitBox;
class Message;
class Button;
class Inventory;

class Map001 : public Scene
{
protected:
	SpriteGo* map001;
	Animator animator;
	Niko* niko;
	Remocon* remocon;
	Computer* computer;
	BookCase* bookcase;
	Message* text;
	Inventory* inventory;

	Button* password[4];
	sf::Vector2f passwordPos = {100.f, 100.f};

	sf::RectangleShape rect[5];
	sf::RectangleShape passwordRect[4];

	bool getRemocon = false;
	bool isCollision = false;
	bool solvePassword = false;
	bool passwordIsActive = false;
	bool a = false;

	int s = 0;
	int selectIndex = 0;

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

