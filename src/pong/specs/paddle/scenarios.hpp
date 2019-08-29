#ifndef _PADDLE_SCENARIO_HPP__
#define _PADDLE_SCENARIO_HPP__

#include "catch.hpp"

#include "game.hpp"

SCENARIO( "A paddle is in the playground when the game is started" )
{
	GIVEN( "A started game" )
	{
		game the_game;
		the_game.start();

		AND_GIVEN( "existing playground" )
		{
			const auto &playground = the_game.get_playground();

			THEN( "A paddle exists in the playground" )
			{
				const auto &paddle = playground.get_paddle();

				GIVEN( "An existing paddle in the playground" )
				{
					THEN( "The paddle is located at the left side of the playground" )
					{
						REQUIRE( paddle.get_location() == paddle_location::left );
					}

					AND_THEN( "The paddle vertically oriented" )
					{
						REQUIRE( paddle.get_orientation() == paddle_orientation::vertical );
					}

					AND_THEN( "The paddle is 50 units width and 10 units height" )
					{
						REQUIRE( paddle.width() == 50 );
						REQUIRE( paddle.height() == 10 );
					}

					AND_THEN( "The paddle position is midway of the playground" )
					{
						REQUIRE( paddle.get_center().y() == playground.get_center().y() );
					}
				}
			}
		}

	}
}

SCENARIO( "The paddle has a velocity" )
{
	GIVEN( "A started game" )
	{
		game the_game;
		the_game.start();
		const auto &playground = the_game.get_playground();

		THEN( "The paddle in the playground is standing still" )
		{
			const auto &paddle_velocity = playground.get_paddle().get_velocity();

			REQUIRE( paddle_velocity.get_speed() == 0 );
			REQUIRE( paddle_velocity.get_direction() == directions::none );
		}
	}
}

#endif // !_PADDLE_SCENARIO_HPP__
