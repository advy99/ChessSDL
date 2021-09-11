#ifndef PAUSESTATE_H_INCLUDED
#define PAUSESTATE_H_INCLUDED

#include "MenuState.hpp"
#include "GameObject.hpp"
#include <vector>

class PauseState : public MenuState {
	private:
		static void pause_to_main();
		static void resume_play();

		static const std::string pause_id_;


		virtual void set_callbacks(const std::vector<std::function<void()> > & callbacks);

	public:
		virtual ~PauseState();

		virtual void update();
		virtual void render();

		virtual bool on_enter();

		virtual std::string get_state_id() const;


};


#endif
