#include "GameWorld.hpp"
#include <iostream>

namespace Sekander
{





        
	GameWorld::GameWorld(GameDataRef data) : _data(data)
	{
		
                _animationIterator = 0;

                source.x = DIRECTION_X_RIGHT_INITAL;
                source.y = DIRECTION_Y_RIGHT_INITAL;
                _playerRect = sf::IntRect(source.x * SPRITE_WIDTH , 
                                            source.y * SPRITE_HEIGHT , 
                                                       SPRITE_WIDTH, 
                                                       SPRITE_HEIGHT);


                
                
                ///////////PLAYER 1     000000000000--------------------------------------------------
               // this->_data->manager.Add("player", PLAYER_FILEPATH, true, 3, 4 );
               // this->_data->manager.Get("player")->setTextureRect(_playerRect);
               // player = this->_data->manager.Get("player")->body;
               // player->SetTransform(b2Vec2(220, -420), 0);




                this->_data->manager.Add("floor", "Resources/res/floor.png", false, 0, 0);
                this->_data->manager.Add("floor1", "Resources/res/floor.png", false, 0, 0);
                this->_data->manager.Add("floor2", "Resources/res/floor.png", false, 0, 0);
                floor = this->_data->manager.Get("floor")->body;
                floor->SetTransform(b2Vec2(200, -480), 0);
                floor = this->_data->manager.Get("floor1")->body;
                floor->SetTransform(b2Vec2(500, -480), 0);
                floor = this->_data->manager.Get("floor2")->body;
                floor->SetTransform(b2Vec2(700, -480), 0);



                //polygonShape->SetAsBox(b2Vec2(0, -200));
                //poly->SetTwoSided(b2Vec2(0, -200), b2Vec2(200, -200));
                //this->_data->manager.Get(poly);
                //this->_data->manager
                //this->_data->manager.Get("")->body->CreateFixture(poly, 0);
            //     is_key_pressed GameWorld::is
                is_key_pressed = false;
                counter = 0;
                input_counter = 0.0f;

                
        }


        GameWorld::GameWorld(GameDataRef data, std::string key,
                                               std::string file_name,
	                                       int source_x,
	                                       int source_y,
	                                       int sprite_WIDTH,
	                                       int sprite_HEIGHT,
	                                       bool dynamic,
	                                       int sprite_X_FRAMES,
	                                       int sprite_Y_FRAMES,
	                                       float sprite_X_POS,
	                                       float  sprite_Y_POS,
	                                       float sprite_ANGLE  ) : _data(data)
        {

                this->_animationIterator = 0;
                this->_key = key;


                this->source.x = source_x;
                this->source.y = source_y;
                this->_sprite_X_FRAMES = sprite_X_FRAMES;
                this->_sprite_Y_FRAMES = sprite_Y_FRAMES;
                this->_sprite_WIDTH = sprite_WIDTH;
                this->_sprite_HEIGHT = sprite_HEIGHT;



                this->_playerRect = sf::IntRect(source.x * sprite_WIDTH , 
                                          source.y * sprite_HEIGHT , 
                                                     sprite_WIDTH, 
                                                     sprite_HEIGHT);

                this->_data->manager.Add(key, 
                                         file_name, 
                                         dynamic, 
                                         sprite_X_FRAMES, 
                                         sprite_Y_FRAMES);

                this->_data->manager.Get(key)->setTextureRect(_playerRect);
                this->_data->manager.Get(key)->body->SetTransform(b2Vec2(sprite_X_POS, 
                                                                         sprite_Y_POS), 
                                                                         sprite_ANGLE * DEGTORAD);
        
                //this->_data->manager.Update(_data);


              //  Animate(dt);


              std::cout << "GAMEOBJECTS KEY NAME : " << _key << std::endl;
              std::cout << "GAMEOBJECTS Sprite SOURCE X : " << this->source.x << std::endl;
              std::cout << "GAMEOBJECTS Sprite SOURCE Y : " << this->source.y << std::endl;
              std::cout << "GAMEOBJECTS Sprite SOURCE X FRAMES : " << this->_sprite_X_FRAMES << std::endl;
              std::cout << "GAMEOBJECTS Sprite SOURCE y FRAMES : " << this->_sprite_Y_FRAMES << std::endl;
              
              std::cout << "GAMEOBJECTS Sprite Width : " << this->_sprite_WIDTH << std::endl;
              std::cout << "GAMEOBJECTS Sprite Height : " << this->_sprite_HEIGHT << std::endl;
              //std::cout << "GAMEOBJECTS Sprite Frames : " << this->_sprite_X_FRAMES << std::endl;

              is_key_pressed = false;
              counter = 0;
              input_counter = 0.0f;



        }



	void GameWorld::Draw()
	{
		//_data->window.draw(_playerSprite);
                this->_data->manager.Render(_data->window);
	}

	
	void GameWorld::Update(float dt)
	{

                //Animate(dt);
                //Animate(dt);
                if (!this->_data->manager.Update(_data->window))
	        {
		        return;
	        }


                for (b2ContactEdge* ce = 
                this->_data->manager.Get(this->_key)->body->GetContactList(); 
                ce;
                ce = ce->next)
                {
                        b2Contact* c = ce->contact;
                        if(c->IsTouching())
                        {
                                //std::cout << "PLAYER : " << this->_key 
                                //<< "TOUCHING THE FLOOO00000RRRRR" << std::endl;
                                this->m_OnFloor = true;
                                this->m_In_the_Air = false;
                        }
                        else{
                                this->m_OnFloor = false;
                                this->m_In_the_Air = true;

                        }
                }

 









/*
                for (b2ContactEdge* ce = 
                player->GetContactList(); 
                ce;
                ce = ce->next)
                {
                        b2Contact* c = ce->contact;
                        if(c->IsTouching())
                        {
                                std::cout << "GAMEWORD : " << "TOUCHING THE FLOOO00000RRRRR" << std::endl;
                                m_OnFloor = true;
                        }
                        else{
                                m_OnFloor = false;
                        }
                }

                //ENTITY -----------------------------Postiotns ----------------------------
             //   std::cout << bullet->GetPosition().x << std::endl;

                
              //  std::cout << player->GetPosition().x << std::endl;

                if(isBulletAlive && bulletCounter > 0)
                {
                        std::cout << "GAMEWORD : " << "Bullet Position : " << bullet->GetPosition().x << std::endl;

                        if( bullet->GetPosition().x > (100 + player->GetPosition().x)  && bulletCounter >= 1)
                        {
                                std::cout <<  "GAMEWORD : " << bullet->GetFixtureList() << " : DELETED " << std::endl;
                                this->_data->manager.Get("bullet")->Destroy();
                                isBulletAlive = false;
                                bulletCounter--;

                        }       

                        std::cout << "Bullet Objects : " << this->_data->manager.Get("bullet")->Active() << std::endl;

                        if(this->_data->manager.Get("bullet")->Active() > 1 )
                        {
                                this->_data->manager.Get("bullet")->Destroy();
                        }






                }


                //this->manager->Get()
                //std::cout << "Printing ALL OBJECTS: " <<  << std::endl;
                //-----------------GAMEWORLD CHECKING----------------------------
                //---------------------------------------------------------------
                int size = this->_data->manager.GetAllEntities(); 

                if(size >= 3)
                {
                        checkingObjects = true;
                }else{
                        checkingObjects = false;
                }


                if(checkingObjects && isBulletAlive)
                {
                        std::cout << "GAMEWORD : " <<  "IM GOOD" << std::endl;
                        checkingObjects = false;
                }
                else if (checkingObjects && !isBulletAlive)
                {
                        std::cout << "GAMEWORD : " << "SOMETHING WENT WRONG !!!!!!!!!!!!!!!!!!!!" << std::endl;
                        std::cout << "GAMEWORD : " << "GameObjects : " << size << std::endl;
                        //this->manager->Get("bullet")->Destroy();
                        std::cout << this->_data->manager.ListAllEnties() << std::endl;

                        if(this->_data->manager.Get("bullet")->Active() == 0 && !isBulletAlive && checkingObjects){
                                //this->manager->Get("bullet0")->Destroy();
                                std::cout << "WARNING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!#######################" << std::endl;
                        }
                }
                else{
                        std::cout << "GAMEWORD : " << "GameObjects : " << size << std::endl;
                }


        

*/

	}
/*
        void GameWorld::MoverRigtht()
        {

                bulletCounter++;

                if(bulletCounter > 0 && bulletTrigger)
                {


                source.x = DIRECTION_X_RIGHT_INITAL;
                source.y = DIRECTION_Y_RIGHT_INITAL;
     
                player->SetLinearVelocity(b2Vec2(20,0));
                
                std::cout << "GAMEWORD : " << "TRYING SOMETHING HEREEEEEEE" << std::endl;
        
        
                }
        
        }

        void GameWorld::MoverLeft()
        {

                bulletCounter++;

                if(bulletCounter > 0 && bulletTrigger)
                {



            //    goDirection(3, _playerSprite);
                source.x = DIRECTION_X_LEFT_INITAL;
                source.y = DIRETION_Y_LEFT_INITAL;
            //    _playerRect = (sf::IntRect(source.x * SPRITE_WIDTH , 
            //                                             source.y * SPRITE_HEIGHT , 
            //                                             SPRITE_WIDTH, 
            //                                             SPRITE_HEIGHT));
                 //  this->manager->Get("player")->setTextureRect(_playerRect);
                player->SetLinearVelocity(b2Vec2(-20,0));
                }
        }

        void GameWorld::MoverUp()
        {

		std::cout << "GAMEWORD : " << "JUMP JUMPJUMP JUMPJUMP JUMPJUMP JUMPJUMP JUMPJUMP JUMPJUMP" << std::endl;


                if(m_OnFloor)
                {
                        float impulse = player->GetMass() * 10;
                        player->ApplyLinearImpulse( b2Vec2(0,impulse), player->GetWorldCenter(), false );
                }
                else
                {
                        m_OnFloor = false;
                }
                
        }

        void GameWorld::MoverDown()
        {
	        //this->manager->Add("ball2", "Resources/res/ship.png", true, 0, 0);
	        //this->manager->Get("ball2")->body->SetTransform(b2Vec2(124, 0), 45 * DEGTORAD);


                bulletCounter++;

                if(bulletCounter > 0 && bulletTrigger)
                {

                         this->_data->manager.Add("bullet", "Resources/res/ship.png", true, 0, 0);





                         bullet = this->_data->manager.Get("bullet")->body;
                         bullet->SetTransform(b2Vec2(player->GetPosition().x, 
                                                     player->GetPosition().y), 0);

                         bullet->IsBullet();
                         bullet->SetGravityScale(0);
                         bullet->SetLinearVelocity(b2Vec2(100000, 0));

                         float force = 0;

                         force = bullet->GetLinearVelocity().x * 1000;

                         bullet->ApplyForce(b2Vec2(force*10, 0), bullet->GetWorldCenter(), true);
                         isBulletAlive = true;

                         std::cout << "GAMEWORD : " << "BULETT ---------------------->" << std::endl;



                }







        }


*/


        bool GameWorld::pressure_sensitive_KEY_PRESS(sf::Keyboard::Key key)
        {
                

                bool level_1, level_2, level_3, level_4, level_5;
                bool tap;


	        if(sf::Keyboard::isKeyPressed(key))
	        {
	        	input_counter += 0.001f;
                        bool key_held = true;
                        float startCount = 0.0f;


                        if(startCount > input_counter + 0.010f)
                        {
                                std::cout 
                                << "PRESSURE SENSITIVE KEY PRESSED :: " 
                                << "LEVEL 1"
                                << std::endl;
                        }
                        
                        else if(startCount > input_counter + 0.025f)
                        {
                                std::cout 
                                << "PRESSURE SENSITIVE KEY PRESSED :: " 
                                << "LEVEL 2"
                                << std::endl;
                        }
                        
                        else if(startCount > input_counter + 0.050f)
                        {
                                std::cout 
                                << "PRESSURE SENSITIVE KEY PRESSED :: " 
                                << "LEVEL 3"
                                << std::endl;
                                return true;
                        }
                        else if(startCount > input_counter + 0.1f)
                        {
                                std::cout 
                                << "PRESSURE SENSITIVE KEY PRESSED :: " 
                                << "LEVEL 4"
                                << std::endl;
                        }
                        else if(startCount > input_counter + 0.2f)
                        {
                                std::cout 
                                << "PRESSURE SENSITIVE KEY PRESSED :: " 
                                << "LEVEL 5"
                                << std::endl;
                        } 
                        
                        
                        
                        

                        std::cout 
                        << "PRESSURE COUNTER :==="
                        << input_counter
                        << std::endl;

                        sf::Time delayTime = sf::milliseconds(0.01);
                        sf::sleep(delayTime);

	        }
                else
                {
                        //checkKEYPRESS();
                        return false;
                        input_counter = 0.0f;

                }






        }



       void GameWorld::Animate(float dt)
       //void GameWorld::Animate()
	{
        
       



        
        //std::cout << "PLAYER Animation KEY NAME : " << this->m_key << std::endl;
        //std::cout << "PLAYER Animation Sprite Frames : " << this->m_sprite_X_FRAMES << std::endl;
        //std::cout << "PLAYER Sprite Width : " << this->m_sprite_WIDTH << std::endl;
        //std::cout << "PLAYER Sprite Height : " << this->m_sprite_HEIGHT << std::endl;

                //std::cout << this->_clock.getElapsedTime().asSeconds() << std::endl;
		//if(this->_clock.getElapsedTime().asSeconds() > 2.00 / this->_sprite_X_FRAMES)
		if(this->_clock.getElapsedTime().asSeconds() > dt / this->_sprite_X_FRAMES)
		{
			//std::cout << "ANIMATION ITER 1 : " << this->_animationIterator << std::endl;

                      


			if(this->_animationIterator < this->_sprite_X_FRAMES -1)
			{
				this->_animationIterator++;
			//std::cout << "ANIMATION ITER 2: " << this->_animationIterator << std::endl;

			}
                        else
                        {
                                this->_animationIterator = 0;
                        }


                          this->_playerRect = sf::IntRect(this->_animationIterator * this->_sprite_WIDTH , 
                                                        this->source.y * this->_sprite_HEIGHT , 
                                                        this->_sprite_WIDTH, 
                                                        this->_sprite_HEIGHT);

                                               


                        
                       

                        this->_data->manager.Get(this->_key)->setTextureRect(this->_playerRect);

                        //std::cout << "RETURN KEY :: " << this->_data->manager.ReturnKey() << std::endl;


			//std::cout << "GAMEWORLD : " << this->_key << " : ANIMATION ITER : " << this->_animationIterator << std::endl;
                        //_playerState = BIRD_STATE_FLYING;
                        this->_clock.restart();

		}
                

	}






       void GameWorld::Animate(float dt, int Y_FRAME)
       {
        
       if(this->_clock.getElapsedTime().asSeconds() > dt / this->_sprite_X_FRAMES)
		{

			if(this->_animationIterator < this->_sprite_X_FRAMES -1)
			{
				this->_animationIterator++;
			//std::cout << "ANIMATION ITER 2: " << this->_animationIterator << std::endl;

			}
                        else
                        {
                                this->_animationIterator = 0;
                        }


                          this->_playerRect = sf::IntRect(this->_animationIterator * this->_sprite_WIDTH , 
                                                        Y_FRAME * this->_sprite_HEIGHT , 
                                                        this->_sprite_WIDTH, 
                                                        this->_sprite_HEIGHT);

                                               


                        
                       

                        this->_data->manager.Get(this->_key)->setTextureRect(this->_playerRect);

                        //std::cout << "RETURN KEY :: " << this->_data->manager.ReturnKey() << std::endl;


			//std::cout << "GAMEWORLD : " << this->_key << " : ANIMATION ITER : " << this->_animationIterator << std::endl;
                        //_playerState = BIRD_STATE_FLYING;
                        this->_clock.restart();

		}
                

	}













        const bool GameWorld::checkKEYPRESS(sf::Keyboard::Key key)
        {
                 static bool lastState = false;
                // key_released = false;
     		 bool currentState = sf::Keyboard::isKeyPressed(key);
                
                //is_key_pressed = false;

                

     		if(!lastState && currentState)
			 {
				//SetPlayerState(BIRD_STATE_FLYING);
                               // key_released = false;
                                std::cout << "//Got pressedGot pressed Got pressed  Got pressed    Got pressed    Got pressed    Got pressed    Got pressed" 
                                          //<< "\nKEY_STATUS :: "   << key_released 
                                          << "\nCURRENT_STATUS :: "   << currentState 
                                          << "\nCOUNTER :: "   << counter 
                                          << std::endl;

                                //lastState = true;
                             //   is_key_pressed = true;
                              


                                //return lastState;
			 }
          		//Got pressed
     		else if(lastState && !currentState)
			 {
          		//Got released      
				
				//SetPlayerState(BIRD_STATE_STILL);
                              //  key_released = true;	
                                std::cout << "//Got RRRRRreleased Got RRRRRreleased Got RRRRRreleased Got RRRRRreleased Got RRRRRreleased Got RRRRRreleased Got RRRRRreleased"
                                          //<< "\nKEY_STATUS :: "   << key_released 
                                          << "\nCURRENT_STATUS :: "   << currentState 
                                          << std::endl;

                        //return currentState;
		}
                
        
          		//Got released      

     		lastState = currentState;
                //std::cout << "//NOTHING GOT PRESSED NOTHING GOT PRESSED NOTHING GOT PRESSED NOTHING GOT PRESSED NOTHING GOT PRESSED NOTHING GOT PRESSEDNOTHING GOT PRESSED NOTHING GOT PRESSED" 
                //  << "\nKEY_STATUS :: "   << key_released 
                //  << "\nCURRENT_STATUS :: "   << currentState 
                //  << "\nELAPSED_TIME :: " << elapsed_time.asMicroseconds() << std::endl;

                counter++;
                return lastState;
                    // return lastState;
        }






	const sf::Sprite &GameWorld::GetSprite() const
	{
		return _playerSprite;
	}
}
