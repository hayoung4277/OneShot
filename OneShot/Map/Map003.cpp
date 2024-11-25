#include "Map003.h"
#include "Niko.h"
#include "TV.h"
#include "FirePlace.h"
#include "Sofa.h"
#include "Refrigerator.h"
#include "Sink.h"
#include "Door.h"
#include "LightDoor.h"
#include "Message.h"
#include "Fire.h"
#include "ItemStar.h"

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
	text = AddGo(new Message("Text"));
	fire = AddGo(new Fire("Fire"));
	itemStar = AddGo(new ItemStar("ItemStar"));

	Scene::Init();

	map003->sortingLayer = SortingLayers::Background;
	map003->sortingOrder = -1;

	map003->SetPosition({ 500.f, 400.f });
	map003->SetScale({ 1.f, 1.3f });
	map003->SetOrigin(Origins::MC);

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 2;

	niko->SetPosition({ 200.f, 200.f });
	niko->SetScale({ 1.5f, 1.5f });
	niko->SetOrigin(Origins::TL);

	tv->sortingLayer = SortingLayers::Foreground;
	tv->sortingOrder = 1;

	tv->SetPosition({ 430.f, 150.f });
	tv->SetScale({ 1.8f, 1.8f });
	tv->SetOrigin(Origins::TL);

	Utils::SetOrigin(tvRect, Origins::TL);
	tvRect.setSize({ 110.f, 60.f });
	tvRect.setPosition({ 430, 220.f });
	tvRect.setScale({ 1.f, 1.f });
	tvRect.setFillColor(sf::Color::Transparent);
	tvRect.setOutlineColor(sf::Color::White);
	tvRect.setOutlineThickness(2);

	sf::Vector2f tvPos = tv->GetPosition();

	fireplace->sortingLayer = SortingLayers::Foreground;
	fireplace->sortingOrder = 1;

	fireplace->SetPosition({ 650.f, -100.f });
	fireplace->SetScale({ 1.8f, 1.8f });
	fireplace->SetOrigin(Origins::TL);

	Utils::SetOrigin(fpRect, Origins::TL);
	fpRect.setSize({ 140.f, 60.f });
	fpRect.setPosition({ 650, 220.f });
	fpRect.setScale({ 1.f, 1.f });
	fpRect.setFillColor(sf::Color::Transparent);
	fpRect.setOutlineColor(sf::Color::White);
	fpRect.setOutlineThickness(2);

	sofa->sortingLayer = SortingLayers::Foreground;
	sofa->sortingOrder = 1;

	sofa->SetPosition({ 300.f, 350.f });
	sofa->SetScale({ 1.8f, 1.8f });
	sofa->SetOrigin(Origins::TL);

	re->sortingLayer = SortingLayers::Foreground;
	re->sortingOrder = 1;

	re->SetPosition({ 800.f, 500.f });
	re->SetScale({ 1.8f, 1.8f });
	re->SetOrigin(Origins::TL);

	Utils::SetOrigin(reRect, Origins::TL);
	reRect.setSize({ 80.f, 60.f });
	reRect.setPosition({ 800, 630.f });
	reRect.setScale({ 1.f, 1.f });
	reRect.setFillColor(sf::Color::Transparent);
	reRect.setOutlineColor(sf::Color::White);
	reRect.setOutlineThickness(2);

	sink->sortingLayer = SortingLayers::Foreground;
	sink->sortingOrder = 1;

	sink->SetPosition({ 525.f, 780.f });
	sink->SetScale({ 1.8f, 1.8f });
	sink->SetOrigin(Origins::ML);

	door->sortingLayer = SortingLayers::Foreground;
	door->sortingOrder = 1;

	door->SetPosition({ 200.f, 70.f });
	door->SetScale({ 1.8f, 1.8f });
	door->SetOrigin(Origins::TL);

	lightdoor->sortingLayer = SortingLayers::Foreground;
	lightdoor->sortingOrder = 1;

	lightdoor->SetPosition({ 35.f, 190.f });
	lightdoor->SetScale({ 1.8f, 1.8f });
	lightdoor->SetOrigin(Origins::TL);

	lightdoorSprite->SetActive(false);
	lightdoorSprite->SetPosition({ 0.f, 0.f });
	lightdoorSprite->SetScale({ 2.5f, 2.7f });
	lightdoorSprite->SetOrigin(Origins::MC);

	fire->sortingLayer = SortingLayers::Foreground;
	fire->sortingOrder = 2;

	fire->SetPosition({ 705.f, 170.f });
	fire->SetOrigin(Origins::MC);
	fire->SetScale({ 2.f,2.f });
	fire->SetActive(false);

	itemStar->sortingLayer = SortingLayers::Foreground;
	itemStar->sortingOrder = 2;

	itemStar->SetPosition({ 600.f, 350.f });
	itemStar->SetOrigin(Origins::MC);
	itemStar->SetScale({ 1.5f,1.5f });
	itemStar->SetActive(false);

	rect.setSize({ 16.f, 32.f });
	Utils::SetOrigin(rect, Origins::BC);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::White);
	rect.setOutlineThickness(2);
	rect.setPosition({ 1000.f, 340.f });
	rect.setScale({ 1.5f, 1.5f });

	text->SetActive(false);

	getBranch = true;
	getBottle = false;
}

void Map003::Enter()
{
	sf::Vector2f nikopos = niko->GetPosition();

	worldView.setSize({ 840, 680 });
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

	sf::Vector2f nikoPos = niko->GetPosition();
	sf::Vector2f tvPos = tv->GetPosition();
	sf::Vector2f sofaPos = sofa->GetPosition();
	sf::Vector2f rePos = re->GetPosition();
	sf::Vector2f sinkPos = sink->GetPosition();
	sf::Vector2f fpPos = fireplace->GetPosition();

	sf::FloatRect fpBound = fpRect.getGlobalBounds();
	sf::FloatRect reBound = reRect.getGlobalBounds();
	sf::FloatRect tvBound = tvRect.getGlobalBounds();
	sf::FloatRect nikoBound = niko->GetGlobalBounds();

	worldView.setSize({ 840, 680 });
	worldView.setCenter(nikoPos.x, nikoPos.y);

	lightdoorSprite->SetPosition({ nikoPos.x, nikoPos.y });

	HitBox& nikoHitbox = niko->GetHitBox();
	HitBox& tvHitbox = tv->GetHitBox();
	HitBox& FPHitBox = fireplace->GetHitBox();
	HitBox& sofaHitBox = sofa->GetHitBox();
	HitBox& reHitBox = re->GetHitBox();
	HitBox& sinkHitBox = sink->GetHitBox();
	HitBox& doorHitBox = door->GetHitBox();
	HitBox& lightdoorHitBox = lightdoor->GetHitBox();
	HitBox& starHitBox = itemStar->GetHitBox();

	sf::FloatRect basementFloatRect = rect.getLocalBounds();
	sf::FloatRect tvFloatRect = tv->GetGlobalBounds();

	HitBox basementHitBox;
	basementHitBox.UpdateTr(rect, basementFloatRect);

	//TV
	if (Utils::CheckCollision(nikoHitbox, tvHitbox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - tvPos;
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

	if (getBottle == true && nikoBound.intersects(tvBound))
	{
		if (isTextVisible == false && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetString("Fired Branch!");
			text->SetStringSize(100);
			text->SetOrigin(Origins::MC);
			text->SetPosition({ nikoPos.x + 100.f, nikoPos.y - 50.f });
			text->SetActive(true);
			getFiredBranch = true;
			isTextVisible = true;
			lock = false;
			return;
		}
		if (text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetSpeed(100.f);
			isTextVisible = false;
		}
	}

	//FIREPLACE
	if (Utils::CheckCollision(nikoHitbox, FPHitBox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - fpPos;
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
		isCollision = true;
	}

	if (getFiredBranch == true && getBottle == true && Utils::CheckCollision(nikoHitbox, FPHitBox))
	{
		if (isCollision == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			fire->SetActive(true);
			itemStar->SetActive(true);
			isCollision = false;
		}
	}

	if (getFiredBranch == true && getBottle == true && nikoBound.intersects(fpBound))
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			fire->SetActive(true);
			itemStar->SetActive(true);
		}
	}

	//SOFA
	if (Utils::CheckCollision(nikoHitbox, sofaHitBox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - sofaPos;
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

	//RE
	if (Utils::CheckCollision(nikoHitbox, reHitBox))
	{
		// 충돌 방향 벡터 계산
		sf::Vector2f direction = nikoPos - rePos;
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
		isCollision = true;
	}

	if (nikoBound.intersects(reBound) && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		if (isTextVisible == false && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			niko->SetSpeed(0.f);
			text->SetString("Get Bottle!");
			text->SetStringSize(100);
			text->SetOrigin(Origins::MC);
			text->SetPosition({ nikoPos.x - 350.f, nikoPos.y - 300.f });
			text->SetActive(true);
			getBottle = true;
			lock = false;
			isTextVisible = true;
			return;
		}

		if (getBottle == true && text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetSpeed(100.f);
			isTextVisible = false;
		}
	}

	/*if (text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		text->SetActive(false);
		niko->SetPosition({ nikopos.x, nikopos.y + 1 });
		niko->SetSpeed(100.f);
	}*/

	//SINK
	if (Utils::CheckCollision(nikoHitbox, sinkHitBox))
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

	//DOOR
	if (Utils::CheckCollision(nikoHitbox, doorHitBox))
	{
		niko->SetBeforeScene(3);
		SCENE_MGR.ChangeScene(SceneIds::Map001);
	}

	if (Utils::CheckCollision(nikoHitbox, lightdoorHitBox))
	{
		niko->SetSpeed(0.f);
		lightdoorSprite->SetActive(true);
		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			lightdoorSprite->SetActive(false);
			niko->SetPosition({ nikoPos.x, nikoPos.y + 1 });
			niko->SetSpeed(100.f);
		}
	}

	//ITEMSTAR
	if (itemStar->IsActive())
	{
		if (Utils::CheckCollision(nikoHitbox, starHitBox))
		{
			niko->SetSpeed(0.f);
			if (isTextVisible == false && InputMgr::GetKeyDown(sf::Keyboard::Z))
			{
				text->SetString("Get Basement Key!");
				text->SetStringSize(100);
				text->SetOrigin(Origins::MC);
				text->SetPosition({ nikoPos.x - 150.f, nikoPos.y - 100.f });
				text->SetActive(true);
				getKey = true;
				lock = false;
				isTextVisible = true;
				return;
			}
		}

		if (text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			itemStar->SetActive(false);
			niko->SetSpeed(100.f);
			text->SetActive(false);
			//niko->SetPosition({ nikopos.x, nikopos.y + 1 });
			niko->SetSpeed(100.f);
			isTextVisible = false;
		}
	}

	//BAESMENT
	if (getKey == false && Utils::CheckCollision(nikoHitbox, basementHitBox))
	{
		niko->SetSpeed(0.f);
		text->SetString("LOCK!");
		text->SetStringSize(100);
		text->SetOrigin(Origins::MC);
		text->SetPosition({ nikoPos.x - 500.f, nikoPos.y - 100.f });
		text->SetActive(true);
		niko->SetPosition({ nikoPos.x - 1, nikoPos.y });
		lock = true;
	}
	else if (lock == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		niko->SetSpeed(100.f);
		text->SetActive(false);
	}

	if (getKey == true && Utils::CheckCollision(nikoHitbox, basementHitBox))
	{
		niko->SetBeforeScene(3);
		SCENE_MGR.ChangeScene(SceneIds::Map004_1);
	}
}

void Map003::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	//window.draw(rect);
	//window.draw(reRect);
//	window.draw(fpRect);
	//window.draw(tvRect);
}
