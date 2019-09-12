#ifndef _PADDLE_HPP_
#define _PADDLE_HPP_

#include "pong_domain_export.h"
#include "position.hpp"
#include "velocity.hpp"
#include "updatable.hpp"

class playground;

enum class paddle_location
{
	left
};

enum class paddle_orientation
{
	vertical
};

class PONG_DOMAIN_EXPORT paddle : public updatable
{
public:
	explicit paddle(const playground &playground) noexcept;

	paddle_location get_location() const noexcept;
	paddle_orientation get_orientation() const noexcept;
	unsigned char width() const noexcept;
	unsigned char height() const noexcept;
	position get_center() const noexcept;
	const velocity &get_velocity() const noexcept;
	void move_to_top() noexcept;
	void move_to_bottom() noexcept;
	void stop_moving() noexcept;

private :
	update_statuses do_update( double delta ) noexcept;

private:
	velocity velocity_;
	const playground &playground_;
};

#endif // !_PADDLE_HPP_
