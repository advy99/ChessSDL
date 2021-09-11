#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED

#include <functional>
#include "GameState.hpp"
#include "GameObject.hpp"
#include <vector>

class MenuState : public GameState {
	protected:
		virtual void set_callbacks(const std::vector<std::function<void()> > & callbacks) = 0;
		std::vector<std::function<void()> > callbacks_;
};


#endif
