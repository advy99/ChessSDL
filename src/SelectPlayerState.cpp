#include "SelectPlayerState.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"
#include "MenuButton.hpp"
#include <iostream>
#include "StateParser.hpp"
#include "PlayState.hpp"
#include "MainMenuState.hpp"

SelectPlayerState::~SelectPlayerState() {

}

void SelectPlayerState :: update(){
	auto it = objects_.begin();
	while (it != objects_.end() && !GameStateMachine::is_changing()) {
		(*it)->update();
		++it;
	}
}

void SelectPlayerState :: render() {
	auto it = objects_.begin();
	while (it != objects_.end() && !GameStateMachine::is_changing()) {
		(*it)->draw();
		++it;
	}

}


bool SelectPlayerState :: on_enter() {
	bool success = true;


	StateParser::parse_state("assets/states.xml", menu_id_, objects_);

	callbacks_.push_back(select_player_to_play);
	callbacks_.push_back(select_player_to_menu);

	set_callbacks(callbacks_);

	return success;

}


std::string SelectPlayerState::get_state_id() const {
	return menu_id_;
}


void SelectPlayerState::select_player_to_play() {

	Game::change_state(std::unique_ptr<PlayState>(new PlayState()));
}


void SelectPlayerState::select_player_to_menu() {
	Game::change_state(std::unique_ptr<MainMenuState>(new MainMenuState()));
}


void SelectPlayerState::set_callbacks(const std::vector<Callback> & callbacks) {
	for ( unsigned i = 0; i < objects_.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects_[i].get()) ;
		if ( button != nullptr ) {
			button->set_callback(callbacks[button->get_callback_id() ]);
		}
	}
}



const std::string SelectPlayerState::menu_id_ = "SELECT_PLAYER";
