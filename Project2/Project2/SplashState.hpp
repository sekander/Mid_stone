#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"


//#include "Flash.hpp"
#include "LoadingGameObjects.hpp"


#include <complex>
#include <cmath>



namespace Sekander 
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);
		SplashState(GameDataRef data, const char* xml_DOC) ;

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		const char* _xml_DOC;

		sf::Clock _clock;

		sf::Sprite _background;


		//Flash *fl;
		LoadingGameObjects *ld;
		sf::SoundBuffer buffer;
		sf::Sound sound;


		sf::RectangleShape window_rec;
		sf::RectangleShape window_rec2;
		int r = 100;
		int b = 100;
		int g = 0;
		int a = 255;
		int a_b = 0;



        double two_PI;
        double  amplitude = 200;
        int frequency = 1;
        int k = 0;

        double y;
        double x;
        double h = 1;


        int n_point = 1000;









		bool _max;

	};
}
