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

paddle playground::get_paddle() const noexcept
{
	return {};
}

position playground::get_center() const noexcept
{
	return {};
}

ball playground::get_ball() const noexcept
{
	return {};
}

void playground::update( double delta ) noexcept
{
	updated_ = true;
}

bool playground::is_updated() noexcept
{
	if( updated_ == true )
	{
		updated_ = false;

		return true;
	}

	return updated_;
}