#include "Map001.h"
#include "Scene.h"
#include "SpriteGo.h"
#include "Niko.h"
#include "Remocon.h"
#include "Computer.h"
#include "BookCase.h"
#include "Message.h"
#include "HitBox.h"
#include "Button.h"
#include "Inventory.h"

Map001::Map001()
	:Scene(SceneIds::Map001)
{
}

void Map001::Init()
{
	map001 = AddGo(new SpriteGo("Graphics/Map/map001.png"));
	niko = AddGo(new Niko("Niko"));
	remocon = AddGo(new Remocon("Remocon"));
	computer = AddGo(new Computer("Computer"));
	bookcase = AddGo(new BookCase("BookCase"));
	text = AddGo(new Message("Message"));
	inventory = AddGo(new Inventory("Inventory"));

	for (int i = 0; i < 4; i++)
	{
		password[i] = AddGo(new Button("Fonts/HMFMPYUN.ttf"));
	}

	Scene::Init();

	map001->sortingLayer = SortingLayers::Background;
	map001->sortingOrder = -1;

	map001->SetOrigin(Origins::MC);
	map001->SetScale(mapScale);
	map001->SetPosition({ 500.f, 500.f });

	niko->sortingLayer = SortingLayers::Foreground;
	niko->sortingOrder = 2;

	niko->SetPosition({ 400.f, 500.f });
	niko->SetScale({ 1.5f,1.5f });
	niko->SetOrigin(Origins::BC);

	remocon->sortingLayer = SortingLayers::Foreground;
	remocon->sortingOrder = 1;

	remocon->SetOrigin(Origins::MC);
	remocon->SetPosition({ 880.f, 600.f });
	remocon->SetScale({ 2.f, 2.f });
	remocon->SetActive(true);

	computer->sortingLayer = SortingLayers::Foreground;
	computer->sortingOrder = 1;

	computer->SetOrigin(Origins::MC);
	computer->SetPosition({ 510.f, 420.f });
	computer->SetScale({ 2.f, 2.f });

	bookcase->sortingLayer = SortingLayers::Foreground;
	bookcase->sortingOrder = 1;

	bookcase->SetOrigin(Origins::MC);
	bookcase->SetPosition({ 680.f, 380.f });
	bookcase->SetScale({ 2.f, 2.f });

	for (int i = 0; i < 5; ++i)
	{
		rect[i].setFillColor(sf::Color::Transparent);
		rect[i].setOutlineColor(sf::Color::Red);
		rect[i].setOutlineThickness(1);
		Utils::SetOrigin(rect[i], Origins::BC);
	}

	rect[0].setSize({ 16.f, 32.f });
	rect[0].setScale({ 1.5f, 1.5f });
	rect[0].setPosition({ 20.f, 540.f });

	rect[1].setSize({ 32.f, 16.f });
	rect[1].setPosition({ 565.f, 800.f });
	rect[1].setScale({ 1.5f, 1.5f });

	rect[2].setSize({ 64.f, 88.f });
	rect[2].setPosition({ 680.f, 600.f });
	rect[2].setScale({ 1.5f, 1.5f });

	rect[3].setSize({ 53.f,87.f });
	rect[3].setPosition({ 240.f,356.f });
	rect[3].setScale({ 1.5f, 1.5f });

	rect[4].setSize({ 100.f,60.f });
	rect[4].setPosition({ 800.f, 360.f });
	rect[4].setScale({ 1.f, 1.f });

	Utils::SetOrigin(windowRect, Origins::BC);
	windowRect.setSize({ 100.f, 60.f });
	windowRect.setPosition({ 800.f, 400.f });
	windowRect.setScale({ 1.f, 1.f });
	windowRect.setFillColor(sf::Color::Transparent);
	windowRect.setOutlineColor(sf::Color::White);
	windowRect.setOutlineThickness(2);

	text->SetActive(false);

	inventory->sortingLayer = SortingLayers::UI;
	inventory->sortingOrder = 1;

	inventory->SetOrigin(Origins::MC);
	inventory->SetPosition({ 1240 * 0.5f, 960 * 0.5f });
	inventory->SetScale({ 4.f, 4.f });
	inventory->SetActive(false);

	for (int i = 0; i < 4; i++)
	{
		password[i]->sortingLayer = SortingLayers::UI;
		password[i]->sortingOrder = 1;
		password[i]->SetText("0");
		password[i]->SetFontSize(50);
		password[i]->SetPosition({ passwordPos.x, passwordPos.y });
		password[i]->SetOrigin(Origins::MC);
		passwordPos.x += 50.f;
		password[i]->SetActive(false);
	}

	/*for (int i = 0; i < 4; ++i)
	{
		passwordRect[i].setFillColor(sf::Color::Transparent);
		passwordRect[i].setOutlineColor(sf::Color::Red);
		passwordRect[i].setOutlineThickness(1);
		Utils::SetOrigin(passwordRect[i], Origins::MC);
	}*/

	getRemocon = false;
	isCollision = false;

	int beforeScene = niko->GetBeforeScene();

	if (beforeScene == 2)
	{
		niko->SetPosition({ 40.f, 540.f });
	}

	if (beforeScene == 3)
	{
		niko->SetPosition({ 565.f, 790.f });
	}
}

void Map001::Enter()
{
	sf::Vector2f nikopos = niko->GetPosition();

	worldView.setSize({ 840, 680 });
	worldView.setCenter(nikopos.x, nikopos.y);

	TEXTURE_MGR.Load("Graphics/Map/map001.png");
	FONT_MGR.Load("Fonts/HMFMPYUN.ttf");

	Scene::Enter();
}

void Map001::Exit()
{
	TEXTURE_MGR.Unload("Graphics/Map/map001.png");
	FONT_MGR.Unload("Fonts/HMFMPYUN.ttf");

	Scene::Exit();
}

void Map001::Update(float dt)
{
	Scene::Update(dt);

	sf::Vector2f nikoPos = niko->GetPosition();
	sf::FloatRect nikoBound = niko->GetGlobalBounds();
	sf::FloatRect windowBound = windowRect.getGlobalBounds();
	sf::FloatRect computerBound = computer->GetLocalBounds();

	worldView.setSize({ 840, 680 });
	worldView.setCenter(nikoPos.x, nikoPos.y);

	HitBox& nikoHitBox = niko->GetHitBox();
	HitBox& computerHitBox = computer->GetHitBox();
	HitBox& remoconHitBox = remocon->GetHitBox();
	HitBox& bookcaseHitBox = bookcase->GetHitBox();

	HitBox toiletDoorHitBox;
	toiletDoorHitBox.UpdateTr(rect[0], rect[0].getLocalBounds());

	HitBox livingroom;
	livingroom.UpdateTr(rect[1], rect[1].getLocalBounds());

	if (getRemocon == false)
	{
		if (Utils::CheckCollision(nikoHitBox, remoconHitBox))
		{
			niko->SetSpeed(0.f);
		}

		if (InputMgr::GetKey(sf::Keyboard::Left))
		{
			niko->SetSpeed(100.f);
		}

		if (Utils::CheckCollision(nikoHitBox, remoconHitBox) && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			getRemocon = true;
		}
	}


	if (getRemocon == true && nikoBound.intersects(windowBound))
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetString("Password: 1375");
			text->SetStringSize(100);
			text->SetOrigin(Origins::MC);
			text->SetPosition({ 500.f, 500.f });
			text->SetActive(true);
			isPasswordVisible = true;
		}
		if (isPasswordVisible == true && InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			text->SetActive(false);
		}
	}


	if (Utils::CheckCollision(nikoHitBox, computerHitBox))
	{
		niko->SetSpeed(0.f);

		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			for (int i = 0; i < 4; i++)
			{
				password[i]->SetActive(true);
			}
			passwordIsActive = true;
		}

		if (passwordIsActive == true)
		{
			if (InputMgr::GetKeyDown(sf::Keyboard::Up))
			{
				s++;
			}

			if (s == 9 && InputMgr::GetKeyDown(sf::Keyboard::Up))
			{
				s = 0;
			}

			if (InputMgr::GetKeyDown(sf::Keyboard::Down))
			{
				s--;
			}

			if (s == 0 && InputMgr::GetKeyDown(sf::Keyboard::Down))
			{
				s = 9;
			}


			if (InputMgr::GetKeyDown(sf::Keyboard::Left))
			{
				s = 0;
				selectIndex--;
			}

			if (selectIndex == -1 && InputMgr::GetKeyDown(sf::Keyboard::Left))
			{
				s = 0;
				selectIndex = 3;
			}

			if (InputMgr::GetKeyDown(sf::Keyboard::Right))
			{
				s = 0;
				selectIndex++;
			}

			if (selectIndex == 4 && InputMgr::GetKeyDown(sf::Keyboard::Right))
			{
				s = 0;
				selectIndex = 0;
			}

			password[selectIndex]->SetText(std::to_string(s));

			if (s == 5 && InputMgr::GetKeyDown(sf::Keyboard::Enter))
			{
				for (int i = 0; i < 4; i++)
				{
					password[i]->SetActive(false);
				}
				text->SetString("Correct!");
				text->SetStringSize(50);
				text->SetActive(true);
				solvePassword = true;
				passwordIsActive = false;
				niko->SetPosition({ nikoPos.x, nikoPos.y + 1 });
			}
			else if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
			{
				for (int i = 0; i < 4; i++)
				{
					password[i]->SetActive(false);
				}
				text->SetString("Wrong!");
				text->SetStringSize(50);
				text->SetActive(true);
				solvePassword = false;
				passwordIsActive = false;
				niko->SetPosition({ nikoPos.x, nikoPos.y + 1 });
			}
		}
	}


	if (solvePassword == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		text->SetActive(false);
		niko->SetSpeed(100.f);
	}

	if (solvePassword == false && Utils::CheckCollision(nikoHitBox, livingroom))
	{
		niko->SetSpeed(0.f);
		text->SetString("LOCK!!");
		text->SetStringSize(200);
		text->SetOrigin(Origins::MC);
		text->SetPosition({ 600.f, 500.f });
		text->SetActive(true);

		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetPosition({ nikoPos.x, nikoPos.y - 1 });
			niko->SetSpeed(100.f);
		}
	}

	if (solvePassword == true && Utils::CheckCollision(nikoHitBox, toiletDoorHitBox))
	{
		niko->SetBeforeScene(1);
		SCENE_MGR.ChangeScene(SceneIds::Map002);
	}

	if (solvePassword == false && Utils::CheckCollision(nikoHitBox, toiletDoorHitBox))
	{
		niko->SetSpeed(0.f);
		text->SetString("LOCK!!");
		text->SetStringSize(200);
		text->SetOrigin(Origins::MC);
		text->SetPosition({ 600.f, 500.f });
		text->SetActive(true);

		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetPosition({ nikoPos.x + 1, nikoPos.y });
			niko->SetSpeed(100.f);
		}
	}

	if (solvePassword == true && Utils::CheckCollision(nikoHitBox, livingroom))
	{
		niko->SetBeforeScene(1);
		SCENE_MGR.ChangeScene(SceneIds::Map003);
	}

	if (getRemocon == true)
	{
		remocon->SetActive(false);
	}

	if (Utils::CheckCollision(nikoHitBox, bookcaseHitBox))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoHitBox, bookcaseHitBox) && InputMgr::GetKey(sf::Keyboard::Down))
	{
		niko->SetSpeed(100.f);
	}
}

void Map001::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	/*for (int i = 0; i < 5; i++)
	{
		window.draw(rect[i]);
	}
	window.draw(windowRect);*/
}