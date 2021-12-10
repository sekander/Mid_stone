
#include <sstream>
#include "DEFINITIONS.hpp"
#include "GameState.hpp"
#include "GameOverState.hpp"
#include "Game.hpp"




#include <iostream>

namespace Sekander 
{



	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	GameState::GameState(GameDataRef data, const char* xml_DOC) : _data(data)
	{
		this->_xml_DOC = xml_DOC;
	}



	void GameState::Init()
	{


		//##################DELETE PREVIOUS GAMEOBJECTS################
		std::cout << "BEFORE DELETION" << std::endl;
		this->_data->manager.ListAllEnties();
		
		this->_data->manager.DeleteEntity();
		
		std::cout << "AFTER DELETION" << std::endl;
		
		this->_data->manager.ListAllEnties();


		window_rec.setSize(this->_data->window.getDefaultView().getSize());
		window_rec.setFillColor(sf::Color(100, 23, 90, 100));






		//_data->assets.LoadTexture("Player", PLAYER_FILEPATH);
		_data->assets.LoadFont("Flappy Font", FONT_FILEPATH);

		
		hud 	= new HUD(_data);




		ld = new LoadingGameObjects(_data);
		ld->Load_XML_PLAY_SCREEN(_xml_DOC);



		





		_score = 0; 
		_gameState = Game_States::e_Ready;
		


			
		//////////////////////////////////LOADING TILES>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


		//map.load("assets/untitled.tmx");

		//layer1 = new MapLayer(map, 0);
		//layer2 = new MapLayer(map, 1);
		//layer3 = new MapLayer(map, 2);

		
        //const auto& tilesets = map.getTilesets();
        //for(const auto& tileset : tilesets)
        //{
            //read out tile set properties, load textures etc...
			//tileset.

		//}


	//level_nu.LoadFromFile("assets/untitled.tmx");

	window_square.height = window_rec.getGlobalBounds().height;
	window_square.width = window_rec.getGlobalBounds().width;
	window_square.left = window_rec.getGlobalBounds().left;
	window_square.top = window_rec.getGlobalBounds().top;

	//level_nu.SetDrawingBounds(window_square);

//		
//		std::cout << map.getTileCount().x << std::endl;
//		std::cout << map.getTileCount().y << std::endl;
		std::cout << "#############STARTING GAME###############" << std::endl;
	//	std::cout << map.getOrientation() << std::endl;


		//std::cout <<
		this->_data->manager.ListAllEnties();
		//<< std::endl;



	isKeyReleased = false;
	//counter = 0;
	input_counter = 0.0f;
	_is_paused = false;
	_un_pause = false;




    minimapView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));


	//m_pause_string = "";
	//#################PAUSE TEXT#########################
	m_pause_text.setFont(_data->assets.GetFont("Flappy Font"));
	m_pause_text.setString("");
	m_pause_text.setCharacterSize(120);
	m_pause_text.setFillColor(sf::Color::Red);
	m_pause_text.setOrigin(this->_data->manager.Get("red")->getPosition().x - 600, 
			           this->_data->manager.Get("red")->getPosition().y + 50);

	//m_pause_text.setOrigin(_data->window.getView().getSize().x / 2, 
	//						   _data->window.getView().getSize().y /5);

	m_p_text.setOrigin(this->_data->manager.Get("red")->getPosition().x - 100, 
			           this->_data->manager.Get("red")->getPosition().y + 50);
	m_a_text.setOrigin(this->_data->manager.Get("red")->getPosition().x - 200, 
			           this->_data->manager.Get("red")->getPosition().y + 50);
	m_u_text.setOrigin(this->_data->manager.Get("red")->getPosition().x - 300, 
			           this->_data->manager.Get("red")->getPosition().y + 50);
	m_s_text.setOrigin(this->_data->manager.Get("red")->getPosition().x - 400, 
			           this->_data->manager.Get("red")->getPosition().y + 50);
	m_e_text.setOrigin(this->_data->manager.Get("red")->getPosition().x - 500, 
			           this->_data->manager.Get("red")->getPosition().y + 50);


	//pause_window_rec.setOrigin(
	//		this->_data->window.getView().getCenter(), 
	//		           this->_data->manager.Get("red")->getPosition().y + 50
	//);


	m_p_text.setFont(_data->assets.GetFont("Flappy Font"));
	m_a_text.setFont(_data->assets.GetFont("Flappy Font"));
	m_u_text.setFont(_data->assets.GetFont("Flappy Font"));
	m_s_text.setFont(_data->assets.GetFont("Flappy Font"));
	m_e_text.setFont(_data->assets.GetFont("Flappy Font"));

	m_p_text.setString("");
	m_a_text.setString("");
	m_u_text.setString("");
	m_s_text.setString("");
	m_e_text.setString("");


	m_p_text.setCharacterSize(100);
	m_a_text.setCharacterSize(100);
	m_u_text.setCharacterSize(100);
	m_s_text.setCharacterSize(100);
	m_e_text.setCharacterSize(100);

	pause_window_rec.setFillColor(sf::Color(0, 0, 0, 0));



	//this->_data->manager.newEdge(0, -480, 500, -480);
	//this->_data->manager.newEdge(500, -480, 500, -400);




 	}

	void GameState::HandleInput()
	{



		_data->window.setKeyRepeatEnabled(false);

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
			else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)      
			{
					i++;
					std::cout << "PPPPP : " << i << std::endl;

					_is_paused = true;
					if(i > 1)
					{
						std::cout << "QQQQQ : " << i << std::endl;
						_is_paused = false;
						i = 0;
						m_pause_text.setString("");
						m_p_text.setString("");
						m_a_text.setString("");
						m_u_text.setString("");
						m_s_text.setString("");
						m_e_text.setString("");

						pause_window_rec.setFillColor(sf::Color(0, 0, 0, 0));

					} 
					
			}

		}



	



	}

	void GameState::Update(float dt)
	{
		//std::cout << "DEBUG0#####" << std::endl;

		auto animation_Speed = dt / 100;
		hud ->Update();
		//flash->Update();


		//m_pause_text.setFillColor(sf::Color(a, b, g, 0));
				
		r++;
		if(r >= 255)
		r = 0;


		b--;
		if(b <= 0)
		b = 255;
		

		g++;
		if(g >= 255)
		g = 0;

		m_p_text.setFillColor(sf::Color(r, g, b));
		m_a_text.setFillColor(sf::Color(g, r, b));
		m_u_text.setFillColor(sf::Color(b, r, g));
		m_s_text.setFillColor(sf::Color(r, b, g));
		m_e_text.setFillColor(sf::Color(g, b, r));


		m_p_text.setPosition(this->_data->window.getView().getCenter().x - 110, this->_data->window.getView().getCenter().y);
		m_a_text.setPosition(this->_data->window.getView().getCenter().x - 108, this->_data->window.getView().getCenter().y);
		m_u_text.setPosition(this->_data->window.getView().getCenter().x - 106, this->_data->window.getView().getCenter().y);
		m_s_text.setPosition(this->_data->window.getView().getCenter().x - 104, this->_data->window.getView().getCenter().y);
		m_e_text.setPosition(this->_data->window.getView().getCenter().x - 102, this->_data->window.getView().getCenter().y);
		m_pause_text.setPosition(this->_data->window.getView().getCenter().x - 100, this->_data->window.getView().getCenter().y);


		pause_window_rec.setSize(this->_data->window.getView().getSize());





		















		if (Game_States::e_GameOver != _gameState)
		{






			if (!_is_paused)
			{
				//std::cout << "DEBUG0####" << std::endl;
				//std::cout << "DEBUG0####" << std::endl;
				//this->_data->manager.ListAllEnties();


				hud->Update_text(std::to_string(_clock.getElapsedTime().asSeconds()));

				this->_data->manager.Update(_data->window);


				/////////////////////??HANDLE GAMEWORLD INPUTS HERE-------------------------------------------------------
				//##############################################################
				//PLAYER INPUTS AND UPDATES	
				auto player_List = ld->Get_Player_Map();
				for (auto& player : player_List)
				{
					//std:: cout
					//<< "PLAYERLIST : " 
					////<< some.second->Animate(dt) <<
					//<< std::endl;
					player.second->Update(dt);
					//some.second->Animate(0.50);

					auto gun_List = ld->Get_Gun_Map();
					for (auto& gun : gun_List)
					{

						auto bullet_list = ld->Get_Bullet_Map();

						//auto s = gun_List.find("gun")->second;

						//std::cout << s << std::endl;

						if (gun.second->Get_key() == "p_gun")
						{
							//std::cout << "I exsit" << std::endl;
							player.second->Shooting(*gun.second, bullet_list);
						}


						//player.second->Shooting(*gun_List.find("gun")->second, bullet_list);


					}





					int counter = 0;
					bool did_jump_again = true;

					//////////////////////PLAYER############################33
				//	player.second->Player_Intialize();
					player.second->MoverRigtht(20);
					player.second->Dash();

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						//if(player.second->Player_get_velocity_Y() == 0)
						//{
						player.second->DoubleJump(did_jump_again);
						counter++;
						if (counter > 2)
						{
							counter = 0;
							did_jump_again = false;
						}
						//}
					}
					//some.second->Shooting(*b				
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))

						player.second->Jump(player.second->m_OnFloor);

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
					{
						counter++;
						input_counter += 0.001f;
						//ld->ListAllGameObjects				
					}




				}


				//#############################################################
				//#############################################################
				//#############################################################
				//ENEMY UPDATES 
				//auto enemy_List = ld->Get_Enemy_Map();
				//for (auto &enemy : enemy_List)
				//{
				//
				//	auto gun_List = ld->Get_Gun_Map();
				//	for(auto &gun : gun_List)
				//	{
				//	
				//		auto bullet_list = ld->Get_Bullet_Map();
//
									//			enemy.second->Shooting(*gun.second, bullet_list);
//
//
									//	}
//
//
//
//
									//}
//








									//mpw->Animate(animation_Speed);
									//std::cout << "DEBUG0###" << std::endl;



									//std::cout << "DEBUG0##" << std::endl;


									//################PLAYER OBJECTS##########################
									//######################################################
				auto playerList = ld->Get_Player_Map();
				for (auto& some : playerList)
				{
					//std:: cout
					//<< "PLAYERLIST : " 
					////<< some.second->Animate(dt) <<
					//<< std::endl;
					//some.second->Update(dt);
					//some.second->Update_HUD();

					some.second->Animate(0.50);

					//std::cout << 
					//"POS : " <<
					//some.second->GetPosition().x << 
					//" , " <<		
					//some.second->GetPosition().y << 
					//std::endl;





					auto enemy_bullet_list = ld->Get_Enemy_Bullet_Map();
					for (auto& e_bullet : enemy_bullet_list)
					{
						if (some.second->CheckCollision(e_bullet.first))
						{
							std::cout << "OUCH!!!!" << std::endl;

							this->_data->manager.Get(e_bullet.first)->body->SetTransform(b2Vec2(-2000, -900), 0);
							this->_data->manager.Get(e_bullet.first)->body->SetEnabled(false);



							//enemy_object.second->Damage();
							some.second->Player_t00k_damange();
							_score = _score - 10;

							hud->UpdateScore(_score);


							if (some.second->GetHealth() <= 0)
							{
								//enemy.second->Destroy();
								std::cout << "Die" << std::endl;

								//this->_data->manager.Get((enemy_object.second)->Get_Name())->body
								//->SetEnabled(false);
//
														//this->_data->manager.Get((enemy_object.second)->Get_Name())->
														//setTextureRect(sf::IntRect(0,0,0,0));

														//this->_data->manager.Get((enemy_object.second)->Get_Name())->DeleteShape();





							}





























						}
					}




					//#######################################################################
					//#######################################################################
					//#######################################################################
					//GAMEOVER
					if (some.second->GetPosition().y < -2000 || 
						some.second->GetHealth() < 5 || 
						sf::Keyboard::isKeyPressed(sf::Keyboard::G))
					{
						//this->_data->manager.DeleteEntity();
						//this->_data->manager.~EntityManager();
						_gameState = Game_States::e_GameOver;

					}

					//float velx, vely;



					some.second->Camera(main_view);


					//################BULLET OBJECTS##########################
					//######################################################


					auto bulletList = ld->Get_Bullet_Map();
					for (auto& playerBullets : bulletList)
					{
						//std:: cout
						//<< "PLAYERLIST : " 
						////<< some.second->Animate(dt) <<
						//<< std::endl;
						//some.second->Update(dt);
						//some.second->Animate(0.50);

						playerBullets.second->IsBulletAlive(this->_data->window.getView());
					}


					//window_rec.setSize(this->_data->window.getView().getSize());


					//e->setColor(sf::Color(255, 255, 255, 255));



				}

				//################GAME OBJECTS##########################
				//######################################################
				auto gameList = ld->Get_Game_objects_Map();
				for (auto& some : gameList)
				{
					//std:: cout
					//<< "GAMELIST : " 
					//<< some.second <<
					//std::endl;
					some.second->Animate(0.5);
				}

				//################ENEMY OBJECTS##########################
				//######################################################

				auto enemy_list = ld->Get_Enemy_Map();


				//#################CHECK COLLISION#####################
				for (auto& enemy_object : enemy_list)
				{
					//std:: cout
					//<< "GAMELIST : " 
					//<< some.second <<
					//std::endl;
					enemy_object.second->Update(dt);

					//for(auto &bull : bullet_list)
					//{
					//	enemy_object.second->Shoot_Gun(bull.second, true, false, false,false, 100, 0);
					//}



					auto gun_List = ld->Get_Gun_Map();
					for (auto& gun : gun_List)
					{


						if (!enemy_object.second->Get_enemy_alive_status())
						{
							//std::cout << "FINALY :::::::::: ALIVE" << std::endl;

							auto bullet_list = ld->Get_Enemy_Bullet_Map();
							for (auto& enemyBullets : bullet_list)
							{
								//std:: cout
								//<< "PLAYERLIST : " 
								////<< some.second->Animate(dt) <<
								//<< std::endl;
								//some.second->Update(dt);
								//some.second->Animate(0.50);

								enemyBullets.second->IsBulletAlive(this->_data->window.getView());
							}




							//if(gun.second->Get_key() == "e_gun")
							//{

							if (!gun.second->Get_key().find("e_gun"))
							{
								//std::cout << "ENEMY GUNS : " << gun.second->Get_key() << std::endl;
								//std::cout << "ENEMY  : " << enemy_object.second->Get_Name() << std::endl;

								//enemy_object.second->Hold_Gun(*gun.second);

								//std::cout << "I exsit" << std::endl;


									//if(!enemy_object.second->Get_Name().find("enemygtori1"))
									//{
									//	enemy_object.second->Hold_Gun(*gun.second);
									//}









								if (!enemy_object.second->Get_Name().find("enemygtori"))
								{
									auto s = gun_List.find("e_gun");




									///std::cout << "Gun : " << s->second->Get_key() << std::endl;

									enemy_object.second->Hold_Gun(*gun.second);

								}

								if (!enemy_object.second->Get_Name().find("enemygtori1"))
								{
									//enemy_object.second->Hold_Gun(gun_List.at(gun.second));

								}




								//std::cout << "Gun: " << gun.second->Get_key() <<
								//" Gun POS: " << gun.second->Get_X_POS() << std::endl;


								if (enemy_object.second->get_attack_square().getGlobalBounds().contains
								(this->_data->manager.Get("red")->getPosition()))
								{
									std::cout << "I SEE YOU !!!!!!!!!!" << std::endl;
									//enemy_object.second->Shooting(*gun.second, bullet_list);
									enemy_object.second->Shooting(*gun.second, bullet_list);




								}

							}


							//}


						}
						else
						{
							std::cout << "FINALY :::::::::: DEAD" << std::endl;

							//gun_List.key_eq()


//												if(gun.second->Get_key() == "e_gun")
							if (!gun.second->Get_key().find("e_gun"))
							{

								std::cout << gun.second->Get_key() << std::endl;
								//std::cout << "I exsit" << std::endl;
								//enemy_object.second->Shooting(*gun.second, bullet_list);


								//DISABLE GUN AND MOVE OFF SCREEN
								this->_data->manager.Get(gun.second->Get_key())->body->SetTransform(b2Vec2(-1000, 0), 0);
								this->_data->manager.Get(gun.second->Get_key())->body->SetEnabled(false);


							}
							//delete enemy_object.second;

						}
					}



					if (enemy_object.second == nullptr)
					{
						std::cout << "CHECK" << std::endl;

					}
					else
					{





						auto bullet_list = ld->Get_Bullet_Map();
						for (auto& bullet : bullet_list)
						{

							if (enemy_object.second->CheckCollision(bullet.first))
							{
								//std::cout << "Bullets : " << bullet.first << std::endl;
								//std::cout << "Enemy : " << enemy_object.second << std::endl;
								//std::cout << "Score : " << _score << std::endl;

								//bullet.second->body->SetTransform(b2Vec2(-2000, -900) ,0);
								//bullet.second->body->SetEnabled(false);

								this->_data->manager.Get(bullet.first)->body->SetTransform(b2Vec2(-2000, -900), 0);
								this->_data->manager.Get(bullet.first)->body->SetEnabled(false);



								enemy_object.second->Damage();
								_score = _score + 10;

								hud->UpdateScore(_score);


								if (enemy_object.second->GetHealth() <= 0)
								{
									//enemy.second->Destroy();
									std::cout << "Die" << std::endl;

									this->_data->manager.Get((enemy_object.second)->Get_Name())->body
										->SetEnabled(false);

									this->_data->manager.Get((enemy_object.second)->Get_Name())->
										setTextureRect(sf::IntRect(0, 0, 0, 0));

									//this->_data->manager.Get((enemy_object.second)->Get_Name())->DeleteShape();










									//enemy_object.second->set_Alive(false);


									//delete enemy_object.second;

									//enemy_list.erase(enemy_object.second);
									//enemy_object.second->set_Alive(false);
									//if(!enemy_object.second->Get_enemy_alive_status())
									//{
									//	std::cout << "DEAD\nDEAD" << std::endl;
									//}
									//delete enemy_object.first;
									//delete enemy_object.second;
									//enemy_object.second->StopAnimation();
								}

							}

						}




					}

				}










			}	//################END OF PAUSE








			float startCount = 0.0f;




			if (_is_paused)
			{
				std::string p = "P";
				std::string a = "A";
				std::string u = "U";
				std::string s = "S";
				std::string e = "E";



				//m_pause_text.setString(p+a);
				m_p_text.setString(p);
				m_a_text.setString(a);
				m_u_text.setString(u);
				m_s_text.setString(s);
				m_e_text.setString(e);



				m_pause_text.setString("!!!");

				pause_window_rec.setFillColor(sf::Color(0, 0, 0, 200));
				pause_window_rec.setSize(sf::Vector2f(main_view.getSize().x + 1000,
					main_view.getSize().y + 1000));

				pause_window_rec.setOrigin(800, 500);
			}



		}

		if (Game_States::e_GameOver == _gameState)
		{

			if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				//this->_data->window.setView(main_view);
				//this->_data->manager.DeleteEntity();

				_data->machine.AddState(StateRef(new GameOverState(_data, _score, this->_xml_DOC)), true);
				_clock.restart();

			}

		}


	}//################END OF GAME LOOP########################

	void GameState::Draw(float dt)
	{


		this->_data->window.clear(sf::Color::Black);
		


			//level_nu.Draw(this->_data->window);


			//Box2D DRAW
			this->_data->manager.Render(_data->window);

				hud->Draw();

				auto enemy_text_list = ld->Get_Enemy_Map();
				for (auto& enemies : enemy_text_list)
				{

					enemies.second->Draw();
				}

				auto player_text_list = ld->Get_Player_Map();
				for (auto& player : player_text_list)
				{

					player.second->Draw();
				}

				






				this->_data->window.draw(pause_window_rec);
				this->_data->window.draw(m_pause_text);
				this->_data->window.draw(m_p_text);
				this->_data->window.draw(m_a_text);
				this->_data->window.draw(m_u_text);
				this->_data->window.draw(m_s_text);
				this->_data->window.draw(m_e_text);


		//this->_data->window.draw(window_rec);


		this->_data->window.display();
		
	}
}
