#pragma once

#include "GameWorld.hpp"

#include "Bullet.hpp"

//#include "LoadingGameObjects.hpp"
#include "Gun.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <unistd.h>

//#include "HUD.hpp"



namespace Sekander
{



	class Main_Player : public GameWorld
	{

	public:

		explicit Main_Player() {}


		explicit Main_Player(GameDataRef data,
			std::string key,
			std::string file_name,
			int source_x,
			int source_y,
			int sprite_WIDTH,
			int sprite_HEIGHT,
			bool dynamic,
			int sprite_X_FRAMES,
			int sprite_Y_FRAMES,
			float sprite_X_POS,
			float sprite_Y_POS,
			float sprite_ANGLE)
			: GameWorld(data,
				key,
				file_name,
				source_x,
				source_y,
				sprite_WIDTH,
				sprite_HEIGHT,
				dynamic,
				sprite_X_FRAMES,
				sprite_Y_FRAMES,
				sprite_X_POS,
				sprite_Y_POS,
				sprite_ANGLE)
		{

			//std::cout << "MAIN PLAYER GOT CREATED :: " << key << std::endl;

			this->m_key = key;
			this->_data = data;
			this->m_source_x = source_x;
			this->m_source_y = source_y;
			this->m_sprite_WIDTH = sprite_WIDTH;
			this->m_sprite_HEIGHT = sprite_HEIGHT;
			this->m_sprite_X_FRAME = sprite_X_FRAMES;
			this->m_sprite_Y_FRAME = sprite_Y_FRAMES;

			world = this->_data->manager.Get(this->m_key)->body->GetWorld();

			//hud = new HUD(this->_data, "Flappy Font", 
			//						   "Score : ", 
			//						   sf::Color::Red,
			//						   50,
			//						   0,
			//						   0);
			this->m_health = 100;

			this->m_health_text.setFont(_data->assets.GetFont("Flappy Font"));
			this->m_health_text.setString(std::to_string(this->m_health));
			this->m_health_text.setCharacterSize(50);
			this->m_health_text.setFillColor(sf::Color::Blue);

		}



		void Jump(bool);
		void DoubleJump(bool);
		void MoverUp();
		void MoverDown();
		void MoverRigtht(float speed);
		void Dash();
		void Shooting(Gun&, std::unordered_map<std::string, Bullet*>);
		void NU_Shooting(Gun&);

		void MoverLeft();

		void Camera(sf::View);

		//void Shooting(Bullet&);
		void Shooting(Gun&);
		void PickUpGun(Gun&);

		void Update(float dt)
		{
			this->m_health_text.setOrigin(-this->_data->manager.Get(this->m_key)->body->GetPosition().x,
				this->_data->manager.Get(this->m_key)->body->GetPosition().y + 40);

			//if(this->m_took_damage)
			//{
			//	this->m_health = this->m_health - 5;
			this->m_health_text.setString(std::to_string(this->m_health));

			//gun_clock.getElapsedTime().asMilliseconds();
			//capture_time += _clock.getElapsedTime().asSeconds();
		}

		void Draw()
		{
			_data->window.draw(m_health_text);
		}


		void Player_t00k_damange()
		{
			m_health = m_health - 5;
			//float elapsed_time = _clock.getElapsedTime().asSeconds();

			std::cout << "Capture Time Befoe : " << _clock.getElapsedTime().asSeconds() <<
				std::endl;

			bool took_damage = true;

			sf::Time damage_duration = sf::seconds(2.5f);
			sf::Time elapsed_time = _clock.getElapsedTime();
			//_clock.restart();
			//while(took_damage)

			bool last_level = false;

			//	if(elapsed_time < damage_duration)
				//while(!last_level)


			for (int i = 3; i > 0; i--)
			{

				this->_data->manager.Get(this->m_key)->body
					->SetEnabled(false);


				this->_data->manager.Get(this->m_key)->
					setColor(sf::Color(255, 255, 255, 255));
				std::cout << " Level 1" << std::endl;
				//			sleep(500);

				this->_data->manager.Get(this->m_key)->
					setColor(sf::Color(255, 255, 255, 150));
				std::cout << " Level 2" << std::endl;
				//			sleep(500);

				this->_data->manager.Get(this->m_key)->
					setTextureRect(sf::IntRect(0, 0, 0, 0));
				std::cout << " Level 3" << std::endl;
				//			sleep(500);

				this->_data->manager.Get(this->m_key)->
					setColor(sf::Color(255, 255, 255, 150));
				std::cout << " Level 4" << std::endl;
				//			sleep(500);

				this->_data->manager.Get(this->m_key)->
					setColor(sf::Color(255, 255, 255, 255));
				std::cout << " Level 5" << std::endl;
				//			sleep(500);




							//std::cout << i << std::endl;
							//this->_data->manager.Get(this->m_key)->
							//setColor(sf::Color(255, 255, 255, i));


			}

			//this->_data->manager.Get(this->m_key)->
			//		setColor(sf::Color(255, 255, 255, 255));


			this->_data->manager.Get(this->m_key)->body->
				SetLinearVelocity(b2Vec2(50, 0));


			_clock.restart();
			this->_data->manager.Get(this->m_key)->body
				->SetEnabled(true);

			//
								//for(int i = 0; i < 10; i++)
								//{
			//
								//	if(_clock.getElapsedTime().asSeconds() > 1.0f) 
								//	{
			//
			//
			//
								//	this->_data->manager.Get(this->m_key)->setColor(sf::Color(255, 255, 255, 0));
								//	//this->_data->manager.Get(this->m_key)->setColor(sf::Color(255, 255, 255, 255));
								//	//this->_data->manager.Get(this->m_key)->setColor(sf::Color(255, 255, 255, 0));
								//	//this->_data->manager.Get(this->m_key)->setColor(sf::Color(255, 255, 255, 255));
								//	//this->_data->manager.Get(this->m_key)->setColor(sf::Color(255, 255, 255, 0));
								//	this->_data->manager.Get(this->m_key)->setTextureRect(sf::IntRect(0,0,0,0));
			//
								//	
								//	//this->_data->manager.Get(this->m_key)->body->;
			//
								//	//this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(b2Vec2(50, 0));
			//
								//	if(_clock.getElapsedTime().asSeconds() > 3.0f)
								//		this->_data->manager.Get(this->m_key)->setColor(sf::Color(255, 255, 255, 255));
								//		//capture_time = 0;
			//
								//		//_clock.restart();
			//
								//		took_damage = false;
								//	}
								//	
								//}



			std::cout << "Capture Time Befoe : " << _clock.getElapsedTime().asSeconds() <<
				std::endl;


			//capture_time = 0;



			//this->_data->manager.Get(this->m_key)->body->SetTransform(b2Vec2(
			//					this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10, 
			//					this->_data->manager.Get(this->m_key)->body->GetPosition().y), 0);

		}


		float Player_get_velocity_Y()
		{
			return this->_data->manager.Get(this->m_key)->body->GetLinearVelocity().y;

		}

		b2Vec2 GetPosition() {
			//return b2Vec2(this->m_sprite_X_POS, this->m_sprite_Y_POS);



			return this->_data->manager.Get(this->m_key)->body->GetPosition();

		}

		bool CheckCollision(std::string bw)
		{
			//return this->getGlobalBounds().intersects(entity->getGlobalBounds());

			auto sprite_box = this->_data->manager.Get(bw)->getGlobalBounds();

			sf::FloatRect s;

			//std::cout << "Player Box :" <<
			s.top = sprite_box.top + 5;       //<< "\n" <<
			s.left = sprite_box.left + 5;     //<< "\n" <<
			s.height = sprite_box.height + 5; //<< "\n" <<
			s.width = sprite_box.width + 5;   //<< "\n" <<

			//std::endl;

			//return this->_data->manager.Get(this->m_key)->getGlobalBounds().intersects
			//(this->_data->manager.Get(bw)->getGlobalBounds() );

			return this->_data->manager.Get(this->m_key)->getGlobalBounds().intersects
			(s);

		}


		int GetHealth() { return this->m_health; }



		//void Shooting(Gun&, LoadingGameObjects*);

	private:
		//std::vector<GameWorld*> ammo;

		b2World* world;
		int count = 0;







		unsigned int _animationIterator = 0;
		int unsigned short counter = 0;

		sf::Clock _clock;
		sf::Time _time;
		sf::IntRect _playerRect;




		GameDataRef _data;
		std::string m_key;
		int m_source_x;
		int m_source_y;
		int m_sprite_WIDTH;
		int m_sprite_HEIGHT;
		int m_sprite_X_FRAME;
		int m_sprite_Y_FRAME;
		float m_sprite_X_POS;
		float m_sprite_Y_POS;
		float m_sprite_ANGLE;


		bool m_trigger_Press = false;
		bool m_am_I_backwards = false;


		bool press_twice = false;



		int m_health;
		sf::Text m_health_text;
		float capture_time;
		sf::Clock gun_clock;

		sf::Time time_g;


		//HUD *hud;



	};




}
