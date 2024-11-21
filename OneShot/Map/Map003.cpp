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

	door->SetPosition({ 200.f, 150.f });
	door->SetScale({ 2.f, 2.f });
	door->SetOrigin(Origins::TL);

	lightdoor->sortingLayer = SortingLayers::Foreground;
	lightdoor->sortingOrder = 1;

	lightdoor->SetPosition({ -60.f, 260.f });
	lightdoor->SetScale({ 2.f, 2.f });
	lightdoor->SetOrigin(Origins::TL);

	lightdoorSprite->SetActive(false);
	lightdoorSprite->SetPosition({ 0.f, 0.f });
	lightdoorSprite->SetScale({ 2.f, 2.2f });
	lightdoorSprite->SetOrigin(Origins::MC);

	fire->sortingLayer = SortingLayers::Foreground;
	fire->sortingOrder = 2;

	fire->SetPosition({ 765.f, 255.f });
	fire->SetOrigin(Origins::MC);
	fire->SetScale({ 2.f,2.f });
	fire->SetActive(false);

	itemStar->sortingLayer = SortingLayers::Foreground;
	itemStar->sortingOrder = 2;

	itemStar->SetPosition({ 650.f, 400.f });
	itemStar->SetOrigin(Origins::MC);
	itemStar->SetScale({ 2.f,2.f });
	itemStar->SetActive(false);

	rect.setSize({ 16.f, 32.f });
	Utils::SetOrigin(rect, Origins::BC);
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineColor(sf::Color::White);
	rect.setOutlineThickness(2);
	rect.setPosition({ 1100.f, 440.f });
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

	sf::Vector2f nikopos = niko->GetPosition();

	worldView.setSize({ 840, 680 });
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
	HitBox& starHitBox = itemStar->GetHitBox();

	sf::FloatRect basementFloatRect = rect.getLocalBounds();

	HitBox basementHitBox;
	basementHitBox.UpdateTr(rect, basementFloatRect);

	if (Utils::CheckCollision(nikoHitbox, tvHitbox))
	{
		niko->SetSpeed(0.f);
		if (InputMgr::GetKey(sf::Keyboard::Down))
		{
			niko->SetSpeed(100.f);
		}
	}

	if (getBranch == true && getBottle == true && Utils::CheckCollision(nikoHitbox, tvHitbox))
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetString("Fired Branch!");
			text->SetStringSize(100);
			text->SetOrigin(Origins::MC);
			text->SetPosition({ nikopos.x + 100.f, nikopos.y - 100.f });
			text->SetActive(true);
			niko->SetPosition({ nikopos.x, nikopos.y + 1 });
			getFiredBranch = true;
			lock = false;
		}
		/*else if (getFiredBranch == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetSpeed(100.f);
		}*/
	}
	else if (getFiredBranch == true && InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		text->SetActive(false);
		niko->SetSpeed(100.f);
	}

	if (Utils::CheckCollision(nikoHitbox, FPHitBox))
	{
		niko->SetSpeed(0.f);
		if (InputMgr::GetKey(sf::Keyboard::Down))
		{
			niko->SetSpeed(100.f);
		}
	}

	if (getFiredBranch == true && getBottle == true && Utils::CheckCollision(nikoHitbox, FPHitBox))
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			fire->SetActive(true);
			itemStar->SetActive(true);
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

	if (Utils::CheckCollision(nikoHitbox, reHitBox) && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		niko->SetSpeed(0.f);
		text->SetString("Get Bottle!");
		text->SetStringSize(100);
		text->SetOrigin(Origins::MC);
		text->SetPosition({ nikopos.x - 350.f, nikopos.y - 300.f });
		text->SetActive(true);
		niko->SetPosition({ nikopos.x, nikopos.y + 1 });
		getBottle = true;
		lock = false;

	}
	else if (getBottle == true && InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		text->SetActive(false);
		//niko->SetPosition({ nikopos.x, nikopos.y + 1 });
		niko->SetSpeed(100.f);
	}

	/*if (text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		text->SetActive(false);
		niko->SetPosition({ nikopos.x, nikopos.y + 1 });
		niko->SetSpeed(100.f);
	}*/

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
			niko->SetPosition({ nikopos.x, nikopos.y + 1 });
			niko->SetSpeed(100.f);
		}
	}

	if (itemStar->IsActive())
	{
		if (Utils::CheckCollision(nikoHitbox, starHitBox))
		{
			niko->SetSpeed(0.f);
		}

		if (InputMgr::GetKey(sf::Keyboard::Right))
		{
			niko->SetSpeed(100.f);
		}

		if (Utils::CheckCollision(nikoHitbox, starHitBox) && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetString("Get Basement Key!");
			text->SetStringSize(100);
			text->SetOrigin(Origins::MC);
			text->SetPosition({ nikopos.x - 150.f, nikopos.y - 100.f });
			text->SetActive(true);
			niko->SetPosition({ nikopos.x + 1, nikopos.y });
			getKey = true;
			lock = false;
		}
		else if (getKey == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			itemStar->SetActive(false);
			//niko->SetPosition({ nikopos.x, nikopos.y + 1 });
			niko->SetSpeed(100.f);
		}
	}

	/*if (getKey == true && InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		text->SetActive(false);
		itemStar->SetActive(false);
		niko->SetPosition({ nikopos.x, nikopos.y + 1 });
		niko->SetSpeed(100.f);
	}*/

	if (getKey == false && Utils::CheckCollision(nikoHitbox, basementHitBox))
	{
		niko->SetSpeed(0.f);
		text->SetString("LOCK!");
		text->SetStringSize(100);
		text->SetOrigin(Origins::MC);
		text->SetPosition({ nikopos.x - 500.f, nikopos.y - 100.f });
		text->SetActive(true);
		niko->SetPosition({ nikopos.x - 1, nikopos.y });
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
}
