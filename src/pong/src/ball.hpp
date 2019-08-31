#ifndef _BALL_HPP_
#define _BALL_HPP_

#include "pong_domain_export.h"
#include "position.hpp"
#include "velocity.hpp"
#include "updatable.hpp"

class PONG_DOMAIN_EXPORT ball : public updatable
{
public:
	position get_center() const noexcept;
	unsigned char size() const noexcept;
	velocity get_velocity() const noexcept;

private :
	update_statuses do_update( double delta ) noexcept;
};

#endif // !_BALL_HPP_
