#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "game.hpp"

SCENARIO( "The player starts a new game", "" )
{
	GIVEN( "The player creates a new game" )
	{
		game the_game;

		WHEN( "The new game is started" )
		{
			the_game.start();

			THEN( "The game is running" )
			{
				REQUIRE( the_game.is_running() == true );
			}
		}
	}
}
