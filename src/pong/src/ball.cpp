#include "ball.hpp"

position ball::get_center() const noexcept
{
	return {};
}

unsigned char ball::size() const noexcept
{
	return 10u;
}

velocity ball::get_velocity() const noexcept
{
	return { 125, directions::right };
}

update_statuses ball::do_update( double delta ) noexcept
{
	return update_statuses::updated;
}
