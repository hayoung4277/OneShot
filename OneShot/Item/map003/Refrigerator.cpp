#include "Refrigerator.h"

Refrigerator::Refrigerator(const std::string& name)
	:GameObject(name)
{
}

void Refrigerator::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Refrigerator::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Refrigerator::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Refrigerator::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Refrigerator::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Refrigerator::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect Refrigerator::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Refrigerator::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Refrigerator::Init()
{
	std::string textureId = "Graphics/Characters/refrigerator.png";
}

void Refrigerator::Release()
{
}

void Refrigerator::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/refrigerator.png"));
	SetOrigin(Origins::TL);
}

void Refrigerator::Update(float dt)
{
	sf::FloatRect reFloatRect = body.getGlobalBounds();

	hitbox.UpdateTr(body, { reFloatRect.left,
						 reFloatRect.top,
						 reFloatRect.width * 0.5f,
						 reFloatRect.height * 0.4f });
}

void Refrigerator::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
