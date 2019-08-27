#include "position.hpp"

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
