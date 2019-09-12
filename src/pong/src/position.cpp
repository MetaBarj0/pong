#include "position.hpp"

position::position( unsigned short x, unsigned short y ) noexcept : x_{ x }, y_{ y }{}

unsigned short position::x() const noexcept
{
	return x_;
}

unsigned short position::y() const noexcept
{
	return y_;
}

bool position::operator==( const position &pos ) const noexcept
{
	return ( pos.x_ == x_ ) && ( pos.y_ == y_ );
}

bool position::operator==( position &&pos ) const noexcept
{
	return ( pos.x_ == x_ ) && ( pos.y_ == y_ );
}

bool position::operator !=( const position &pos ) const noexcept
{
	return !( pos == *this );
}

bool position::operator !=( position &&pos ) const noexcept
{
	return !( pos == *this );
}
