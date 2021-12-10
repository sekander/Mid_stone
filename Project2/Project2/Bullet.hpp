#pragma once

#include "GameWorld.hpp"
#include <iostream>

namespace Sekander
{



	class Bullet : GameWorld
	{

	public:

		explicit Bullet() {}


		explicit Bullet(GameDataRef data,
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
			float sprite_ANGLE) : GameWorld(data,
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


			this->_data->manager.Get(this->m_key)->body->IsBullet();
			this->_data->manager.Get(this->m_key)->body->SetGravityScale(0);

			this->_data->manager.Get(this->m_key)->body
				->SetEnabled(false);



		}
		void SetOrigin(float x, float y)
		{
			this->_data->manager.Get(this->m_key)->body
				->SetEnabled(true);



			this->_data->manager.Get(this->m_key)->body->SetTransform(b2Vec2(x, y), 0);

		}

		void SetSpeed(float speedX, float speedY)
		{



			this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(b2Vec2(speedX, speedY));
			this->m_is_Moving = true;
		}

		float Get_X_POS() { return this->m_sprite_X_POS; }
		float Get_Y_POS() { return this->m_sprite_Y_POS; }

		void Set_X_POS(float x) { this->m_sprite_X_POS = x; }
		void Set_Y_POS(float y) { this->m_sprite_Y_POS = y; }

		std::string Get_Name() { return this->m_key; }

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


		void IsBulletAlive(sf::View v)
		{
			auto windowSpace = this->_data->window.getView();
			auto bullet = this->_data->manager.Get(this->m_key)->body;


			
			///std::cout << windowSpace.getSize().x << std::endl;
			//std::cout << windowSpace.getSize().y << std::endl;


			//if(bullet->GetPosition().x > windowSpace.getSize().x + 100       ||
			if (bullet->GetPosition().x > v.getSize().x + 10000 ||
				bullet->GetPosition().x < 0 && this->m_is_Moving || 
				bullet->GetLinearVelocity().y > 0)
			{
				//std::cout << "BULLET PASSED" << std::endl;
				bullet->SetTransform(b2Vec2(-10, -900), 0);
				bullet->SetEnabled(false);

				//bullet->SetLinearVelocity(b2Vec2(0,0));



			}

	


			//for(auto& some : this->_data->manager.ReturnMap())
			//{
			//	if(!some.first.find("enemy"))
			//	{
			//		//std::cout << some.first << std::endl;
			//	}
			//}


			//if(bullet->GetPosition().x > this->_data->manager.Get("enemy")->getPosition().x)
			//{
//
					//}


		}

		void Update(float dt)
		{

		}



	private:
		GameDataRef _data;
		std::string m_key;
		float m_sprite_X_POS;
		float m_sprite_Y_POS;
		bool m_is_Moving;





	};




}