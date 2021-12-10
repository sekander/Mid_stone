#pragma once

#include <unordered_map>
#include <vector>


#include <box2d/box2d.h> 
#include "Entity.hpp"

namespace Sekander
{

	enum shape_options {
		Square = 1,
		Circle = 2
	};


	class EntityManager
	{
	public:
		EntityManager();

		void Add(std::string name, std::string filename, bool dynamic,
			unsigned const short int,
			unsigned const short int);

		void Add(std::string name, std::string filename, bool dynamic, shape_options);

		void newEdge();
		void newEdge(std::string,float, float, float , float);

		Entity* Get(std::string name);

		void ListAllEnties();


		std::unordered_map<std::string, Entity*> ReturnMap() {

			return entities;
		}



		bool Update(sf::RenderWindow& window);
		void Render(sf::RenderWindow& window);

		void DeleteEntity();
		void EnableEntity();

		~EntityManager();
	private:
		std::unordered_map<std::string, Entity*> entities;

		sf::Vertex vertices[2];
		

		std::vector<sf::Vertex> vertices_vec;
		
		
		int counter = 0;
		
		b2World* world;
	};

} // namespace Sekander
