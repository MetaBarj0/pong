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

bool ball::is_updated() noexcept
{
	if( updated_ == true )
	{
		updated_ = false;

		return true;
	}

	return updated_;
}

void ball::update( double delta ) noexcept
{
	updated_ = true;
}
