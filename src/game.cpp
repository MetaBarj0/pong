#include "game.hpp"

#include "SDL.h"

#include <initializer_list>
#include <cmath>

bool game::startup() noexcept
{
	int sdlResult = SDL_Init( SDL_INIT_VIDEO );

	if( sdlResult != 0 )
	{
		SDL_Log( "Unable to initialize SDL: %s", SDL_GetError() );
		return false;
	}

	elapsed_milliseconds = SDL_GetTicks();

	window =
		SDL_CreateWindow(
			"pong",
			100,
			100,
			1024,
			768,
			0
		);

	if( window == nullptr )
	{
		SDL_Log( "Failed to create window: %s", SDL_GetError() );
		return false;
	}

	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	if( renderer == nullptr )
	{
		SDL_Log( "Failed to create renderer: %s", SDL_GetError() );
		return false;
	}

	return true;
}

void game::run() noexcept
{
	while( is_running )
	{
		process_input();
		update();
		generate_output();
	}
}

void game::shutdown() noexcept
{
	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}

void game::process_input() noexcept
{
	SDL_Event event;

	while( SDL_PollEvent( &event ) )
	{
		switch( event.type )
		{
		case SDL_QUIT:
			is_running = false;
			break;
		}
	}
	const Uint8 *state = SDL_GetKeyboardState( nullptr );

	if( state[ SDL_SCANCODE_ESCAPE ] )
		is_running = false;

	if( state[ SDL_SCANCODE_Q ] )
		paddle_velocity = { 0.f, -1.f };
	else if( state[ SDL_SCANCODE_A ] )
		paddle_velocity = { 0.f, 1.f };
	else
		paddle_velocity = { 0.f, 0.f };
}

void game::update() noexcept
{
	while( ( SDL_GetTicks() - elapsed_milliseconds ) < 1000 / 60 );

	float delta = ( SDL_GetTicks() - elapsed_milliseconds ) / 1000.0f;
	elapsed_milliseconds = SDL_GetTicks();

	if( delta > .05f )
		delta = .05f;

	update_paddle( delta );
	update_ball( delta );
}

void game::generate_output() noexcept
{
	SDL_SetRenderDrawColor( renderer, 32, 0, 64, 255 );
	SDL_RenderClear( renderer );

	render_statics();
	render_paddle();
	render_ball();

	SDL_RenderPresent( renderer );
}

void game::render_statics() noexcept
{
	const auto [r, g, b, a] = WALL_COLOR;
	SDL_SetRenderDrawColor( renderer, r, g, b, a );

	for( auto &&wall :
		 {
			 SDL_Rect { 0, 0, WINDOW_WIDTH, WALL_THICKNESS },
			 SDL_Rect { 0, WINDOW_HEIGHT - WALL_THICKNESS, WINDOW_WIDTH, WINDOW_HEIGHT },
			 SDL_Rect { WINDOW_WIDTH - WALL_THICKNESS, 0, WINDOW_WIDTH, WINDOW_HEIGHT }
		 } )
		SDL_RenderFillRect( renderer, &wall );
}

void game::render_paddle() noexcept
{
	const auto [r, g, b, a] = PADDLE_COLOR;
	SDL_SetRenderDrawColor( renderer, r, g, b, a );

	const auto px = static_cast< std::uint16_t >( paddle_position.x );
	const auto py = static_cast< std::uint16_t >( paddle_position.y );
	const auto w = PADDLE_WIDTH;
	const auto h = PADDLE_HEIGHT;

	const SDL_Rect paddle = { px - w / 2, py - h / 2, w, h };
	SDL_RenderFillRect( renderer, &paddle );
}

void game::render_ball() noexcept
{
	const auto [r, g, b, a] = BALL_COLOR;
	SDL_SetRenderDrawColor( renderer, r, g, b, a );

	const auto bx = static_cast< std::uint16_t >( ball_position.x );
	const auto by = static_cast< std::uint16_t >( ball_position.y );
	const auto s = BALL_SIZE;

	const SDL_Rect ball = { bx - s / 2, by - s / 2, s, s };
	SDL_RenderFillRect( renderer, &ball );
}

void game::update_paddle( float delta ) noexcept
{
	paddle_position.y += paddle_velocity.y * PADDLE_SPEED * delta;

	if( ( paddle_velocity.y < 0 ) && ( paddle_position.y <= MIN_PADDLE_POSITION ) )
		paddle_position.y = MIN_PADDLE_POSITION;
	else if( ( paddle_velocity.y > 0 ) && ( paddle_position.y >= MAX_PADDLE_POSITION ) )
		paddle_position.y = MAX_PADDLE_POSITION;
}

void game::update_ball( float delta ) noexcept
{
	handle_ball_collision( delta );

	auto hypot = std::hypot( ball_velocity.x, ball_velocity.y );

	ball_position.x += ball_velocity.x * BALL_SPEED * delta / hypot;
	ball_position.y += ball_velocity.y * BALL_SPEED * delta / hypot;
}

void game::handle_ball_collision( float delta ) noexcept
{
	handle_paddle_collision( delta );
	handle_loosing_area_collision( delta );
	handle_wall_collision( delta );
}

void game::handle_paddle_collision( float delta ) noexcept
{
	const auto right_paddle_x = paddle_position.x + PADDLE_WIDTH / 2,
		left_ball_x = ball_position.x - BALL_SIZE / 2,
		top_paddle_y = paddle_position.y - PADDLE_HEIGHT / 2,
		top_ball_y = ball_position.y - BALL_SIZE / 2,
		bottom_paddle_y = paddle_position.y + PADDLE_HEIGHT / 2,
		bottom_ball_y = ball_position.y + BALL_SIZE / 2;

	if( ( left_ball_x <= right_paddle_x ) && ( ball_velocity.x < 0 ) )
	{
		if( ( bottom_ball_y >= top_paddle_y ) && ( top_ball_y <= bottom_paddle_y ) )
		{
			ball_position.x = right_paddle_x;
			ball_velocity.x = 1.f;
			ball_velocity.y = ( ball_position.y > paddle_position.y ) ? 1.f : -1.f;
		}
	}
}

void game::handle_wall_collision( float delta ) noexcept
{
	const float wall_top_min_x = WALL_THICKNESS,
		wall_top_max_x = WINDOW_WIDTH - WALL_THICKNESS,
		wall_top_y = WALL_THICKNESS,
		wall_bottom_min_x = WALL_THICKNESS,
		wall_bottom_max_x = WINDOW_WIDTH - WALL_THICKNESS,
		wall_bottom_y = WINDOW_HEIGHT - WALL_THICKNESS,
		wall_right_x = WINDOW_WIDTH - WALL_THICKNESS,
		wall_right_min_y = WALL_THICKNESS,
		wall_right_max_y = WINDOW_HEIGHT - WALL_THICKNESS,
		ball_top_y = ball_position.y - BALL_SIZE / 2,
		ball_bottom_y = ball_position.y + BALL_SIZE / 2,
		ball_left_x = ball_position.x - BALL_SIZE / 2,
		ball_right_x = ball_position.x + BALL_SIZE / 2;

	if( ( ball_velocity.y < 0 ) && ( ball_top_y <= wall_top_y ) && ( ball_left_x >= wall_top_min_x ) )
	{
		ball_velocity.y = 1.f;
		ball_position.y = wall_top_y + BALL_SIZE / 2;

		if( ball_right_x >= wall_right_x )
			ball_position.x = wall_right_x - BALL_SIZE / 2;
	}
	else if( ( ball_velocity.y > 0 ) && ( ball_bottom_y >= wall_bottom_y ) && ( ball_left_x >= wall_bottom_min_x ) )
	{
		ball_velocity.y = -1.f;
		ball_position.y = wall_bottom_y - BALL_SIZE / 2;

		if( ball_right_x >= wall_right_x )
			ball_position.x = wall_right_x - BALL_SIZE / 2;
	}

	if( ( ball_velocity.x > 0 ) && ( ball_right_x >= wall_right_x ) )
	{
		ball_velocity.x = -1.f;
		ball_position.x = wall_right_x - BALL_SIZE / 2;

		if( ball_top_y <= wall_top_y )
			ball_position.y = wall_top_y + BALL_SIZE / 2;
		else if( ball_bottom_y >= wall_bottom_y )
			ball_position.y = wall_bottom_y - BALL_SIZE / 2;
	}
}

void game::handle_loosing_area_collision( float delta ) noexcept
{
	const auto right_paddle_x = paddle_position.x + PADDLE_WIDTH / 2,
		left_ball_x = ball_position.x - BALL_SIZE / 2,
		top_paddle_y = paddle_position.y - PADDLE_HEIGHT / 2,
		top_ball_y = ball_position.y - BALL_SIZE / 2,
		bottom_paddle_y = paddle_position.y + PADDLE_HEIGHT / 2,
		bottom_ball_y = ball_position.y + BALL_SIZE / 2;

	if( ( ball_velocity.x < 0 ) && ( left_ball_x < right_paddle_x ) )
	{
		if( ( bottom_ball_y < top_paddle_y ) || ( top_ball_y > bottom_paddle_y ) )
			is_running = false;
	}
}
