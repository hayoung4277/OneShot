#include "FirePlace.h"

FirePlace::FirePlace(const std::string& name)
    :GameObject(name)
{
}

void FirePlace::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void FirePlace::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void FirePlace::SetScale(const sf::Vector2f& s)
{
    scale = s;
    body.setScale(scale);
}

void FirePlace::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void FirePlace::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f FirePlace::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect FirePlace::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect FirePlace::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void FirePlace::Init()
{
    std::string textureId = "Graphics/Characters/fireplace.png";
}

void FirePlace::Release()
{
}

void FirePlace::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/fireplace.png"));
    SetOrigin(Origins::TL);
}

void FirePlace::Update(float dt)
{
    sf::FloatRect FPRect = body.getGlobalBounds();

    hitbox.UpdateTr(body, { FPRect.left,
                            FPRect.top,
                            FPRect.width * 0.5f,
                            FPRect.height * 0.45f});
}

void FirePlace::Draw(sf::RenderWindow& window)
{
    hitbox.Draw(window);
    window.draw(body);
}
