#include "Fire.h"

Fire::Fire(const std::string& name)
	:GameObject(name)
{
}

void Fire::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Fire::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Fire::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Fire::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Fire::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Fire::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect Fire::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Fire::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Fire::Init()
{
	std::string textureId = "Graphics/Characters/fire.png";
}

void Fire::Release()
{
}

void Fire::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/fire.png"));
	SetOrigin(Origins::TL);
}

void Fire::Update(float dt)
{

}

void Fire::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
