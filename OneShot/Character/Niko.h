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
	sf::Vector2f nikoPosition;

	std::list<GameObject*> getItems;
	std::list<GameObject*> useItems;

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

	const std::list<GameObject*>& GetItemList() const { return getItems; }
	const std::list<GameObject*>& UseItemList() const { return useItems; }

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

