#ifndef _WALL_HPP_
#define _WALL_HPP_

#include "pong_domain_export.h"

enum class wall_position
{
	top,
	right,
	bottom
};

class PONG_DOMAIN_EXPORT wall
{
public :
	explicit wall( wall_position position ) noexcept;

	wall_position get_location() const noexcept;
	unsigned char thickness() const noexcept;

private :
	const wall_position position;
};

#endif // !_WALL_HPP_
