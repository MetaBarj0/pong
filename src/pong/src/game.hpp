#ifndef _GAME_HPP_
#define _GAME_HPP_

#include "pong_domain_export.h"

#include "playground.hpp"
#include "updatable.hpp"

class PONG_DOMAIN_EXPORT game : public updatable
{
public:
	void start() noexcept;
	bool is_running() const noexcept;
	void stop() noexcept;
	playground &get_playground() noexcept;

private:
	update_statuses do_update( double delta ) noexcept;

private:
	bool running_ = false;
	playground playground_;
};

#endif // !_GAME_HPP_