#include "DryFlower.h"

DryFlower::DryFlower(const std::string& name)
	:GameObject(name)
{
}

void DryFlower::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void DryFlower::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void DryFlower::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void DryFlower::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void DryFlower::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f DryFlower::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect DryFlower::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect DryFlower::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void DryFlower::Init()
{
	std::string textureId = "Graphics/Characters/dryflower.png";
}

void DryFlower::Release()
{
	
}

void DryFlower::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/dryflower.png"));
	SetOrigin(Origins::TL);
}

void DryFlower::Update(float dt)
{
	sf::FloatRect dryflowerFloatRect = body.getGlobalBounds();

	hitbox.UpdateTr(body, { dryflowerFloatRect.left,
						 dryflowerFloatRect.top,
						 dryflowerFloatRect.width * 0.5f,
						 dryflowerFloatRect.height * 0.5f });
}

void DryFlower::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
