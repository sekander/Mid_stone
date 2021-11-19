#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

//#include <SFGUI/SFGUI.hpp>
//#include <SFGUI/Widgets.hpp>

#include "LoadingGameObjects.hpp"




namespace Sekander 
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);
		MainMenuState(GameDataRef data, const char* xml_DOC);
		//MainMenuState(GameDataRef data, const char* xml_DOC, sf::Sound* sound);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Clock _clock;

		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		sf::Sprite _creditsButton;
		//sf::Sprite _credit;
		//sf::Sprite _backButton;
		//sf::Sprite _exitButton;

//		sfg::SFGUI	gui;

		const char* xml_DOC;

		LoadingGameObjects *ld;
		sf::SoundBuffer buffer;
		sf::Sound sound;




		sf::RectangleShape selection_rec;
		int r = 100;
		int b = 255;
		int g = 0;


		bool play_button;
		bool seting_button;
		bool exit_button;
		bool credits_button;
		//bool credit;
		//bool back;
		//bool exit;
		//


		double two_PI;
        double  amplitude = 200;
        int frequency = 1;
        int k = 0;

        double y;
        double x;
        double h = 1;


        int n_point = 1000;


		//###########RGB#############################




sf::RectangleShape window_rec;
sf::RectangleShape window_rec2;
int a = 255;
int a_b = 0;
bool _max;

bool fade_out;
bool credits_On = false;
bool credits_Off = true;

	};
}


