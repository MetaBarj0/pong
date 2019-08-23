#include "pong_export.h"

class PONG_EXPORT game
{
public :
	void start() const noexcept;
	bool is_running() const noexcept;
};