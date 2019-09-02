#ifndef _INTEGRATABLE_HPP_
#define _INTEGRATABLE_HPP_

#include "pong_domain_export.h"

enum class integration_statuses
{
	integrated,
	not_integrated
};

class PONG_DOMAIN_EXPORT integratable
{
public:
	void integrate( double delta ) noexcept;
	bool is_integrated() noexcept;

protected:
	virtual integration_statuses do_integrate( double delta ) noexcept = 0;

protected:
	integration_statuses status_ = integration_statuses::not_integrated;
};

#endif // !_INTEGRATABLE_HPP_
