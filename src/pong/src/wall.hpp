#include "pong_export.h"

enum class wall_position
{
	top,
	right,
	bottom
};

class PONG_EXPORT wall
{
public :
	wall( wall_position position ) noexcept;

	wall_position get_position() const noexcept;
	unsigned char thickness() const noexcept;

private :
	wall_position position;
};
