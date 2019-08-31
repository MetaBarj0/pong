#ifndef _PLAYGROUND_HPP_
#define _PLAYGROUND_HPP_

#include "pong_domain_export.h"

#include "wall.hpp"
#include "paddle.hpp"
#include "position.hpp"
#include "ball.hpp"
#include "updatable.hpp"

class PONG_DOMAIN_EXPORT playground : public updatable
{
public:
	unsigned short width() const noexcept;
	unsigned short height() const noexcept;
	wall get_wall_by_position( wall_position position ) const noexcept;
	paddle &get_paddle() noexcept;
	position get_center() const noexcept;
	ball &get_ball() noexcept;

private :
	bool update_details( double delta ) noexcept;

private:
	paddle paddle_;
	ball ball_;
};

#endif // !_PLAYGROUND_HPP_
