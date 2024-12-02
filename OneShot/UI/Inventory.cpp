#include "Inventory.h"

Inventory::Inventory(const std::string& name)
    :GameObject(name)
{
}

void Inventory::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void Inventory::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void Inventory::SetScale(const sf::Vector2f& s)
{

    scale = s;
    body.setScale(scale);
}

void Inventory::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void Inventory::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Inventory::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect Inventory::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect Inventory::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void Inventory::Init()
{
    std::string textureId = "Graphics/Windowskins/inventoryUI.png";
}

void Inventory::Release()
{
}

void Inventory::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/Windowskins/inventoryUI.png"));
    SetOrigin(Origins::MC);
}

void Inventory::Update(float dt)
{
    sf::FloatRect inventoryFloatRect = body.getGlobalBounds();

    hitbox.UpdateTr(body, { inventoryFloatRect.left,
                         inventoryFloatRect.top,
                         inventoryFloatRect.width * 0.5f,
                         inventoryFloatRect.height * 0.2f });
}

void Inventory::Draw(sf::RenderWindow& window)
{
    hitbox.Draw(window);
    window.draw(body);
}
