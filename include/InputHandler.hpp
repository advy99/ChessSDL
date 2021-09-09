#ifndef INPUTHANDLER_H_INCLUDED
#define INPUTHANDLER_H_INCLUDED

#include <vector>
#include "Vector2D.hpp"
#include <SDL2/SDL.h>

enum class mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {
	private:
		static bool joysticks_initialised_;
		static std::vector<SDL_Joystick *> joysticks_;
		static std::vector<std::pair<Vector2D , Vector2D > > joystick_values_;
		static std::vector<std::vector<bool> > button_states_;

		static std::vector<bool> mouse_button_states_;

		static Vector2D mouse_position_;
		static Uint8 * key_state_;

		static void on_joystick_axis_move(const SDL_Event event);
		static void on_joystick_button_down(const SDL_Event event);
		static void on_joystick_button_up( const SDL_Event event );
		static void on_mouse_button_down( const SDL_Event event );
		static void on_mouse_button_up( const SDL_Event event );
		static void on_mouse_motion ( const SDL_Event event );




		static const int joystick_dead_zone_ = 10000;

	public:

		static void update();

		static void initialise_joysticks();
		static bool joysticks_initialised() const;

		static int x_value(const int joy, const int stick) const;
		static int y_value(const int joy, const int stick) const;
		static bool get_button_state(const int joy, const int button_number) const;
		static bool get_mouse_button_state(const int button) const;

		static Vector2D get_mouse_position() const;
		static bool is_key_down(const SDL_Scancode key) const;

		static void reset();

};



#endif
