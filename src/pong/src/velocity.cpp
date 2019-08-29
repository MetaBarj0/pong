#include "velocity.hpp"

velocity::velocity( const unsigned char speed_value, directions direction_value ) noexcept : speed{ speed_value }, direction{ direction_value }
{
}

unsigned char velocity::get_speed() const noexcept
{
	return speed;
}

void velocity::set_speed( unsigned char value ) noexcept
{
	speed = value;
}

directions velocity::get_direction() const noexcept
{
	return direction;
}

void velocity::set_direction( directions value ) noexcept
{
	direction = value;
}