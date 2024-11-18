#include "ObjectHitBox.h"

sf::RectangleShape ObjectHitBox::rect(sf::Vector2f(100.f, 100.f));

ObjectHitBox::ObjectHitBox(const std::string& name)
    :GameObject(name)
{
}

void ObjectHitBox::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    square.setPosition(position);
}

void ObjectHitBox::SetRotation(float angle)
{
    rotation = angle;
    square.setRotation(rotation);
}

void ObjectHitBox::SetScale(const sf::Vector2f& scale)
{
    this->scale = scale;
    square.setScale(this->scale);
}

sf::FloatRect ObjectHitBox::GetLocalBounds() const
{
    return square.getLocalBounds();
}

sf::FloatRect ObjectHitBox::GetGlobalBounds() const
{
    return square.getGlobalBounds();
}

void ObjectHitBox::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(square, originPreset);
    }
}

void ObjectHitBox::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = newOrigin;
    square.setOrigin(origin);
}

sf::Vector2f ObjectHitBox::GetPosition()
{
    pos = square.getPosition();
    return pos;
}

void ObjectHitBox::Init()
{
    std::string textureId = "Graphics/Characters/rect3226.png";

    Utils::SetOrigin(rect, Origins::BC);
    rect.setSize({ 64, 64 });
    rect.setPosition(square.getPosition());
}

void ObjectHitBox::Release()
{
}

void ObjectHitBox::Reset()
{
    square.setTexture(TEXTURE_MGR.Get("Graphics/Characters/rect3226.png"));
    SetOrigin(Origins::BC);
}

void ObjectHitBox::Update(float dt)
{
    debugBox.SetBounds(square.getGlobalBounds());
}

void ObjectHitBox::Draw(sf::RenderWindow& window)
{
    debugBox.Draw(window);
    window.draw(square);
}

void ObjectHitBox::SetDebugBoxOutlineColor(const sf::Color& color)
{
    debugBox.SetOutlineColor(color);
}
