#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Remocon : public GameObject
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

	std::map<std::string, AnimationClip> temp;
	std::vector<ClipInfo> clipInfos;
	int cuurentClipIndex;

	DebugBox debugBox;

public:
	Remocon(const std::string& name = "");
	~Remocon() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	sf::Sprite GetSprite() { return body; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetDebugBoxOutlineColor(const sf::Color& color);

};

