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

update_statuses game::do_update( double delta ) noexcept
{
	if( !running_ )
		return update_statuses::not_updated;

	playground_.update( delta );

	return update_statuses::updated;
}
