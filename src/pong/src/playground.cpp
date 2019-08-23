#include "playground.hpp"

unsigned short playground::width() const noexcept
{
	return 500u;
}

unsigned short playground::height() const noexcept
{
	return 500u;
}

wall playground::get_wall_by_position( wall_position position ) const noexcept
{
	return { position };
}

paddle playground::get_paddle() const noexcept
{
	return {};
}
