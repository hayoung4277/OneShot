#include "ItemStar.h"

ItemStar::ItemStar(const std::string& name)
	:GameObject(name)
{
}

void ItemStar::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void ItemStar::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void ItemStar::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void ItemStar::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void ItemStar::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f ItemStar::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect ItemStar::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect ItemStar::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void ItemStar::Init()
{
	std::string textureId = "Graphics/Characters/itemstar.png";
}

void ItemStar::Release()
{
}

void ItemStar::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/itemstar.png"));
	SetOrigin(Origins::TL);
}

void ItemStar::Update(float dt)
{
	sf::FloatRect starFloatRect = body.getGlobalBounds();

	hitbox.UpdateTr(body, { starFloatRect.left, starFloatRect.top,
							starFloatRect.width * 0.5f,
							starFloatRect.height * 0.5f });
}

void ItemStar::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
