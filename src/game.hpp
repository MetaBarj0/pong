#ifndef _GAME_HPP_
#define _GAME_HPP_

struct SDL_Window;
struct SDL_Renderer;

#include <cstdint>

struct vec2
{
	float x = 0.f, y = 0.f;
};

struct rgba
{
	std::uint8_t r = 0, g = 0, b = 0, a = 255;
};

class game
{
public:
	bool startup() noexcept;
	void run() noexcept;
	void shutdown() noexcept;

private:
	void process_input() noexcept;
	void update() noexcept;
	void generate_output() noexcept;

	void render_statics() noexcept;
	void render_paddle() noexcept;
	void render_ball() noexcept;

	void update_paddle( float delta ) noexcept;
	void update_ball( float delta ) noexcept;

	void handle_ball_collision( float delta ) noexcept;
	void handle_paddle_collision( float delta )noexcept;
	void handle_wall_collision( float delta )noexcept;
	void handle_loosing_area_collision( float delta )noexcept;

private:
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	std::uint32_t elapsed_milliseconds = 0u;
	bool is_running = true;

private:
	static constexpr std::uint16_t WINDOW_WIDTH = 1024u;
	static constexpr std::uint16_t WINDOW_HEIGHT = 768u;

	static constexpr std::uint8_t WALL_THICKNESS = 16u;
	static constexpr std::uint8_t BALL_SIZE = 8u;
	static constexpr std::uint8_t PADDLE_WIDTH = 8u;
	static constexpr std::uint8_t PADDLE_HEIGHT = 64u;

	static constexpr rgba WALL_COLOR = { 192, 192, 192, 192 };
	static constexpr rgba BALL_COLOR = { 255, 255, 255, 255 };
	static constexpr rgba PADDLE_COLOR = { 255, 255, 255, 255 };

	static constexpr float PADDLE_SPEED = 300.f;
	static constexpr float BALL_SPEED = 300.f;

	static constexpr std::uint16_t MIN_PADDLE_POSITION = WALL_THICKNESS + PADDLE_HEIGHT / 2;
	static constexpr std::uint16_t MAX_PADDLE_POSITION = WINDOW_HEIGHT - WALL_THICKNESS - PADDLE_HEIGHT / 2;

private:
	vec2 paddle_position{ WALL_THICKNESS + PADDLE_WIDTH / 2, WINDOW_HEIGHT / 2 },
		ball_position{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };

	vec2 ball_velocity{ 1.f, 0.f }, paddle_velocity;

};

#endif