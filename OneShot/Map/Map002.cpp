#include "Map002.h"
#include "Niko.h"

Map002::Map002()
	:Scene(SceneIds::Map002)
{
}

void Map002::Init()
{
	map002 = AddGo(new SpriteGo("Graphics/Map/map002.png"));
	niko = AddGo(new Niko("Niko"));

	Scene::Init();

	map002->sortingLayer = SortingLayers::Background;
	map002->sortingOrder = -1;

	map002->SetOrigin(Origins::MC);
	map002->SetScale(mapScale);
	map002->SetPosition({ 500.f, 500.f });

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 1;

	niko->SetOrigin(Origins::BC);
	niko->SetScale({ 1.5f, 1.5f });
	niko->SetPosition({ 500.f, 500.f });
}

void Map002::Enter()
{
	TEXTURE_MGR.Load("Graphics/Map/map002.png");

	Scene::Enter();
}

void Map002::Exit()
{
	Scene::Exit();

	TEXTURE_MGR.Unload("Graphics/Map/map002.png");
}

void Map002::Update(float dt)
{
	Scene::Update(dt);
}

void Map002::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
