#include <sstream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"

#include <iostream>
//#include <SFGUI/SFGUI.hpp>



namespace Sekander 
{

//			sfg::Button::Ptr button;

	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}

	MainMenuState::MainMenuState(GameDataRef data, const char* xml_DOC) : _data(data)
	{
		this->xml_DOC = xml_DOC;
	}

	//MainMenuState::MainMenuState(GameDataRef data, const char* xml_DOC, sf::Sound* sound) : _data(data)
	//{
	//	this->xml_DOC = xml_DOC;
	//	this->sound = sound;
	//}



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




		this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		//this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));
		//_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

		//_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));


		

//		button = sfg::Button::Create("Hello");

		ld = new LoadingGameObjects(_data);

		ld->Load_XML_MENU_SCREEN(xml_DOC);

		//ld = new LoadingGameObjects(_data, xml_DOC, 2);
		//ld = new LoadingGameObjects(_data, xml_DOC, "Main");

		if (buffer.loadFromFile("Resources/audio/main_menu.wav"))
		{
			sound.setBuffer(buffer);
			sound.play();
			sound.setLoop(true);
		}
		//else
		//{
		//	
		//}
		
		
		
		
		
		//button->GetSignal( sfg::Widget::OnLeftClick ).Connect( [&button] {
		//	// When the Button is clicked it's label should change.
		//	button->SetLabel( "I was clicked" );
		//} );


		selection_rec.setPosition(_playButton.getPosition().x -20,
								  _playButton.getPosition().y - 10);



		
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

				//this->_data->machine.AddState(StateRef(new GameState(_data, this->xml_DOC, this->ld)), true);

			}


			if(selection_rec.getPosition().x < _playButton.getPosition().x &&
			   selection_rec.getPosition().y < _playButton.getPosition().y &&
				event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
			{
				std::cout << "3#################GOT TRIGGEREEEEEEEEEEEEEEEE" << std::endl;
				//if(play_button)

				//fade_out = true;



				if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
				{	
					this->_data->machine.AddState(StateRef(new GameState(_data, this->xml_DOC)), true);
				}

			}

			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				std::cout << "3#################GOT TRIGGEREEEEEEEEEEEEEEEE" << std::endl;

				selection_rec.setPosition(selection_rec.getPosition().x,
										  selection_rec.getPosition().y - 100);
				play_button= false;
			}
			if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				std::cout << "3#################GOT TRIGGEREEEEEEEEEEEEEEEE" << std::endl;

				selection_rec.setPosition(selection_rec.getPosition().x,
										  selection_rec.getPosition().y +  100);
			}
//




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
		


		std::cout << 
		"Mouse pos " <<
		"\n x : " << sf::Mouse::getPosition().x <<
		"\n y : " << sf::Mouse::getPosition().y <<
		std::endl;



		//selection_rec.setTextureRect(_playButton.getTextureRect());
		
		//selection_rec.setOrigin(_playButton.getPosition().x ,
		//						_playButton.getPosition().y + 200);



		//selection_rec.setPosition(_playButton.getPosition().x -20,
		//						  _playButton.getPosition().y - 10);

		//selection_rec.setOrigin(_playButton.getPosition().x -20,
		//						  _playButton.getPosition().y - 10);

		//selection_rec.setPosition(sf::Mouse::getPosition().x,
		//						  sf::Mouse::getPosition().y);

		selection_rec.setSize(sf::Vector2f(_playButton.getTextureRect().width + 35,
								   		   _playButton.getTextureRect().height + 15));


		selection_rec.setFillColor(sf::Color(100,10,200,50));

		std::cout << 
		"SQUARE pos " <<
		"\n x : " << selection_rec.getPosition().x <<
		"\n y : " << selection_rec.getPosition().y <<
		"\n size x : " << selection_rec.getSize().x <<
		"\n size y : " << selection_rec.getSize().y <<

		"\nPLAY pos " <<
		"\n x : " << _playButton.getPosition().x <<
		"\n y : " << _playButton.getPosition().y <<
		std::endl;




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

		std::cout << "REd : " << r << "\nBlue : " << b << std::endl;


		two_PI= atan(1) * 8.0;
		//for(int i = 0; i < n_point; i++)
        //{
                x = static_cast<double>(dt) / n_point;
                y = amplitude * sin(((two_PI * frequency)/h) *x) + k;

        //      std::cout << "Value : "  << y  << std::endl;
                std::cout << "Absolute Value : "  << abs(static_cast<int>(y)) << dt << std::endl;

			//selection_rec.setFillColor(sf::Color(abs(static_cast<int>(y)), 0, 0));

			//selection_rec.setPosition(selection_rec.getPosition().x, abs(static_cast<int>(y)));
		
		//}




		selection_rec.setOutlineColor(sf::Color(r, g, b));
		selection_rec.setOutlineThickness(5);
		


		for(auto& entity : this->_data->manager.ReturnMap())
		{
			if(!entity.first.find("kirby"))
			{
				//std::cout << entity.first << std::endl;
				if(this->_data->manager.Get(entity.first)->getTextureRect().contains(sf::Mouse::getPosition())
				  && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					std::cout << "#############KIRBY#################" << std::endl;

					main_view.move(0, -SCREEN_HEIGHT);
					this->_data->window.setView(main_view);

				}





//
				//if (this->_data->input.IsSpriteClicked(this->_data->assets.GetTexture(""), 
				//								   sf::Mouse::Left, 
				//								   this->_data->window) )
				//{
//
				//	std::cout << "PROGRAM CLOSING" << std::endl;
//
				//}

			}
		}


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

			if(!o.first.find("settings"))
			{

				auto so = o.second->getTextureRect();


				if (this->_data->input.IsSpriteClicked(*o.second, 
								   sf::Mouse::Left, 
								   this->_data->window) )
				{
					
					main_view.move(0, SCREEN_HEIGHT);

					this->_data->window.setView(main_view);


				}


			}

			sf::IntRect temp_rec;
			if(!o.first.find("SETTINGS"))
			{

				temp_rec = o.second->getTextureRect();


				if (this->_data->input.IsSpriteClicked(*o.second, 
								   sf::Mouse::Left, 
								   this->_data->window) )
				{

					
					std::cout << "OH OH OH I've been clicked" << std::endl;
					

					//o.second->setTextureRect(sf::IntRect(0,0,0,0));


				}


			}





		}
















	
//		button->Update(dt);
	}

	void MainMenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		//this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->selection_rec);


		auto s = ld->sdGet_Sprie_Map();

		for(auto& o : s)
		{
			this->_data->window.draw(*o.second);
		}




		//Draw Box2d objects 
		this->_data->manager.Render(_data->window);

//		gui.Display(_data->window);

		this->_data->window.draw(window_rec);
		this->_data->window.draw(window_rec2);



		this->_data->window.display();
	}
}
