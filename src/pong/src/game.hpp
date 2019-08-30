#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "pong_domain_export.h"

#include "playground.hpp"

class PONG_DOMAIN_EXPORT game
{
public:
	void start() noexcept;
	bool is_running() const noexcept;
	void stop() noexcept;
	playground &get_playground() noexcept;
	void update( double delta ) noexcept;
	bool is_updated() noexcept;

private:
	bool running_ = false;
	bool updated_ = false;
	playground playground_;
};

#endif // !_GAME_HPP_