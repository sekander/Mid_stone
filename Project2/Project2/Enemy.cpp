#include "Enemy.hpp"

namespace Sekander
{


    void Enemy::Hold_Gun(Gun& gw)
    {
        if (!this->m_am_I_backwards)
        {

            gw.SetOrigin(this->m_sprite_WIDTH + (this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10),
                this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
        }

        if (this->m_am_I_backwards)
        {


            gw.SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
        }

    }




    void Enemy::Shoot_Gun(Bullet* bw, bool right, bool left, bool up, bool down, float x, float y)
    {


        //bool neutral_shot = true;
        //bool pull_trigger = false;



        this->delay++;
        //bool neutral_shot = true;
        //bool pull_trigger = false;



        //std::cout << "Bullet :: " << bw->Get_Name() << std::endl;
        //std::cout << "Delay :: " << this->delay << std::endl;



            //if(!pull_trigger && neutral_shot || this->delay >= 500)
        if (this->delay >= 1600)
        {
            if (this->m_am_I_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);



                //bw->SetSpeed(10000.0f + this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);


                if (gun_clock.getElapsedTime().asSeconds() > 0.0f &&
                    gun_clock.getElapsedTime().asSeconds() < 0.025f)
                {
                    //gw.Shoot_Gun(bw, true, false, false, false);
                   // gw.Shoot_Gun(bw, true, false, false, false, this->b_speed_x, this->b_speed_y);
                    bw->SetSpeed(x, y);


                }

                if (gun_clock.getElapsedTime().asSeconds() > 0.025f)
                {
                    gun_clock.restart();

                }

                //neutral_shot = false;
                //pull_trigger = true;
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                //Set_Trigger(true);
                this->delay = 0;
                //bw->IsBulletAlive();


            }

            else if (this->m_am_I_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                //bw->SetSpeed(-10000.0f - this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);


                if (gun_clock.getElapsedTime().asSeconds() > 0.0f &&
                    gun_clock.getElapsedTime().asSeconds() < 0.025f)
                {
                    //gw.Shoot_Gun(bw, true, false, false, false);
                   // gw.Shoot_Gun(bw, true, false, false, false, this->b_speed_x, this->b_speed_y);
                    bw->SetSpeed(x, y);


                }

                if (gun_clock.getElapsedTime().asSeconds() > 0.025f)
                {
                    gun_clock.restart();

                }
                //bw->SetSpeed(-x, y);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
               // Set_Trigger(true);
                this->delay = 0;

            }




        }
        //}


    //}







    }


    void Enemy::Shooting(std::unordered_map<std::string, Bullet*> bullet_list)
    {
        for (auto& bullet : bullet_list)
        {

            if (!this->m_am_I_backwards)
            {


                if (this->delay >= 1600)
                {

                    bullet.second->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                        this->_data->manager.Get(this->m_key)->body->GetPosition().y);



                    //bw->SetSpeed(10000.0f + this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);
                    //bullet.second->SetSpeed(10000.0f , 0);
                    bullet.second->SetSpeed(this->b_speed_x, this->b_speed_y);
                    //neutral_shot = false;
                    //pull_trigger = true;
                    //sf::sleep(sf::milliseconds(250));
                    //this->m_trigger_Press = true;
                    //Set_Trigger(true);
                    this->delay = 0;
                    //bw->IsBulletAlive();
                }
            }
            else if (this->m_am_I_backwards)
            {

                if (this->delay >= 1600)
                {

                    bullet.second->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                        this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                    //bw->SetSpeed(-10000.0f - this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);
                    //bullet.second->SetSpeed(-10000 , 0);
                    bullet.second->SetSpeed(-this->b_speed_x, this->b_speed_y);
                    //sf::sleep(sf::milliseconds(250));
                    //this->m_trigger_Press = true;
                    //Set_Trigger(true);
                    this->delay = 0;
                }

            }
        }

    }

    void Enemy::Shooting(Gun& gw, std::unordered_map<std::string, Bullet*> bullet_list)
    {
        if (!this->m_am_I_backwards)
        {

            for (auto& bullet : bullet_list)
            {



                auto bw = bullet.second;




                float temp_time = 0;




                if (gun_clock.getElapsedTime().asSeconds() > 0.0f &&
                    gun_clock.getElapsedTime().asSeconds() < 0.025f)
                {
                    //gw.Shoot_Gun(bw, true, false, false, false);
                    gw.Shoot_Gun(bw, true, false, false, false, this->b_speed_x, this->b_speed_y);

                }

                if (gun_clock.getElapsedTime().asSeconds() > 0.025f)
                {
                    gun_clock.restart();

                }





                sf::Time elapsed2 = gun_clock.getElapsedTime();
                //std::cout << "After : " <<  elapsed2.asSeconds() << std::endl; 

                //_clock.restart();



            }

        }
        if (this->m_am_I_backwards)
        {


            //gw.SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 60,
            //     this->_data->manager.Get(this->m_key)->body->GetPosition().y + 40);
            //if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            //if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            //if(this->checkKEYPRESS(sf::Keyboard::LShift))
            //{

            for (auto& bullet : bullet_list)
            {
                auto bw = bullet.second;



                if (gun_clock.getElapsedTime().asSeconds() > 0.0f &&
                    gun_clock.getElapsedTime().asSeconds() < 0.025f)
                {
                    //gw.Shoot_Gun(bw, false, true, false, false);
                    gw.Shoot_Gun(bw, false, true, false, false, this->b_speed_x, this->b_speed_y);

                }

                if (gun_clock.getElapsedTime().asSeconds() > 0.025f)
                {
                    gun_clock.restart();

                }





            }

        }

    }



}