#ifndef _BALL_TESTS_HPP_
#define _BALL_TESTS_HPP_

#include "catch.hpp"

#include "game.hpp"

TEST_CASE( "A playground update triggers an unique ball update" )
{
	game the_game;
	the_game.start();
	the_game.update( 0.01 );

	auto &ball = the_game.get_playground().get_ball();

	REQUIRE( ball.is_updated() == true );
	REQUIRE( ball.is_updated() == false );
}

TEST_CASE( "A ball update triggers an unique ball physics integration" )
{
	game the_game;
	the_game.start();
	the_game.update( 0.01 );

	auto &ball = the_game.get_playground().get_ball();

	REQUIRE( ball.is_updated() == true );
	REQUIRE( ball.is_integrated() == true );
	REQUIRE( ball.is_integrated() == false );
}

#endif // !_BALL_TESTS_HPP_
