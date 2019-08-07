#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "sum_integers.hpp"

TEST_CASE( "Sum of empty vector is 0", "[sum]" )
{
	REQUIRE( sum_integers( {} ) == 0 );
}
