#include "MainMenuState.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"
#include "MenuButton.hpp"
#include <iostream>
#include "StateParser.hpp"
#include "PlayState.hpp"
#include "SelectPlayerState.hpp"

MainMenuState::~MainMenuState() {

}

void MainMenuState :: update(){
	auto it = objects_.begin();
	while (it != objects_.end() && !GameStateMachine::is_changing()) {
		(*it)->update();
		++it;
	}
}

void MainMenuState :: render() {
	auto it = objects_.begin();
	while (it != objects_.end() && !GameStateMachine::is_changing()) {
		(*it)->draw();
		++it;
	}

}


bool MainMenuState :: on_enter() {
	bool success = true;


	StateParser::parse_state("assets/states.xml", menu_id_, objects_);

	callbacks_.push_back(menu_to_select_player);
	callbacks_.push_back(exit_from_menu);

	set_callbacks(callbacks_);

	return success;

}


std::string MainMenuState::get_state_id() const {
	return menu_id_;
}


void MainMenuState::menu_to_select_player() {
	Game::change_state(std::unique_ptr<SelectPlayerState>(new SelectPlayerState()));
}


void MainMenuState::exit_from_menu() {
	Game::stop_running();
}


void MainMenuState::set_callbacks(const std::vector<Callback> & callbacks) {
	for ( unsigned i = 0; i < objects_.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects_[i].get()) ;
		if ( button != nullptr ) {
			button->set_callback(callbacks[button->get_callback_id() ]);
		}
	}
}



const std::string MainMenuState::menu_id_ = "MENU";
