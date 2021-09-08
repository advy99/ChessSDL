#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <memory>

#include "InputHandler.hpp"
#include "GameStateMachine.hpp"
#include "TextureManager.hpp"


struct SDL_WindowDeleter {
	void operator()(SDL_Window * window);
};

struct SDL_RendererDeleter {
	void operator()(SDL_Renderer * renderer);
};



class Game {
	private: 
		bool running_;

		std::unique_ptr<SDL_Window, SDL_WindowDeleter> window_;
		std::unique_ptr<SDL_Renderer, SDL_RendererDeleter> renderer_;

		InputHandler input_handler_;
		GameStateMachine game_state_machine_;
		TextureManager texture_manager_;

		uint32_t current_frame_;

		uint32_t width_;
		uint32_t height_;

		std::vector< GameObject > objects_;

	public:

		Game(const std::string & title, const uint32_t XPOS, const uint32_t YPOS,
					const uint32_t WIDTH, const uint32_t HEIGHT, const uint32_t FLAGS);


		void render();
		
		void draw();

		void update();

		void handle_events();

		bool running() const noexcept;

		SDL_Renderer * get_renderer() const;

		static void stop_running();

		static void change_state(const GameState & state);

		uint32_t width() const;
		uint32_t height() const;

}

#endif
