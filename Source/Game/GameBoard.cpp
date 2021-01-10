#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include "Game/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

using namespace Game;

GameBoard::GameBoard()
{
	CreatePlayer();
	CreatePersonA();
	CreatePersonB();
	CreatePersonC();
	CreateTextA();
	//CreateTextB();
	//CreateTextC();
	CreateBackground();
	CreateRope();
	CreateBoat();
	CreateTop();
	CreateLock();
	CreateKey();
	CreateBottom();
	CreateAxe();
}

GameBoard::~GameBoard()
{

}

void GameBoard::CreatePlayer()
{
	m_player = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);

	m_player->SetPos(sf::Vector2f(500.0f, 325.0f));
	m_player->SetSize(sf::Vector2f(100.0f, 100.0f));

	//Render
	GameEngine::SpriteRenderComponent* render = m_player->AddComponent<GameEngine::SpriteRenderComponent>();

	render->SetTexture(GameEngine::eTexture::Player);  // <-- Assign the texture to this entity
	render->SetFillColor(sf::Color::Transparent);

	//Movement
	m_player->AddComponent<Game::PlayerMovementComponent>();  // <-- Added the movement component to the player
	m_player->AddComponent<GameEngine::CollidablePhysicsComponent>();  // <-- Added the movement component to the player
	render->SetZLevel(3);
}
void GameBoard::CreatePersonA()
{
	GameEngine::Entity* person_a = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(person_a);

	person_a->SetPos(sf::Vector2f(200.0f, 150.0f));
	person_a->SetSize(sf::Vector2f(100.0f, 100.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_p1 = person_a->AddComponent<GameEngine::SpriteRenderComponent>();

	render_p1->SetTexture(GameEngine::eTexture::Person1);  // <-- Assign the texture to this entity
	render_p1->SetFillColor(sf::Color::Transparent);

	person_a->AddComponent<GameEngine::CollidablePhysicsComponent>();  // <-- Added the movement component to the player
}
void GameBoard::CreatePersonB()
{
	GameEngine::Entity* person_b = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(person_b);

	person_b->SetPos(sf::Vector2f(200.0f, 600.0f));
	person_b->SetSize(sf::Vector2f(100.0f, 100.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_p2 = person_b->AddComponent<GameEngine::SpriteRenderComponent>();

	render_p2->SetTexture(GameEngine::eTexture::Person2);  // <-- Assign the texture to this entity
	render_p2->SetFillColor(sf::Color::Transparent);

	person_b->AddComponent<GameEngine::CollidablePhysicsComponent>();  // <-- Added the movement component to the player
}
void GameBoard::CreatePersonC()
{
	GameEngine::Entity* person_c = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(person_c);

	person_c->SetPos(sf::Vector2f(750.0f, 425.0f));
	person_c->SetSize(sf::Vector2f(100.0f, 100.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_p3 = person_c->AddComponent<GameEngine::SpriteRenderComponent>();

	render_p3->SetTexture(GameEngine::eTexture::Person3);  // <-- Assign the texture to this entity
	render_p3->SetFillColor(sf::Color::Transparent);

	person_c->AddComponent<GameEngine::CollidablePhysicsComponent>();  // <-- Added the movement component to the player
}

void GameBoard::CreateTextA()
{
	GameEngine::Entity* text_a = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(text_a);

	text_a->SetPos(sf::Vector2f(725.0f, 600.0f));
	text_a->SetSize(sf::Vector2f(550.0f, 500.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_t1 = text_a->AddComponent<GameEngine::SpriteRenderComponent>();

	render_t1->SetTexture(GameEngine::eTexture::Text1);  // <-- Assign the texture to this entity
	render_t1->SetFillColor(sf::Color::Transparent);
	render_t1->SetZLevel(-1);
}
/*
void GameBoard::CreateTextB()
{
	GameEngine::Entity* text_b = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(text_b);

	text_b->SetPos(sf::Vector2f(725.0f, 600.0f));
	text_b->SetSize(sf::Vector2f(550.0f, 500.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_t2 = text_b->AddComponent<GameEngine::SpriteRenderComponent>();

	render_t2->SetTexture(GameEngine::eTexture::Text2);  // <-- Assign the texture to this entity
	render_t2->SetFillColor(sf::Color::Transparent);
	render_t2->SetZLevel(-1);
}

void GameBoard::CreateTextC()
{
	GameEngine::Entity* text_c = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(text_c);

	text_c->SetPos(sf::Vector2f(725.0f, 600.0f));
	text_c->SetSize(sf::Vector2f(550.0f, 500.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_t3 = text_c->AddComponent<GameEngine::SpriteRenderComponent>();

	render_t3->SetTexture(GameEngine::eTexture::Text3);  // <-- Assign the texture to this entity
	render_t3->SetFillColor(sf::Color::Transparent);
	render_t3->SetZLevel(-1);
}
*/
void GameBoard::CreateBackground()
{
	GameEngine::Entity* background = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(background);

	background->SetPos(sf::Vector2f(500.f, 350.f));
	background->SetSize(sf::Vector2f(1000.f, 700.f));

	GameEngine::SpriteRenderComponent* render_bg = static_cast<GameEngine::SpriteRenderComponent*>(background->AddComponent<GameEngine::SpriteRenderComponent>());

	render_bg->SetTexture(GameEngine::eTexture::Background);
	render_bg->SetFillColor(sf::Color::Transparent);
	render_bg->SetZLevel(-3);
}
void GameBoard::CreateRope()
{
	GameEngine::Entity* rope = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(rope);

	rope->SetPos(sf::Vector2f(425.0f, 500.0f));
	rope->SetSize(sf::Vector2f(700.0f, 700.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_rope = rope->AddComponent<GameEngine::SpriteRenderComponent>();

	render_rope->SetTexture(GameEngine::eTexture::Rope);  // <-- Assign the texture to this entity
	render_rope->SetFillColor(sf::Color::Transparent);
	render_rope->SetZLevel(-1);
}
void GameBoard::CreateBoat()
{
	GameEngine::Entity* boat = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(boat);

	boat->SetPos(sf::Vector2f(240.0f, 440.0f));
	boat->SetSize(sf::Vector2f(275.0f, 75.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_boat = boat->AddComponent<GameEngine::SpriteRenderComponent>();

	render_boat->SetTexture(GameEngine::eTexture::Boat);  // <-- Assign the texture to this entity
	render_boat->SetFillColor(sf::Color::Transparent);
	render_boat->SetZLevel(-1);
}

void GameBoard::CreateTop()
{
	GameEngine::Entity* top = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(top);

	top->SetPos(sf::Vector2f(425.0f, 90.0f));
	top->SetSize(sf::Vector2f(175.0f, 80.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_top = top->AddComponent<GameEngine::SpriteRenderComponent>();

	render_top->SetTexture(GameEngine::eTexture::Top);  // <-- Assign the texture to this entity
	render_top->SetFillColor(sf::Color::Transparent);
	render_top->SetZLevel(1);
}
void GameBoard::CreateLock()
{
	GameEngine::Entity* lock = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(lock);

	lock->SetPos(sf::Vector2f(430.0f, 130.0f));
	lock->SetSize(sf::Vector2f(50.0f, 50.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_lock = lock->AddComponent<GameEngine::SpriteRenderComponent>();

	render_lock->SetTexture(GameEngine::eTexture::Lock);  // <-- Assign the texture to this entity
	render_lock->SetFillColor(sf::Color::Transparent);
	render_lock->SetZLevel(2);
}
void GameBoard::CreateKey()
{
	GameEngine::Entity* key = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(key);

	key->SetPos(sf::Vector2f(920.0f, 480.0f));
	key->SetSize(sf::Vector2f(50.0f, 30.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_key = key->AddComponent<GameEngine::SpriteRenderComponent>();

	render_key->SetTexture(GameEngine::eTexture::Key);  // <-- Assign the texture to this entity
	render_key->SetFillColor(sf::Color::Transparent);
	render_key->SetZLevel(0);
}
void GameBoard::CreateBottom()
{
	GameEngine::Entity* bottom = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bottom);

	bottom->SetPos(sf::Vector2f(425.0f, 90.0f));
	bottom->SetSize(sf::Vector2f(175.0f, 75.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_bottom = bottom->AddComponent<GameEngine::SpriteRenderComponent>();

	render_bottom->SetTexture(GameEngine::eTexture::Bottom);  // <-- Assign the texture to this entity
	render_bottom->SetFillColor(sf::Color::Transparent);
	render_bottom->SetZLevel(-2);
}
void GameBoard::CreateAxe()
{
	GameEngine::Entity* axe = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(axe);

	axe->SetPos(sf::Vector2f(425.0f, 75.0f));
	axe->SetSize(sf::Vector2f(70.0f, 30.0f));

	//Render
	GameEngine::SpriteRenderComponent* render_axe = axe->AddComponent<GameEngine::SpriteRenderComponent>();

	render_axe->SetTexture(GameEngine::eTexture::Axe);  // <-- Assign the texture to this entity
	render_axe->SetFillColor(sf::Color::Transparent);
	render_axe->SetZLevel(-1);
}



void GameBoard::Update()
{

}
