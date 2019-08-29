#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "pong_export.h"

#include "playground.hpp"

class PONG_EXPORT game
{
public:
	void start() noexcept;
	bool is_running() const noexcept;
	void stop() noexcept;
	const playground &get_playground() const noexcept;

private:
	bool running = false;
	const playground playground;
};

#endif // !_GAME_HPP_