#include "playground.hpp"

unsigned short playground::width() const noexcept
{
	return 500u;
}

unsigned short playground::height() const noexcept
{
	return 500u;
}

wall playground::get_wall_by_position( wall_position position ) const noexcept
{
	return wall{ position };
}

paddle &playground::get_paddle() noexcept
{
	return paddle_;
}

position playground::get_center() const noexcept
{
	return { 250, 250 };
}

ball &playground::get_ball() noexcept
{
	return ball_;
}

update_statuses playground::do_update( double delta ) noexcept
{
	paddle_.update( delta );
	ball_.update( delta );

	return update_statuses::updated;
}