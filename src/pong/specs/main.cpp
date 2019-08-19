#define CATCH_CONFIG_MAIN

#include "catch.hpp"

SCENARIO( "A scenario", "" )
{
	GIVEN( "A piece of context" )
	{
		THEN( "Something good happens" )
		{
			REQUIRE( true == true );
		}
	}
}
