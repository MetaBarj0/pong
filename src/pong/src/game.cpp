#include "game.hpp"

void game::start() noexcept
{
	running = true;
}

bool game::is_running() const noexcept
{
	return running;
}

void game::stop() noexcept
{
	running = false;
}

const playground &game::get_playground() const noexcept
{
	return playground;
}
