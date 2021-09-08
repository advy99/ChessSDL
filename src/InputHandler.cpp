#include "InputHandler.h"
#include <iostream>
#include "Game.h"

InputHandler :: InputHandler() {
	joysticks_initialised_ = false;

	mouse_button_states_ = std::vector<bool>(3, false);

	mouse_position_ = Vector2D(0, 0);
	key_state_ = nullptr;
}

InputHandler :: ~InputHandler(){
	while (!joysticks.empty()){
		SDL_JoystickClose(joysticks.back());
		joysticks.pop_back();
	}


}

bool InputHandler :: joysticks_initialised() const {
	return joysticks_initialised_;
}


void InputHandler :: update(){
	SDL_Event event;

	while ( SDL_PollEvent(&event) ){

		key_state_ = const_cast <Uint8*> ( SDL_GetKeyboardState( nullptr ) );

		if (event.type == SDL_QUIT){
			Game::quit();
		} else if ( event.type == SDL_JOYAXISMOTION ) {
			on_joystick_axis_move(event);

		} else if ( event.type == SDL_JOYBUTTONDOWN ) {
			on_joystick_button_down(event);

		} else if ( event.type == SDL_JOYBUTTONUP ) {
			on_joystick_button_up(event);

		} else if ( event.type == SDL_MOUSEBUTTONDOWN ) {
			on_mouse_button_down(event);

		} else if ( event.type == SDL_MOUSEBUTTONUP ) {
			on_mouse_button_up(event);

		} else if ( event.type == SDL_MOUSEMOTION ) {
			on_mouse_motion(event);

		}




	}
}

void InputHandler :: on_joystick_button_down(const SDL_Event event){
	button_states_[event.jaxis.which][event.jbutton.button] = true;
}

void InputHandler :: on_joystick_button_up(const SDL_Event event) {
	button_states_[event.jaxis.which][event.jbutton.button] = false;
}

void InputHandler :: on_mouse_button_down(const SDL_Event event) {

	// El izquierdo es 1, central 2 y derecha 3
	// por lo que le restamos 1 para tener 0, 1 y 2
	mouse_button_states_[event.button.button - 1] = true;

}


void InputHandler :: on_mouse_button_up(const SDL_Event event) {

	// El izquierdo es 1, central 2 y derecha 3
	// por lo que le restamos 1 para tener 0, 1 y 2
	mouse_button_states_[event.button.button - 1] = false;

}

void InputHandler :: on_mouse_motion( const SDL_Event event ) {

	mouse_position_.set_x(event.motion.x);
	mouse_position_.set_y(event.motion.y);
}



void InputHandler :: initialise_joysticks(){
	Uint32 init_joysticks = SDL_INIT_JOYSTICK;

	if ( SDL_WasInit(init_joysticks) != init_joysticks ){
		SDL_InitSubSystem(init_joysticks);
	}

	for (int i = 0; i < SDL_NumJoysticks(); i++){
		SDL_Joystick * joy = SDL_JoystickOpen(i);

		if ( joy != nullptr ){
			joysticks_.push_back(joy);

			Vector2D stick1 = Vector2D(0,0);
			Vector2D stick2 = Vector2D(0,0);

			joystick_values_.push_back(std::make_pair(stick1, stick2));

			std::vector<bool> tmp_buttons =
									std::vector<bool>(SDL_JoystickNumButtons(joy), false);

			button_states_.push_back(tmp_buttons);


		} else {
			std::cerr << SDL_GetError() << std::endl;
		}

	}

	joysticks_initialised_ = !joysticks.empty();

	if (joysticks_initialised_){
		SDL_JoystickEventState(SDL_ENABLE);
	}


}


int InputHandler :: x_value(const int joy, const int stick) const{
	int valor = 0;

	if ( !joystick_values_.empty() ){
		if ( stick == 1 ){
			valor = joystick_values_[joy].first.get_x();
		} else if ( stick == 2 ) {
			valor = joystick_values_[joy].second.get_x();
		}
	}


	return valor;
}

int InputHandler :: y_value(const int joy, const int stick) const{
	int valor = 0;

	if ( !joystick_values_.empty() ){
		if ( stick == 1 ){
			valor = joystick_values_[joy].first.get_y();
		} else if ( stick == 2 ) {
			valor = joystick_values_[joy].second.get_y();
		}
	}


	return valor;
}


bool InputHandler :: get_button_state(const int joy, const int button_number)const{
	return button_states_[joy][button_number];
}

bool InputHandler :: get_mouse_button_state(const int button) const {
	return mouse_button_states_[button];
}

Vector2D InputHandler :: get_mouse_position() const {
	return mouse_position_;
}

bool InputHandler :: is_key_down(const SDL_Scancode key) const {
	bool is_down = false;

	if (key_state_ != nullptr){
		is_down = key_state_[key] == 1;
	}

	return is_down;


}

void InputHandler::onJoystickAxisMove(const SDL_Event event){

	int which_one = event.jaxis.which;

	if ( event.jaxis.axis == 0 ) {
		if ( event.jaxis.value > joystick_dead_zone_ ){
			joystick_values_[which_one].first.set_x(1);
		} else if ( event.jaxis.value < -joystick_dead_zone_ ){
			joystick_values_[which_one].first.set_x(-1);
		} else {
			joystick_values_[which_one].first.set_x(0);
		}
	} else if ( event.jaxis.axis == 1 ) {

		if ( event.jaxis.value > joystick_dead_zone_ ){
			joystick_values_[which_one].first.set_y(1);
		} else if ( event.jaxis.value < -joystick_dead_zone ){
			joystick_values_[which_one].first.set_y(-1);
		} else {
			joystick_values_[which_one].first.set_y(0);
		}
	} else if ( event.jaxis.axis == 3 ) {

		if ( event.jaxis.value > joystick_dead_zone_ ){
			joystick_values_[which_one].second.set_x(1);
		} else if ( event.jaxis.value < -joystick_dead_zone_ ){
			joystick_values_[which_one].second.set_x(-1);
		} else {
			joystick_values_[which_one].second.set_x(0);
		}
	} else if ( event.jaxis.axis == 4 ) {

		if ( event.jaxis.value > joystick_dead_zone_ ){
			joystick_values_[which_one].second.set_y(1);
		} else if ( event.jaxis.value < -joystick_dead_zone_ ){
			joystick_values_[which_one].second.set_y(-1);
		} else {
			joystick_values_[which_one].second.set_y(0);
		}
	}

}

void InputHandler :: reset(){
	mouse_button_states_ = std::vector<bool>(3, false);
}

