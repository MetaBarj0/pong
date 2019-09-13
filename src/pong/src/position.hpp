#ifndef _POSITION_HPP_
#define _POSITION_HPP_

#include "pong_domain_export.h"

class PONG_DOMAIN_EXPORT position
{
public:
	position() noexcept = default;
	position( unsigned short x, unsigned short y ) noexcept;

	unsigned short x() const noexcept;
	unsigned short y() const noexcept;
	void x( unsigned short value ) noexcept;
	void y( unsigned short value ) noexcept;

	bool operator ==( const position &pos ) const noexcept;
	bool operator ==( position &&pos ) const noexcept;
	bool operator !=( const position &pos ) const noexcept;
	bool operator !=( position &&pos ) const noexcept;

private:
	unsigned short x_, y_;
};

#endif // !_POSITION_HPP_
