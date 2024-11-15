#include "Map001.h"
#include "Scene.h"
#include "SpriteGo.h"
#include "Neko.h"
#include "Remocon.h"
#include "HitBox.h"

Map001::Map001()
	:Scene(SceneIds::Map001)
{
}

void Map001::Init()
{
	map001 = AddGo(new SpriteGo("Graphics/Map/map001.png"));
	niko = AddGo(new Neko("Niko"));
	remocon = AddGo(new Remocon("Remocon"));

	Scene::Init();

	map001->sortingLayer = SortingLayers::Background;
	map001->sortingOrder = -1;

	map001->SetOrigin(Origins::MC);
	map001->SetScale(mapScale);
	map001->SetPosition({ 500.f, 500.f });

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 1;

	niko->SetPosition({ 400.f, 500.f });
	niko->SetScale({ 1.5f,1.5f });
	niko->SetOrigin(Origins::BC);

	remocon->sortingLayer = SortingLayers::Foreground;
	remocon->sortingOrder = 1;

	remocon->SetOrigin(Origins::MC);
	remocon->SetPosition({ 880.f, 600.f });
	remocon->SetScale({ 2.f, 2.f });
	remocon->SetActive(true);

	getRemocon = false;
}

void Map001::Enter()
{
	TEXTURE_MGR.Load("Graphics/Map/map001.png");

	Scene::Enter();
}

void Map001::Exit()
{
	Scene::Exit();

	TEXTURE_MGR.Unload("Graphics/Map/map001.png");
}

void Map001::Update(float dt)
{
	Scene::Update(dt);

	sf::Sprite nikoSprite = niko->GetSprite();
	sf::Sprite remoconSprite = remocon->GetSprite();

	if (Utils::CheckCollision(nikoSprite, remoconSprite))
	{
		isCollision = true;
		collisionDelay -= dt;
	}
	
	if (isCollision == true && InputMgr::GetKey(sf::Keyboard::Left))
	{
		if(collisionDelay < 5.f)
		{
			isCollision = false;
		}
		
	}
	else if (isCollision == true && InputMgr::GetKey(sf::Keyboard::Up))
	{
		if (collisionDelay < 5.f)
		{
			isCollision = false;
		}
	}
	else if (isCollision == true && InputMgr::GetKey(sf::Keyboard::Down))
	{
		if (collisionDelay < 5.f)
		{
			isCollision = false;
		}
	}

	if (isCollision == true)
	{
		niko->SetSpeed(0.f);
	}

	if (isCollision == false)
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoSprite, remoconSprite) && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		getRemocon = true;
	}

	if (getRemocon == true)
	{
		remocon->SetActive(false);
	}
}

void Map001::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
