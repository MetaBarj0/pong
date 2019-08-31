#ifndef _PADDLE_TESTS_HPP_
#define _PADDLE_TESTS_HPP_

#include "catch.hpp"

#include "game.hpp"

TEST_CASE( "A playground update triggers an unique paddle update" )
{
	game the_game;
	the_game.start();
	the_game.update( 0.01 );

	auto &paddle = the_game.get_playground().get_paddle();

	REQUIRE( paddle.is_updated() == true );
	REQUIRE( paddle.is_updated() == false );
}

#endif // !_PADDLE_TESTS_HPP_
