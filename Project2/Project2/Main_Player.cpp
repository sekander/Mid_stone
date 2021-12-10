#include "Main_Player.hpp"

namespace Sekander {

    void Main_Player::MoverRigtht(float speed)
    {
        //this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(b2Vec2(speed, 0));

        b2Vec2 vel = this->_data->manager.Get(this->m_key)->body->GetLinearVelocity();

        float desiredVel = 0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

            //if(speed > 0){
            Animate(0.25, 2);

            vel.x = b2Min(vel.x + 1.0f, 100.0f);

            //std::cout 
            //<< "Gravity :: " 
            //<< world->GetGravity().x 
            //<< " :: " 
            //<< world->GetGravity().y
            //<< "\nSpeed :: " 
            //<< vel.x
            //<< std::endl;

            this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(vel);
            //this->_data->manager.Get(this->m_key)->body->ApplyForce()

            //this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(b2Vec2(speed, 0));
            this->m_am_I_backwards = false;

        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Animate(0.25, 1);
            this->m_am_I_backwards = true;
            vel.x = b2Max(vel.x - 1.0f, -100.0f);

            //std::cout 
            //<< "Gravity :: " 
            //<< world->GetGravity().x 
            //<< " :: " 
            //<< world->GetGravity().y
            //<< "\nSpeed :: " 
            //<< vel.x
            //<< std::endl;

            this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(vel);
            this->m_am_I_backwards = true;

            //this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(b2Vec2(-speed, 0));
        }
        else
        {
            //std::cout 
            //<< "\nSpeed :: " 
            //<< vel.x
            //<< std::endl;

            vel.x = 0;
        }
    }


    void Main_Player::Dash()
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {

            b2Vec2 vel;
            vel.x = 40;
            vel.y = 0;

            this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(vel);

        }


    }

    //void Main_Player::Shooting(Gun& gw)
    //void Main_Player::Shooting(Gun& gw, LoadingGameObjects *ld)

    void Main_Player::NU_Shooting(Gun& gw)
    {
        if (!this->m_am_I_backwards)
        {



            gw.SetOrigin(this->m_sprite_WIDTH + (this->_data->manager.Get(this->m_key)->body->GetPosition().x + 60),
                this->_data->manager.Get(this->m_key)->body->GetPosition().y + 40);


            for (auto& some : this->_data->manager.ReturnMap())
            {
                if (!some.first.find("bullet"))
                {

                    auto bw = some.second;

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                    {
                        std::cout << "Bullet : " << some.first << std::endl;

                        gw.Shoot_Entities(bw, true, false);
                    }

                }

            }
        }
        if (this->m_am_I_backwards)
        {

            gw.SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 60,
                this->_data->manager.Get(this->m_key)->body->GetPosition().y + 40);


            for (auto& some : this->_data->manager.ReturnMap())
            {
                if (!some.first.find("bullet"))
                {

                    auto bw = some.second;

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                    {
                        std::cout << "BACKWARDS  Bullet : " << some.first << std::endl;

                        gw.Shoot_Entities(bw, false, true);
                    }

                }

            }

        }

    }



    void Main_Player::Shooting(Gun& gw, std::unordered_map<std::string, Bullet*> bullet_list)
    {
        if (!this->m_am_I_backwards)
        {

            this->_data->manager.Get(gw.Get_key())->setScale(-1, 1);



            gw.SetOrigin(this->m_sprite_WIDTH + (this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10),
                this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);



            for (auto& bullet : bullet_list)
            {

                auto bw = bullet.second;


                //if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                if (this->checkKEYPRESS(sf::Keyboard::LShift))
                {




                    float temp_time = 0;


                    //sf::Time elapsed1 = gun_clock.getElapsedTime();
                    //std::cout << "Elapsed Time : " << elapsed1.asSeconds() << std::endl;
//
//
                        //std::cout << "Gun clock started : " << 
                        //gun_clock.getElapsedTime().asSeconds() << 
                        //"\nTime passed : " << time_g.asSeconds() <<
//
                        //std::endl;






                        //if(_clock.getElapsedTime().asSeconds() > 5.0f &&
                        //   _clock.getElapsedTime().asSeconds() < 8.0f)

                    if (gun_clock.getElapsedTime().asSeconds() > 0.0f &&
                        gun_clock.getElapsedTime().asSeconds() < 0.05f)
                    {
                        gw.Shoot_Gun(bw, true, false, false, false);

                    }

                    if (gun_clock.getElapsedTime().asSeconds() > 0.05f)
                    {
                        gun_clock.restart();

                    }





                    //sf::Time elapsed2 = gun_clock.getElapsedTime();
                    //std::cout << "After : " <<  elapsed2.asSeconds() << std::endl; 

                    //_clock.restart();


                    //std::cout << "BULLET : " << bw->Get_Name() << std::endl;
                    //gw.SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    //             this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                    //gw.Set_X_POS(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10);
                    //gw.Set_Y_POS(this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                    //std::cout << "BRAP BRAP BRAP" << std::endl;
                    //############SHOOTING RIGHT############
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    //{    this->m_am_I_backwards = true;
                    //     gw.Shoot_Gun(bw, false, true, false, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    //{ gw.Shoot_Gun(bw, false, false, true, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    //{ gw.Shoot_Gun(bw, false, false, false, true);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    //{ gw.Shoot_Gun(bw, true, false, true, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    //{ gw.Shoot_Gun(bw, false, true, true, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    //{ gw.Shoot_Gun(bw, true, false, false, true);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    //{ gw.Shoot_Gun(bw, false, true, false, true);}
                }
            }
        }
        if (this->m_am_I_backwards)
        {

            this->_data->manager.Get(gw.Get_key())->setScale(1, 1);



            gw.SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 15,
                this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
            //if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            //if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))

            for (auto& bullet : bullet_list)
            {
                auto bw = bullet.second;

                if (this->checkKEYPRESS(sf::Keyboard::LShift))
                {


                    if (gun_clock.getElapsedTime().asSeconds() > 0.0f &&
                        gun_clock.getElapsedTime().asSeconds() < 0.05f)
                    {
                        gw.Shoot_Gun(bw, false, true, false, false);

                    }

                    if (gun_clock.getElapsedTime().asSeconds() > 0.05f)
                    {
                        gun_clock.restart();

                    }




                    //std::cout << "BULLET : " << bw->Get_Name() << std::endl;

                    //gw.SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    //             this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                    //gw.Set_X_POS(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10);
                    //gw.Set_Y_POS(this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                    //std::cout << "BRAP BRAP BRAP" << std::endl;
                    //############SHOOTING LEFT############
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    //{   this->m_am_I_backwards = false;
                    //    gw.Shoot_Gun(bw, true, false, false, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    //{ gw.Shoot_Gun(bw, false, false, true, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    //{ gw.Shoot_Gun(bw, false, false, false, true);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    //{ gw.Shoot_Gun(bw, true, false, true, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    //{ gw.Shoot_Gun(bw, false, true, true, false);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    //{ gw.Shoot_Gun(bw, true, false, false, true);}
                    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
                    //   sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    //{ gw.Shoot_Gun(bw, false, true, false, true);}
                }
            }
        }

    }



    void Main_Player::Jump(bool m_OnFloor)
    {

        std::cout << " Bool " <<
            this->m_OnFloor <<
            "Couter" <<
            jet_fuel <<
            std::endl;


        if (jet_fuel > 499)
            this->m_OnFloor = true;

        //    if(counter < 1)
        if (this->m_OnFloor)
        {

            b2Vec2 vel;

            jet_fuel++;

            // m_OnFloor = false;

            std::cout << " Bool " <<
                this->m_OnFloor <<
                "Couter" <<
                jet_fuel <<
                std::endl;
            //press_twice = tru;

            vel.y = 25;
            vel.x = 0 + this->_data->manager.Get(this->m_key)->body->GetLinearVelocity().x;

            this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(vel);

            if (jet_fuel > 1500)
            {
                this->m_OnFloor = false;

                vel.y = -200;
                vel.x = 0 + this->_data->manager.Get(this->m_key)->body->GetLinearVelocity().x;

                this->_data->manager.Get(this->m_key)->body->SetLinearVelocity(vel);

                jet_fuel = 0;

                //   counter = 0;
                   //this->m_OnFloor = false;
            }

        }
        else
        {
            this->m_OnFloor = false;
            //`:        counter = 0;
        }
    }


    void Main_Player::DoubleJump(bool second)
    {
        if (this->can_i_jump)
        {

            std::cout << "JUMPING\n";
            float impulse = this->_data->manager.Get(this->m_key)->body->GetMass() * 10;
            this->_data->manager.Get(this->m_key)->body->
                ApplyLinearImpulse(b2Vec2(0, impulse),
                    this->_data->manager.Get(this->m_key)->body->
                    GetWorldCenter(), true);

            //this->m_OnFloor = false;
           // counter = 0;
            count = 0;

        }


    }


    void Main_Player::Camera(sf::View view)
    {
        //auto windowSpace = this->_data->window.getView();

        //sf::View view = this->_data->window.getDefaultView();
        //sf::View minimapView;		


        //minimapView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 0.25f));




        float cameraShiftl = 0;
        sf::FloatRect camera_screen = view.getViewport();

        //std::cout << 
        //"Camera Top : " <<
        //camera_screen.top << 
        //" Camera Left : " <<
        //camera_screen.left << 
        //" ViewPort Width : " <<
        //view.getSize().x / 2 <<
        //std::endl;

        cameraShiftl = 0;

        //if(this->GetPosition().x > view.getSize().x/2)
//          {

              //this->_data->window.setView(minimapView);
              //this->_data->window.draw();
        view.setCenter(this->GetPosition().x,
            ((this->GetPosition().y) * -1) - view.getSize().y / 4);

        //view.move(this->GetPosition().x, 0);
        view.zoom(0.7f);
        this->_data->window.setView(view);
        //this->_data->window.setView(minimapView);

//            }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        {
            count--;
            float cameraShiftl = 0;
            cameraShiftl = cameraShiftl + count;

            view.move(cameraShiftl, 0);
            this->_data->window.setView(view);


            //std::cout << 
            //"GOING LEFT" <<
            //"Camera Top :" <<
            //camera_screen.top << 
            //" Camera Left :" <<
            //camera_screen.left << 
            //std::endl;


        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            count++;

            if (cameraShiftl < 0)
            {

            }


            cameraShiftl = cameraShiftl + count;

            view.move(cameraShiftl, 0);
            this->_data->window.setView(view);

            //std::cout << 
            //"GOING RIGHT" <<
            //"Camera Top :" <<
            //camera_screen.top << 
            //" Camera Left :" <<
            //camera_screen.left << 
            //std::endl;



        }



    }
}
