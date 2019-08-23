#include "pong_export.h"

#include "wall.hpp"
#include "paddle.hpp"

class PONG_EXPORT playground
{
public:
	unsigned short width() const noexcept;
	unsigned short height() const noexcept;
	wall get_wall_by_position( wall_position position ) const noexcept;
	paddle get_paddle() const noexcept;
};
