#pragma once

#include "GameWorld.hpp"
#include "Bullet.hpp"


#include <iostream>

namespace Sekander
{



	class Gun : GameWorld
	{

	public:

		explicit Gun() {}

		explicit Gun(GameDataRef data,
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
			std::cout << "GUN OBJECT GOT CREATED :: " << key << std::endl;

			this->m_key = key;
			this->_data = data;

			this->m_sprite_X_POS = sprite_X_POS;
			this->m_sprite_Y_POS = sprite_Y_POS;
			this->m_trigger_press = false;

			dead_gun = false;

			//this->_data->manager.Get()
		}
		void SetOrigin(float x, float y)
		{
			this->_data->manager.Get(this->m_key)->body->SetTransform(b2Vec2(x, y), 0);
		}

		//void Load_Gun(Bullet& bw);
		void Shoot_Gun(Bullet* bw, bool right, bool left, bool up, bool down);
		void Shoot_Gun(Bullet* bw, bool right, bool left, bool up, bool down, float x, float y);
		void Shoot_Gun(Bullet* bw, bool left);

		void Shoot_Entities(Entity*, bool left, bool right);
		//void Shoot_Gun(bool);

		float Get_X_POS() { return this->_data->manager.Get(this->m_key)->body->GetPosition().x; }
		float Get_Y_POS() { return this->m_sprite_Y_POS; }

		void Set_X_POS(float x) { this->m_sprite_X_POS = x; }
		void Set_Y_POS(float y) { this->m_sprite_Y_POS = y; }
		void Set_Trigger(bool press) { this->m_trigger_press = press; }
		void Set_Gun_Direction(bool yes) { this->m_gun_direction_backwards = yes; }
		void Set_Gun_UP_Direction(bool yes) { this->m_gun_direction_upwards = yes; }
		void Set_Gun_DOWN_Direction(bool yes) { this->m_gun_direction_downwards = yes; }


		std::string Get_key() {
			return this->m_key;
		}

	private:
		GameDataRef _data;
		std::string m_key;
		float 		m_sprite_X_POS;
		float 		m_sprite_Y_POS;
		bool  		m_trigger_press;
		bool  		m_gun_direction_rightwards;
		bool  		m_gun_direction_backwards;
		bool  		m_gun_direction_upwards;
		bool  		m_gun_direction_downwards;

		int delay = 0;
		int bullet_counter = 0;


		bool		dead_gun;


		//std::vector<Bullet&> _ammo;

	};
}