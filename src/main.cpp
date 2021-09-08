#include <iostream>

#include "Game.hpp"

const uint32_t TARGET_FPS = 60;
const uint32_t DELAY_TIME = 1000.0 / TARGET_FPS;


int main() {
	
	Game my_game;

	uint32_t frame_start, frame_time;

	while (my_game.is_running()) {

		frame_start = SDL_GetTicks();

		my_game.handle_events();
		my_game.update();
		my_game.render();

		frame_time = SDL_GetTicks() - frame_start;

		if (frame_time < DELAY_TIME) {
			SDL_Delay( static_cast<int>(DELAY_TIME - frame_time) );
		}
		
	}


}
