#pragma once

#include "GameWorld.hpp"
#include <iostream>
#include <stdlib.h>

#include "Gun.hpp"
#include "Bullet.hpp"



//#include "LoadingGameObjects.hpp"


namespace Sekander
{



	class Enemy : public GameWorld
	{

	public:

		explicit Enemy() {}


		explicit Enemy(GameDataRef data,
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
			float sprite_ANGLE,
			int enemy_walking_distance,
			float attack_square_x,
			float attack_square_y,
			float bullet_speed_x,
			float bullet_speed_y,
			float enemy_speed_x,
			float enemy_speed_y
			//float enemy_attack_square_x,
			//float enemy_attack_square_y
		) : GameWorld(data,
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
			std::cout << "BULLET OBJECT GOT CREATED :: " << key << std::endl;

			this->m_key = key;
			this->_data = data;

			this->m_sprite_X_POS = sprite_X_POS;
			this->m_sprite_Y_POS = sprite_Y_POS;

			this->m_is_Moving = false;
			this->m_health = 100;

			this->m_health_text.setFont(_data->assets.GetFont("Flappy Font"));
			this->m_health_text.setString(std::to_string(this->m_health));
			this->m_health_text.setCharacterSize(20);
			this->m_health_text.setFillColor(sf::Color::Red);

			//this->_data->manager.Get(this->m_key)->body->IsBullet();
			//this->_data->manager.Get(this->m_key)->body->SetGravityScale(0);
			this->m_took_damage = false;
			this->is_alive = true;
			this->m_dead = false;

			this->pixel_walking_distance = enemy_walking_distance;
			//this->e_attack_square_x = enemy_attack_square_x;
			//this->e_attack_square_y = enemy_attack_square_y;


			this->m_sprite_WIDTH = sprite_WIDTH;

			this->b_speed_x = bullet_speed_x;
			this->b_speed_y = bullet_speed_y;

			this->enemy_speed_x = enemy_speed_x;
			this->enemy_speed_y = enemy_speed_y;




			enemy_attack_square.setOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x,
				this->_data->manager.Get(this->m_key)->body->GetPosition().y);
			//enemy_attack_square.setSize(sf::Vector2f(this->e_attack_square_x, this->e_attack_square_y));
			//enemy_attack_square.setSize(sf::Vector2f(100, 200));
			enemy_attack_square.setSize(sf::Vector2f(attack_square_x, attack_square_y));
			enemy_attack_square.setFillColor(sf::Color(250, 0, 0, 100));

			this->e_attack_square_x = attack_square_x;

		}





		void SetOrigin(float x, float y)
		{
			this->_data->manager.Get(this->m_key)->body->SetTransform(b2Vec2(x, y), 0);

		}

		void SetSpeed(float speedX, float speedY)
		{



			this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(b2Vec2(speedX, speedY));
			this->m_is_Moving = true;
		}

		void Damage()
		{

			this->m_health = this->m_health - 5;
			//this->is_alive = false;
			//this->m_dead = true;

			//auto s = this->GetSprite();

			auto e = this->_data->manager.Get(this->m_key);

			e->setColor(sf::Color(255, 255, 255, 100));
			e->setColor(sf::Color::White);
			e->setColor(sf::Color(0, 0, 0, 255));
			//e->setColor(sf::Color::White);
			//e->setColor(sf::Color(255, 255, 255, 100));


			//e->setTextureRect(sf::IntRect(0, 0, 0, 0));
			//s.rotate(90);

			//e->
		}

		void Set_Health(int h) { this->m_health = h; }
		int GetHealth() { return this->m_health; }

		void Jump();

		float Get_X_POS() { return this->m_sprite_X_POS; }
		float Get_Y_POS() { return this->m_sprite_Y_POS; }

		void Set_X_POS(float x) { this->m_sprite_X_POS = x; }
		void Set_Y_POS(float y) { this->m_sprite_Y_POS = y; }


		void Hold_Gun(Gun& gw);

		void Shooting(Gun&, std::unordered_map<std::string, Bullet*>);
		void Shooting(std::unordered_map<std::string, Bullet*>);
		void Shoot_Gun(Bullet* bw, bool right, bool left, bool up, bool down, float x, float y);


		//				void Shooting(Gun&,    std::unordered_map<std::string, Bullet*> bullet_list);



		std::string Get_Name() { return this->m_key; }


		void Update(float dt)
		{

			if (!this->m_dead) {
				this->m_health_text.setOrigin(-this->_data->manager.Get(this->m_key)->body->GetPosition().x,
					this->_data->manager.Get(this->m_key)->body->GetPosition().y + 40);

				//if(this->m_took_damage)
				//{
				//	this->m_health = this->m_health - 5;
				this->m_health_text.setString(std::to_string(this->m_health));


				//}

				//Animate(0.5);


				b2Vec2 vel = this->_data->manager.Get(this->m_key)->body->GetLinearVelocity();
				//std::cout << "Starting speed : "  << vel.x << std::endl;



				auto enemy_pos = this->_data->manager.Get(this->m_key)->body->GetPosition().x;
				auto enemy_pos_y = this->_data->manager.Get(this->m_key)->body->GetPosition().y;

				//float temp_pos =  this->

				if (pixel_walking_distance == 0)
				{
					Animate(0.75);
					this->enemy_attack_square.setOrigin(-this->_data->manager.Get(this->m_key)->body->GetPosition().x + this->_data->manager.Get(this->m_key)->body->GetPosition().x / 2,
						this->_data->manager.Get(this->m_key)->body->GetPosition().y + 38);


				}
				//if(enemy_pos > ){

				//if(enemy_pos >= this->m_sprite_X_POS && !this->m_am_I_backwards){
				else if (!this->m_am_I_backwards) {
					Animate(0.75, 2);

					//vel.x = b2Min(vel.x + 0.5f, 50.0f);
					vel.x = this->enemy_speed_x;
					vel.y = this->enemy_speed_y;
					//std::cout << "ENEMY POS : " << enemy_pos <<
					//"\nOriginal POS : " << m_sprite_X_POS <<
					//std::endl;

					this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(vel);

					this->enemy_attack_square.setOrigin(-this->_data->manager.Get(this->m_key)->body->GetPosition().x,
						this->_data->manager.Get(this->m_key)->body->GetPosition().y + 38);



					if (enemy_pos > this->m_sprite_X_POS + pixel_walking_distance)
					{
						this->m_am_I_backwards = true;
						//Animate(0.75, 1);

					}



				}
				else if (this->m_am_I_backwards)
				{
					this->m_am_I_backwards = true;
					Animate(0.75, 1);

					//vel.x = b2Min(vel.x - 0.5f, -50.0f);
					vel.x = -this->enemy_speed_x;
					//vel.y = -this->enemy_speed_y;
					vel.y = this->_data->manager.Get(this->m_key)->body->GetWorld()->GetGravity().y;

					//std::cout << "ENEMY POS : " << enemy_pos <<
					//"\nOriginal POS : " << m_sprite_X_POS <<
					//std::endl;

					this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(vel);

					this->enemy_attack_square.setOrigin(-this->_data->manager.Get(this->m_key)->body->GetPosition().x + this->e_attack_square_x - this->m_sprite_WIDTH,
						this->_data->manager.Get(this->m_key)->body->GetPosition().y + 38);

					if (enemy_pos < this->m_sprite_X_POS - pixel_walking_distance)
					{
						this->m_am_I_backwards = false;
						//Animate(0.75, 1);

					}


				}


				//if(enemy_attack_square.getGlobalBounds().contains(this->_data->manager.Get("red")->getPosition()))
				//{
				//	std::cout << "I SEE YOU !!!!!!!!!!" << std::endl;
				//}






				if (this->m_health < 5)
				{
					std::cout << this->m_key << " : Died" << std::endl;
					//	this->m_dead = true;

						//Enemy()

						//this->m_health_text.setString("");

					this->m_dead = true;

				}

			}
			else
			{
				//delete this->m_health_text;
				std::cout << "DEAD : " << this->m_key << std::endl;

				this->m_health_text.setString("");


				//return ;
				//else
				//delete this;
				//this->m_dead = false;


				//this->is_alive = false;

				//this->m_health = NULL;
			//this->m_dead = false;

			}

			//this->m_dead = false;
		}


		bool Get_enemy_alive_status()
		{
			return this->m_dead;
		}

		void Draw()
		{
			if (!this->m_dead) {

				_data->window.draw(m_health_text);
				_data->window.draw(enemy_attack_square);
			}
		}

		void set_damage(bool s)
		{
			m_took_damage = s;
		}

		void set_Alive(bool s)
		{
			this->m_dead = s;
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

		sf::RectangleShape get_attack_square()
		{
			return this->enemy_attack_square;
		}



	private:
		GameDataRef _data;
		std::string m_key;
		float m_sprite_X_POS;
		float m_sprite_Y_POS;
		bool m_is_Moving;
		int m_health;
		sf::Text m_health_text;

		bool m_took_damage;
		bool is_alive;
		bool m_dead;



		int delay = 0;
		int bullet_counter = 0;


		bool		dead_gun;



		int m_sprite_WIDTH;

		bool m_am_I_backwards = false;
		float capture_time;

		sf::Clock gun_clock;

		sf::Time time_g;

		sf::RectangleShape enemy_attack_square;

		int pixel_walking_distance;

		float e_attack_square_x;
		float e_attack_square_y;

		float b_speed_x;
		float b_speed_y;

		float enemy_speed_x;
		float enemy_speed_y;



	};




}