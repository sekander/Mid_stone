#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

#include "LoadingGameObjects.hpp"



namespace Sekander 
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data, int score);
		GameOverState(GameDataRef data, int score, const char* xml_DOC);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Clock _clock;

		sf::Sprite _background;
		
		sf::Sprite _gameOverTitle;
		sf::Sprite _gameOverContainer;
		sf::Sprite _retryButton;


		sf::Text _scoreText;
		sf::Text _highScoreText;

		int _score;
		int _highScore;
		const char* _xml_DOC;

		LoadingGameObjects *ld;

		sf::RectangleShape window_rec;
		sf::RectangleShape window_rec2;

		int r = 100;
		int b = 100;
		int g = 0;
		int a = 255;
		int a_b = 0;

		bool _max;

		bool fade_out;



	};
}
