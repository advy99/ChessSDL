#include "GameOverState.hpp"
#include "PlayState.hpp"
#include "Game.hpp"
#include "MenuState.hpp"
#include "MenuButton.hpp"
#include "AnimatedGraphic.hpp"
#include "InputHandler.hpp"
#include "StateParser.hpp"

GameOverState::~GameOverState() {
}

std::string GameOverState::get_state_id() const {
	return game_over_id_;
}

void GameOverState::game_over_to_main() {
	Game::change_state(std::unique_ptr<MainMenuState>(new MainMenuState()));
}

void GameOverState::restart_play() {
	Game::change_state(std::unique_ptr<PlayState>(new PlayState()));

}

bool GameOverState::on_enter() {
	bool success = true;


	StateParser::parse_state("assets/states.xml", game_over_id_, objects_);

	callbacks_.push_back(game_over_to_main);
	callbacks_.push_back(restart_play);

	set_callbacks(callbacks_);

	return success;


}


void GameOverState::update() {
	for ( unsigned i = 0; i < objects_.size() && !GameStateMachine::is_changing(); i++ ) {
		objects_[i]->update();
	}
}


void GameOverState::render() {
	for ( unsigned i = 0; i < objects_.size() && !GameStateMachine::is_changing(); i++ ) {
		objects_[i]->draw();
	}
}



void GameOverState::set_callbacks(const std::vector<std::function<void()> > & callbacks) {
	for ( unsigned i = 0; i < objects_.size(); i++ ) {
		MenuButton * button = dynamic_cast<MenuButton*> (objects_[i].get()) ;
		if ( button != nullptr ) {
			button->set_callback(callbacks[button->get_callback_id() ]);
		}
	}
}




const std::string GameOverState::game_over_id_ = "GAMEOVER";
