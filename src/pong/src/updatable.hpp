#ifndef _UPDATABLE_HPP_
#define _UPDATABLE_HPP_

#include "pong_domain_export.h"

enum class update_statuses
{
	updated,
	not_updated
};

class PONG_DOMAIN_EXPORT updatable
{
public:
	void update( double delta ) noexcept;
	bool is_updated() noexcept;

protected:
	virtual update_statuses do_update( double delta ) noexcept = 0;

protected:
	update_statuses status_ = update_statuses::not_updated;
};

#endif // !_UPDATABLE_HPP_
