#ifndef _BALL_HPP_
#define _BALL_HPP_

#include "pong_export.h"
#include "position.hpp"
#include "velocity.hpp"

class PONG_EXPORT ball
{
public :
	position get_center() const noexcept;
	unsigned char size() const noexcept;
	velocity get_velocity() const noexcept;
};

#endif // !_BALL_HPP_
