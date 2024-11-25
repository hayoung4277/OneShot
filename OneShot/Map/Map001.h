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
class AniNiko;

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
	sf::Vector2f passwordPos = {430.f, 300.f};

	HitBox hitbox[6];
	sf::FloatRect rects[6];
	sf::Vector2f Pos[6];

	sf::RectangleShape rect[8];
	sf::RectangleShape passwordRect[4];

	sf::RectangleShape windowRect;
	sf::RectangleShape computerRect;
	sf::RectangleShape remoconRect;

	bool getRemocon = false;
	bool isCollision = false;
	bool solvePassword = false;
	bool passwordIsActive = false;
	bool getBranch = false;
	bool isTextVisible = false;

	int s = 0;
	int selectIndex = 0;

	sf::Vector2f mapScale = {1.f, 1.f};
	sf::Vector2f mapPosition = FRAMEWORK.GetWindowSizeF();
	
public:
	Map001();
	~Map001() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

