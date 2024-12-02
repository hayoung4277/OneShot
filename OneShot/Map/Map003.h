#pragma once
#include "stdafx.h"
#include "Scene.h"

class Niko;
class TV;
class FirePlace;
class Sofa;
class Refrigerator;
class Sink;
class Door;
class LightDoor;
class Message;
class Fire;
class ItemStar;

class Map003 : public Scene
{
protected:
	SpriteGo* map003;
	Niko* niko;
	TV* tv;
	FirePlace* fireplace;
	Sofa* sofa;
	Refrigerator* re;
	Sink* sink;
	Door* door;
	LightDoor* lightdoor;
	Message* text;
	Fire* fire;
	ItemStar* itemStar;

	SpriteGo* lightdoorSprite;

	sf::RectangleShape rect;

	sf::RectangleShape reRect;
	sf::RectangleShape fpRect;
	sf::RectangleShape tvRect;

	bool getBottle = false;
	bool getBranch = true;
	bool getFiredBranch = false;
	bool getKey = false;
	bool lock = false;
	bool isCollision = false;
	bool isTextVisible = false;

public:
	Map003();
	~Map003() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

