#include "Sofa.h"

Sofa::Sofa(const std::string& name)
    :GameObject(name)
{
}

void Sofa::SetPosition(const sf::Vector2f& pos)
{
    position = pos;
    body.setPosition(position);
}

void Sofa::SetRotation(float angle)
{
    rotation = angle;
    body.setRotation(rotation);
}

void Sofa::SetScale(const sf::Vector2f& s)
{
    scale = s;
    body.setScale(scale);
}

void Sofa::SetOrigin(Origins preset)
{
    originPreset = preset;
    if (originPreset != Origins::Custom)
    {
        Utils::SetOrigin(body, originPreset);
    }
}

void Sofa::SetOrigin(const sf::Vector2f& newOrigin)
{
    originPreset = Origins::Custom;
    origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Sofa::GetPosition()
{
    pos = body.getPosition();
    return pos;
}

sf::FloatRect Sofa::GetLocalBounds() const
{
    return body.getLocalBounds();
}

sf::FloatRect Sofa::GetGlobalBounds() const
{
    return body.getGlobalBounds();
}

void Sofa::Init()
{
    std::string textureId = "Graphics/Characters/longsofa.png";
}

void Sofa::Release()
{
}

void Sofa::Reset()
{
    body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/longsofa.png"));
    SetOrigin(Origins::TL);
}

void Sofa::Update(float dt)
{
    sf::FloatRect sofaFloatRect = body.getGlobalBounds();

    sf::Transformable sofa;
    sofa.setRotation(28);
    sofa.setPosition({ body.getPosition().x + 30, body.getPosition().y - 10});

    hitbox.UpdateTr(sofa, { sofaFloatRect.left,
                         sofaFloatRect.top,
                         sofaFloatRect.width,
                         sofaFloatRect.height * 0.5f});
}

void Sofa::Draw(sf::RenderWindow& window)
{
    hitbox.Draw(window);
    window.draw(body);
}
