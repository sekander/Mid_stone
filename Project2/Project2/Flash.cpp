#include "Flash.hpp"

namespace Sekander
{
	Flash::Flash(GameDataRef data) : _data(data)
	{
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
		_shape.setFillColor(sf::Color(255, 255, 255, 0));

		_flashOn = true;
	}

	void Flash::Show(float dt)
	{
		if(_flashOn)
		{
			int alapha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);

			if(alapha >= 255.0f)
			{
				alapha = 255.0f;
				_flashOn = false;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alapha));

		}
		else
		{

			int alapha = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);

			if(alapha <= 255.0f)
			{
				alapha = 0.0f;
				_flashOn = false;
			}

			_shape.setFillColor(sf::Color(255, 255, 255, alapha));
		}
	}

	void Flash::Draw(){
		_data->window.draw(_shape);
	}



}
