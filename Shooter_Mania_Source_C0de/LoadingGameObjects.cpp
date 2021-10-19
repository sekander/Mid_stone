// tutorial demo program
#include "LoadingGameObjects.hpp"
#include <stdio.h>
#include <iostream>

// ----------------------------------------------------------------------
// STDOUT dump and indenting utility functions
// ----------------------------------------------------------------------

namespace Sekander {


    LoadingGameObjects::LoadingGameObjects(GameDataRef data) : _data(data)
    {

    }

    void LoadingGameObjects::Load_XML_SPLASH_SCREEN(const char* fileName)
    {
        TiXmlDocument   doc(fileName);
        GameWorld* gw;

        if (doc.LoadFile())
        {

            TiXmlElement* pRoot, * pBody, * pParms, * pProcess, * pApp, * pLineFormat, * pParm;
            pRoot = doc.FirstChildElement("Splash_State");
            if (pRoot)
            {
                pBody = pRoot->FirstChildElement("body"); //body should be read
                //while(pBody){
                if (pBody) {
                    //pParms= pBody->FirstChildElement( "gw" ); //now params
                    //pParms= pBody->FirstChildElement( "gw" ); //now param

                    if (pParms = pBody->FirstChildElement("tx"))
                    {


                        pParm = pParms->FirstChildElement("param");
                        while (pParm) {

                            std::cout << "SPLASH STATE GW::key = " << pParm->Attribute("key") << std::endl;

                            sfe = new sf::Sprite();


                            this->_data->assets.LoadTexture(pParm->Attribute("key"), pParm->Attribute("file_name"));
                            sfe->setTexture(this->_data->assets.GetTexture(pParm->Attribute("key")));
                            sfe->setTextureRect(sf::IntRect(
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT"))

                            ));
                            sfe->setPosition(std::stof(pParm->Attribute("sprite_X_POS")), std::stof(pParm->Attribute("sprite_Y_POS")));

                            this->_sprite_Objects.insert(std::make_pair(pParm->Attribute("key"), sfe));



                            pParm = pParm->NextSiblingElement("param");

                        }
                    }
                }
            }

        }


    }

    void LoadingGameObjects::Load_XML_MENU_SCREEN(const char* fileName)
    {
        TiXmlDocument   doc(fileName);
        GameWorld* gw;

        if (doc.LoadFile())
        {

            TiXmlElement* pRoot, * pBody, * pParms, * pProcess, * pApp, * pLineFormat, * pParm;
            pRoot = doc.FirstChildElement("Main_Menu_State");
            if (pRoot)
            {
                pBody = pRoot->FirstChildElement("body"); //body should be read
                //while(pBody){
                if (pBody) {
                    //pParms= pBody->FirstChildElement( "gw" ); //now params
                    //pParms= pBody->FirstChildElement( "gw" ); //now param

                    if (pParms = pBody->FirstChildElement("tx"))
                    {


                        pParm = pParms->FirstChildElement("param");
                        while (pParm) {

                            std::cout << "MENU STATE GW::key = " << pParm->Attribute("key") << std::endl;

                            sfe = new sf::Sprite();


                            this->_data->assets.LoadTexture(pParm->Attribute("key"), pParm->Attribute("file_name"));
                            sfe->setTexture(this->_data->assets.GetTexture(pParm->Attribute("key")));
                            sfe->setTextureRect(sf::IntRect(
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT"))

                            ));
                            sfe->setPosition(std::stof(pParm->Attribute("sprite_X_POS")), std::stof(pParm->Attribute("sprite_Y_POS")));

                            //this->_sprite_Objects.insert(std::make_pair(pParm->Attribute("key"), sfe));
                            this->mm_sprite_Objects.insert(std::make_pair(pParm->Attribute("key"), sfe));


                            pParm = pParm->NextSiblingElement("param");

                        }
                    }


                    if (pParms = pBody->FirstChildElement("gw"))
                    {


                        pParm = pParms->FirstChildElement("param");
                        while (pParm) {


                            // now loop al param elements and get their attributes
                            std::cout << "GW::key = " << pParm->Attribute("key") << std::endl;

                            gw = new GameWorld(_data, pParm->Attribute("key"),
                                pParm->Attribute("file_name"),
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT")),
                                //(std::stoi(pParm->Attribute("dynamic")).c_str()),




                                //(bool)(pParm->Attribute("dynamic")),
                                false,
                                std::stoi(pParm->Attribute("sprite_X_FRAMES")),
                                std::stoi(pParm->Attribute("sprite_Y_FRAMES")),
                                std::stof(pParm->Attribute("sprite_X_POS")),
                                std::stof(pParm->Attribute("sprite_Y_POS")),
                                std::stof(pParm->Attribute("sprite_ANGLE"))
                            );
                            this->_gameObjects.insert(std::make_pair(pParm->Attribute("key"), gw));

                            // ListAllGameObjects();

                             //this->_data->manager.Add(pParm->Attribute("key"), gw(Entity));




                            pParm = pParm->NextSiblingElement("param");
                        }
                    }






                }
            }

        }

    }


    void LoadingGameObjects::Load_XML_PLAY_SCREEN(const char* fileName)
    {

        TiXmlDocument   doc(fileName);
        GameWorld* gw;
        Main_Player* mpw;
        Bullet* bw;
        Gun* gun;


        if (doc.LoadFile())
        {
            TiXmlElement* pRoot, * pBody, * pParms, * pProcess, * pApp, * pLineFormat, * pParm;
            pRoot = doc.FirstChildElement("GameWorld");
            if (pRoot)
            {
                pBody = pRoot->FirstChildElement("body"); //body should be read
                //while(pBody){
                if (pBody) {
                    //pParms= pBody->FirstChildElement( "gw" ); //now params
                    //pParms= pBody->FirstChildElement( "gw" ); //now params




                    if (pParms = pBody->FirstChildElement("gw"))
                    {


                        pParm = pParms->FirstChildElement("param");
                        while (pParm) {


                            // now loop al param elements and get their attributes
                            std::cout << "GW::key = " << pParm->Attribute("key") << std::endl;

                            gw = new GameWorld(_data, pParm->Attribute("key"),
                                pParm->Attribute("file_name"),
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT")),
                                //(std::stoi(pParm->Attribute("dynamic")).c_str()),




                                //(bool)(pParm->Attribute("dynamic")),
                                false,
                                std::stoi(pParm->Attribute("sprite_X_FRAMES")),
                                std::stoi(pParm->Attribute("sprite_Y_FRAMES")),
                                std::stof(pParm->Attribute("sprite_X_POS")),
                                std::stof(pParm->Attribute("sprite_Y_POS")),
                                std::stof(pParm->Attribute("sprite_ANGLE"))
                            );
                            this->_gameObjects.insert(std::make_pair(pParm->Attribute("key"), gw));

                            // ListAllGameObjects();

                             //this->_data->manager.Add(pParm->Attribute("key"), gw(Entity));




                            pParm = pParm->NextSiblingElement("param");
                        }
                    }

                    std::cout << "DO I GET HERE" << std::endl;


                    //Future different gameobjects 
                    if (pParms = pBody->FirstChildElement("pw"))
                    {
                        pParm = pParms->FirstChildElement("param");

                        while (pParm)
                        {
                            std::cout << "PW::key    =" << pParm->Attribute("key") << std::endl;


                            mpw = new Main_Player(_data, pParm->Attribute("key"),
                                pParm->Attribute("file_name"),
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT")),
                                //(bool)(pParm->Attribute("dynamic")),
                                true,
                                std::stoi(pParm->Attribute("sprite_X_FRAMES")),
                                std::stoi(pParm->Attribute("sprite_Y_FRAMES")),
                                std::stof(pParm->Attribute("sprite_X_POS")),
                                std::stof(pParm->Attribute("sprite_Y_POS")),
                                std::stof(pParm->Attribute("sprite_ANGLE"))

                            );

                            this->_playerObjects.insert(std::make_pair(pParm->Attribute("key"), mpw));
                            //this->_data->manager.Add()
                            pParm = pParm->NextSiblingElement("param");
                        }
                    }



                    if (pParms = pBody->FirstChildElement("bw"))
                    {
                        pParm = pParms->FirstChildElement("param");

                        while (pParm)
                        {
                            std::cout << "BW::key    =" << pParm->Attribute("key") << std::endl;

                            //int counter = 0;
                            ////int max_bullets = 100;
//
                            std::string string_key_name = pParm->Attribute("key");
                            std::string file_name = pParm->Attribute("file_name");
                            int source_x = std::stoi(pParm->Attribute("source_x"));
                            int source_y = std::stoi(pParm->Attribute("source_y"));
                            int sprie_width = std::stoi(pParm->Attribute("sprite_WIDTH"));
                            int sprite_height = std::stoi(pParm->Attribute("sprite_HEIGHT"));
                            int sprite_x_frames = std::stoi(pParm->Attribute("sprite_X_FRAMES"));
                            int sprite_y_frames = std::stoi(pParm->Attribute("sprite_Y_FRAMES"));
                            float x_pos = std::stof(pParm->Attribute("sprite_X_POS"));
                            float y_pos = std::stof(pParm->Attribute("sprite_Y_POS"));
                            float angle = std::stof(pParm->Attribute("sprite_ANGLE"));
                            //
                            //
                            populate_bullets(50,
                                string_key_name,
                                file_name,
                                source_x,
                                source_y,
                                sprie_width,
                                sprite_height,
                                sprite_x_frames,
                                sprite_y_frames,
                                x_pos,
                                y_pos,
                                angle);

                            //bw = new Bullet(_data, pParm->Attribute("key"),
                            //                          pParm->Attribute("file_name"),
                            //                          std::stoi(pParm->Attribute("source_x")),
                            //                          std::stoi(pParm->Attribute("source_y")),
                            //                          std::stoi(pParm->Attribute("sprite_WIDTH")),
                            //                          std::stoi(pParm->Attribute("sprite_HEIGHT")),
                            //                          //(bool)(pParm->Attribute("dynamic")),
                            //                          true,
                            //                          std::stoi(pParm->Attribute("sprite_X_FRAMES")),
                            //                          std::stoi(pParm->Attribute("sprite_Y_FRAMES")),
                            //                          std::stof(pParm->Attribute("sprite_X_POS")),
                            //                          std::stof(pParm->Attribute("sprite_Y_POS")),
                            //                          std::stof(pParm->Attribute("sprite_ANGLE"))   
                            //                    );
//
                                //this->_bullet_s.insert(std::make_pair(pParm->Attribute("key"), bw));



                            pParm = pParm->NextSiblingElement("param");
                        }

                    }



                    if (pParms = pBody->FirstChildElement("e_bw"))
                    {
                        pParm = pParms->FirstChildElement("param");

                        while (pParm)
                        {
                            std::cout << "BW::key    =" << pParm->Attribute("key") << std::endl;

                            //int counter = 0;
                            ////int max_bullets = 100;
//
                            std::string string_key_name = pParm->Attribute("key");
                            std::string file_name = pParm->Attribute("file_name");
                            int source_x = std::stoi(pParm->Attribute("source_x"));
                            int source_y = std::stoi(pParm->Attribute("source_y"));
                            int sprie_width = std::stoi(pParm->Attribute("sprite_WIDTH"));
                            int sprite_height = std::stoi(pParm->Attribute("sprite_HEIGHT"));
                            int sprite_x_frames = std::stoi(pParm->Attribute("sprite_X_FRAMES"));
                            int sprite_y_frames = std::stoi(pParm->Attribute("sprite_Y_FRAMES"));
                            float x_pos = std::stof(pParm->Attribute("sprite_X_POS"));
                            float y_pos = std::stof(pParm->Attribute("sprite_Y_POS"));
                            float angle = std::stof(pParm->Attribute("sprite_ANGLE"));
                            //
                            //
                            populate_enemy_bullets(50,
                                string_key_name,
                                file_name,
                                source_x,
                                source_y,
                                sprie_width,
                                sprite_height,
                                sprite_x_frames,
                                sprite_y_frames,
                                x_pos,
                                y_pos,
                                angle);

                            //bw = new Bullet(_data, pParm->Attribute("key"),
                            //                          pParm->Attribute("file_name"),
                            //                          std::stoi(pParm->Attribute("source_x")),
                            //                          std::stoi(pParm->Attribute("source_y")),
                            //                          std::stoi(pParm->Attribute("sprite_WIDTH")),
                            //                          std::stoi(pParm->Attribute("sprite_HEIGHT")),
                            //                          //(bool)(pParm->Attribute("dynamic")),
                            //                          true,
                            //                          std::stoi(pParm->Attribute("sprite_X_FRAMES")),
                            //                          std::stoi(pParm->Attribute("sprite_Y_FRAMES")),
                            //                          std::stof(pParm->Attribute("sprite_X_POS")),
                            //                          std::stof(pParm->Attribute("sprite_Y_POS")),
                            //                          std::stof(pParm->Attribute("sprite_ANGLE"))   
                            //                    );
//
                                //this->_bullet_s.insert(std::make_pair(pParm->Attribute("key"), bw));



                            pParm = pParm->NextSiblingElement("param");
                        }

                    }

                    if (pParms = pBody->FirstChildElement("gun"))
                    {
                        pParm = pParms->FirstChildElement("param");

                        while (pParm)
                        {
                            std::cout << "GUN::key    =" << pParm->Attribute("key") << std::endl;


                            gun = new Gun(_data, pParm->Attribute("key"),
                                pParm->Attribute("file_name"),
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT")),
                                //(bool)(pParm->Attribute("dynamic")),
                                true,
                                std::stoi(pParm->Attribute("sprite_X_FRAMES")),
                                std::stoi(pParm->Attribute("sprite_Y_FRAMES")),
                                std::stof(pParm->Attribute("sprite_X_POS")),
                                std::stof(pParm->Attribute("sprite_Y_POS")),
                                std::stof(pParm->Attribute("sprite_ANGLE"))
                            );

                            this->_gun_Objects.insert(std::make_pair(pParm->Attribute("key"), gun));
                            //this->_data->manager.Add()
                            pParm = pParm->NextSiblingElement("param");
                        }
                    }


                    if (pParms = pBody->FirstChildElement("em"))
                    {
                        pParm = pParms->FirstChildElement("param");

                        while (pParm)
                        {
                            std::cout << "Enemy::key    =" << pParm->Attribute("key") << std::endl;


                            Enemy* em = new Enemy(_data, pParm->Attribute("key"),
                                pParm->Attribute("file_name"),
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT")),
                                //(bool)(pParm->Attribute("dynamic")),
                                true,
                                std::stoi(pParm->Attribute("sprite_X_FRAMES")),
                                std::stoi(pParm->Attribute("sprite_Y_FRAMES")),
                                std::stof(pParm->Attribute("sprite_X_POS")),
                                std::stof(pParm->Attribute("sprite_Y_POS")),
                                std::stof(pParm->Attribute("sprite_ANGLE")),
                                std::stoi(pParm->Attribute("enemy_walking_distance")),
                                std::stof(pParm->Attribute("attack_square_x")),
                                std::stof(pParm->Attribute("attack_square_y")),
                                std::stof(pParm->Attribute("bullet_speed_x")),
                                std::stof(pParm->Attribute("bullet_speed_y")),
                                std::stof(pParm->Attribute("enemy_speed_x")),
                                std::stof(pParm->Attribute("enemy_speed_y"))
                                //std::stof(pParm->Attribute("enemy_attack_square_x")),
                                //std::stof(pParm->Attribute("enemy_attack_square_y"))

                            );

                            this->_enemy_Objects.insert(std::make_pair(pParm->Attribute("key"), em));
                            //this->_data->manager.Add()
                            pParm = pParm->NextSiblingElement("param");
                        }
                    }








                }
            }
        }
    }

    void LoadingGameObjects::Load_XML_GAME_OVER_SCREEN(const char* fileName)
    {

        TiXmlDocument   doc(fileName);
        GameWorld* gw;

        if (doc.LoadFile())
        {

            TiXmlElement* pRoot, * pBody, * pParms, * pProcess, * pApp, * pLineFormat, * pParm;
            pRoot = doc.FirstChildElement("Game_Over_State");
            if (pRoot)
            {
                pBody = pRoot->FirstChildElement("body"); //body should be read
                //while(pBody){
                if (pBody) {
                    //pParms= pBody->FirstChildElement( "gw" ); //now params
                    //pParms= pBody->FirstChildElement( "gw" ); //now param

                    if (pParms = pBody->FirstChildElement("tx"))
                    {


                        pParm = pParms->FirstChildElement("param");
                        while (pParm) {

                            std::cout << "GAME OVER STATE GW::key = " << pParm->Attribute("key") << std::endl;


                            sfe = new sf::Sprite();

                            this->_data->assets.LoadTexture(pParm->Attribute("key"), pParm->Attribute("file_name"));
                            sfe->setTexture(this->_data->assets.GetTexture(pParm->Attribute("key")));
                            sfe->setTextureRect(sf::IntRect(
                                std::stoi(pParm->Attribute("source_x")),
                                std::stoi(pParm->Attribute("source_y")),
                                std::stoi(pParm->Attribute("sprite_WIDTH")),
                                std::stoi(pParm->Attribute("sprite_HEIGHT"))

                            ));

                            sfe->setPosition(std::stof(pParm->Attribute("sprite_X_POS")), std::stof(pParm->Attribute("sprite_Y_POS")));

                            this->_sprite_Objects.insert(std::make_pair(pParm->Attribute("key"), sfe));



                            //this->_gameObjects.insert(std::make_pair(pParm->Attribute("key"), gw));

                           // ListAllGameObjects();

                            //this->_data->manager.Add(pParm->Attribute("key"), gw(Entity));




                            pParm = pParm->NextSiblingElement("param");

                        }
                    }
                }
            }

        }



    }





    GameWorld* LoadingGameObjects::Get(const char* name)
    {
        std::unordered_map<const char*, GameWorld*>::const_iterator found = this->_gameObjects.find(name);

        if (found == this->_gameObjects.end())
        {
            return NULL;
        }
        else
        {
            return found->second;
        }
    }

    Main_Player* LoadingGameObjects::Get_PLAYER(const char* name)
    {
        std::unordered_map<const char*, Main_Player*>::const_iterator found = this->_playerObjects.find(name);

        if (found == this->_playerObjects.end())
        {
            return NULL;
        }
        else
        {
            return found->second;
        }
    }


    void LoadingGameObjects::ListAllGameObjects()
    {
        std::unordered_map<const char*, GameWorld*>::iterator it = _gameObjects.begin();
        while (it != _gameObjects.end())
        {
            std::cout << it->first << " :: " << it->second << std::endl;
            it++;
        }
    }


    //void LoadingGameObjects::Render()}{}
    //void LoadingGameObjects::Update()}{}


    void LoadingGameObjects::Update(float dt)
    {
        //    ListAllGameObjects();

    }












    LoadingGameObjects::~LoadingGameObjects()
    {
        for (auto& iterator : this->_gameObjects)
        {
            delete iterator.second;
        }
        this->_gameObjects.clear();
    }













}