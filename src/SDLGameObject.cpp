#include "SDLGameObject.hpp"
#include "Game.hpp"

SDLGameObject::SDLGameObject() :GameObject(){

}

void SDLGameObject::draw(){

	// if its zero, the last used
	if ( velocity_.get_x() > 0 ) {
		last_flip_ = SDL_FLIP_HORIZONTAL;

	} else if ( velocity_.get_x() < 0 ) {
		last_flip_ = SDL_FLIP_NONE;
	}

	texture_.draw_frame(position_.get_x(),
							  position_.get_y(), width_, height_,
							  current_row_, current_frame_,
							  Game::get_renderer(),
							  last_flip_);
}

void SDLGameObject::update() {
	velocity_ += acceleration_;
	position_ += velocity_;
}

Vector2D SDLGameObject::get_position() const {
	return position_;
}

int SDLGameObject::get_width() const {
	return width_;
}

int SDLGameObject::get_height() const {
	return height_;
}

void SDLGameObject::load(const LoaderParams * params) {
	position_ = Vector2D(params->get_x(), params->get_x());
	velocity_ = Vector2D(0, 0);
	acceleration_ = Vector2D(0, 0);
	width_ = params->get_width();
	height_ = params->get_height();
	texture_id_ = params->get_texture_id();
	current_frame_ = 1;
	current_row_ = 1;
	num_frames_ = params->get_num_frames();
	last_flip_ = params->get_flip();

}
