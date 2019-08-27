#ifndef _GAME_SCENARIO_HPP__
#define _GAME_SCENARIO_HPP__

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

SCENARIO( "The player stops the game" )
{
	GIVEN( "A running game" )
	{
		game the_game;
		the_game.start();

		REQUIRE( the_game.is_running() == true );

		WHEN( "The player stops the game" )
		{
			the_game.stop();

			THEN( "The game is stopped" )
			{
				REQUIRE( the_game.is_running() == false );
			}
		}
	}
}

#endif // !_GAME_SCENARIO_HPP__
