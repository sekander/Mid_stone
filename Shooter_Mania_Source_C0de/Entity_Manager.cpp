#include "Entity_manager.hpp"
#include <iostream>

namespace Sekander
{

	EntityManager::EntityManager()
	{
		this->world = new b2World(b2Vec2(0, -50));
	}

	void EntityManager::Add(std::string name, std::string filename,
		bool dynamic,
		unsigned const short int x_frames,
		unsigned const short int y_frames)
	{

		Entity* entity = new Entity(this->world);
		entity->Load(filename, dynamic, x_frames, y_frames);
		this->entities.insert(std::make_pair(name, entity));
		std::cout <<
			"ENTITY BEING CREATED: " <<
			name <<
			std::endl;
	}

	void EntityManager::Add(std::string name, std::string filename, bool dynamic, shape_options shapes)
	{
		if (shapes == Square)
		{
		}
		else if (shapes == Circle)
		{
			std::cout << "END\nEND\n"
				<< std::endl;
		}
	}


	Entity* EntityManager::Get(std::string name)
	{
		std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);

		if (found == this->entities.end())
		{
			return NULL;
		}
		else
		{
			return found->second;
		}
	}

	bool EntityManager::Update(sf::RenderWindow& window)
	{
		std::vector<std::string> toRemove;

		this->world->Step(1.0f / 60.0f, 6, 2);

		for (auto& iterator : this->entities)
		{
			//std::cout << "ENTITIES UPDATING : " <<
			//iterator.first
			//<< std::endl;

			switch (iterator.second->Active())
			{
			case 0:
				toRemove.push_back(iterator.first);
				break;
			default:
				if (!iterator.second->Update(window))
				{
					return false;
				}
				break;
			}
		}

		for (auto& iterator : toRemove)
		{
			std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(iterator);

			if (found != this->entities.end())
			{
				std::cout <<
					"DELETING :: " <<
					found->first <<
					found->second <<
					std::endl;
				this->entities.erase(found->first);

				found->second->~Entity();
				//delete found->second;
				//found->second->body->DestroyFixture();
			}
		}
		toRemove.clear();

		return true;
	}

	void EntityManager::Render(sf::RenderWindow& window)
	{

		//sf::IntRect debug_rec = sf::IntRect(this->body->GetPosition().x, this->body->GetPosition().y,
		//	this->texture->getSize().x, this->texture->getSize().y);

		for (auto& iterator : this->entities)
		{
			sf::RectangleShape de = sf::RectangleShape(iterator.second->getScale());
			de.setOutlineColor(sf::Color::Red);

			window.draw(de);

			window.draw(*iterator.second);

		}
	}

	//int EntityManager::GetAllEntities()
	//{
	//	for (auto& iterator : this->entities)
	//	{
	//		//std::cout << this->entities.size() << std::endl;
//
	//		return this->entities.size();		
	//	}
	//}

	void EntityManager::ListAllEnties()
	{


		std::unordered_map<std::string, Entity*>::iterator it = entities.begin();
		while (it != entities.end())
		{
			std::cout << it->first << " :: " << it->second << std::endl;
			it++;




		}



	}


	void EntityManager::DeleteEntity()
	{
		for (auto& iterator : this->entities)
		{
			std::cout << "Deleting : " << iterator.first << std::endl;
			iterator.second->~Entity();
			//delete iterator.second;
			//this->entities.erase(iterator.second);


		}

		/*

		for (auto& iterator : this->entities)
		{
			std::cout << "Objects::" <<
			iterator.first


			<< std::endl;
			//iterator.second->DeleteShape();
	//
			//iterator.second->Destroy();

			iterator.second->~Entity();
			delete &iterator;
			//iterator = NULL;

			//delete iterator.second;
			//iterator.second = NULL;
			//delete iterator.second;
//
			//iterator.second->Destroy();
			//iterator.first.at(iterator);

			//iterator.second->Destroy();
			//iterator.second->~Entity();

			//		std::cout << "Objects DIE::" <<
			//iterator.second
			//
//
			//<< std::endl;

			//delete iterator.second;

		}
			*/
		this->entities.clear();


	}

	void EntityManager::EnableEntity()
	{
		for (auto& iterator : this->entities)
		{

			std::cout << "Objects::" <<
				iterator.second


				<< std::endl;

			iterator.second->Enable();
			std::cout << "Objects ALIVe::" <<
				iterator.second


				<< std::endl;


		}

	}

	EntityManager::~EntityManager()
	{
		//for (auto& iterator : this->entities)
		//{
		//	delete iterator.second;
		//}
		//this->entities.clear();
		delete this->world;
	}

} // namespace Sekander
