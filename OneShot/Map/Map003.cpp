#include "Map003.h"
#include "Niko.h"
#include "TV.h"
#include "FirePlace.h"
#include "Sofa.h"
#include "Refrigerator.h"
#include "Sink.h"
#include "Door.h"
#include "LightDoor.h"

Map003::Map003()
	:Scene(SceneIds::Map003)
{
}

void Map003::Init()
{
	map003 = AddGo(new SpriteGo("Graphics/Map/map003.png"));
	lightdoorSprite = AddGo(new SpriteGo("Graphics/Pictures/cg_door1.png"));
	niko = AddGo(new Niko("Niko"));
	tv = AddGo(new TV("TV"));
	fireplace = AddGo(new FirePlace("FirePlace"));
	sofa = AddGo(new Sofa("Sofa"));
	re = AddGo(new Refrigerator("Refrigerator"));
	sink = AddGo(new Sink("Sink"));
	door = AddGo(new Door("Door"));
	lightdoor = AddGo(new LightDoor("LightDoor"));

	Scene::Init();

	map003->sortingLayer = SortingLayers::Background;
	map003->sortingOrder = -1;

	map003->SetPosition({ 500.f, 400.f });
	map003->SetScale({ 1.8f, 1.8f });
	map003->SetOrigin(Origins::MC);

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 2;

	niko->SetPosition({ 200.f, 200.f });
	niko->SetScale({ 1.5f, 1.5f });
	niko->SetOrigin(Origins::TL);

	tv->sortingLayer = SortingLayers::Foreground;
	tv->sortingOrder = 1;

	tv->SetPosition({ 400.f, 200.f });
	tv->SetScale({ 2.f, 2.f });
	tv->SetOrigin(Origins::TL);

	fireplace->sortingLayer = SortingLayers::Foreground;
	fireplace->sortingOrder = 1;

	fireplace->SetPosition({ 700.f, -50.f });
	fireplace->SetScale({ 2.f, 2.f });
	fireplace->SetOrigin(Origins::TL);

	sofa->sortingLayer = SortingLayers::Foreground;
	sofa->sortingOrder = 1;

	sofa->SetPosition({ 300.f, 400.f });
	sofa->SetScale({ 2.f, 2.f });
	sofa->SetOrigin(Origins::TL);

	re->sortingLayer = SortingLayers::Foreground;
	re->sortingOrder = 1;

	re->SetPosition({ 880.f, 600.f });
	re->SetScale({ 2.f, 2.f });
	re->SetOrigin(Origins::TL);

	sink->sortingLayer = SortingLayers::Foreground;
	sink->sortingOrder = 1;

	sink->SetPosition({ 525.f, 780.f });
	sink->SetScale({ 2.f, 2.f });
	sink->SetOrigin(Origins::ML);

	door->sortingLayer = SortingLayers::Foreground;
	door->sortingOrder = 1;

	door->SetPosition({200.f, 150.f});
	door->SetScale({ 2.f, 2.f });
	door->SetOrigin(Origins::TL);

	lightdoor->sortingLayer = SortingLayers::Foreground;
	lightdoor->sortingOrder = 1;

	lightdoor->SetPosition({-60.f, 260.f});
	lightdoor->SetScale({ 2.f, 2.f });
	lightdoor->SetOrigin(Origins::TL);

	lightdoorSprite->SetActive(false);
	lightdoorSprite->SetPosition({ 0.f, 0.f });
	lightdoorSprite->SetScale({ 2.f, 2.2f });
	lightdoorSprite->SetOrigin(Origins::MC);
}

void Map003::Enter()
{
	sf::Vector2f nikopos = niko->GetPosition();

	worldView.setSize(FRAMEWORK.GetWindowSizeF());
	worldView.setCenter(nikopos.x, nikopos.y);

	TEXTURE_MGR.Load("Graphics/Map/map003.png");
	TEXTURE_MGR.Load("Graphics/Pictures/cg_door1.png");

	Scene::Enter();
}

void Map003::Exit()
{
	TEXTURE_MGR.Unload("Graphics/Map/map003.png");
	TEXTURE_MGR.Unload("Graphics/Pictures/cg_door1.png");

	Scene::Exit();
}

void Map003::Update(float dt)
{
	Scene::Update(dt);

	sf::Vector2f nikopos = niko->GetPosition();

	worldView.setSize(FRAMEWORK.GetWindowSizeF());
	worldView.setCenter(nikopos.x, nikopos.y);

	lightdoorSprite->SetPosition({ nikopos.x, nikopos.y });

	HitBox& nikoHitbox = niko->GetHitBox();
	HitBox& tvHitbox = tv->GetHitBox();
	HitBox& FPHitBox = fireplace->GetHitBox();
	HitBox& sofaHitBox = sofa->GetHitBox();
	HitBox& reHitBox = re->GetHitBox();
	HitBox& sinkHitBox = sink->GetHitBox();
	HitBox& doorHitBox = door->GetHitBox();
	HitBox& lightdoorHitBox = lightdoor->GetHitBox();

	if (Utils::CheckCollision(nikoHitbox, tvHitbox))
	{
		niko->SetSpeed(0.f);
		if (InputMgr::GetKey(sf::Keyboard::Down))
		{
			niko->SetSpeed(100.f);
		}
	}

	if (Utils::CheckCollision(nikoHitbox, FPHitBox))
	{
		niko->SetSpeed(0.f);
		if (InputMgr::GetKey(sf::Keyboard::Down))
		{
			niko->SetSpeed(100.f);
		}
	}

	if (Utils::CheckCollision(nikoHitbox, sofaHitBox))
	{
		niko->SetSpeed(0.f);
		if (InputMgr::GetKey(sf::Keyboard::Down))
		{
			niko->SetSpeed(100.f);
		}
	}

	if (Utils::CheckCollision(nikoHitbox, reHitBox))
	{
		niko->SetSpeed(0.f);
		if (InputMgr::GetKey(sf::Keyboard::Down))
		{
			niko->SetSpeed(100.f);
		}
	}

	if (Utils::CheckCollision(nikoHitbox, sinkHitBox))
	{
		niko->SetSpeed(0.f);

		if (niko->GetPosition().y > sink->GetPosition().y && InputMgr::GetKey(sf::Keyboard::Down))
		{
			niko->SetSpeed(100.f);
		}
		else if (niko->GetPosition().y < sink->GetPosition().y && InputMgr::GetKey(sf::Keyboard::Up))
		{
			niko->SetSpeed(100.f);
		}
		else if (InputMgr::GetKey(sf::Keyboard::Right))
		{
			niko->SetSpeed(100.f);
		}
	}

	if (Utils::CheckCollision(nikoHitbox, doorHitBox))
	{
		SCENE_MGR.ChangeScene(SceneIds::Map001);
	}

	if (Utils::CheckCollision(nikoHitbox, lightdoorHitBox))
	{
		niko->SetSpeed(0.f);
		lightdoorSprite->SetActive(true);
		if (InputMgr::GetKey(sf::Keyboard::Z))
		{
			lightdoorSprite->SetActive(false);
			niko->SetPosition({ nikopos.x, nikopos.y + 1 });
			niko->SetSpeed(100.f);
		}
	}
}

void Map003::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
