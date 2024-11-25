#include "stdafx.h"
#include "Niko.h"

Niko::Niko(const std::string& name)
	:GameObject(name)
{
}

void Niko::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Niko::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Niko::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

sf::FloatRect Niko::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Niko::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Niko::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Niko::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

void Niko::SetSpeed(float speed)
{
	this->speed = speed;
}

sf::Vector2f Niko::GetPosition()
{
	nikoPosition = body.getPosition();
	return nikoPosition;
}

void Niko::SetBranchGet()
{
	getBranch = true;
}

void Niko::SetBeforeScene(int current)
{
	beforeScene = current;
}

void Niko::SetTextureId(const std::string& id)
{
	textureId = id;
}

void Niko::SetISBulb(bool is)
{
	isBulb = is;
}

void Niko::Init()
{

}

void Niko::Release()
{
}

void Niko::Reset()
{
	body.setTexture(TEXTURE_MGR.Get(textureId));
	body.setTextureRect({ 0,0,48,64 });
	SetOrigin(Origins::TL);
}

void Niko::Update(float dt)
{
	animator.Update(dt);

	direction.x = InputMgr::GetAxis(Axis::Horizontal);
	direction.y = InputMgr::GetAxis(Axis::Vertical);
	float mag = Utils::Magnitude(direction);
	if (mag > 1.f)
	{
		Utils::Normailize(direction);
	}

	// 움직임 적용
	SetPosition(position + direction * speed * dt);

	if (InputMgr::GetKey(sf::Keyboard::LShift))
	{
		speed = 200.f;
	}
	else
	{
		speed = 100.f;
	}

	sf::FloatRect nikoFloatRect = body.getGlobalBounds();

	sf::Transformable a;
	a.setPosition(body.getPosition().x + 18, body.getPosition().y + 27);

	hitbox.UpdateTr(a, { nikoFloatRect.left, nikoFloatRect.top,
							nikoFloatRect.width * 0.5f,
							nikoFloatRect.height * 0.5f });
}

void Niko::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	hitbox.Draw(window);
}
