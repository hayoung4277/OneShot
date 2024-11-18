#include "LightDoor.h"

LightDoor::LightDoor(const std::string& name)
    :GameObject(name)
{
}

void LightDoor::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void LightDoor::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void LightDoor::SetScale(const sf::Vector2f& s)
{
    scale = s;
    body.setScale(scale);
}

void LightDoor::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void LightDoor::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f LightDoor::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect LightDoor::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect LightDoor::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void LightDoor::Init()
{
    std::string textureId = "Graphics/Characters/lightdoor.png";
}

void LightDoor::Release()
{
}

void LightDoor::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/lightdoor.png"));
    SetOrigin(Origins::TL);
}

void LightDoor::Update(float dt)
{
    sf::FloatRect lightdoorFloatRect = body.getGlobalBounds();

    hitbox.UpdateTr(body, { lightdoorFloatRect.left,
                         lightdoorFloatRect.top,
                         lightdoorFloatRect.width * 0.5f,
                         lightdoorFloatRect.height * 0.4f });
}

void LightDoor::Draw(sf::RenderWindow& window)
{
    hitbox.Draw(window);
    window.draw(body);
}
