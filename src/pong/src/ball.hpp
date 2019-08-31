#ifndef _BALL_HPP_
#define _BALL_HPP_

#include "pong_domain_export.h"
#include "position.hpp"
#include "velocity.hpp"

class PONG_DOMAIN_EXPORT ball
{
public:
	position get_center() const noexcept;
	unsigned char size() const noexcept;
	velocity get_velocity() const noexcept;
	bool is_updated() noexcept;
	void update( double delta ) noexcept;

private:
	bool updated_ = false;
};

#endif // !_BALL_HPP_
