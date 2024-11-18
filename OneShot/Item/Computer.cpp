#include "Computer.h"

Computer::Computer(const std::string& name)
	:GameObject(name)
{
}

void Computer::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Computer::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Computer::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Computer::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Computer::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Computer::GetPositoin()
{
	pos = body.getPosition();
	return pos;
}

void Computer::Init()
{
	std::string textureId = "Graphics/Characters/computer.png";
}

void Computer::Release()
{
}

void Computer::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/computer.png"));
	SetOrigin(Origins::MC);
}

void Computer::Update(float dt)
{
	animator.Update(dt);

	debugBox.SetBounds(body.getGlobalBounds());
}

void Computer::Draw(sf::RenderWindow& window)
{
	debugBox.Draw(window);
	window.draw(body);
}
