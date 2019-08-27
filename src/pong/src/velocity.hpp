#ifndef _VELOCITY_HPP_
#define _VELOCITY_HPP_

enum class direction
{
	right,
	left,
	top_right,
	bottom_right,
	top_left,
	bottom_left
};

struct velocity
{
	const unsigned char speed = 125;
	const direction direction = direction::right;
};

#endif // !_VELOCITY_HPP_
