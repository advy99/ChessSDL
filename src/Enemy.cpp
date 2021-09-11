#include "Enemy.hpp"



Enemy::Enemy():SDLGameObject(){
}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::update() {

	current_frame_ = int( (SDL_GetTicks() / 100) % num_frames_ );

	if ( position_.get_y() < 0 ) {
		velocity_.set_y(2);

	} else if ( position_.get_y() > 400 ) {
		velocity_.set_y(-2);
	}

	SDLGameObject::update();
}


void Enemy::load(const LoaderParams * params) {
	SDLGameObject::load(params);
	velocity_.set_y(2);

}


std::unique_ptr<GameObject> EnemyCreator::create_game_object() const {
	return std::make_unique<Enemy>();
}
