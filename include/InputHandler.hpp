#ifndef INPUTHANDLER_H_INCLUDED
#define INPUTHANDLER_H_INCLUDED

#include <vector>
#include "Vector2D.h"
#include <SDL2/SDL.h>

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {
	private:
		bool joysticks_initialised_;
		std::vector<SDL_Joystick *> joysticks_;
		std::vector<std::pair<Vector2D , Vector2D > > joystick_values_;
		std::vector<std::vector<bool> > button_states_;

		std::vector<bool> mouse_button_states_;

		Vector2D mouse_position_;
		Uint8 * key_state_;

		void on_joystick_axis_move(const SDL_Event event);
		void on_joystick_button_down(const SDL_Event event);
		void on_joystick_button_up( const SDL_Event event );
		void on_mouse_button_down( const SDL_Event event );
		void on_mouse_button_up( const SDL_Event event );
		void on_mouse_motion ( const SDL_Event event );




		const int joystick_dead_zone_ = 10000;

	public:
		InputHandler();
		~InputHandler();

		void update();

		void initialise_joysticks();
		bool joysticks_initialised() const;

		int x_value(const int joy, const int stick) const;
		int y_value(const int joy, const int stick) const;
		bool get_button_state(const int joy, const int button_number) const;
		bool get_mouse_button_state(const int button) const;

		Vector2D get_mouse_position() const;
		bool is_key_down(const SDL_Scancode key) const;

		void reset();

};



#endif
