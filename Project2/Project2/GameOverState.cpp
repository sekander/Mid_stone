#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameOverState.hpp"
#include "GameState.hpp"
#include "MainMenuState.hpp"

#include <iostream>
#include <fstream>

namespace Sekander 
{
	GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
	{

	}

	GameOverState::GameOverState(GameDataRef data, int score, const char* xml_DOC) : _data(data), _score(score)
	{
		this->_xml_DOC = xml_DOC;
	}


	void GameOverState::Init()
	{

		this->_data->window.setView(this->_data->window.getDefaultView());
		window_rec.setSize(this->_data->window.getDefaultView().getSize());
		window_rec.setFillColor(sf::Color(100, 23, 90, 100));
		window_rec2.setSize(this->_data->window.getDefaultView().getSize());
		window_rec2.setFillColor(sf::Color(0, 0, 0, 0));


		std::ifstream _readFile;
		_readFile.open("Resouces/score.txt");

		if (_readFile.is_open())
		{
			while (!_readFile.eof())
			{
				_readFile >> _score;
			}
		}

	
		std::ofstream _writeFile("Resouces/score.txt");

		if (_writeFile.is_open())
		{
		

			_writeFile << _score;
		}
		_writeFile.close();





		std::ifstream readFile;
		readFile.open(HIGH_SCORE_FILEPATH);

		if(readFile.is_open())
		{
			while (!readFile.eof())
			{
				readFile >> _highScore;
			}
		}

	readFile.close();
	std::ofstream writeFile(HIGH_SCORE_FILEPATH);

	if(writeFile.is_open())
	{
		if (_score > _highScore)
		{
			_highScore = _score;
		}

		writeFile << _highScore;
	}
	writeFile.close();




		



		this->_data->assets.LoadTexture("Retry Button", "Resources/res/play_bt.png");
		_retry_button.setTexture(this->_data->assets.GetTexture("Retry Button"));
		_retry_button.setPosition((_data->window.getSize().x / 2) - (_retry_button.getGlobalBounds().width /2),
								   (_data->window.getSize().y / 2) - (_retry_button.getGlobalBounds().height / 2) + 150 ); 

		this->_data->assets.LoadTexture("Menu Button", "Resources/res/Setting_Button.png");
		_main_menu_button.setTexture(this->_data->assets.GetTexture("Menu Button"));
		_main_menu_button.setPosition((_data->window.getSize().x / 2) - (_main_menu_button.getGlobalBounds().width / 2),
									  (_data->window.getSize().y / 2) - (_main_menu_button.getGlobalBounds().height / 2) + 250);

		_scoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_scoreText.setString(std::to_string(_score));
		_scoreText.setCharacterSize(56);
		_scoreText.setFillColor(sf::Color::White);
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width/2 , 
												 _scoreText.getGlobalBounds().height /2);
		_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25,
				_data->window.getSize().y / 2.15);
		
		_highScoreText.setFont(_data->assets.GetFont("Flappy Font"));
		_highScoreText.setString(std::to_string(_highScore));
		_highScoreText.setCharacterSize(56);
		_highScoreText.setFillColor(sf::Color::White);
		_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width/2 , 
												 _highScoreText.getGlobalBounds().height /2);
		_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25,
				_data->window.getSize().y / 1.78);





		std::cout << "BEFORE DELETION" << std::endl;
		this->_data->manager.ListAllEnties();
		
		this->_data->manager.DeleteEntity();
		
		std::cout << "AFTER DELETION" << std::endl;
		
		this->_data->manager.ListAllEnties();
		ld = new LoadingGameObjects(_data);

		ld->Load_XML_GAME_OVER_SCREEN(this->_xml_DOC);

		fade_out = false;

	}

	void GameOverState::HandleInput()
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

			if(_data->input.IsSpriteClicked(_retry_button, sf::Mouse::Left,
						_data->window))
				{

					fade_out = true;
				//EDIT HERE
				
				//if(this->_clock.getElapsedTime().asSeconds() > 7.0f)
				//{
					_data->machine.AddState(StateRef(new GameState(_data, this->_xml_DOC)), true);

				//}
				

			}

				if(_data->input.IsSpriteClicked(_main_menu_button, sf::Mouse::Left,
						_data->window))
				{

					fade_out = true;
				//EDIT HERE
				
				//if(this->_clock.getElapsedTime().asSeconds() > 7.0f)
				//{
					//_data->machine.AddState(StateRef(new GameState(_data, this->_xml_DOC)), true);
					this->_data->machine.AddState(StateRef(new MainMenuState(_data, this->_xml_DOC)), true);


				//}
				

			}
		}
	}

	void GameOverState::Update(float dt)
	{
		//std::cout << "TEST CLEAM" << std::endl;
		if(!_max)
		a--;
		if(a <= 0)
		{
			a = 0;
			_max = true;
		}
		window_rec.setFillColor(sf::Color(0, 0, 0, a));

		if(fade_out)
		{

			if (this->_clock.getElapsedTime().asSeconds() > 4.5) {

				a_b = a_b + 5;
				if (a_b >= 255)
				{
					a_b = 255;
					_max = true;
				}
				window_rec2.setFillColor(sf::Color(0, 0, 0, a_b));

			}

		}


		auto s = ld->sdGet_Sprie_Map();
		for (auto& o : s)
		{


			if (!o.first.find("exi"))
			{

				if (this->_data->input.IsSpriteClicked(*o.second,
					sf::Mouse::Left,
					this->_data->window))
				{

					std::cout << "PROGRAM CLOSING" << std::endl;

					this->_data->window.close();

				}

			}
		}



	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Red);


		auto spriteList = ld->sdGet_Sprie_Map();
		for(auto& obj : spriteList)
		{
			this->_data->window.draw(*obj.second);
			std::cout << 
			
			"SPRITES : " <<
			obj.second
			
			<< std::endl;
		}


		_data->window.draw(_retry_button);
		_data->window.draw(_main_menu_button);
		_data->window.draw(_scoreText);
		_data->window.draw(_highScoreText);

		this->_data->window.draw(window_rec);
		this->_data->window.draw(window_rec2);



		this->_data->window.display();
	}
}
