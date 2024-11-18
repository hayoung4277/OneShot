#include "Door.h"

Door::Door(const std::string& name)
	:GameObject(name)
{
}

void Door::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Door::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Door::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Door::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Door::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Door::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect Door::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Door::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Door::Init()
{
	std::string textureId = "Graphics/Characters/door.png";
}

void Door::Release()
{
}

void Door::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/door.png"));
	SetOrigin(Origins::TL);
}

void Door::Update(float dt)
{
	sf::FloatRect doorFloatRect = body.getGlobalBounds();

	hitbox.UpdateTr(body, { doorFloatRect.left,
						 doorFloatRect.top,
						 doorFloatRect.width * 0.5f,
						 doorFloatRect.height * 0.2f });
}

void Door::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
