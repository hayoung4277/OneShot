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

	SpriteGo* lightdoorSprite;

public:
	Map003();
	~Map003() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

