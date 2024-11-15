#include "stdafx.h"
#include "Button.h"

Button::Button(const std::string& fontId, const std::string& name)
	:GameObject(name), fontId(fontId)
{
	text.setFont(FONT_MGR.Get(fontId));
	text.setString("asd");
	rect.setSize({ 370.f, 180.f });
}

void Button::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	rect.setPosition(position);
	text.setPosition(position + sf::Vector2f(0.f, -10.f));
}

void Button::SetScale(const sf::Vector2f& scale)
{
	this->scale = scale;
	rect.setScale(scale);
	text.setScale(scale);
}

void Button::SetRotation(float angle)
{
	rotation = angle;
	rect.setRotation(rotation);
	text.setRotation(rotation);
}

void Button::Reset()
{
	text.setFont(FONT_MGR.Get(fontId));
	rect.setFillColor(sf::Color::Transparent);
	text.setFillColor(ColorIdle);
}

void Button::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		origin = Utils::SetOrigin(rect, originPreset);
	}
}

void Button::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = newOrigin;
	rect.setOrigin(origin);
}

void Button::Init()
{
}

void Button::Release()
{
}

void Button::Update(float dt)
{
	sf::Vector2f mousePos =
	{ (float)InputMgr::GetMousePosition().x, (float)InputMgr::GetMousePosition().y };
	if (rect.getGlobalBounds().contains(mousePos)) {
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) || InputMgr::GetMouseButton(sf::Mouse::Left)) {
			text.setFillColor(ColorPressed);
		}
		else if (InputMgr::GetMouseButtonUp(sf::Mouse::Left)) {
			text.setFillColor(ColorHover);
		}
		else {
			text.setFillColor(ColorHover);
		}
	}
	else {
		text.setFillColor(ColorIdle);
	}

}

void Button::SetText(const sf::String& str)
{
	text.setString(str);
	Utils::SetOrigin(text, Origins::MC);
	SetPosition(position);
}

void Button::SetFontSize(int size)
{
	text.setCharacterSize(size);

}

void Button::SetRectFillColor(const sf::Color& color)
{
	rect.setFillColor(color);
}

void Button::SetRectOutlineColor(const sf::Color& color)
{
	rect.setOutlineColor(color);
}

void Button::SetRectOutlineThickness(float thickness)
{
	rect.setOutlineThickness(thickness);
}

void Button::SetRectSize(const sf::Vector2f& size)
{
	rect.setSize(size);
}

bool Button::IsCursorOn()
{
	sf::Vector2f mousePos =
	{ (float)InputMgr::GetMousePosition().x, (float)InputMgr::GetMousePosition().y };
	return rect.getGlobalBounds().contains(mousePos);
}



void Button::Draw(sf::RenderWindow& window)
{
	window.draw(rect);
	window.draw(text);
}
