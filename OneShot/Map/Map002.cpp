#include "Map002.h"
#include "Niko.h"
#include "Message.h"
#include "Bath.h"
#include "DryFlower.h"
#include "Toilet.h"
#include "ToiletSink.h"

Map002::Map002()
	:Scene(SceneIds::Map002)
{
}

void Map002::Init()
{
	map002 = AddGo(new SpriteGo("Graphics/Map/map002.png"));
	niko = AddGo(new Niko("Niko"));
	text = AddGo(new Message("Text"));
	bath = AddGo(new Bath("Bath"));
	dryflower = AddGo(new DryFlower("DryFlower"));
	toilet = AddGo(new Toilet("Toilet"));
	sink = AddGo(new ToiletSink("Sink"));

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
	niko->SetPosition({ 650.f, 620.f });

	dryflower->sortingLayer = SortingLayers::Foreground;
	dryflower->sortingOrder = 1;
	dryflower->SetPosition({ 600.f, 570.f });
	dryflower->SetScale({ 1.f, 1.f });

	sink->sortingLayer = SortingLayers::Foreground;
	sink->sortingOrder = 1;
	sink->SetPosition({ 440.f, 480.f });
	sink->SetScale({2.f, 2.f});

	toilet->sortingLayer = SortingLayers::Foreground;
	toilet->sortingOrder = 1;
	toilet->SetPosition({ 340.f, 485.f });
	toilet->SetScale({ 2.f, 2.f });

	bath->sortingLayer = SortingLayers::Foreground;
	bath->sortingOrder = 3;
	bath->SetOrigin(Origins::TL);
	bath->SetPosition({ 295.f, 650.f });
	bath->SetScale({ 2.f, 2.f });

	doorRect.setSize({ 16.f, 32.f });
	Utils::SetOrigin(doorRect, Origins::MC);
	doorRect.setScale({ 1.5f, 1.5f });
	doorRect.setPosition({720.f, 700.f});

	text->SetActive(false);

	getBranch = false;

	int beforeScene = niko->GetBeforeScene();
}

void Map002::Enter()
{
	sf::Vector2f nikopos = niko->GetPosition();

	worldView.setSize({ 840, 680 });
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

	worldView.setSize({ 840, 680 });
	worldView.setCenter(pos.x, pos.y);

	sf::FloatRect doorRectHitBox = doorRect.getLocalBounds();

	HitBox& nikoHitBox = niko->GetHitBox();
	HitBox& bathHitBox = bath->GetHitBox();
	HitBox& dryflowerHitBox = dryflower->GetHitBox();
	HitBox& toiletHitBox = toilet->GetHitBox();
	HitBox& sinkHitBox = sink->GetHitBox();
	HitBox doorHitBox;
	doorHitBox.UpdateTr(doorRect, doorRectHitBox);

	if (Utils::CheckCollision(nikoHitBox, dryflowerHitBox))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoHitBox, sinkHitBox))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoHitBox, toiletHitBox))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoHitBox, bathHitBox))
	{
		niko->SetSpeed(0.f);
	}
	
	if(getBranch == false)
	{
		if (Utils::CheckCollision(nikoHitBox, dryflowerHitBox) && InputMgr::GetKey(sf::Keyboard::Z))
		{
			text->SetString("Get Branch!");
			text->SetStringSize(50);
			text->SetActive(true);
			niko->SetBranchGet();
			niko->SetPosition({ pos.x - 1, pos.y });
			niko->SetSpeed(0.f);
		}
		else if (niko->IsGetBranch() == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetSpeed(100.f);
		}
	}

	if (Utils::CheckCollision(nikoHitBox, dryflowerHitBox) && InputMgr::GetKey(sf::Keyboard::Left))
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoHitBox, sinkHitBox) && InputMgr::GetKey(sf::Keyboard::Down)
		|| InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right))
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoHitBox, toiletHitBox) && InputMgr::GetKey(sf::Keyboard::Down)
		|| InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right))
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoHitBox, bathHitBox) && InputMgr::GetKey(sf::Keyboard::Up)
		|| InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right))
	{
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoHitBox, doorHitBox))
	{
		niko->SetBeforeScene(2);
		SCENE_MGR.ChangeScene(SceneIds::Map001);

	}
}

void Map002::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	//window.draw(doorRect);
}
