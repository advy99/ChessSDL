#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <memory>

#include "Turn.hpp"
#include "InputHandler.hpp"
#include "GameStateMachine.hpp"
#include "GameObjectFactory.hpp"
#include "MenuButton.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "AnimatedGraphic.hpp"
#include "MainMenuState.hpp"
#include "ChessBoard.hpp"
#include "Texture.hpp"
#include "Figures/Rectangle.hpp"


struct SDL_WindowDeleter {
	void operator()(SDL_Window * window);
};

struct SDL_RendererDeleter {
	void operator()(SDL_Renderer * renderer);
};


class Game {
	private:
		static bool running_;

		static std::unique_ptr<SDL_Window, SDL_WindowDeleter> window_;
		static std::unique_ptr<SDL_Renderer, SDL_RendererDeleter> renderer_;

		static GameStateMachine game_state_machine_;

		static uint32_t current_frame_;

		static uint32_t width_;
		static uint32_t height_;
		static std::unique_ptr<GameState> next_state_;
		static bool changing_game_state_;

		static Turn player_turn_;

	public:

		static void init(const std::string & title, const uint32_t XPOS, const uint32_t YPOS,
					const uint32_t WIDTH, const uint32_t HEIGHT, const uint32_t FLAGS);


		static void render();

		static void draw();

		static void update();

		static void handle_events();

		static bool running();

		static SDL_Renderer * get_renderer() ;

		static void stop_running();

		static void change_state(std::unique_ptr<GameState> && state);

		static void pop_state();

		static uint32_t width() ;
		static uint32_t height() ;

		static Turn player_turn();
		static void player_turn_ended();

};

#endif
