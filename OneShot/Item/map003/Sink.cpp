#include "Sink.h"

Sink::Sink(const std::string& name)
    :GameObject(name)
{
}

void Sink::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void Sink::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void Sink::SetScale(const sf::Vector2f& s)
{
    scale = s;
    body.setScale(scale);
}

void Sink::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void Sink::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Sink::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect Sink::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect Sink::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void Sink::Init()
{
    std::string textureId = "Graphics/Characters/sink.png";
}

void Sink::Release()
{
}

void Sink::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/sink.png"));
    SetOrigin(Origins::ML);
}

void Sink::Update(float dt)
{
    sf::FloatRect sinkFloatRect = body.getGlobalBounds();

    hitbox.UpdateTr(body, { sinkFloatRect.left,
                         sinkFloatRect.top,
                         sinkFloatRect.width * 0.5f,
                         sinkFloatRect.height * 0.4f });
}

void Sink::Draw(sf::RenderWindow& window)
{
    hitbox.Draw(window);
    window.draw(body);
}
