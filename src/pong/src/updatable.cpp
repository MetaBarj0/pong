#include "updatable.hpp"

void updatable::update( double delta ) noexcept
{
	status_ = do_update( delta );
}

bool updatable::is_updated() noexcept
{
	if( status_ == update_statuses::updated )
	{
		status_= update_statuses::not_updated;

		return true;
	}

	return false;
}
