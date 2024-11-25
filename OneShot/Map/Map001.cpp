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

	niko->SetPosition({ 330.f, 450.f });
	niko->SetScale({ 1.5f,1.5f });
	niko->SetOrigin(Origins::BC);

	remocon->sortingLayer = SortingLayers::Foreground;
	remocon->sortingOrder = 1;

	remocon->SetOrigin(Origins::ML);
	remocon->SetPosition({ 880.f, 600.f });
	remocon->SetScale({ 1.f, 1.f });
	remocon->SetActive(true);

	computer->sortingLayer = SortingLayers::Foreground;
	computer->sortingOrder = 1;

	computer->SetOrigin(Origins::MC);
	computer->SetPosition({ 420.f, 360.f });
	computer->SetScale({ 1.f, 1.f });

	bookcase->sortingLayer = SortingLayers::Foreground;
	bookcase->sortingOrder = 1;

	bookcase->SetOrigin(Origins::MC);
	bookcase->SetPosition({ 600.f, 300.f });
	bookcase->SetScale({ 1.f, 1.f });

	for (int i = 0; i < 8; ++i)
	{
		rect[i].setFillColor(sf::Color::Transparent);
		rect[i].setOutlineColor(sf::Color::Red);
		rect[i].setOutlineThickness(1);
		Utils::SetOrigin(rect[i], Origins::BC);
	}

	//ȭ��� �Ա�
	rect[0].setSize({ 16.f, 32.f });
	rect[0].setScale({ 1.5f, 1.5f });
	rect[0].setPosition({ 20.f, 540.f });

	//�Ž� �Ա�
	rect[1].setSize({ 32.f, 16.f });
	rect[1].setPosition({ 565.f, 800.f });
	rect[1].setScale({ 1.5f, 1.5f });

	//��
	rect[2].setSize({ 110.f, 88.f });
	rect[2].setPosition({ 40.f, 600.f });
	rect[2].setScale({ 1.5f, 1.5f });

	//��1
	rect[3].setSize({ 350.f,60.f });
	rect[3].setPosition({ 210.f, 740.f });
	rect[4].setScale({ 1.f, 1.f });

	//��2
	rect[4].setSize({ 350.f,60.f });
	rect[4].setPosition({ 620.f, 740.f });
	rect[4].setScale({ 1.f, 1.f });

	//��3
	rect[5].setSize({ 620.f,60.f });
	rect[5].setPosition({ 340.f, 340.f });
	rect[6].setScale({ 1.f, 1.f });

	//��4
	rect[6].setSize({ 30.f, 600.f });
	rect[6].setPosition({ 970.f, 200.f });
	rect[6].setScale({ 1.f, 1.f });

	//��5
	rect[7].setSize({ 120.f, 30.f });
	rect[7].setPosition({ 40.f, 430.f });
	rect[7].setScale({ 1.5f, 1.5f });


	Utils::SetOrigin(windowRect, Origins::BC);
	windowRect.setSize({ 100.f, 60.f });
	windowRect.setPosition({ 800.f, 400.f });
	windowRect.setScale({ 1.f, 1.f });
	windowRect.setFillColor(sf::Color::Transparent);
	windowRect.setOutlineColor(sf::Color::White);
	windowRect.setOutlineThickness(2);

	Utils::SetOrigin(computerRect, Origins::TL);
	computerRect.setSize({ 128.f, 50.f });
	computerRect.setPosition({ 420.f, 450.f });
	computerRect.setScale({ 1.f, 1.f });
	computerRect.setFillColor(sf::Color::Transparent);
	computerRect.setOutlineColor(sf::Color::White);
	computerRect.setOutlineThickness(2);

	Utils::SetOrigin(remoconRect, Origins::ML);
	remoconRect.setSize({ 32.f, 32.f });
	remoconRect.setPosition({ 845.f, 585.f });
	remoconRect.setScale({ 1.f, 1.f });
	remoconRect.setFillColor(sf::Color::Transparent);
	remoconRect.setOutlineColor(sf::Color::White);
	remoconRect.setOutlineThickness(2);

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
	solvePassword = false;
	passwordIsActive = false;
	getBranch = false;
	isTextVisible = false;

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
	sf::Vector2f computerPos = computer->GetPosition();
	sf::Vector2f remoconPos = remocon->GetPosition();
	sf::Vector2f bookcasePos = bookcase->GetPosition();
	sf::FloatRect nikoBound = niko->GetGlobalBounds();
	sf::FloatRect windowBound = windowRect.getGlobalBounds();
	sf::FloatRect computerBound = computerRect.getGlobalBounds();
	sf::FloatRect remoconBound = remoconRect.getGlobalBounds();

	for (int i = 0; i < 6; i++)
	{
		rects[i] = rect[i + 2].getGlobalBounds();
	}

	//std::cout << nikoPos.x << ", " << nikoPos.y << std::endl;

	worldView.setSize({ 840, 680 });
	worldView.setCenter(nikoPos.x, nikoPos.y);

	HitBox& nikoHitBox = niko->GetHitBox();
	HitBox& computerHitBox = computer->GetHitBox();
	HitBox& remoconHitBox = remocon->GetHitBox();
	HitBox& bookcaseHitBox = bookcase->GetHitBox();

	for (int i = 0; i < 6; i++)
	{
		hitbox[i].UpdateTr(rect[i + 2], rects[i]);
	}

	HitBox toiletDoorHitBox;
	toiletDoorHitBox.UpdateTr(rect[0], rect[0].getLocalBounds());

	HitBox livingroom;
	livingroom.UpdateTr(rect[1], rect[1].getLocalBounds());

	//REMOCON
	if (getRemocon == false)
	{
		if (Utils::CheckCollision(nikoHitBox, remoconHitBox))
		{
			// �浹 ���� ���
			sf::Vector2f direction = nikoPos - remoconPos;
			float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
			if (magnitude != 0.f)
				direction /= magnitude;

			// �浹 ���� ��� (X �Ǵ� Y�� ����)
			if (std::abs(direction.x) > std::abs(direction.y))
			{
				// ���� �浹: ��/��θ� �и�
				direction.y = 0.f;
			}
			else
			{
				// ���� �浹: ��/�Ʒ��θ� �и�
				direction.x = 0.f;
			}

			// Niko�� �浹 �������� �о
			niko->SetPosition(nikoPos + direction * 1.f);
			niko->SetSpeed(0.f); // �浹 �� �ӵ� ����
		}

	}
	if (nikoBound.intersects(remoconBound) && InputMgr::GetKeyDown(sf::Keyboard::Z))
	{
		getRemocon = true;
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[0]))
	{
		niko->SetPosition({ nikoPos.x + 1, nikoPos.y });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[1]))
	{
		niko->SetPosition({ nikoPos.x, nikoPos.y - 1 });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[2]))
	{
		niko->SetPosition({ nikoPos.x, nikoPos.y - 1 });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[3]))
	{
		niko->SetPosition({ nikoPos.x, nikoPos.y + 1 });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[4]))
	{
		niko->SetPosition({ nikoPos.x, nikoPos.y });
	}

	if (Utils::CheckCollision(nikoHitBox, hitbox[5]))
	{
		niko->SetPosition({ nikoPos.x + 1, nikoPos.y });
	}

	if (getRemocon == true && nikoBound.intersects(windowBound))
	{
		if (isTextVisible == false && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetString("Password: 1375");
			text->SetStringSize(100);
			text->SetOrigin(Origins::MC);
			text->SetPosition({ 500.f, 500.f });
			text->SetActive(true);
			isTextVisible = true;
			return;
		}
		if (text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			text->SetActive(false);
			isTextVisible = false;
		}
	}

	// Computer���� �浹 ó��
	if (Utils::CheckCollision(nikoHitBox, computerHitBox))
	{
		// �浹 ���� ���� ���
		sf::Vector2f direction = nikoPos - computerPos;
		float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (magnitude != 0.f)
			direction /= magnitude;

		// �浹 ���� ��� (X �Ǵ� Y�� ����)
		if (std::abs(direction.x) > std::abs(direction.y))
		{
			// ���� �浹: ��/��θ� �и�
			direction.y = 0.f;
		}
		else
		{
			// ���� �浹: ��/�Ʒ��θ� �и�
			direction.x = 0.f;
		}

		// Niko�� �浹 �������� �о
		niko->SetPosition(nikoPos + direction * 1.f);
		niko->SetSpeed(0.f);
	}

	//BookCase���� �浹 ����
	if (Utils::CheckCollision(nikoHitBox, bookcaseHitBox))
	{
		// �浹 ���� ���� ���
		sf::Vector2f direction = nikoPos - bookcasePos;
		float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		if (magnitude != 0.f)
			direction /= magnitude;

		// �浹 ���� ��� (X �Ǵ� Y�� ����)
		if (std::abs(direction.x) > std::abs(direction.y))
		{
			// ���� �浹: ��/��θ� �и�
			direction.y = 0.f;
		}
		else
		{
			// ���� �浹: ��/�Ʒ��θ� �и�
			direction.x = 0.f;
		}

		// Niko�� �浹 �������� �о
		niko->SetPosition(nikoPos + direction * 1.f);
		niko->SetSpeed(0.f);
		isCollision = true;
	}

	// Computer �� �ٿ�忡 ������ ��� z������ ��й�ȣ �̺�Ʈ Ȱ��ȭ
	if (computerBound.intersects(nikoBound))
	{
		//Z Ű�� ������ ��й�ȣ �̺�Ʈ�� Ȱ��ȭ
		if (solvePassword == false && passwordIsActive == false && InputMgr::GetKeyDown(sf::Keyboard::Z))
		{
			// ��й�ȣ �Է� �̺�Ʈ ����

			for (int i = 0; i < 4; i++)
			{
				password[i]->SetActive(true); // ��й�ȣ UI Ȱ��ȭ
			}
			passwordIsActive = true;
			isTextVisible = true;
			selectIndex = 0; // �ʱ� ���� ��ġ
			s = 0;           // �ʱ� ����
			return;
		}

		// ��й�ȣ �Է� ���� �� �̺�Ʈ ó��
		if (passwordIsActive)
		{
			niko->SetSpeed(0.f);
			if (InputMgr::GetKeyDown(sf::Keyboard::Up))
			{
				s = (s + 1) % 10; // ���ڴ� 0~9 �ݺ�
				password[selectIndex]->SetText(std::to_string(s));
			}

			if (InputMgr::GetKeyDown(sf::Keyboard::Down))
			{
				s = (s + 9) % 10; // ���ڴ� 0~9 �ݺ�
				password[selectIndex]->SetText(std::to_string(s));
			}

			if (InputMgr::GetKeyDown(sf::Keyboard::Left))
			{
				s = 0;
				selectIndex = (selectIndex + 3) % 4; // ���� �̵�
			}

			if (InputMgr::GetKeyDown(sf::Keyboard::Right))
			{
				s = 0;
				selectIndex = (selectIndex + 1) % 4; // ������ �̵�
			}

			if (isTextVisible == true && InputMgr::GetKeyDown(sf::Keyboard::Z))
			{
				// �Է� �Ϸ� ó��
				for (int i = 0; i < 4; i++)
				{
					password[i]->SetActive(false); // ��й�ȣ UI ��Ȱ��ȭ
				}

				// ��й�ȣ Ȯ��
				if (s == 5) // ���� ��й�ȣ
				{
					text->SetString("Correct Password!");
					text->SetStringSize(50);
					text->SetPosition({ nikoPos.x, nikoPos.y - 50.f });
					text->SetActive(true);
					solvePassword = true; // ���� �ذ� ���� ������Ʈ
					passwordIsActive = false;
					isTextVisible = false;
				}
				else
				{
					text->SetString("Wrong Password!");
					text->SetStringSize(50);
					text->SetPosition({ nikoPos.x, nikoPos.y - 20.f });
					text->SetActive(true);
					passwordIsActive = false;
				}

			}
		}

		if (text->IsActive() && InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			text->SetActive(false);
			isTextVisible = false;
			niko->SetSpeed(100.f);
		}

	}


	//��й�ȣ Ǯ�� �� ��� ���¿��� �޽��� ���(�Ž�)
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

	//��й�ȣ Ǭ �� ȭ��Ƿ� �̵�
	if (solvePassword == true && Utils::CheckCollision(nikoHitBox, toiletDoorHitBox))
	{
		niko->SetBeforeScene(1);
		SCENE_MGR.ChangeScene(SceneIds::Map002);
	}

	//��й�ȣ Ǯ�� �� ��� ���¿��� �޽��� ���(ȭ���)
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

	//��й�ȣ Ǭ �� �ŽǷ� �̵�
	if (solvePassword == true && Utils::CheckCollision(nikoHitBox, livingroom))
	{
		niko->SetBeforeScene(1);
		SCENE_MGR.ChangeScene(SceneIds::Map003);
	}

	//������ ȹ�� �� ������ ��Ȱ��ȭ
	if (getRemocon == true)
	{
		remocon->SetActive(false);
	}
}

void Map001::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	//for (int i = 0; i < 8; i++)
	//{
	//	window.draw(rect[i]);
	//}
	//window.draw(windowRect);
	//window.draw(computerRect);
	//window.draw(remoconRect);
}