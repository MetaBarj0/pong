#ifndef _VELOCITY_INTEGRATOR_HPP_
#define _VELOCITY_INTEGRATOR_HPP_

#include "catch.hpp"

#include "ball.hpp"

#include <initializer_list>
#include <cmath>

TEST_CASE( "A speed of 0 induces no change in position using a velocity integrator with any direction" )
{
	playground a_playground;

	for( auto &&direction : { directions::bottom,
		 directions::bottom_left,
		 directions::bottom_right,
		 directions::left,
		 directions::none,
		 directions::right,
		 directions::top,
		 directions::top_left,
		 directions::top_right } )
		[ direction, &a_playground ]() {
		ball &a_ball = a_playground.get_ball();
		a_ball.set_velocity( { 0,direction } );

		const auto &center_before = a_ball.get_center();

		a_ball.integrate( 1 );

		REQUIRE( center_before == a_ball.get_center() );
	}( );
}

TEST_CASE( "Moving in all supported directions at specified speed change position accordingly" )
{
	SECTION( "With an existing playground containing a ball" )
	{
		playground a_playground;

		ball &a_ball = a_playground.get_ball();

		const auto center_before = a_ball.get_center();

		auto skew_delta_pos = static_cast< unsigned short >( double{ a_ball.get_velocity().get_speed() / std::sqrt( 2 ) } );

		SECTION( "Moving to the right at 125 u/s increases the x coordinate by 125" )
		{
			a_ball.set_velocity( { 125, directions::right } );

			a_ball.integrate( 1 );

			REQUIRE( center_before.x() + 125 == a_ball.get_center().x() );
			REQUIRE( center_before.y() == a_ball.get_center().y() );
		}

		SECTION( "Moving to the left at 125 u/s decreases the x coordinate by 125" )
		{
			a_ball.set_velocity( { 125, directions::left } );

			a_ball.integrate( 1 );

			REQUIRE( center_before.x() - 125 == a_ball.get_center().x() );
			REQUIRE( center_before.y() == a_ball.get_center().y() );
		}

		SECTION( "Moving to the top-left at 125 u/s decreases the x and y coordinate by 125 / sqrt( 2 )" )
		{
			a_ball.set_velocity( { 125, directions::top_left } );

			a_ball.integrate( 1 );

			REQUIRE( center_before.x() - skew_delta_pos == a_ball.get_center().x() );
			REQUIRE( center_before.y() - skew_delta_pos == a_ball.get_center().y() );
		}

		SECTION( "Moving to the top-right at 125 u/s increases the x and decreases y coordinate by 125 / sqrt( 2 )" )
		{
			a_ball.set_velocity( { 125, directions::top_right } );

			a_ball.integrate( 1 );

			REQUIRE( center_before.x() + skew_delta_pos == a_ball.get_center().x() );
			REQUIRE( center_before.y() - skew_delta_pos == a_ball.get_center().y() );
		}

		SECTION( "Moving to the bottom-right at 125 u/s increases the x and y coordinate by 125 / sqrt( 2 )" )
		{
			a_ball.set_velocity( { 125, directions::bottom_right } );

			a_ball.integrate( 1 );

			REQUIRE( center_before.x() + skew_delta_pos == a_ball.get_center().x() );
			REQUIRE( center_before.y() + skew_delta_pos == a_ball.get_center().y() );
		}

		SECTION( "Moving to the bottom-left at 125 u/s decreases the x and increases y coordinate by 125 / sqrt( 2 )" )
		{
			a_ball.set_velocity( { 125, directions::bottom_left } );

			a_ball.integrate( 1 );

			REQUIRE( center_before.x() - skew_delta_pos == a_ball.get_center().x() );
			REQUIRE( center_before.y() + skew_delta_pos == a_ball.get_center().y() );
		}
	}
}

#endif // !_VELOCITY_INTEGRATOR_HPP_
