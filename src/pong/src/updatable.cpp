#include "updatable.hpp"

void updatable::update( double delta ) noexcept
{
	updated_ = update_details( delta );
}

bool updatable::is_updated() noexcept
{
	if( updated_ == true )
	{
		updated_ = false;

		return true;
	}

	return updated_;
}
