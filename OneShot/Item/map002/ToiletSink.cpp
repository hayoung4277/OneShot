#include "ToiletSink.h"

ToiletSink::ToiletSink(const std::string& name)
    :GameObject(name)
{
}

void ToiletSink::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void ToiletSink::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void ToiletSink::SetScale(const sf::Vector2f& s)
{
    scale = s;
    body.setScale(scale);
}

void ToiletSink::SetOrigin(Origins preset)
{

    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void ToiletSink::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f ToiletSink::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect ToiletSink::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect ToiletSink::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void ToiletSink::Init()
{
    std::string textureId = "Graphics/Characters/bathsink.png";
}

void ToiletSink::Release()
{

}

void ToiletSink::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/bathsink.png"));
    SetOrigin(Origins::TL);
}

void ToiletSink::Update(float dt)
{
    sf::FloatRect sinkFloatRect = body.getGlobalBounds();

    hitbox.UpdateTr(body, { sinkFloatRect.left,
                         sinkFloatRect.top,
                         sinkFloatRect.width * 0.5f,
                         sinkFloatRect.height * 0.2f });
}

void ToiletSink::Draw(sf::RenderWindow& window)
{
    hitbox.Draw(window);
    window.draw(body);
}
