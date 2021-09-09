#include "GameStateMachine.hpp"

void GameStateMachine :: push(const GameState & state) {
	game_states_.push(state);
	game_states_.top().on_enter();

	changing_ = true;
}

void GameStateMachine :: change(const GameState & state) {

	if ( !game_states_.empty() ) {
		if ( game_states_.top().get_state_id() != state.get_state_id() ){
			pop();
			push(state);
		}
	} else {
		push(state);
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
	changing_ = false;
	if ( !game_states_.empty() ) {
		game_states_.top().update();
	}
}

void GameStateMachine :: render() {
	if ( !game_states_.empty() ) {
		game_states_.top().render();
	}
}

bool GameStateMachine :: is_changing() {
	return changing_;
}


bool GameStateMachine :: changing_ = false;
