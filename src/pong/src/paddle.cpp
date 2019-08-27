#include "paddle.hpp"

paddle_location paddle::get_location() const noexcept
{
	return paddle_location::left;
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

position paddle::get_center() const noexcept
{
	return {};
}
