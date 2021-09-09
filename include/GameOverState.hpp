#ifndef GAMEOVERSTATE_H_INCLUDED
#define GAMEOVERSTATE_H_INCLUDED

#include "MenuState.hpp"
#include "GameObject.hpp"
#include <vector>


class GameOverState : public MenuState {
	private:
		static void game_over_to_main();
		static void restart_play();

		static const std::string game_over_id_;


		virtual void set_callbacks(const std::vector<Callback> & callbacks);

	public:
		virtual ~GameOverState();
		virtual void update();
		virtual void render();
		virtual bool onEnter();

		virtual std::string get_state_id() const;


};


#endif
