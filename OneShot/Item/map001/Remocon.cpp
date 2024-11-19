#include "Remocon.h"
#include "Niko.h"

Remocon::Remocon(const std::string& name)
	:GameObject(name)
{
}

void Remocon::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	body.setPosition(position);
}

void Remocon::SetRotation(float angle)
{
	rotation = angle;
	body.setRotation(rotation);
}

void Remocon::SetScale(const sf::Vector2f& s)
{
	scale = s;
	body.setScale(scale);
}

void Remocon::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom)
	{
		Utils::SetOrigin(body, originPreset);
	}
}

void Remocon::SetOrigin(const sf::Vector2f& newOrigin)
{
	originPreset = Origins::Custom;
	origin = Utils::SetOrigin(body, originPreset);
}

sf::Vector2f Remocon::GetPosition()
{
	pos = body.getPosition();
	return pos;
}

sf::FloatRect Remocon::GetLocalBounds() const
{
	return body.getLocalBounds();
}

sf::FloatRect Remocon::GetGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Remocon::Init()
{
	std::string textureId = "Graphics/Characters/remocon.png";

	int width = 32;
	int height = 32;

	{
		AnimationClip clip;
		clip.id = "IdleRemocon";
		clip.fps = 3;
		clip.loopType = AnimationLoopTypes::Loop;
		clip.frames.push_back({ textureId, {0, 0, width, height} });
		temp.insert({ "IdleRemocon", clip });
	}

	{
		AnimationClip clip;
		clip.id = "MoveRemocon";
		clip.fps = 10;
		clip.loopType = AnimationLoopTypes::Loop;
		for (int i = 0; i < 4; ++i)
		{
			clip.frames.push_back({ textureId, {0, i * height, width, height} });
		}
		temp.insert({ "MoveRemocon", clip });
	}

	clipInfos.push_back({ "IdleRemocon", "MoveRemocon" });

	animator.SetTarget(&body);
}

void Remocon::Release()
{
}

void Remocon::Reset()
{
	body.setTexture(TEXTURE_MGR.Get("Graphics/Characters/remocon.png"));
	body.setTextureRect({ 0,0,32,32 });
	SetOrigin(Origins::MC);
}

void Remocon::Update(float dt)
{
	animator.Update(dt);

	sf::FloatRect remoconFloatRect = body.getLocalBounds();

	hitbox.UpdateTr(body, remoconFloatRect);
}

void Remocon::Draw(sf::RenderWindow& window)
{
	hitbox.Draw(window);
	window.draw(body);
}
