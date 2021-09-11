#ifndef PLAYSTATE_H_INCLUDED
#define PLAYSTATE_H_INCLUDED

#include "GameState.hpp"
#include "GameObject.hpp"
#include "SDLGameObject.hpp"
#include <vector>
#include "Level.hpp"
#include "ChessBoard.hpp"
#include "Game.hpp"

class PlayState : public GameState {
	private:
		static const std::string play_id_;
		bool check_collision(const SDLGameObject * p1, const SDLGameObject * p2);

	public:
		virtual ~PlayState();
		virtual void update();
		virtual void render();

		virtual bool on_enter();

		virtual std::string get_state_id() const;

};



#endif
