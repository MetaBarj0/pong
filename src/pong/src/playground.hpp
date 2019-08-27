#ifndef _PLAYGROUND_HPP_
#define _PLAYGROUND_HPP_

#include "pong_export.h"

#include "wall.hpp"
#include "paddle.hpp"
#include "position.hpp"

class PONG_EXPORT playground
{
public:
	unsigned short width() const noexcept;
	unsigned short height() const noexcept;
	wall get_wall_by_position( wall_position position ) const noexcept;
	paddle get_paddle() const noexcept;
	position get_center() const noexcept;
};

#endif // !_PLAYGROUND_HPP_
