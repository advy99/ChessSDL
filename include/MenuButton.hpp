#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED

#include "SDLGameObject.h"
#include "GameObjectFactory.hpp"

class MenuButton : public SDLGameObject {
	private:
		enum class button_state{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};

		void (*callback) ();
		int callback_id_;

		bool button_released_;

	public:
		MenuButton();

		virtual void draw();
		virtual void update();
		virtual void load(const LoaderParams * params);

		void set_callback( void (*func)()  );
		int get_callback_id() const;

};


class MenuButtonCreator : public BaseCreator {

	public:
		GameObject create_game_object() const;

};

#endif
