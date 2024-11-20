#include "stdafx.h"
#include "SceneTitle.h"
#include "SpriteGo.h"
#include "Button.h"
#include "Scene.h"

SceneTitle::SceneTitle() : Scene(SceneIds::Title)
{

}

void SceneTitle::Init()
{
	background = AddGo(new SpriteGo("Graphics/Titles/normal1.png"));
	explanation = AddGo(new SpriteGo("Graphics/Pictures/instruction1.png"));

	startBtn = AddGo(new Button("Fonts/SourceHanSansHWSC-Regular.otf"));
	quitBtn = AddGo(new Button("Fonts/SourceHanSansHWSC-Regular.otf"));

	Scene::Init();

	background->sortingLayer = SortingLayers::Background;
	background->sortingOrder = -2;
	background->SetOrigin(Origins::TL);
	background->SetScale(titleScale);
	background->SetPosition({ 0, 0 });

	explanation->SetActive(false);
	explanation->sortingLayer = SortingLayers::UI;
	explanation->sortingOrder = 0;
	explanation->SetOrigin(Origins::TL);
	explanation->SetScale({ 1.56f, 2.1f });
	explanation->SetPosition({ 0, 0 });

	startBtn->sortingLayer = SortingLayers::UI;
	startBtn->sortingOrder = 1;
	startBtn->SetPosition({ 640.f + 200.f, 480.f + 380.f });
	startBtn->SetFontSize(50);
	startBtn->SetOrigin(Origins::MC);
	startBtn->SetText(std::to_string(s));

	quitBtn->sortingLayer = SortingLayers::UI;
	quitBtn->sortingOrder = 1;
	quitBtn->SetPosition({ 640.f + 200.f, 480.f + 470.f });
	quitBtn->SetFontSize(50);
	quitBtn->SetOrigin(Origins::ML);
	quitBtn->SetText("QUIT");

	for (int i = 0; i < 2; ++i)
	{
		rect[i].setFillColor(sf::Color::Transparent);
		rect[i].setOutlineColor(sf::Color::White);
		rect[i].setOutlineThickness(5);
		Utils::SetOrigin(rect[i], Origins::MC);
		rect[i].setPosition({ btnPos.x, btnPos.y });
		btnPos.y += 90.f;
	}
}

void SceneTitle::Enter()
{
	titleScale = { 1.6f, 2.2f };
	TEXTURE_MGR.Load("Graphics/Titles/normal1.png");
	TEXTURE_MGR.Load("Graphics/Pictures/instruction1.png");
	FONT_MGR.Load("Fonts/SourceHanSansHWSC-Regular.otf");

	Scene::Enter();
}

void SceneTitle::Exit()
{

	Scene::Exit();

	TEXTURE_MGR.Unload("Graphics/Titles/normal1.png");
	TEXTURE_MGR.Unload("Graphics/Pictures/instruction1.png");
	FONT_MGR.Unload("Fonts/SourceHanSansHWSC-Regular.otf");
}

void SceneTitle::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		explanation->SetActive(true);
	}

	if (explanation->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		SCENE_MGR.ChangeScene(SceneIds::Map001);
	}

	HitBox& startBtnHitBox = startBtn->GetHitBox();

	if (InputMgr::GetKeyDown(sf::Keyboard::Down))
	{
		s++;
	}

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left)) {
		if (startBtn->IsCursorOn()) {
			startBtnPressed = true;
		}
		if (quitBtn->IsCursorOn()) {
			quitBtnPressed = true;
		}
	}
	if (InputMgr::GetMouseButtonUp(sf::Mouse::Left)) {
		if (startBtn->IsCursorOn()) {
			startBtnPressed = false;
			SCENE_MGR.ChangeScene(SceneIds::Map001);
		}
		else if (quitBtn->IsCursorOn()) {
			quitBtnPressed = false;
			FRAMEWORK.GetWindow().close();
		}
		else {
			startBtnPressed = false;
			quitBtnPressed = false;
		}
	}
}

void SceneTitle::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	for (int i = 0; i < 2; i++)
	{
		window.draw(rect[i]);
	}
}
