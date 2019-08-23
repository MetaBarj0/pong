#include "wall.hpp"

wall::wall( wall_position position ) noexcept : position{ position }
{
}

wall_position wall::get_position() const noexcept
{
	return position;
}

unsigned char wall::thickness() const noexcept
{
	return 10u;
}
