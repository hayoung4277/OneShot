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

	int beforeScene = 1;

	std::string textureId = "Graphics/Characters/niko.png";

	sf::Vector2f direction;
	sf::Vector2f lastDirection = { 0.f, 0.f };
	float speed = 100.f;

	std::map<std::string, AnimationClip> temp;
	std::vector<ClipInfo> clipInfos;
	int currentClipIndex;

	sf::Vector2f velocity = { 0.f, 0.f };
	sf::Vector2f nikoPosition;

	bool getBranch = false;
	bool isBulb = false;

public:
	Niko(const std::string& name = "");
	~Niko() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	sf::Sprite GetSprite() { return body; }
	sf::FloatRect GetLocalBounds() const override;
	sf::FloatRect GetGlobalBounds() const override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;

	void SetSpeed(float speed);
	sf::Vector2f GetPosition();

	void SetBranchGet();
	bool IsGetBranch() { return getBranch; }

	void SetBeforeScene(int current);
	int GetBeforeScene() { return beforeScene; }

	void SetTextureId(const std::string& id);
	void SetISBulb(bool is);
	bool GetIsBulb() { return isBulb; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

