#include "paddle.hpp"

paddle_position paddle::get_position() const noexcept
{
	return paddle_position::left;
}

paddle_orientation paddle::get_orientation() const noexcept
{
	return paddle_orientation::vertical;
}

unsigned char paddle::width() const noexcept
{
	return 50u;
}

unsigned char paddle::height() const noexcept
{
	return 10u;
}
