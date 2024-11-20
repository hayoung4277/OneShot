#include "Toilet.h"

Toilet::Toilet(const std::string& name)
	:GameObject(name)
{
}

void Toilet::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Toilet::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Toilet::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Toilet::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Toilet::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Toilet::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect Toilet::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Toilet::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Toilet::Init()
{
	std::string textureId = "Graphics/Characters/toilet.png";
}

void Toilet::Release()
{
	
}

void Toilet::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/toilet.png"));
	SetOrigin(Origins::TL);
}

void Toilet::Update(float dt)
{
	sf::FloatRect toiletFloatRect = body.getGlobalBounds();

	hitbox.UpdateTr(body, { toiletFloatRect.left,
						 toiletFloatRect.top,
						 toiletFloatRect.width * 0.5f,
						 toiletFloatRect.height * 0.3f });
}

void Toilet::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
