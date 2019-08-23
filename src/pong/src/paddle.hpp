#include "pong_export.h"

enum class paddle_position
{
	left
};

enum class paddle_orientation
{
	vertical
};

class PONG_EXPORT paddle
{
public:
	paddle_position get_position() const noexcept;
	paddle_orientation get_orientation() const noexcept;
	unsigned char width() const noexcept;
	unsigned char height() const noexcept;
};
