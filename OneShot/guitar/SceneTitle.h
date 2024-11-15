#pragma once
#include "Scene.h"

class Button;
class SpriteGo;

class SceneTitle : public Scene
{
protected:
	SpriteGo* background;
	SpriteGo* explanation;
	sf::Vector2f titleScale = { 1.6f, 2.2f };
	float scaleMultiply = 0.02f;

	Button* startBtn;
	Button* quitBtn;
	bool startBtnPressed;
	bool quitBtnPressed;
public:
	SceneTitle();
	~SceneTitle() = default;

	void Init() override;
	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void TitleMove(float dt);
};

