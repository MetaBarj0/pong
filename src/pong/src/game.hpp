#include "pong_export.h"

#include "playground.hpp"

class PONG_EXPORT game
{
public :
	void start() noexcept;
	bool is_running() const noexcept;
	void stop() noexcept;
	const playground &get_playground() const noexcept;

private :
	bool running = false;
	playground playground;
};