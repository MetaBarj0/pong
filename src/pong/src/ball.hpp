#ifndef _BALL_HPP_
#define _BALL_HPP_

#include "pong_domain_export.h"
#include "position.hpp"
#include "velocity.hpp"
#include "updatable.hpp"
#include "integratable.hpp"

class PONG_DOMAIN_EXPORT ball : public updatable, public integratable
{
public:
	position get_center() const noexcept;
	unsigned char size() const noexcept;
	velocity get_velocity() const noexcept;

private:
	update_statuses do_update( double delta ) noexcept;
	integration_statuses do_integrate() noexcept;
};

#endif // !_BALL_HPP_
