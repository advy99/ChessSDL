#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include "GameObject.hpp"

class GameState {
	protected:

		std::vector<std::unique_ptr<GameObject> > objects_;

	public:
		virtual ~GameState() {};
		virtual void update() = 0;
		virtual void render() = 0;

		virtual bool on_enter() = 0;

		virtual std::string get_state_id() const = 0;

};


#endif
