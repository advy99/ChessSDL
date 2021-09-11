#include "LoaderParams.hpp"

LoaderParams::LoaderParams(const int X, const int Y,
									const int WIDTH, const int HEIGHT,
									const std::string & id,const std::string & path, const int NUM_FRAMES,
									const int CALLBACK_ID, const int ANIM_SPEED, const uint32_t color,
									const SDL_RendererFlip INIT_FLIP)
									:x_pos_(X), y_pos_(Y), width_(WIDTH), height_(HEIGHT),
									texture_id_(id), texture_path_(path), num_frames_(NUM_FRAMES),
									callback_id_(CALLBACK_ID), anim_speed_(ANIM_SPEED), color_(color),
									flip_(INIT_FLIP){


}

int LoaderParams::get_x() const{
	return x_pos_;
}

int LoaderParams::get_y() const{
	return y_pos_;
}

uint32_t LoaderParams::get_color() const{
	return color_;
}

int LoaderParams::get_width() const{
	return width_;
}


int LoaderParams::get_height() const{
	return height_;
}


std::string LoaderParams::get_texture_id() const{
	return texture_id_;
}


std::string LoaderParams::get_texture_path() const{
	return texture_path_;
}

SDL_RendererFlip LoaderParams::get_flip() const {
	return flip_;
}

int LoaderParams::get_anim_speed() const {
	return anim_speed_;
}

int LoaderParams::get_callback_id() const {
	return callback_id_;
}

int LoaderParams::get_num_frames() const {
	return num_frames_;
}
