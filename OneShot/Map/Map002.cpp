#include "Map002.h"
#include "Niko.h"
#include "ObjectHitBox.h"
#include "Message.h"

sf::RectangleShape Map002::nikoRect(sf::Vector2f(48.f, 64.f));
sf::RectangleShape Map002::flowerRect(sf::Vector2f({ 32.f, 26.f }));

Map002::Map002()
	:Scene(SceneIds::Map002)
{
}

void Map002::Init()
{
	map002 = AddGo(new SpriteGo("Graphics/Map/map002.png"));
	niko = AddGo(new Niko("Niko"));
	hitbox = AddGo(new ObjectHitBox("HitBox"));
	text = AddGo(new Message("Text"));

	Scene::Init();

	map002->sortingLayer = SortingLayers::Background;
	map002->sortingOrder = -1;

	map002->SetOrigin(Origins::MC);
	map002->SetScale(mapScale);
	map002->SetPosition({ 500.f, 500.f });

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 2;

	niko->SetOrigin(Origins::BC);
	niko->SetScale({ 1.5f, 1.5f });
	niko->SetPosition({ 680.f, 710.f });

	Utils::SetOrigin(nikoRect, Origins::BC);
	nikoRect.setPosition(niko->GetPosition());
	nikoRect.setFillColor(sf::Color::Transparent);
	nikoRect.setOutlineColor(sf::Color::Green);
	nikoRect.setOutlineThickness(1);

	hitbox->SetOrigin(Origins::BC);
	hitbox->SetScale({ 1.f, 1.f });
	hitbox->SetPosition({ 610.f, 580.f });

	Utils::SetOrigin(flowerRect, Origins::BC);
	flowerRect.setPosition(hitbox->GetPosition());
	flowerRect.setScale({ 1.f, 1.f });

	text->SetActive(false);

	getBranch = false;
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

	sf::Vector2f pos = niko->GetPosition();

	nikoRect.setPosition(pos);

	if (Utils::CheckCollision(nikoRect, flowerRect))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoRect, flowerRect) && InputMgr::GetKey(sf::Keyboard::Z))
	{
		text->SetString("Get Branch!");
		text->SetStringSize(50);
		text->SetActive(true);
		getBranch = true;
		niko->SetSpeed(0.f);
	}

	if (getBranch == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		text->SetActive(false);
		niko->SetSpeed(100.f);
		niko->SetPosition({ pos.x - 1, pos.y });
	}

	if (Utils::CheckCollision(nikoRect, flowerRect) && InputMgr::GetKey(sf::Keyboard::Left))
	{
		niko->SetSpeed(100.f);
	}
}

void Map002::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
