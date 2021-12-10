#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main(int argc, char* argv[])
{

/*
	for (int i=1; i<argc; i++)
	{
		//dump_to_stdout(argv[i]);
        //dump_xml_attributes(argv[i]);
	    //test(argv[i]);

	Sekander::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine", false, argv[i]);
	//Sekander::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine", false);

	}
	*/
	Sekander::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Game Engine", true, "game_settings.xml");


	return EXIT_SUCCESS;
}
