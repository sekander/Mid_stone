#include "Gun.hpp"

namespace Sekander {


    //void Gun::Load_Gun(Bullet& bw)
    //{
    ////    this->_ammo.push_back(bw);
    //}

    void Gun::Shoot_Gun(Bullet* bw, bool left_direction)
    {
        this->m_gun_direction_backwards = left_direction;

        this->delay++;
        bool neutral_shot = true;
        bool pull_trigger = false;


        if (this->delay >= 400)
        {
            if (this->m_gun_direction_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                bw->SetSpeed(-500.0f, 0);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }
        }


    }




    void Gun::Shoot_Gun(Bullet* bw, bool right_direction, bool left_direction, bool up_direction, bool down_direction)
        //    void Gun::Shoot_Gun(bool direction)
    {
        //for(auto& bw : _ammo)
        //{

        this->m_gun_direction_rightwards = right_direction;
        this->m_gun_direction_backwards = left_direction;
        this->m_gun_direction_upwards = up_direction;
        this->m_gun_direction_downwards = down_direction;


        this->delay++;
        bool neutral_shot = true;
        bool pull_trigger = false;



        //std::cout << "Bullet :: " << bw->Get_Name() << std::endl;
        //std::cout << "Delay :: " << this->delay << std::endl;



            //if(!pull_trigger && neutral_shot || this->delay >= 500)
        if (this->delay >= 600)
        {
            if (this->m_gun_direction_rightwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);



                //bw->SetSpeed(10000.0f + this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);
                bw->SetSpeed(1000.0f, 0);
                neutral_shot = false;
                pull_trigger = true;
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;
                //bw->IsBulletAlive();


            }

            else if (this->m_gun_direction_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                //bw->SetSpeed(-10000.0f - this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);
                bw->SetSpeed(-1000.0f, 0);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_upwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                bw->SetSpeed(0.0f, 1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_downwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y - 10);
                bw->SetSpeed(0.0f, -1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_upwards && this->m_gun_direction_rightwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                bw->SetSpeed(1000.0f, 1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
            }

            else if (this->m_gun_direction_upwards && this->m_gun_direction_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                bw->SetSpeed(-1000.0f, 1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_downwards && this->m_gun_direction_rightwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y - 10);
                bw->SetSpeed(500.0f, -1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_downwards && this->m_gun_direction_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y - 10);
                bw->SetSpeed(-500.0f, -1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

        }
        //}


    //}





    }

    void Gun::Shoot_Gun(Bullet* bw, bool right_direction, bool left_direction, bool up_direction, bool down_direction, float x, float y)
        //    void Gun::Shoot_Gun(bool direction)
    {
        //for(auto& bw : _ammo)
        //{

        this->m_gun_direction_rightwards = right_direction;
        this->m_gun_direction_backwards = left_direction;
        this->m_gun_direction_upwards = up_direction;
        this->m_gun_direction_downwards = down_direction;


        this->delay++;
        bool neutral_shot = true;
        bool pull_trigger = false;



        //std::cout << "Bullet :: " << bw->Get_Name() << std::endl;
        //std::cout << "Delay :: " << this->delay << std::endl;



            //if(!pull_trigger && neutral_shot || this->delay >= 500)
        if (this->delay >= 600)
        {
            if (this->m_gun_direction_rightwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);



                //bw->SetSpeed(10000.0f + this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);
                bw->SetSpeed(x, y);
                neutral_shot = false;
                pull_trigger = true;
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;
                //bw->IsBulletAlive();


            }

            else if (this->m_gun_direction_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                //bw->SetSpeed(-10000.0f - this->_data->manager.Get("gun")->body->GetLinearVelocity().x, 0);
                bw->SetSpeed(-x, y);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_upwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                bw->SetSpeed(0.0f, 1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_downwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y - 10);
                bw->SetSpeed(0.0f, -1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_upwards && this->m_gun_direction_rightwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                bw->SetSpeed(1000.0f, 1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
            }

            else if (this->m_gun_direction_upwards && this->m_gun_direction_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y + 10);
                bw->SetSpeed(-1000.0f, 1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_downwards && this->m_gun_direction_rightwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y - 10);
                bw->SetSpeed(500.0f, -1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

            else if (this->m_gun_direction_downwards && this->m_gun_direction_backwards)
            {
                bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y - 10);
                bw->SetSpeed(-500.0f, -1000.0f);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;

            }

        }
        //}


    //}





    }






    void Gun::Shoot_Entities(Entity* ew, bool left, bool right)
    {

        this->m_gun_direction_rightwards = right;
        this->m_gun_direction_backwards = left;
        //this->m_gun_direction_upwards = up_direction;
        //this->m_gun_direction_downwards = down_direction;


        this->delay++;
        bool neutral_shot = true;
        bool pull_trigger = false;



        //std::cout << "Bullet :: " << bw->Get_Name() << std::endl;
        //std::cout << "Delay :: " << this->delay << std::endl;



            //if(!pull_trigger && neutral_shot || this->delay >= 500)
        if (this->delay >= 100)
        {
            if (this->m_gun_direction_rightwards)
            {


                ew->setOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                //ew->SetSpeed(1000.0f, 0);
                ew->body->SetLinearVelocity(b2Vec2(10000.0f, 0));
                neutral_shot = false;
                pull_trigger = true;
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                Set_Trigger(true);
                this->delay = 0;
                //bw->IsBulletAlive();


            }

            else if (this->m_gun_direction_backwards)
            {
                //bw->SetOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x - 10,
                //             this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                //bw->SetSpeed(-1000.0f, 0);
                //sf::sleep(sf::milliseconds(250));
                //this->m_trigger_Press = true;
                ew->setOrigin(this->_data->manager.Get(this->m_key)->body->GetPosition().x + 10,
                    this->_data->manager.Get(this->m_key)->body->GetPosition().y);
                //ew->SetSpeed(1000.0f, 0);
                ew->body->SetLinearVelocity(b2Vec2(-10000.0f, 0));


                Set_Trigger(true);
                this->delay = 0;

            }
        }


    }






}