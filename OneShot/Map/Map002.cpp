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

	Utils::SetOrigin(flowerRect, Origins::ML);
	flowerRect.setSize({ 32.f, 32.f });
	flowerRect.setPosition({ 570.f, 570.f });
	flowerRect.setScale({ 1.f, 1.f });
	flowerRect.setFillColor(sf::Color::Transparent);
	flowerRect.setOutlineColor(sf::Color::White);
	flowerRect.setOutlineThickness(2);

	sink->sortingLayer = SortingLayers::Foreground;
	sink->sortingOrder = 1;
	sink->SetPosition({ 440.f, 480.f });
	sink->SetScale({ 2.f, 2.f });

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
	doorRect.setPosition({ 720.f, 700.f });

	for (int i = 0; i < 4; i++)
	{
		hitboxRects[i].setFillColor(sf::Color::Transparent);
		hitboxRects[i].setOutlineColor(sf::Color::Red);
		hitboxRects[i].setOutlineThickness(1);
		Utils::SetOrigin(hitboxRects[i], Origins::TL);
	}

	//벽1
	hitboxRects[0].setSize({ 450.f, 30.f });
	hitboxRects[0].setPosition({ 285.f, 720.f });

	//벽2
	hitboxRects[1].setSize({ 30.f, 300.f });
	hitboxRects[1].setPosition({ 262.f, 450.f });

	//벽3
	hitboxRects[2].setSize({ 370.f, 30.f });
	hitboxRects[2].setPosition({ 285.f, 450.f });

	//벽4
	hitboxRects[3].setSize({ 30.f, 190.f });
	hitboxRects[3].setPosition({ 650.f, 450.f });

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

	sf::Vector2f nikoPos = niko->GetPosition();
	sf::Vector2f toiletPos = toilet->GetPosition();
	sf::Vector2f bathPos = bath->GetPosition();
	sf::Vector2f sinkPos = sink->GetPosition();
	sf::Vector2f flowerPos = dryflower->GetPosition();

	for (int i = 0; i < 4; i++)
	{
		rects[i] = hitboxRects[i].getGlobalBounds();
	}

	for (int i = 0; i < 4; i++)
	{
		hitbox[i].UpdateTr(hitboxRects[i], rects[i]);
	}

	worldView.setSize({ 840, 680 });
	worldView.setCenter(nikoPos.x, nikoPos.y);

	sf::FloatRect doorRectHitBox = doorRect.getLocalBounds();
	sf::FloatRect bathBound = bath->GetGlobalBounds();
	sf::FloatRect flowerBound = flowerRect.getGlobalBounds();
	sf::FloatRect nikoBound = niko->GetGlobalBounds();

	HitBox& nikoHitBox = niko->GetHitBox();
	HitBox& bathHitBox = bath->GetHitBox();
	HitBox& dryflowerHitBox = dryflower->GetHitBox();
	HitBox& toiletHitBox = toilet->GetHitBox();
	HitBox& sinkHitBox = sink->GetHitBox();
	HitBox doorHitBox;
	doorHitBox.UpdateTr(doorRect, doorRectHitBox);

	//TOILET
	if (Utils::CheckCollision(nikoHitBox, toiletHitBox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - toiletPos;
		float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (magnitude != 0.f)
			direction /= magnitude;

		// 충돌 방향 계산 (X 또는 Y로 제한)
		if (std::abs(direction.x) > std::abs(direction.y))
		{
			// 수평 충돌: 좌/우로만 밀림
			direction.y = 0.f;
		}
		else
		{
			// 수직 충돌: 위/아래로만 밀림
			direction.x = 0.f;
		}

		// Niko를 충돌 방향으로 밀어냄
		niko->SetPosition(nikoPos + direction * 1.f);
		niko->SetSpeed(0.f);
	}

	//BATH
	if (Utils::CheckCollision(nikoHitBox, bathHitBox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - bathPos;
		float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (magnitude != 0.f)
			direction /= magnitude;

		// 충돌 방향 계산 (X 또는 Y로 제한)
		if (std::abs(direction.x) > std::abs(direction.y))
		{
			// 수평 충돌: 좌/우로만 밀림
			direction.y = 0.f;
		}
		else
		{
			// 수직 충돌: 위/아래로만 밀림
			direction.x = 0.f;
		}

		// Niko를 충돌 방향으로 밀어냄
		niko->SetPosition(nikoPos + direction * 1.f);
		niko->SetSpeed(0.f);
	}

	//SINK
	if (Utils::CheckCollision(nikoHitBox, sinkHitBox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - sinkPos;
		float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (magnitude != 0.f)
			direction /= magnitude;

		// 충돌 방향 계산 (X 또는 Y로 제한)
		if (std::abs(direction.x) > std::abs(direction.y))
		{
			// 수평 충돌: 좌/우로만 밀림
			direction.y = 0.f;
		}
		else
		{
			// 수직 충돌: 위/아래로만 밀림
			direction.x = 0.f;
		}

		// Niko를 충돌 방향으로 밀어냄
		niko->SetPosition(nikoPos + direction * 1.f);
		niko->SetSpeed(0.f);
	}

	//FLOWER
	if (getBranch == false && nikoBound.intersects(flowerBound))
	{
		if (isTextVisible == false && InputMgr::GetKey(sf::Keyboard::Z))
		{
			text->SetString("Get Branch!");
			text->SetStringSize(50);
			text->SetActive(true);
			text->SetPosition({ nikoPos.x, nikoPos.y - 100.f });
			niko->SetBranchGet();
			niko->SetSpeed(0.f);
			isTextVisible = true;
			return;
		}

		if (text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetSpeed(100.f);
			isTextVisible = false;
			getBranch = true;
		}
	}

	if (Utils::CheckCollision(nikoHitBox, dryflowerHitBox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - flowerPos;
		float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (magnitude != 0.f)
			direction /= magnitude;

		// 충돌 방향 계산 (X 또는 Y로 제한)
		if (std::abs(direction.x) > std::abs(direction.y))
		{
			// 수평 충돌: 좌/우로만 밀림
			direction.y = 0.f;
		}
		else
		{
			// 수직 충돌: 위/아래로만 밀림
			direction.x = 0.f;
		}

		// Niko를 충돌 방향으로 밀어냄
		niko->SetPosition(nikoPos + direction * 1.f);
		niko->SetSpeed(0.f);
	}

	//이동(방)
	if (Utils::CheckCollision(nikoHitBox, doorHitBox))
	{
		niko->SetBeforeScene(2);
		SCENE_MGR.ChangeScene(SceneIds::Map001);
	}

	//벽 충돌
	if (Utils::CheckCollision(nikoHitBox, hitbox[0]))
	{
		niko->SetPosition({ nikoPos.x, nikoPos.y - 1 });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[1]))
	{
		niko->SetPosition({ nikoPos.x + 1, nikoPos.y });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[2]))
	{
		niko->SetPosition({ nikoPos.x, nikoPos.y + 1 });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[3]))
	{
		niko->SetPosition({ nikoPos.x - 1, nikoPos.y });
	}
}

void Map002::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	//window.draw(flowerRect);
	//for (int i = 0; i < 4; i++)
	//{
	//	window.draw(hitboxRects[i]);
	//}
}
