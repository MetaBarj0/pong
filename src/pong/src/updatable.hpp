#ifndef _UPDATABLE_HPP_
#define _UPDATABLE_HPP_

#include "pong_domain_export.h"

class PONG_DOMAIN_EXPORT updatable
{
public :
	void update( double delta ) noexcept;
	bool is_updated() noexcept;

protected :
	virtual bool update_details( double delta ) noexcept = 0;

protected :
	bool updated_ = false;
};

#endif // !_UPDATABLE_HPP_
