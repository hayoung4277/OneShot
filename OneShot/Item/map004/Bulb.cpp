#include "Bulb.h"

Bulb::Bulb(const std::string& name)
	:GameObject(name)
{
}

void Bulb::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Bulb::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Bulb::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Bulb::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Bulb::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Bulb::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect Bulb::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Bulb::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Bulb::SetTexture(const std::string& tex)
{
	textureId = tex;
}

void Bulb::Init()
{
}

void Bulb::Release()
{
}

void Bulb::Reset()
{
	body.setTexture(TEXTURE_MGR.Get(textureId));
	SetOrigin(Origins::TL);
}

void Bulb::Update(float dt)
{
	sf::FloatRect bulbFloatRect = body.getGlobalBounds();

	hitbox.UpdateTr(body, { bulbFloatRect.left,
						 bulbFloatRect.top,
						 bulbFloatRect.width * 0.5f,
						 bulbFloatRect.height * 0.5f });
}

void Bulb::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
