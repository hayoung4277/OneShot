#pragma once
#include "stdafx.h"

class SpriteGo;
class Niko;
class Remocon;
class Computer;
class BookCase;
class ObjectHitBox;
class HitBox;
class Message;

class Map001 : public Scene
{
protected:
	SpriteGo* map001;
	Animator animator;
	Niko* niko;
	Remocon* remocon;
	Computer* computer;
	BookCase* bookcase;
	ObjectHitBox* square;
	Message* text;

	DebugBox debugBox;

	static sf::RectangleShape nikoRect;
	static sf::RectangleShape remoconRect;
	static sf::RectangleShape rect1;
	static sf::RectangleShape rect2;
	static sf::RectangleShape computerRect;

	bool getRemocon = false;
	bool isCollision = false;
	bool solvePassword = false;

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

