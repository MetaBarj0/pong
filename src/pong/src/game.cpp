#include "game.hpp"

void game::start() noexcept
{
	running_ = true;
}

bool game::is_running() const noexcept
{
	return running_;
}

void game::stop() noexcept
{
	running_ = false;
}

playground &game::get_playground() noexcept
{
	return playground_;
}

bool game::update_details( double delta ) noexcept
{
	if( !running_ )
		return false;

	playground_.update( delta );

	return true;
}
