#ifndef _VELOCITY_HPP_
#define _VELOCITY_HPP_

#include "pong_export.h"

enum class directions
{
	right,
	left,
	top_right,
	bottom_right,
	top_left,
	bottom_left,
	top,
	bottom,
	none
};

class PONG_EXPORT velocity
{
public:
	velocity( unsigned char speed_value, directions direction_value ) noexcept;

	unsigned char get_speed() const noexcept;
	void set_speed( unsigned char value ) noexcept;
	directions get_direction() const noexcept;
	void set_direction( directions value ) noexcept;

private:
	unsigned char speed = 0;
	directions direction = directions::right;
};

#endif // !_VELOCITY_HPP_
