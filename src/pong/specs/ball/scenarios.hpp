#ifndef _BALL_SCENARIO_HPP__
#define _BALL_SCENARIO_HPP__

#include "catch.hpp"

#include "game.hpp"

SCENARIO( "A ball is in the playground when the game is started" )
{
	GIVEN( "A started game" )
	{
		game the_game;
		the_game.start();

		AND_GIVEN( "There is a playground" )
		{
			auto &playground = the_game.get_playground();

			THEN( "There is one ball in the playground" )
			{
				const auto &ball = playground.get_ball();

				AND_THEN( "The ball is at the center of the playground" )
				{
					REQUIRE( ball.get_center() == playground.get_center() );
				}

				AND_THEN( "The ball has a size of 10 units" )
				{
					REQUIRE( ball.size() == 10 );
				}
			}
		}
	}
}

SCENARIO( "A ball has a velocity" )
{
	GIVEN( "A ball in a game" )
	{
		game the_game;
		const auto &ball = the_game.get_playground().get_ball();

		THEN( "The ball has a velocity" )
		{
			const auto &velocity = ball.get_velocity();

			AND_THEN( "The velocity of the ball has a fixed speed of 125 units per second" )
			{
				REQUIRE( velocity.get_speed() == 125 );
			}

			AND_THEN( "The direction of the velocity of the ball is right" )
			{
				REQUIRE( velocity.get_direction() == directions::right );
			}
		}
	}
}

#endif // !_BALL_SCENARIO_HPP__
