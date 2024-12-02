#include "BookCase.h"

BookCase::BookCase(const std::string& name)
    :GameObject(name)
{
}

void BookCase::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void BookCase::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void BookCase::SetScale(const sf::Vector2f& s)
{
    scale = s;
    body.setScale(scale);
}

void BookCase::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void BookCase::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f BookCase::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect BookCase::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect BookCase::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void BookCase::Init()
{
    std::string textureId = "Graphics/MapSource/bookcase.png";
}

void BookCase::Release()
{
}

void BookCase::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/MapSource/bookcase.png"));
    SetOrigin(Origins::TL);
}

void BookCase::Update(float dt)
{
    sf::FloatRect bookcaseFloatRect = body.getGlobalBounds();

    hitbox.UpdateTr(body, bookcaseFloatRect);
}

void BookCase::Draw(sf::RenderWindow& window)
{
    window.draw(body);
    hitbox.Draw(window);
}
