#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"


#include <iostream>
//#include <SFGUI/SFGUI.hpp>



namespace Sekander 
{


	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	MainMenuState::MainMenuState(GameDataRef data, const char* xml_DOC) : _data(data)
	{
		this->xml_DOC = xml_DOC;
	}


	void callbackFunc()
		{
    		std::cout << "Button pressed" << std::endl;
			
		}



	void MainMenuState::Init()
	{

		this->_data->window.setView(this->_data->window.getDefaultView());
		window_rec.setSize(this->_data->window.getDefaultView().getSize());
		window_rec.setFillColor(sf::Color(0, 0, 0, 0));
		window_rec2.setSize(this->_data->window.getDefaultView().getSize());
		window_rec2.setFillColor(sf::Color(0, 0, 0, 0));




	
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));


		

		std::cout << "BEFORE DELETION" << std::endl;
		this->_data->manager.ListAllEnties();

		this->_data->manager.DeleteEntity();

		std::cout << "AFTER DELETION" << std::endl;

		this->_data->manager.ListAllEnties();

		ld = new LoadingGameObjects(_data);

		ld->Load_XML_MENU_SCREEN(xml_DOC);
		if (buffer.loadFromFile("Resources/audio/main_menu.wav"))
		{
			sound.setBuffer(buffer);
			sound.play();
			sound.setLoop(true);
		}


		credits_button = false;
		
	}

	void MainMenuState::HandleInput()
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

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
			{
				// Switch To Main Menu
		
							//this->_data->manager.DeleteEntity();
							//this->_data->manager.Update(_data->window);
							//this->_data->manager.DeleteEntity();
							//this->_data->manager.~EntityManager();

				//delete ld;
				//this->_data->manager.DeleteEntity();
				fade_out = true;
				//sound->pause();
				this->_data->machine.AddState(StateRef(new GameState(_data, this->xml_DOC)), true);
				//this->_data->machine.AddState(StateRef(new GameOverState(_data, 100, this->xml_DOC)), true);


				//this->_data->machine.AddState(StateRef(new GameState(_data, this->xml_DOC, this->ld)), true);

			}





//			button->GetSignal( sfg::Widget::OnLeftClick ).Connect( &callbackFunc) ;
		
		
		}
	}

	void MainMenuState::Update(float dt)
	{
		////gui.updateTime(dt);
		
		//Update Box2d objects

		sf::View main_view = _data->window.getDefaultView();
		if(!_max)
		a = a - 5;
		if(a <= 0)
		{
			a = 0;
			_max = true;
		}
		window_rec.setFillColor(sf::Color(0, 0, 0, a));

		if(fade_out){
				if (this->_clock.getElapsedTime().asSeconds() > 4.5)
				{

					a_b = a_b + 5;
					if(a_b >= 255)
					{
						a_b = 255;
						_max = true;
					}
					window_rec.setFillColor(sf::Color(0, 0, 0, a_b));

				}
		}
		

		/*S
		std::cout << 
		"Mouse pos " <<
		"\n x : " << sf::Mouse::getPosition().x <<
		"\n y : " << sf::Mouse::getPosition().y <<
		std::endl;
		*/




		bool min, max;

		r++;
		if(r >= 255)
		r = 0;


		b--;
		if(b <= 0)
		b = 255;
		

		g++;
		if(g >= 255)
		g = 0;


		



		this->_data->manager.Update(_data->window);
		auto gameList = ld->Get_Game_objects_Map();
		for (auto &some : gameList)
		{
			//std:: cout
			//<< "GAMELIST : " 
			//<< some.second <<
			//std::endl;
			some.second->Animate(0.5);
			
			

		}

	


		


		auto spriteList = ld->Get_Sprie_Map();

		auto s = ld->sdGet_Sprie_Map();

		for(auto& o : s)
		{




			if(!o.first.find("exi"))
			{

				if (this->_data->input.IsSpriteClicked(*o.second, 
												   sf::Mouse::Left, 
												   this->_data->window) )
				{

					std::cout << "PROGRAM CLOSING" << std::endl;

					this->_data->window.close();

				}

			}

			if (!o.first.find("back"))
			{

				auto so = o.second->getTextureRect();


				if (this->_data->input.IsSpriteClicked(*o.second,
					sf::Mouse::Left,
					this->_data->window))
				{
					credits_button = false;
					//main_view.move(1000, 0);
					/*sf::View main_view = _data->window.getDefaultView();
					this->_data->window.setView(main_view);*/

				}


			}


			if (!o.first.find("credits"))
			{

				auto so = o.second->getTextureRect();


				if (this->_data->input.IsSpriteClicked(*o.second,
					sf::Mouse::Left,
					this->_data->window))
				{
					credits_button = true;
					//main_view.move(1000, 0);
					/*sf::View main_view = _data->window.getDefaultView();
					this->_data->window.setView(main_view);*/

				}


			}







		}
















	
//		button->Update(dt);
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

//		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_title);


		auto s = ld->sdGet_Sprie_Map();

		for(auto& o : s)
		{
			if (o.first.find("credit_screen") &&
				o.first.find("back"))
				this->_data->window.draw(*o.second);



				if (credits_button)
				{
					std::cout << "MainMenu???????????????" << std::endl;


					if (!o.first.find("credit_screen") )
						this->_data->window.draw(*o.second);

					if (!o.first.find("back"))
						this->_data->window.draw(*o.second);

					

				}

		}

		if (!credits_button )
			this->_data->window.draw(this->_playButton);
		//this->_data->window.draw(this->selection_rec);



		//Draw Box2d objects 
		this->_data->manager.Render(_data->window);

//		gui.Display(_data->window);

		this->_data->window.draw(window_rec);
		this->_data->window.draw(window_rec2);



		this->_data->window.display();
	}
}
