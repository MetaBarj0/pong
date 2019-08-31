#include "paddle.hpp"

paddle::paddle() noexcept : velocity_{ 0,directions::none }
{
}

paddle_location paddle::get_location() const noexcept
{
	return paddle_location::left;
}

paddle_orientation paddle::get_orientation() const noexcept
{
	return paddle_orientation::vertical;
}

unsigned char paddle::width() const noexcept
{
	return 50u;
}

unsigned char paddle::height() const noexcept
{
	return 10u;
}

position paddle::get_center() const noexcept
{
	return {};
}

const velocity &paddle::get_velocity() const noexcept
{
	return velocity_;
}

void paddle::move_to_top() noexcept
{
	velocity_.set_direction( directions::top );
	velocity_.set_speed( 175 );
}

void paddle::move_to_bottom() noexcept
{
	velocity_.set_direction( directions::bottom );
	velocity_.set_speed( 175 );
}

void paddle::stop_moving() noexcept
{
	velocity_.set_direction( directions::none );
	velocity_.set_speed( 0 );
}

update_statuses paddle::do_update( double delta ) noexcept
{
	return update_statuses::updated;
}
