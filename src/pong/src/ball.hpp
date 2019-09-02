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
	void set_velocity( const velocity &value ) noexcept;

private:
	update_statuses do_update( double delta ) noexcept;
	integration_statuses do_integrate( double delta ) noexcept;

private :
	velocity velocity_ = { 125, directions::right };
};

#endif // !_BALL_HPP_
