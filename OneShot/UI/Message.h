#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Message : public GameObject
{
protected:

	sf::Text message;

	sf::Vector2f pos = FRAMEWORK.GetWindowSizeF() * 0.5f;

public:
	Message(const std::string& name = "");
	~Message() = default;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetRotation(float angle) override;
	void SetScale(const sf::Vector2f& scale) override;

	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetString(const sf::String& str);
	/*void SetString(int s);*/
	void SetStringSize(int size);

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

