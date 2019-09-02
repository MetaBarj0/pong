#include "integratable.hpp"

void integratable::integrate( double delta ) noexcept
{
	status_ = do_integrate( delta );
}

bool integratable::is_integrated() noexcept
{
	if( status_ == integration_statuses::integrated )
	{
		status_ = integration_statuses::not_integrated;

		return true;
	}

	return false;
}
