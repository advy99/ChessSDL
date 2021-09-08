#include "MainMenuState.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"
#include "MenuButton.hpp"
#include <iostream>
#include "StateParser.hpp"

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

	StateParser parser;

	parser.parse_state("assets/test.xml", menu_id, objects, texture_id_list);

	callbacks.push_back(menu_to_play);
	callbacks.push_back(exit_from_menu);

	set_callbacks(callbacks);

	return success;

}


std::string MainMenuState::get_state_id() const {
	return menu_id;
}


void MainMenuState::menuToPlay() {
	std::cout << "Clicked Play button" << std::endl;

	Game::change_state(PlayState());
}


void MainMenuState::exit_from_menu() {
	std::cout << "Clicked Exit button" << std::endl;
	Game::stop_running();
}


void MainMenuState::set_callbacks(const std::vector<Callback> & callbacks) {
	for ( unsigned i = 0; i < objects.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects[i]) ;
		if ( button != nullptr ) {
			button->setCallback(callbacks[button->getCallbackID() ]);
		}
	}
}



const std::string MainMenuState::menu_id = "MENU";
