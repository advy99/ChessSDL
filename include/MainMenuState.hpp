#ifndef MAINMENUSTATE_H_INCLUDED
#define MAINMENUSTATE_H_INCLUDED

#include "MenuState.hpp"
#include "GameObject.hpp"
#include <vector>

class MainMenuState : public MenuState {
	private:
		static const std::string menu_id_;


		static void menu_to_play();
		static void exit_from_menu();


		virtual void set_callbacks(const std::vector<Callback> & callbacks);

	public:
		virtual ~MainMenuState();
		virtual void update();
		virtual void render();

		virtual bool on_enter();

		virtual std::string get_state_id() const;

};


#endif
