#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,

			Player, // Replace this for your own enumerations
			Person1,
			Person2,
			Person3,
			Text1,
			//Text2,
			//Text3,
			Background,
			Rope,
			Boat,
			Top,
			Lock,
			Key,
			Bottom,
			Axe,
			Count,
		};
	}

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
			case eTexture::Player: return "Player.png"; 
			case eTexture::Person1: return "Person1.png";			
			case eTexture::Person2: return "Person2.png";
			case eTexture::Person3: return "Person3.png";
			case eTexture::Text1: return "Text1.png";
			//case eTexture::Text2: return "Text2.png";
			//case eTexture::Text3: return "Text3.png";
			case eTexture::Background: return "Background.png";
			case eTexture::Rope: return "Rope.png";
			case eTexture::Boat: return "Boat.png";
			case eTexture::Top: return "Top.png";
			case eTexture::Lock: return "Lock.png";
			case eTexture::Key: return "Key.png";
			case eTexture::Bottom: return "Bottom.png";
			case eTexture::Axe: return "Axe.png";
		}
		return "UnknownTexType";
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

