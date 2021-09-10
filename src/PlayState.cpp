#include "PlayState.hpp"
#include "InputHandler.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "Game.hpp"
#include <iostream>
#include "StateParser.hpp"
#include "LevelParser.hpp"



PlayState::~PlayState() {
}

void PlayState::update() {
	level_->update();

}

void PlayState::render() {
	level_->render();
}

bool PlayState :: on_enter() {
	std::cout << "Entering Play state" << std::endl;

	bool success = true;

	level_ = std::move(LevelParser::parse_level("assets/first_csv.tmx"));

	return success;
}

std::string PlayState :: get_state_id() const {
	return play_id_;
}

bool PlayState::check_collision(const SDLGameObject * p1,
										  const SDLGameObject * p2){
	bool collision = false;


	int leftA = p1->get_position().get_x();
	int rightA = leftA + p1->get_width();
	int topA = p1->get_position().get_y();
	int bottomA = topA + p1->get_height();


	int leftB = p2->get_position().get_x();
	int rightB = leftB + p2->get_width();
	int topB = p2->get_position().get_y();
	int bottomB = topB + p2->get_height();


	collision = ( bottomA >= topB && topA <= bottomB ) &&
					( rightA >= leftB && leftA <= rightB );


	return collision;
}



const std::string PlayState::play_id_ = "PLAY";
