#include "TV.h"

TV::TV(const std::string& name)
    :GameObject(name)
{
}

void TV::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void TV::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void TV::SetScale(const sf::Vector2f& s)
{
    scale = s;
    body.setScale(scale);
}

void TV::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void TV::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f TV::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect TV::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect TV::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void TV::Init()
{
    std::string textureId = "Graphics/Characters/TV.png";
}

void TV::Release()
{
}

void TV::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/TV.png"));
    body.setTextureRect({ 0, 0, 64, 46 });
    SetOrigin(Origins::TL);
}

void TV::Update(float dt)
{
    sf::FloatRect tvFloatRect = body.getGlobalBounds();

    hitbox.UpdateTr(body, { tvFloatRect.left,
                         tvFloatRect.top,
                         tvFloatRect.width * 0.5f,
                         tvFloatRect.height * 0.35f});
}

void TV::Draw(sf::RenderWindow& window)
{
    hitbox.Draw(window);
    window.draw(body);
}
