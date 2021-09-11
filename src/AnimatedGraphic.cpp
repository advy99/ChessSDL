#include "AnimatedGraphic.hpp"

AnimatedGraphic::AnimatedGraphic():SDLGameObject(){
}

void AnimatedGraphic::update() {
	current_frame_ = int( (SDL_GetTicks() / ( 1000 / animation_speed_ ))
								% num_frames_ ) ;
}

void AnimatedGraphic::draw() {
	SDLGameObject::draw();
}

void AnimatedGraphic::load(const LoaderParams * params) {
	SDLGameObject::load(params);
	animation_speed_ = params->get_anim_speed();
}

std::unique_ptr<GameObject> AnimatedGraphicCreator::create_game_object() const {
	return std::make_unique<AnimatedGraphic>();
}
