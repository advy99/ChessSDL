#include <iostream>

#include "Game.hpp"

const uint32_t TARGET_FPS = 60;
const uint32_t DELAY_TIME = 1000.0 / TARGET_FPS;


int main() {
	
	Game::init("Titulo", 100, 100, 1024, 768, 0);

	uint32_t frame_start, frame_time;

	while (Game::running()) {

		frame_start = SDL_GetTicks();

		Game::handle_events();
		Game::update();
		Game::render();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_time < DELAY_TIME) {
			SDL_Delay( static_cast<int>(DELAY_TIME - frame_time) );
		}
		
	}


}
