#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Niko :  public GameObject
{
public:
	struct ClipInfo
	{
		std::string idle;
		std::string move;
		//bool flipX = false;
		//sf::Vector2f point;
	};

protected:
	sf::Sprite body;
	Animator animator;

	sf::Vector2f direction;
	float speed = 100.f;

	std::map<std::string, AnimationClip> temp;
	std::vector<ClipInfo> clipInfos;
	int currentClipIndex;

	sf::Vector2f velocity = { 0.f, 0.f };

	DebugBox debugBox;

public:
	Niko(const std::string& name = "");
	~Niko() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	sf::Sprite GetSprite() { return body; }

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void SetSpeed(float speed);
	float GetSpeed() { return speed; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetDebugBoxOutlineColor(const sf::Color& color);

};

