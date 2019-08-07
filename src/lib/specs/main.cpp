#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "sum_integers.hpp"

SCENARIO( "An empty vector of integers sums up to 0", "" )
{
	GIVEN( "An empty vector of integers" )
	{
		std::vector< int > empty_vector;

		THEN( "the empty vector sums up to 0" )
		{
			REQUIRE( sum_integers( empty_vector ) == 0 );
		}
	}
}
