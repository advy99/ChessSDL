#include "MainMenuState.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"
#include "MenuButton.hpp"
#include <iostream>
#include "StateParser.hpp"
#include "PlayState.hpp"

MainMenuState::~MainMenuState() {

}

void MainMenuState :: update(){
	if (!GameStateMachine::is_changing()) {
		for(auto & object: objects_) {
			object.update();
		}
	}
}

void MainMenuState :: render() {
	if (!GameStateMachine::is_changing()) {
		for(auto & object: objects_) {
			object.draw();
		}
	}

}


bool MainMenuState :: on_enter() {
	bool success = true;


	StateParser::parse_state("assets/test.xml", menu_id_, objects_);

	callbacks_.push_back(menu_to_play);
	callbacks_.push_back(exit_from_menu);

	set_callbacks(callbacks_);

	return success;

}


std::string MainMenuState::get_state_id() const {
	return menu_id_;
}


void MainMenuState::menu_to_play() {
	std::cout << "Clicked Play button" << std::endl;

	Game::change_state(PlayState());
}


void MainMenuState::exit_from_menu() {
	std::cout << "Clicked Exit button" << std::endl;
	Game::stop_running();
}


void MainMenuState::set_callbacks(const std::vector<Callback> & callbacks) {
	for ( unsigned i = 0; i < objects_.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (&objects_[i]) ;
		if ( button != nullptr ) {
			button->set_callback(callbacks[button->get_callback_id() ]);
		}
	}
}



const std::string MainMenuState::menu_id_ = "MENU";
