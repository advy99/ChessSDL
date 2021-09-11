#include "Player.hpp"
#include "InputHandler.hpp"

Player::Player(  ):SDLGameObject(){

}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update() {
	velocity_.set_x(0);
	velocity_.set_y(0);

	handle_input();

	current_frame_ = int( (SDL_GetTicks() / 100) % num_frames_  );


	SDLGameObject::update();
}

void Player::handle_input() {

	Vector2D target = InputHandler::get_mouse_position();

	velocity_ = target - position_;

	velocity_ /= 10;

}

void Player::load(const LoaderParams * params) {
	SDLGameObject::load(params);
}


std::unique_ptr<GameObject> PlayerCreator::create_game_object() const {
	return std::make_unique<Player>();
}
