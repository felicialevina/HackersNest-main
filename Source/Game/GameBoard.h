#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		
		bool IsGameOver() { return false; }
	private:
		void CreatePlayer();
		GameEngine::Entity* m_player;
		void CreatePersonA();
		GameEngine::Entity* person_a;
		void CreatePersonB();
		GameEngine::Entity* person_b;
		void CreatePersonC();
		GameEngine::Entity* person_c;
		void CreateTextA();
		GameEngine::Entity* text_a;
		void CreateTextB();
		GameEngine::Entity* text_b;
		void CreateTextC();
		GameEngine::Entity* text_c;
		void CreateBackground();
		GameEngine::Entity* background;
		void CreateRope();
		GameEngine::Entity* rope;
		void CreateBoat();
		GameEngine::Entity* boat;
		void CreateTop();
		GameEngine::Entity* top;
		void CreateLock();
		GameEngine::Entity* lock;
		void CreateKey();
		GameEngine::Entity* key;
		void CreateBottom();
		GameEngine::Entity* bottom;
		void CreateAxe();
		GameEngine::Entity* axe;
	};
}

