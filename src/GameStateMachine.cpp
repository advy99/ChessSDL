#include "GameStateMachine.hpp"

GameStateMachine :: GameStateMachine(){}

void GameStateMachine :: push(std::unique_ptr<GameState> && state) {
	game_states_.push(std::move(state));

	changing_ = true;
}

void GameStateMachine :: change(std::unique_ptr<GameState> && state) {

	if ( !game_states_.empty() ) {
		if ( game_states_.top()->get_state_id() != state->get_state_id() ){
			pop();
			push(std::move(state));
		}
	} else {
		push(std::move(state));
	}

	changing_ = true;

}


void GameStateMachine :: pop() {
	if ( !game_states_.empty() ) {
		changing_ = true;
		game_states_.pop();
	}
}

void GameStateMachine :: update() {

	// we are changing of state, need to enter the new state
	if (changing_ && !game_states_.empty()) {
		changing_ = false;
		game_states_.top()->on_enter();
	}

	if ( !game_states_.empty() ) {
		game_states_.top()->update();
	}
}

void GameStateMachine :: render() {
	if ( !game_states_.empty() ) {
		game_states_.top()->render();
	}
}

bool GameStateMachine :: is_changing() {
	return changing_;
}


bool GameStateMachine :: changing_ = false;
