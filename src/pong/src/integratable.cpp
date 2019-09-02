#include "integratable.hpp"

void integratable::integrate() noexcept
{
	status_ = do_integrate();
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
