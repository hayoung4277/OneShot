#include "Map001.h"
#include "Scene.h"
#include "SpriteGo.h"
#include "Niko.h"
#include "Remocon.h"
#include "Computer.h"
#include "BookCase.h"
#include "Message.h"
#include "HitBox.h"
#include "TransfomableRect.h"

sf::RectangleShape Map001::nikoRect(sf::Vector2f(48.f, 64.f));
sf::RectangleShape Map001::rect1(sf::Vector2f(16.f, 32.f));
sf::RectangleShape Map001::rect2(sf::Vector2f(56.f, 30.f));

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
	bookcase->SetPosition({680.f, 380.f});
	bookcase->SetScale({ 2.f, 2.f });

	Utils::SetOrigin(rect1, Origins::BC);
	rect1.setScale({ 1.5f, 1.5f });
	rect1.setPosition({ 20.f, 590.f });
	rect1.setFillColor(sf::Color::Transparent);
	rect1.setOutlineColor(sf::Color::Green);
	rect1.setOutlineThickness(1);

	Utils::SetOrigin(rect2, Origins::BC);
	rect2.setScale({ 1.5f, 1.5f });
	rect2.setPosition({ 850.f, 420.f });
	rect2.setFillColor(sf::Color::Transparent);
	rect2.setOutlineColor(sf::Color::Green);
	rect2.setOutlineThickness(1);


	Utils::SetOrigin(nikoRect, Origins::BC);
	nikoRect.setPosition(niko->GetPosition());
	nikoRect.setFillColor(sf::Color::Transparent);
	nikoRect.setOutlineColor(sf::Color::Green);
	nikoRect.setOutlineThickness(1);

	text->SetString("message");
	text->SetActive(false);
	text->SetPosition({ 600.f, 500.f });
	text->SetStringSize(10);

	getRemocon = false;
	isCollision = false;
}

void Map001::Enter()
{
	//sf::Vector2f nikopos = niko->GetPosition();

	//worldView.setSize(FRAMEWORK.GetWindowSizeF());
	//worldView.setCenter(nikopos.x, nikopos.y);

	TEXTURE_MGR.Load("Graphics/Map/map001.png");

	Scene::Enter();
}

void Map001::Exit()
{


	TEXTURE_MGR.Unload("Graphics/Map/map001.png");

	Scene::Exit();
}

void Map001::Update(float dt)
{
	Scene::Update(dt);

	sf::Vector2f pos = niko->GetPosition();

	//worldView.setSize(FRAMEWORK.GetWindowSizeF());
	//worldView.setCenter(pos.x, pos.y);

	sf::FloatRect bound = niko->GetGlobalBounds();
	sf::FloatRect rect2Bound = rect2.getGlobalBounds();

	/*sf::Vector2i mousePos = InputMgr::GetMousePosition();

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{
		std::cout << mousePos.x << ", " << mousePos.y << std::endl;
	}*/

	nikoRect.setPosition(pos);

	if (getRemocon == true && bound.intersects(rect2Bound))
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			solvePassword = true;
		}
	}

	if (solvePassword == true && Utils::CheckCollision(rect1, nikoRect))
	{
		SCENE_MGR.ChangeScene(SceneIds::Map002);
	}
	
	if (solvePassword == false && Utils::CheckCollision(rect1, nikoRect))
	{
		text->SetString("LOCK!!");
		niko->SetSpeed(0.f);
		text->SetActive(true);
		text->SetStringSize(100);

		if (InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			niko->SetPosition({ pos.x + 1, pos.y });
			niko->SetSpeed(100.f);
		}
	}

	if (getRemocon == false)
	{
		if (Utils::CheckCollision(nikoRect, remoconRect))
		{
			niko->SetSpeed(0.f);
			remocon->SetDebugBoxOutlineColor(sf::Color::Red);
			isCollision = true;
		}

		if (isCollision == true)
		{
			if (InputMgr::GetKey(sf::Keyboard::Left))
			{
				niko->SetSpeed(100.f);

				remocon->SetDebugBoxOutlineColor(sf::Color::Green);

				isCollision = false;
			}
			else if (niko->GetPosition().y < remocon->GetPosition().y && InputMgr::GetKey(sf::Keyboard::Up))
			{
				niko->SetSpeed(100.f);

				remocon->SetDebugBoxOutlineColor(sf::Color::Green);
				isCollision = false;
			}
			else if (niko->GetPosition().y > remocon->GetPosition().y && InputMgr::GetKey(sf::Keyboard::Down))
			{
				niko->SetSpeed(100.f);

				remocon->SetDebugBoxOutlineColor(sf::Color::Green);
				isCollision = false;
			}
			else if (InputMgr::GetKeyDown(sf::Keyboard::Z))
			{
				getRemocon = true;
			}
		}
	}

	if (Utils::CheckCollision(nikoRect, computerRect))
	{
		niko->SetSpeed(0.f);
	}

	if (Utils::CheckCollision(nikoRect, computerRect) && InputMgr::GetKey(sf::Keyboard::Down))
	{
		niko->SetSpeed(100.f);
	}
	else if (Utils::CheckCollision(nikoRect, computerRect) && InputMgr::GetKey(sf::Keyboard::Left))
	{
		niko->SetSpeed(100.f);
	}

	if (getRemocon == true)
	{
		remocon->SetActive(false);
	}
}

void Map001::Draw(sf::RenderWindow& window)
{
	window.draw(nikoRect);
	window.draw(rect1);
	window.draw(rect2);
	Scene::Draw(window);
}