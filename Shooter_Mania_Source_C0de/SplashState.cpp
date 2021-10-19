#include <sstream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace Sekander 
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	SplashState::SplashState(GameDataRef data, const char* xml_DOC) : _data(data)
	{
		this->_xml_DOC = xml_DOC;
	}

	void SplashState::Init()
	{

		this->_data->window.setView(this->_data->window.getDefaultView());
		window_rec.setSize(this->_data->window.getDefaultView().getSize());
		window_rec.setFillColor(sf::Color(100, 23, 90, 100));
		window_rec2.setSize(this->_data->window.getDefaultView().getSize());
		window_rec2.setFillColor(sf::Color(0, 0, 0, 0));
		
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	
		ld = new LoadingGameObjects(_data);

		ld->Load_XML_SPLASH_SCREEN(_xml_DOC);


		if (buffer.loadFromFile("Resources/audio/splash_sound.wav"))
		{
			sound.setBuffer(buffer);
			sound.play();
			//x`x`sound->setLoop(true);

		}


	//		fl = new Flash(_data);
	
	}

	void SplashState::HandleInput()
	{

		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5)      
			{
				//this->_data->toggleFullScreen.ToggleFullscreen();
								        std::cout << "ENTERING FULLSCREEN" << std::endl;
					   

	
				_data->window.close();
				_data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "NUUUU", sf::Style::Fullscreen);
			}
			else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)      
			{
				//this->_data->toggleFullScreen.ToggleFullscreen();
								        std::cout << "ENTERING WINDOW MODE" << std::endl;
					    

	
				_data->window.close();
				_data->window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "NUUUU", sf::Style::Default);
			}
			else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)      
			{
								this->_data->window.close();

			}

		}
	}

	void SplashState::Update(float dt)
	{
		//this->_data->manager.Update(_data->window);
		//auto gameList = ld->Get_Game_objects_Map();
		//for (auto &some : gameList)
		//{
		//	//std:: cout
		//	//<< "GAMELIST : " 
		//	//<< some.second <<
		//	//std::endl;
		//	some.second->Animate(0.5);
		//}

		//r++;
		//if(r >= 255)
		//{
		//	r = 0;
		//}

        two_PI= atan(1) * 8.0;
		for(int i = 0; i < n_point; i++)
        {
                x = static_cast<double>(i) / n_point;
                y = amplitude * sin(((two_PI * frequency)/h) *x) + k;

        //      std::cout << "Value : "  << y  << std::endl;
             //   std::cout << "Absolute Value : "  << abs(static_cast<int>(y))  << std::endl;

		
		}




		if(!_max)
		a--;
		if(a <= 0)
		{
			//a = 255;
			_max = true;
		}
		window_rec.setFillColor(sf::Color(0, 0, 0, a));





		//if(_max)
		//{	
		//	a_b++;
		//	window_rec.setFillColor(sf::Color(0, 0, 0, a_b));
		//	
//
		//}

		if(this->_clock.getElapsedTime().asSeconds() > 4.5f)
		{
			std::cout << "GOT HERE" << std::endl;
			//if(!_max)
				a_b = a_b + 2;
				if(a_b >= 255)
				{
					a_b = 255;
					_max = true;
				}
			window_rec2.setFillColor(sf::Color(0, 0, 0, a_b));

		}
		




			//fl->Show(dt);

		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			

			
			// Switch To Main Menu
			//this->_data->manager.DeleteEntity();

			sound.pause();
			
			this->_data->machine.AddState(StateRef(new MainMenuState(_data, this->_xml_DOC)), true);
			//this->_data->machine.AddState(StateRef(new MainMenuState(_data, this->_xml_DOC, sound)), true);
		
		}
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		//fl->Draw();


		this->_data->window.draw( this->_background );

		auto spriteList = ld->Get_Sprie_Map();
		for(auto& obj : spriteList)
		{
			this->_data->window.draw(*obj.second);
			std::cout << 
			
			"SPRITES : " <<
			obj.second
			
			<< std::endl;
		}

		this->_data->window.draw(window_rec);
		this->_data->window.draw(window_rec2);

		//Draw Box2d objects 
		//this->_data->manager.Render(_data->window);


		this->_data->window.display();
	}
}
