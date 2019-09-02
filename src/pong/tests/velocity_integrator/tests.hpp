#ifndef _VELOCITY_INTEGRATOR_HPP_
#define _VELOCITY_INTEGRATOR_HPP_

#include "catch.hpp"

#include "ball.hpp"

#include <initializer_list>

TEST_CASE( "A speed of 0 induces no change in position using a velocity integrator with any direction" )
{
	for( auto &&direction : { directions::bottom,
		 directions::bottom_left,
		 directions::bottom_right,
		 directions::left,
		 directions::none,
		 directions::right,
		 directions::top,
		 directions::top_left,
		 directions::top_right } )
		[ direction ]() {
		ball a_ball;
		a_ball.set_velocity( { 0,direction } );

		const auto &center_before = a_ball.get_center();

		a_ball.integrate( 1 );

		REQUIRE( center_before == a_ball.get_center() );
	}( );
}

#endif // !_VELOCITY_INTEGRATOR_HPP_
