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
			const auto &playground = the_game.get_playground();

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

#endif // !_BALL_SCENARIO_HPP__
