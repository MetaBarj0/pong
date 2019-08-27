#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "game.hpp"

#include <initializer_list>

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
						paddle.get_center().y == playground.get_center().y;
					}
				}
			}
		}

	}
}
