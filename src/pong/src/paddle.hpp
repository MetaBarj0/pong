#ifndef _PADDLE_HPP_
#define _PADDLE_HPP_

#include "pong_export.h"
#include "position.hpp"

enum class paddle_location
{
	left
};

enum class paddle_orientation
{
	vertical
};

class PONG_EXPORT paddle
{
public:
	paddle_location get_location() const noexcept;
	paddle_orientation get_orientation() const noexcept;
	unsigned char width() const noexcept;
	unsigned char height() const noexcept;
	position get_center() const noexcept;
};

#endif // !_PADDLE_HPP_