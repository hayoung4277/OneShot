#pragma once
#include "stdafx.h"
#include "GameObject.h"

class TransfomableRect : public GameObject
{
public:
	TransfomableRect();

	sf::Transformable rect;

	void SetPosition(sf::Vector2f& pos);
	void SetScale(sf::Vector2f& scale);
};

