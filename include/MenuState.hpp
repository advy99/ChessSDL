#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED

#include "GameState.hpp"
#include "GameObject.hpp"
#include <vector>

class MenuState : public GameState {
	protected:
		typedef void(*Callback)();
		virtual void setCallbacks(const std::vector<Callback> & callbacks) = 0;
		std::vector<Callback> callbacks;
};


#endif
