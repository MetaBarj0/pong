#ifndef _PLAYGROUND_SCENARIO_HPP__
#define _PLAYGROUND_SCENARIO_HPP__

#include "catch.hpp"

#include "game.hpp"

SCENARIO( "The playground exists when the game is started" )
{
	GIVEN( "a new started game" )
	{
		game the_game;
		the_game.start();

		THEN( "The playground exists" )
		{
			const auto &playground = the_game.get_playground();
		}
	}
}

SCENARIO( "The playground has walls and is correctly sized" )
{
	GIVEN( "A started game" )
	{
		game the_game;
		the_game.start();

		WHEN( "Observing the playground" )
		{
			const auto &playground = the_game.get_playground();

			THEN( "The playground is a square of a certain size (500 arbitrary units)" )
			{
				REQUIRE( playground.width() == 500 );
				REQUIRE( playground.height() == 500 );
			}

			AND_WHEN( "Looking in all existing positions" )
			{
				const auto positions =
				{
					wall_position::top,
					wall_position::right,
					wall_position::bottom
				};

				THEN( "The playground has all its walls (top, right and bottom)" )
				{
					for( auto position : positions )
						REQUIRE( playground.get_wall_by_position( position ).get_location() == position );
				}

				THEN( "Each and every walls are 10 units thick" )
				{
					for( auto position : positions )
						REQUIRE( playground.get_wall_by_position( position ).thickness() == 10 );
				}
			}

		}
	}
}

#endif // !_PLAYGROUND_SCENARIO_HPP__
