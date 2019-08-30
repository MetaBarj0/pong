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

void game::update( double delta ) noexcept
{
	if( !running_ )
		return;

	playground_.update( delta );

	updated_ = true;
}

bool game::is_updated() noexcept
{
	if( updated_ == true )
	{
		updated_ = false;
		return true;
	}

	return updated_;
}
