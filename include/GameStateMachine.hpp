#ifndef GAMESTATEMACHINE_H_INCLUDED
#define GAMESTATEMACHINE_H_INCLUDED

#include "GameState.hpp"
#include <stack>

class GameStateMachine {
	private:
		std::stack<GameState> game_states_;
		static bool changing_;


	public:
		~GameStateMachine() = default;
		void push(const GameState & state);
		void change(const GameState & state);
		void pop();

		void update();
		void render();

		static bool is_changing() ;


};



#endif
