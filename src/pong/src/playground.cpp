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
	return {};
}

ball &playground::get_ball() noexcept
{
	return ball_;
}

bool playground::update_details( double delta ) noexcept
{
	paddle_.update( delta );
	ball_.update( delta );

	return true;
}