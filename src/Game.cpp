#include "Game.hpp"

#include <iostream>

void SDL_WindowDeleter :: operator()(SDL_Window * window) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SDL_RendererDeleter :: operator()(SDL_Renderer * renderer) {
	SDL_DestroyRenderer(renderer);
}


Game :: Game(const std::string & title, const uint32_t XPOS, const uint32_t YPOS,
				 const uint32_t WIDTH, const uint32_t HEIGHT, const uint32_t FLAGS) {
	
	running_ = true;
					
	if (SDL_Init(SDL_INIT_EVERYTHING)  < 0) {
		std::cerr << "SDL could not initialize. SDL_Error: "
					 << SDL_GetError() << std::endl;

		running_ = false;
		
	} else {
		window_.reset(SDL_CreateWindow(title.c_str(), XPOS, YPOS, WIDTH, HEIGHT, FLAGS) );

		if (window_ == nullptr) {
			std::cerr << "SDL could not create window. SDL_Error: "
						 << SDL_GetError() << std::endl;

			running_ = false;
		} else {
			renderer_.reset(SDL_CreateRenderer(window_.get(), -1, 0) );

			if (renderer_ == nullptr) {
				std::cerr << "SDL could not create renderer. SDL_Error: "
						 	 << SDL_GetError() << std::endl;

				running_ = false;

			} else {
				SDL_SetRenderDrawColor(renderer_.get(), 0, 0, 0, 255);

				game_state_machine_ = GameStateMachine();
				input_handler_ = InputHandler();
				texture_manager_ = TextureManager();

				game_state_machine_.change_state(MainMenuState());

				width_ = WIDTH;
				height_ = HEIGHT;

			}
		}

	}


}


void Game :: render() {
	SDL_RenderClear(renderer_.get());

	game_state_machine_.render();


	SDL_RenderPresent(renderer_.get());

}

void Game :: update() {
	game_state_machine_.update();
}

void Game :: handle_events() {
	input_handler_.update();
}

void Game :: running() const noexcept {
	return running_;
}

SDL_Renderer * Game :: get_renderer() const {
	return renderer_.get();
}

uint32_t Game :: width() const noexcept {
	return width_;
}

uint32_t Game :: height() const noexcept {
	return height_;
}

