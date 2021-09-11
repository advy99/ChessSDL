#include "PauseState.hpp"
#include "Game.hpp"
#include "MainMenuState.hpp"
#include "MenuButton.hpp"
#include "InputHandler.hpp"
#include "StateParser.hpp"

PauseState::~PauseState() {
	
}

std::string PauseState::get_state_id() const {
	return pause_id_;
}

void PauseState::pause_to_main(){
	Game::change_state(std::make_unique<MainMenuState>());
}


void PauseState::resume_play() {
	Game::pop_state();
}

void PauseState::update() {
	for ( unsigned i = 0; i < objects_.size() &&
								!GameStateMachine::is_changing(); i++ ) {
		objects_[i]->update();
	}
}


void PauseState::render() {
	for ( unsigned i = 0; i < objects_.size() &&
								!GameStateMachine::is_changing(); i++ ) {
		objects_[i]->draw();
	}
}

bool PauseState::on_enter() {
	bool success = true;


	StateParser::parse_state("assets/test.xml", pause_id_, objects_);

	callbacks_.push_back(pause_to_main);
	callbacks_.push_back(resume_play);

	set_callbacks(callbacks_);

	return success;
}


void PauseState::set_callbacks(const std::vector<std::function<void()> > & callbacks) {
	for ( unsigned i = 0; i < objects_.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects_[i].get()) ;
		if ( button != nullptr ) {
			button->set_callback(callbacks[button->get_callback_id() ]);
		}
	}
}


const std::string PauseState::pause_id_ = "PAUSE";
