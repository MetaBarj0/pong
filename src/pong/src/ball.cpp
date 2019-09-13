#include "ball.hpp"
#include "playground.hpp"

#include <cmath>

ball::ball( const playground &playground ) noexcept : velocity_{ 125, directions::right }, playground_{ playground }, position_{ playground_.get_center() } {}

const position &ball::get_center() const noexcept
{
	return position_;
}

unsigned char ball::size() const noexcept
{
	return 10u;
}

velocity ball::get_velocity() const noexcept
{
	return velocity_;
}

void ball::set_velocity( const velocity &value ) noexcept
{
	velocity_ = value;
}

update_statuses ball::do_update( double delta ) noexcept
{
	integrate( delta );

	return update_statuses::updated;
}

integration_statuses ball::do_integrate( double delta ) noexcept
{
	const auto direction = velocity_.get_direction();

	auto delta_x = velocity_.get_speed() / delta;
	auto delta_y = velocity_.get_speed() / delta;

	if( direction == directions::left )
	{
		delta_x *= -1;
		delta_y = 0;
	}
	if( direction == directions::right )
	{
		delta_x *= 1;
		delta_y = 0;
	}
	else if( direction == directions::top_left )
	{
		delta_x *= -1 / std::sqrt( 2 );
		delta_y *= -1 / std::sqrt( 2 );
	}
	else if( direction == directions::top_right )
	{
		delta_x *= 1 / std::sqrt( 2 );
		delta_y *= -1 / std::sqrt( 2 );
	}
	else if( direction == directions::bottom_right )
	{
		delta_x *= 1 / std::sqrt( 2 );
		delta_y *= 1 / std::sqrt( 2 );
	}
	else if( direction == directions::bottom_left )
	{
		delta_x *= -1 / std::sqrt( 2 );
		delta_y *= 1 / std::sqrt( 2 );
	}

	position_.x( position_.x() + static_cast< unsigned short >( delta_x ) );
	position_.y( position_.y() + static_cast< unsigned short >( delta_y ) );

	return integration_statuses::integrated;
}
