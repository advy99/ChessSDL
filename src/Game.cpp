#include "Game.hpp"

#include <iostream>

void SDL_WindowDeleter :: operator()(SDL_Window * window) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SDL_RendererDeleter :: operator()(SDL_Renderer * renderer) {
	SDL_DestroyRenderer(renderer);
}


void Game :: init(const std::string & title, const uint32_t XPOS, const uint32_t YPOS,
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

				GameObjectFactory::register_type("MenuButton", std::make_unique<MenuButtonCreator>());
				GameObjectFactory::register_type("ChessBoard", std::make_unique<ChessBoardCreator>());
				GameObjectFactory::register_type("Rectangle", std::make_unique<RectangleCreator>());

				game_state_machine_.change(std::make_unique<MainMenuState>());

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
	if (changing_game_state_) {
		game_state_machine_.change(std::move(next_state_));
		changing_game_state_ = false;
	}
	game_state_machine_.update();
}

void Game :: handle_events() {
	InputHandler::update();
}

bool Game :: running() {
	return running_;
}

SDL_Renderer * Game :: get_renderer()  {
	return renderer_.get();
}

uint32_t Game :: width() {
	return width_;
}

uint32_t Game :: height() {
	return height_;
}

void Game :: stop_running () {
	running_ = false;
}
void Game :: change_state(std::unique_ptr<GameState> && state) {
	next_state_ = std::move(state);
	changing_game_state_ = true;
}


void Game :: pop_state() {
	game_state_machine_.pop();
}

Turn Game :: player_turn() {
	return player_turn_;
}

void Game :: player_turn_ended() {
	if (player_turn_ == Turn::WHITE) {
		player_turn_ = Turn::BLACK;
	} else {
		player_turn_ = Turn::WHITE;
	}
}


bool Game :: running_ = false;
std::unique_ptr<SDL_Window, SDL_WindowDeleter> Game :: window_ = nullptr;
std::unique_ptr<SDL_Renderer, SDL_RendererDeleter> Game :: renderer_ = nullptr;
GameStateMachine Game :: game_state_machine_;
uint32_t Game :: current_frame_;
uint32_t Game :: width_;
uint32_t Game :: height_;
std::unique_ptr<GameState> Game :: next_state_ = nullptr;
bool Game :: changing_game_state_ = false;
Turn Game :: player_turn_ = Turn::WHITE;
