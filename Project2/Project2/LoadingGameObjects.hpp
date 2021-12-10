// tutorial demo program
#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"


//#include "GameWorld.hpp"

#include "Main_Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

#include <tinyxml.h>

// ----------------------------------------------------------------------
// STDOUT dump and indenting utility functions
// ----------------------------------------------------------------------
namespace Sekander {



    class LoadingGameObjects
    {



    public:
        LoadingGameObjects(GameDataRef data);
        ~LoadingGameObjects();

        void Load_XML_SPLASH_SCREEN(const char* fileName);
        void Load_XML_MENU_SCREEN(const char* fileName);
        void Load_XML_PLAY_SCREEN(const char* fileName);
        void Load_XML_GAME_OVER_SCREEN(const char* fileName);


        void Update(float dt);

        GameWorld* Get(const char* name);
        Main_Player* Get_PLAYER(const char* name);
        void ListAllGameObjects();


        std::unordered_map<const char*, GameWorld*> Get_Game_objects_Map() {
            return _gameObjects;
        }
        std::unordered_map<const char*, Main_Player*> Get_Player_Map() {
            return _playerObjects;
        }

        std::unordered_map<std::string, Bullet*> Get_Bullet_Map() {
            return _bullet_s;
        }

        std::unordered_map<std::string, Bullet*> Get_Enemy_Bullet_Map() {
            return enemy_bullet_s;
        }


        std::unordered_map<const char*, Gun*> Get_Gun_Map() {
            return _gun_Objects;
        }

        std::unordered_map<const char*, sf::Sprite*> Get_Sprie_Map()
        {
            return _sprite_Objects;
        }

        std::unordered_map<std::string, sf::Sprite*> sdGet_Sprie_Map()
        {
            return mm_sprite_Objects;
        }



        std::unordered_map<const char*, Enemy*> Get_Enemy_Map()
        {
            return _enemy_Objects;
        }

        void populate_bullets(int max, std::string string_key_name,
            std::string file_name,
            int source_x,
            int source_y,
            int sprite_width,
            int sprite_height,
            int sprite_x_frames,
            int sprite_y_frames,
            float x_pos,
            float y_pos,
            float angle)
        {

            int counter = 0;
            std::string temp_string;

            while (counter < max)
            {
                std::string s = std::to_string(counter);

                temp_string = string_key_name;
                //string_key_name = string_key_name + "_"  + s;
                string_key_name = string_key_name + s;
                //std::cout << "Bullet Object : " << string_key_name 
                ////<< file_name
                //<< std::endl;



                _bullet_s.insert(std::make_pair(string_key_name, new Bullet(_data,
                    string_key_name,
                    file_name,
                    source_x,
                    source_y,
                    sprite_width,
                    sprite_height,
                    true,
                    sprite_x_frames,
                    sprite_y_frames,
                    x_pos + 10 * counter,
                    y_pos + 10 * counter,
                    angle)));

                string_key_name = temp_string;
                //this->_data->manager.A

              //  pParm=pParm->NextSiblingElement("param");

                counter++;


            }

            std::cout << "SIZE OF BULLET LIST : " << _bullet_s.size() << std::endl;
            //std::cout << "SIZE OF TEST : " << some.size() << std::endl;
            std::cout << "SIZE OF Bullets  : " << bullets.size() << std::endl;

        }

        void populate_enemy_bullets(int max, std::string string_key_name,
            std::string file_name,
            int source_x,
            int source_y,
            int sprite_width,
            int sprite_height,
            int sprite_x_frames,
            int sprite_y_frames,
            float x_pos,
            float y_pos,
            float angle)
        {

            int counter = 0;
            std::string temp_string;

            while (counter < max)
            {
                std::string s = std::to_string(counter);

                temp_string = string_key_name;
                //string_key_name = string_key_name + "_"  + s;
                string_key_name = string_key_name + s;
                //std::cout << "Bullet Object : " << string_key_name 
                ////<< file_name
                //<< std::endl;



                enemy_bullet_s.insert(std::make_pair(string_key_name, new Bullet(_data,
                    string_key_name,
                    file_name,
                    source_x,
                    source_y,
                    sprite_width,
                    sprite_height,
                    true,
                    sprite_x_frames,
                    sprite_y_frames,
                    x_pos + 10 * counter,
                    y_pos + 10 * counter,
                    angle)));

                string_key_name = temp_string;
                //this->_data->manager.A

              //  pParm=pParm->NextSiblingElement("param");

                counter++;


            }

            std::cout << "SIZE OF BULLET LIST : " << _bullet_s.size() << std::endl;
            //std::cout << "SIZE OF TEST : " << some.size() << std::endl;
            std::cout << "SIZE OF Bullets  : " << bullets.size() << std::endl;

        }




    private:
        GameDataRef _data;
        //std::vector<GameWorld> _gameObjects;
        std::unordered_map<const char*, GameWorld*> _gameObjects;
        std::unordered_map<const char*, Main_Player*> _playerObjects;
        //std::unordered_map<std::string, Bullet*> _bullet_Objects;
        std::unordered_map<std::string, Bullet*> _bullet_s;
        std::unordered_map<std::string, Bullet*> enemy_bullet_s;

        std::unordered_map<const char*, Gun*> _gun_Objects;
        std::unordered_map<const char*, Enemy*> _enemy_Objects;


        std::unordered_map<const char*, sf::Sprite*> _sprite_Objects;
        std::unordered_map<std::string, sf::Sprite*> mm_sprite_Objects;


        sf::Sprite* sfe;

        std::vector<std::string> some;
        std::vector<Bullet*> bullets;
        //GameWorld *gw[];w


        sf::RectangleShape* debug;


        const char* _fileName;


        //  TiXmlElement *pParms;





    };

}