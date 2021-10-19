#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "Entity_manager.hpp"
//#include "XML_Manager.hpp"

namespace Sekander
{
	struct GameData
	{
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
		EntityManager manager;
//		XML_Manger xml;


	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game
	{
	public:
		Game(int width, int height, std::string title);
		Game(int width, int height, std::string title, bool);
		Game(int width, int height, std::string title, bool, const char* xml_DOC);

	    void ToggleFullscreen();
		 bool IsDone();    bool IsFullscreen();

	private:
		// Updates run at 60 per second.
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameData>();

		void Run();
		    bool m_isFullscreen;
	};
}
