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
	auto it = objects_.begin();
	while (it != objects_.end() && !GameStateMachine::is_changing()) {
		(*it)->update();
		++it;
	}
}

void PlayState::render() {
	auto it = objects_.begin();
	while (it != objects_.end() && !GameStateMachine::is_changing()) {
		(*it)->draw();
		++it;
	}
}

bool PlayState :: on_enter() {

	bool success = true;

	StateParser::parse_state("assets/states.xml", play_id_, objects_);


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
