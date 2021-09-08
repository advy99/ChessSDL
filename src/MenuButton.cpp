#include "MenuButton.hpp"
#include "InputHandler.hpp"

MenuButton::MenuButton()
							  :SDLGameObject(){
}


void MenuButton::draw() {
	SDLGameObject::draw();
}


void MenuButton::update() {
	// TODO: this need to be static in input handler
	Vector2D mouse_position = InputHandler::get_mouse_position();


	if ( mouse_position.get_x() < position.get_x() + width &&
		  mouse_position.get_x() > position.get_x() &&
		  mouse_position.get_y() < position.get_y() + height &&
		  mouse_position.get_y() > position.get_y()) {


		if ( InputHandler::get_mouse_button_state(LEFT) &&
			  button_released_) {
			current_frame_ = button_state::CLICKED;

			callback();

			button_released_ = false;
		} else if ( !InputHandler::get_mouse_button_state(LEFT) ) {
			button_released_ = true;
			current_frame_ = button_state::MOUSE_OVER;
		}


	} else {
		current_frame_ = button_state::MOUSE_OUT;
	}

}


void MenuButton::load(const LoaderParams * params) {
	SDLGameObject::load(params);
	callback_id = params->get_callback_id();
	current_frame = button_state::MOUSE_OUT;
}

void MenuButton::set_callback( void (*func)()  ) {
	callback = func;
}

int MenuButton::get_callback_id() const {
	return callback_id;
}



GameObject MenuButtonCreator::create_game_object() const {
	return MenuButton();
}
