#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Sofa : public GameObject
{
protected:
	sf::Sprite body;

	sf::Vector2f pos;

public:
	Sofa(const std::string& name = "");
	~Sofa() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	sf::Sprite GetSprite() { return body; }
	sf::Vector2f GetPosition();
	sf::FloatRect GetLocalBounds() const override;
	sf::FloatRect GetGlobalBounds() const override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

