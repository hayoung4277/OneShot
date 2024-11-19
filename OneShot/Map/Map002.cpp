#include "Map002.h"
#include "Niko.h"
#include "Message.h"

sf::RectangleShape Map002::nikoRect(sf::Vector2f(48.f, 64.f));
sf::RectangleShape Map002::flowerRect(sf::Vector2f({ 32.f, 26.f }));
sf::RectangleShape Map002::sinkRect(sf::Vector2f({ 32.f, 43.f }));
sf::RectangleShape Map002::toiletRect(sf::Vector2f({ 29.f, 53.f }));
sf::RectangleShape Map002::bathRect(sf::Vector2f({ 64.f, 34.f }));
sf::RectangleShape Map002::rect(sf::Vector2f(16.f, 32.f));

Map002::Map002()
	:Scene(SceneIds::Map002)
{
}

void Map002::Init()
{
	map002 = AddGo(new SpriteGo("Graphics/Map/map002.png"));
	niko = AddGo(new Niko("Niko"));
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
	niko->SetPosition({ 600.f, 620.f });

	Utils::SetOrigin(nikoRect, Origins::BC);
	nikoRect.setPosition(niko->GetPosition());
	nikoRect.setFillColor(sf::Color::Transparent);
	nikoRect.setOutlineColor(sf::Color::Green);
	nikoRect.setOutlineThickness(1);

	Utils::SetOrigin(rect, Origins::MC);
	rect.setPosition({ 730.f, 710.f });
	rect.setScale({ 1.5f, 1.5f });

	Utils::SetOrigin(flowerRect, Origins::BC);
	flowerRect.setPosition({ 610.f, 580.f });
	flowerRect.setScale({ 1.f, 1.f });

	Utils::SetOrigin(sinkRect, Origins::BC);
	sinkRect.setPosition({ 475.f, 515.f });
	sinkRect.setScale({2.f, 2.f});

	Utils::SetOrigin(toiletRect, Origins::BC);
	toiletRect.setPosition({ 365.f, 535.f });
	toiletRect.setScale({ 2.f, 2.f });

	Utils::SetOrigin(bathRect, Origins::BC);
	bathRect.setPosition({ 355.f, 750.f });
	bathRect.setScale({ 2.f, 2.f });

	doorRect.setSize({ 16.f, 32.f });
	Utils::SetOrigin(doorRect, Origins::MC);
	doorRect.setScale({ 1.5f, 1.5f });
	doorRect.setPosition({720.f, 700.f});

	text->SetActive(false);

	getBranch = false;
}

void Map002::Enter()
{
	sf::Vector2f nikopos = niko->GetPosition();

	worldView.setSize(FRAMEWORK.GetWindowSizeF());
	worldView.setCenter(nikopos.x, nikopos.y);

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

	worldView.setSize(FRAMEWORK.GetWindowSizeF());
	worldView.setCenter(pos.x, pos.y);

	sf::FloatRect doorRectHitBox = doorRect.getLocalBounds();

	HitBox& nikoHitBox = niko->GetHitBox();
	HitBox doorHitBox;
	doorHitBox.UpdateTr(doorRect, doorRectHitBox);

	nikoRect.setPosition(pos);

	if (Utils::CheckCollision(nikoRect, flowerRect))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoRect, sinkRect))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoRect, toiletRect))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoRect, bathRect))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoRect, rect))
	{
		SCENE_MGR.ChangeScene(SceneIds::Map001);
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

	if (Utils::CheckCollision(nikoRect, sinkRect) && InputMgr::GetKey(sf::Keyboard::Down))
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoRect, toiletRect) && InputMgr::GetKey(sf::Keyboard::Down)
		|| InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right))
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoRect, bathRect) && InputMgr::GetKey(sf::Keyboard::Up)
		|| InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right))
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoHitBox, doorHitBox))
	{
		SCENE_MGR.ChangeScene(SceneIds::Map001);
	}
}

void Map002::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	window.draw(doorRect);
}
