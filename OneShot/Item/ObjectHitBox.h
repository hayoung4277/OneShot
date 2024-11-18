#pragma once
#include "stdafx.h"
#include "GameObject.h"

class ObjectHitBox : public GameObject
{
protected:
	sf::Sprite square;

	sf::Vector2f size;

	static sf::RectangleShape rect;
	sf::Vector2f pos;

	DebugBox debugBox;

public:
	ObjectHitBox(const std::string& name = "");
	~ObjectHitBox() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	sf::FloatRect GetLocalBounds() const override;
	sf::FloatRect GetGlobalBounds() const override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	sf::RectangleShape GetRectangleShape() { return rect; }
	sf::Vector2f GetPosition();

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetDebugBoxOutlineColor(const sf::Color& color);
};

