#include "Map004_2.h"
#include "Niko.h"
#include "Message.h"
#include "Bulb.h"

Map004_2::Map004_2()
	:Scene(SceneIds::Map004_2)
{
}

void Map004_2::Init()
{
	map004_2 = AddGo(new SpriteGo("Graphics/Map/map004-2.png"));
	niko = AddGo(new Niko("Niko"));
	text = AddGo(new Message("Text"));
	bulb = AddGo(new Bulb("Bulb"));

	Scene::Init();

	map004_2->sortingLayer = SortingLayers::Background;
	map004_2->sortingOrder = -1;
	map004_2->SetOrigin(Origins::MC);
	map004_2->SetScale(mapScale);
	map004_2->SetPosition({ 500.f, 500.f });

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 2;
	niko->SetOrigin(Origins::BC);
	niko->SetPosition({ 40.f, 550.f });
	niko->SetScale({ 1.5f, 1.5f });

	for (int i = 0; i < 2; i++)
	{
		Utils::SetOrigin(rect[i], Origins::MC);
		rect[i].setFillColor(sf::Color::Transparent);
		rect[i].setOutlineColor(sf::Color::White);
		rect[i].setOutlineThickness(2);
		rect[i].setScale({ 1.5f, 1.5f });
	}

	rect[0].setSize({ 16.f, 32.f });
	rect[0].setPosition({ 0.f, 600.f });
	rect[1].setSize({ 16.f, 32.f });
	rect[1].setPosition({ 500.f, 600.f });

	bulb->sortingLayer = SortingLayers::Foreground;
	bulb->sortingOrder = 1;
	bulb->SetOrigin(Origins::BL);
	bulb->SetScale({ 2.f, 2.f });
	bulb->SetPosition({ 900.f, 610.f });

	text->SetActive(false);
}

void Map004_2::Enter()
{
	TEXTURE_MGR.Load("Graphics/Map/map004-2.png");

	Scene::Enter();
}

void Map004_2::Exit()
{
	TEXTURE_MGR.Unload("Graphics/Map/map004-2.png");

	Scene::Exit();
}

void Map004_2::Update(float dt)
{
	Scene::Update(dt);

	sf::Vector2f nikoPos = niko->GetPosition();
	sf::FloatRect doorFloatRect = rect[0].getLocalBounds();

	HitBox& nikoHitBox = niko->GetHitBox();
	HitBox& bulbHitBox = bulb->GetHitBox();
	HitBox doorHitBix;
	doorHitBix.UpdateTr(rect[0], doorFloatRect);

	if (Utils::CheckCollision(nikoHitBox, bulbHitBox))
	{
		niko->SetSpeed(0.f);
		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			isBulbOn = true;
			bulb->SetTexture("Graphics/Characters/lighton.png");
			bulb->Reset();
			niko->SetPosition({ nikoPos.x - 1, nikoPos.y });
		}
	}
	else if (isBulbOn == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		bulb->SetActive(false);
		niko->SetSpeed(100.f);
		niko->SetTexutreID("Graphics/Characters/niko_bulb.png");
		niko->Reset();
	}

	if (Utils::CheckCollision(nikoHitBox, doorHitBix))
	{
		niko->SetBeforeScene(5);
		SCENE_MGR.ChangeScene(SceneIds::Map004_1);
	}
}

void Map004_2::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(rect[i]);
	}
	Scene::Draw(window);
}
