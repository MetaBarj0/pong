#include "game.hpp"

#include "SDL.h"

int SDL_main( int, char *[] )
{
	game game;

	if( game.startup() )
		game.run();

	game.shutdown();

	return 0;
}
