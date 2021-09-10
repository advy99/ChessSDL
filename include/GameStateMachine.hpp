#ifndef GAMESTATEMACHINE_H_INCLUDED
#define GAMESTATEMACHINE_H_INCLUDED

#include "GameState.hpp"
#include <stack>
#include <memory>

class GameStateMachine {
	private:
		std::stack< std::unique_ptr<GameState> > game_states_;
		static bool changing_;


	public:
		~GameStateMachine() = default;
		void push(std::unique_ptr<GameState> state);
		void change(std::unique_ptr<GameState> state);
		void pop();

		void update();
		void render();

		static bool is_changing() ;


};



#endif
