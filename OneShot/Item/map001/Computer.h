#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Computer : public GameObject
{
public:
	struct ClipInfo
	{
	std::string idle;
	std::string move;
	};

protected:
	sf::Sprite body;
	Animator animator;

	sf::Vector2f pos;

	DebugBox debugBox;
	HitBox hitbox;

public:
	Computer(const std::string& name = "");
	~Computer() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	sf::Sprite GetSprite() { return body; }
	sf::Vector2f GetPositoin();

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

