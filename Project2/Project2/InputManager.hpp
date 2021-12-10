#pragma once

#include "SFML/Graphics.hpp"

namespace Sekander 
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		bool IsKeyPressed(sf::Keyboard key);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	
	private:
		sf::Keyboard _key;
	};
}
