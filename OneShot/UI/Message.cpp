#include "Message.h"

Message::Message(const std::string& name)
	:GameObject(name)
{
}

void Message::SetPosition(const sf::Vector2f& pos)
{
	this->pos = pos;
	message.setPosition(this->pos);
}

void Message::SetRotation(float angle)
{
	rotation = angle;
	message.setRotation(rotation);
}

void Message::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
	message.setScale(this->scale);
}

void Message::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(message, originPreset);
	}
}

void Message::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	message.setOrigin(origin);
}

void Message::SetString(const sf::String& str)
{
	message.setString(str);
}

void Message::SetStringSize(int size)
{
	message.setCharacterSize(size);
}

void Message::Init()
{
	sortingLayer = SortingLayers::UI;
	sortingOrder = 2;
}

void Message::Release()
{
}

void Message::Reset()
{
	message.setFont(FONT_MGR.Get("Fonts/HMFMPYUN.ttf"));
	message.setCharacterSize(100);
	message.setPosition(pos);
	message.setString("Message!");
	Utils::SetOrigin(message, Origins::MC);
}

void Message::Update(float dt)
{
}

void Message::Draw(sf::RenderWindow& window)
{
	window.draw(message);
}
