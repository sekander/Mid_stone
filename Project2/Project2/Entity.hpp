#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <box2d/box2d.h>
#include <iostream>




namespace Sekander {

	struct b0x_2d_SHAPES
	{
		/* data */
		b2CircleShape circle;

	};


	//Inherit sfml Sprite functions 
	class Entity : public sf::Sprite
	{

	public:

		//Vector representing velocity
		sf::Vector2f velocity;

		//Entitny constructor taking in box2d world object 
		Entity(b2World* world);

		//Load texture and create box2d object 
		void Load(std::string filename, bool dynamic,
			unsigned const short int x_frame,
			unsigned const short int y_frame);

		void Load(std::string filename, bool dynamic, struct b0x_2d_SHAPES* shape,
			unsigned const short int x_frame,
			unsigned const short int y_frame);

		void CreateEdge();
		void CreateEdge(float, float, float, float);


		bool Update(sf::RenderWindow& window);

		bool CheckCollision(Entity* entity);


		int GroupID() { return this->groupId; }
		int Active() { return this->active; }

		void DeleteShape()
		{
			this->shape = NULL;
			//delete this->shape;
			//delete this->texture;
			this->bodyDef = NULL;
			//delete this->bodyDef;
			//delete this->shape;
			this->fixtureDef = NULL;
			//delete this->fixtureDef;
			this->texture = NULL;
			active = 0;
			//delete shape;
			//delete bodyDef;
			//delete fixtureDef;
			////this->body->DestroyFixture()
			//delete texture;
			//this->world->DestroyBody(this->body);

			std::cout << "DIE" << std::endl;

		}


		void Destroy();
		void Enable();
		b2Body* body;

		~Entity();
	protected:
		int active;
		int groupId;
		b2World* world;
		b2BodyDef* bodyDef;
		b2PolygonShape* shape;
		b2EdgeShape* edge;
		b2CircleShape* circle;
		b2FixtureDef* fixtureDef;

		//b2Shape* she;

	private:
		sf::Texture* texture;
	};

}