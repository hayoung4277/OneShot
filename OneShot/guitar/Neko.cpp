#include "stdafx.h"
#include "Neko.h"

Neko::Neko(const std::string& name)
	:GameObject(name)
{
}

void Neko::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Neko::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Neko::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Neko::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Neko::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

void Neko::SetSpeed(float speed)
{
	this->speed = speed;
}

void Neko::Init()
{
	std::string textureId = "Graphics/Characters/niko.png";

	int width = 48;
	int height = 64;

	{
		AnimationClip clip;
		clip.id = "IdleDown";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, {0, 0, width, height} });
		temp.insert({ "IdleDown", clip });
	}

	{
		AnimationClip clip;
		clip.id = "IdleLeft";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, {0, 1 * height, width, height} });
		temp.insert({ "IdleLeft", clip });
	}

	{
		AnimationClip clip;
		clip.id = "IdleRight";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, {0, 2 * height, width, height} });
		temp.insert({ "IdleRight", clip });
	}

	{
		AnimationClip clip;
		clip.id = "Idleup";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, {0, 3 * height, width, height} });
		temp.insert({ "IdleUp", clip });
	}

	{
		AnimationClip clip;
		clip.id = "MoveUp";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, { i * width, 3 * height, width, height } });
		}
		temp.insert({ "MoveUp", clip });
	}

	{
		AnimationClip clip;
		clip.id = "MoveDown";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, { i * width, 0, width, height } });
		}
		temp.insert({ "MoveDown", clip });
	}

	{
		AnimationClip clip;
		clip.id = "MoveLeft";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, { i * width, height, width, height } });
		}
		temp.insert({ "MoveLeft", clip });
	}

	{
		AnimationClip clip;
		clip.id = "MoveRight";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, { i * width, 2 * height, width, height } });
		}
		temp.insert({ "MoveRight", clip });
	}

	clipInfos.push_back({ "IdleUp", "MoveUp" });
	clipInfos.push_back({ "IdleLeft", "MoveLeft" });
	clipInfos.push_back({ "IdleRihgt", "MoveRight" });

	animator.SetTarget(&body);
}

void Neko::Release()
{
}

void Neko::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/niko.png"));
	body.setTextureRect({ 0,0,48,64 });
	SetOrigin(Origins::BC);
}

void Neko::Update(float dt)
{
	animator.Update(dt);

	direction.x = InputMgr::GetAxis(Axis::Horizontal);
	direction.y = InputMgr::GetAxis(Axis::Vertical);
	float mag = Utils::Magnitude(direction);
	if (mag > 1.f)
	{
		Utils::Normailize(direction);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::LShift))
	{
		speed = 300.f;
	}
	if (InputMgr::GetKeyUp(sf::Keyboard::LShift))
	{
		speed = 100.f;
	}

	SetPosition(position + direction * speed * dt);

	debugBox.SetBounds(body.getGlobalBounds());
}

void Neko::Draw(sf::RenderWindow& window)
{
	debugBox.Draw(window);
	window.draw(body);
}
