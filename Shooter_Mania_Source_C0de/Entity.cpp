#include "Entity.hpp"

namespace Sekander
{

	Entity::Entity(b2World* world)
	{
		this->texture = new sf::Texture();
		this->active = 1;
		this->groupId = 0;
		this->world = world;
	}

	void Entity::Load(std::string filename, bool dynamic,
		unsigned const short int x_frames,
		unsigned const short int y_frames)
	{
		this->texture->loadFromFile(filename);
		this->setTexture(*this->texture);

		//she->e_circle = new b2CircleShape();

		this->bodyDef = new b2BodyDef();
		if (dynamic)
		{
			this->bodyDef->type = b2_dynamicBody;
		}
		else
		{
			this->bodyDef->type = b2_staticBody;
		}
		this->bodyDef->position.Set(this->getPosition().x, this->getPosition().y);
		this->body = this->world->CreateBody(this->bodyDef);

		//this->shape = new b2CircleShape();

		this->shape = new b2PolygonShape();

		if (x_frames == 0 || y_frames == 0)
		{

			this->shape->SetAsBox(this->texture->getSize().x * 0.5f - b2_polygonRadius,
				this->texture->getSize().y * 0.5f - b2_polygonRadius);

			sf::IntRect debug_rec = sf::IntRect(this->body->GetPosition().x, this->body->GetPosition().y,
												this->texture->getSize().x , this->texture->getSize().y);
		}
		else
		{
			this->shape->SetAsBox(((this->texture->getSize().x) / x_frames) * 0.5f - b2_polygonRadius,
				((this->texture->getSize().y) / y_frames) * 0.5f - b2_polygonRadius);
		}

		this->fixtureDef = new b2FixtureDef();
		this->fixtureDef->shape = this->shape;

		if (dynamic)
		{
			this->fixtureDef->density = 1.0f;
			this->fixtureDef->friction = 0.3f;
			this->body->CreateFixture(this->fixtureDef);
		}
		else
		{
			this->body->CreateFixture(this->shape, 0);
		}
	}




	bool Entity::Update(sf::RenderWindow& window)
	{
		b2Vec2 pos = this->body->GetPosition();
		//float32 rot = this->body->GetAngle();
		float_t rot = this->body->GetAngle();
		this->setPosition(pos.x, -pos.y);
		this->setRotation(rot);

		return true;
	}

	bool Entity::CheckCollision(Entity* entity)
	{
		return this->getGlobalBounds().intersects(entity->getGlobalBounds());
	}


	void Entity::Destroy()
	{
		this->active = 0;
	}

	void Entity::Enable()
	{
		this->active = 1;
	}

	Entity::~Entity()
	{
		std::cout << "DEBUG DELETION" << std::endl;
		this->texture = NULL;
		this->bodyDef = NULL;
		//this->body = NULL;
		this->shape = NULL;
		this->fixtureDef = NULL;
		//this->body->DestroyFixture(this->fixtureDef);


		//std::cout << "DEBUG DELETION#" << std::endl;

		delete this->texture;
		//std::cout << "DEBUG DELETION##" << std::endl;

		delete this->bodyDef;
		//std::cout << "DEBUG DELETION###" << std::endl;

		delete this->shape;
		//std::cout << "DEBUG DELETION####" << std::endl;

		delete this->fixtureDef;
		//std::cout << "DEBUG DELETION#####" << std::endl;
		this->world->DestroyBody(this->body);

		std::cout << "LAST DEBUG DELETION######" << std::endl;

		//delete this->body;
	}


} // namespace Sekander
