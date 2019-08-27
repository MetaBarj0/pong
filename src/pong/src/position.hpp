#ifndef _POSITION_HPP_
#define _POSITION_HPP_

#include "pong_export.h"

class PONG_EXPORT position
{
public :
	unsigned short x() const noexcept;
	unsigned short y() const noexcept;

	bool operator == ( const position &pos ) const noexcept;
	bool operator == ( position &&pos ) const noexcept;

private :
	unsigned short x_, y_;
};

#endif // !_POSITION_HPP_