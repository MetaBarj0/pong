#ifndef _PLAYGROUND_TESTS_HPP_
#define _PLAYGROUND_TESTS_HPP_

#include "catch.hpp"

#include "game.hpp"

TEST_CASE( "A game update triggers an unique playground update" )
{
	game the_game;

	the_game.start();

	the_game.update( 0.01 );

	REQUIRE( the_game.get_playground().is_updated() == true );
	REQUIRE( the_game.get_playground().is_updated() == false );
}

#endif // !_PLAYGROUND_TESTS_HPP_
