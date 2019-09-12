#include "ball.hpp"
#include "playground.hpp"

ball::ball( const playground &playground ) noexcept : velocity_{ 125, directions::right }, playground_{ playground } {}

position ball::get_center() const noexcept
{
	return playground_.get_center();
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
	return integration_statuses::integrated;
}
