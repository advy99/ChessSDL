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

void AnimatedGraphic::clean() {
	SDLGameObject::clean();
}

void AnimatedGraphic::load(const LoaderParams * params) {
	SDLGameObject::load(params);
	animation_speed_ = params->get_anim_speed();
}

/* GameObject * AnimatedGraphicCreator::createGameObject() const {
	return new AnimatedGraphic();
} */
