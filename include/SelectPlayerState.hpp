#ifndef SELECTPLAYERSTATE_H_INCLUDED
#define SELECTPLAYERSTATE_H_INCLUDED

#include "MenuState.hpp"
#include "GameObject.hpp"
#include <vector>

class SelectPlayerState : public MenuState {
	private:
		static const std::string menu_id_;


		static void select_player_to_play();
		static void select_player_to_menu();


		virtual void set_callbacks(const std::vector<Callback> & callbacks);

	public:
		virtual ~SelectPlayerState();
		virtual void update();
		virtual void render();

		virtual bool on_enter();

		virtual std::string get_state_id() const;

};


#endif
