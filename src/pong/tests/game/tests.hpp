#ifndef _GAME_TESTS_HPP_
#define _GAME_TESTS_HPP_

#include "catch.hpp"

#include "game.hpp"

TEST_CASE( "A running game can be updated each fraction of seconds" )
{
	game the_game;
	the_game.start();

	the_game.update( 0.01 );

	REQUIRE( the_game.is_updated() == true );
}

TEST_CASE( "A running game update updates the game only once" )
{
	game the_game;

	the_game.start();
	the_game.update( 0.01 );

	REQUIRE( the_game.is_updated() == true );
	REQUIRE( the_game.is_updated() == false );
	REQUIRE( the_game.is_updated() == false );
}

TEST_CASE( "A stopped game cannot be updated" )
{
	game the_game;

	REQUIRE( the_game.is_running() == false );

	the_game.update( 0.01 );

	REQUIRE( the_game.is_updated() == false );
	REQUIRE( the_game.is_updated() == false );
}

#endif // !_GAME_TESTS_HPP_
