#include "Map004_1.h"
#include "Niko.h"
#include "Message.h"

Map004_1::Map004_1()
	:Scene(SceneIds::Map004_1)
{
}

void Map004_1::Init()
{
	map004_1 = AddGo(new SpriteGo("Graphics/Map/map004-1.png"));
	niko = AddGo(new Niko("Niko"));
	text = AddGo(new Message("Text"));

	Scene::Init();

	map004_1->sortingLayer = SortingLayers::Background;
	map004_1->sortingOrder = -1;
	map004_1->SetOrigin(Origins::MC);
	map004_1->SetScale(mapScale);
	map004_1->SetPosition({500.f, 500.f});

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 2;
	niko->SetOrigin(Origins::BC);
	niko->SetPosition({-20.f, 120.f});
	niko->SetScale({1.5f, 1.5f});

	text->SetActive(false);

	for (int i = 0; i < 2; i++)
	{
		Utils::SetOrigin(rect[i], Origins::MC);
		rect[i].setFillColor(sf::Color::Transparent);
		rect[i].setOutlineColor(sf::Color::White);
		rect[i].setOutlineThickness(2);
		rect[i].setScale({ 1.5f, 1.5f });
	}

	rect[0].setSize({16.f, 32.f});
	rect[0].setPosition({-30.f, 120.f});
	rect[1].setSize({16.f, 32.f});
	rect[1].setPosition({740.f, 810.f});

	if (niko->GetBeforeScene() == 5)
	{
		niko->SetPosition({730.f, 790.f});
	}
}

void Map004_1::Enter()
{
	TEXTURE_MGR.Load("Graphics/Map/map004-1.png");

	Scene::Enter();
}

void Map004_1::Exit()
{
	TEXTURE_MGR.Unload("Graphics/Map/map004-1.png");

	Scene::Exit();
}

void Map004_1::Update(float dt)
{
	Scene::Update(dt);

	sf::FloatRect doorFloatRect = rect[0].getLocalBounds();
	sf::FloatRect basementFloatRect = rect[1].getLocalBounds();

	HitBox& nikoHitBox = niko->GetHitBox();
	HitBox doorHitBix;
	doorHitBix.UpdateTr(rect[0], doorFloatRect);
	HitBox basementHitBox;
	basementHitBox.UpdateTr(rect[1], basementFloatRect);

	if (Utils::CheckCollision(nikoHitBox, doorHitBix))
	{
		niko->SetBeforeScene(4);
		SCENE_MGR.ChangeScene(SceneIds::Map003);
	}

	if (Utils::CheckCollision(nikoHitBox, basementHitBox))
	{
		niko->SetBeforeScene(4);
		SCENE_MGR.ChangeScene(SceneIds::Map004_2);
	}

}

void Map004_1::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(rect[i]);
	}
	Scene::Draw(window);
}
