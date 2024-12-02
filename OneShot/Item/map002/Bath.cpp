#include "Bath.h"

Bath::Bath(const std::string& name)
	:GameObject(name)
{
}

void Bath::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Bath::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Bath::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Bath::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Bath::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Bath::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect Bath::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Bath::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Bath::Init()
{
	std::string textureId = "Graphics/Characters/bath.png";
}

void Bath::Release()
{
}

void Bath::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/bath.png"));
	SetOrigin(Origins::TL);
}

void Bath::Update(float dt)
{
	sf::FloatRect bathFloatRect = body.getGlobalBounds();

	hitbox.UpdateTr(body, { bathFloatRect.left,
						 bathFloatRect.top,
						 bathFloatRect.width * 0.5f,
						 bathFloatRect.height * 0.2f });
}

void Bath::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
