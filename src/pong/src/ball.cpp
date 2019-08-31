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

bool ball::update_details( double delta ) noexcept
{
	return true;
}
