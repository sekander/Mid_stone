#pragma once

#include "InputManager.hpp"

namespace Sekander 
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (playButtonRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}

		return false;
	}

	bool InputManager::IsKeyPressed(sf::Keyboard key)
	{
		this->_key = key;

		if(key.Right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window)
	{
		return sf::Mouse::getPosition(window);
	}
}
