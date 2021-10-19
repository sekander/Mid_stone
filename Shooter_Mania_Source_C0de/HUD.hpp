#pragma once


#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Sekander
{
	class HUD
	{
	public:
		HUD(GameDataRef data);


		void setPositon();
		void Draw();
		void Update();

		void UpdateScore(int score);

		void Update_text(std::string);

	private:



		sf::Text m_text;





		GameDataRef _data;
		sf::Text _scoreText;
		sf::Text text;

		sf::Text m_clock_text;


		int test = 1000;

		sf::Text mytext;

		//sf::Sprite *sprite;
		//sf::Text   *hud_text;
//std::stringstream ss; 


	};
}
