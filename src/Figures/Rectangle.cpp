#include "Figures/Rectangle.hpp"
#include "Game.hpp"

Rectangle :: Rectangle(const int16_t x, const int16_t y, 
					 const int16_t width, const int16_t height,
					 const Color & color) {
	std::unique_ptr<LoaderParams> params = std::make_unique<LoaderParams>(x, y, width, height, "", "", 0, 0, 0, color.get_color(), SDL_FLIP_NONE);
	load(params.get());
}

Rectangle :: ~Rectangle(){}

void Rectangle :: draw() {

	uint16_t x_pos = position_.get_x();
	uint16_t y_pos = position_.get_y();

	boxRGBA(Game::get_renderer(), x_pos, y_pos, x_pos + width_, y_pos + height_, color_.red(), color_.green(), color_.blue(), color_.alpha());
}

void Rectangle :: update() {}

void Rectangle :: load(const LoaderParams * params) {
	SDLGameObject::load(params);	
}

int16_t Rectangle :: width() const noexcept {
	return width_;
}

int16_t Rectangle :: height() const noexcept {
	return height_;
}

void Rectangle :: set_width(const int16_t width) noexcept {
	width_ = width;
}

void Rectangle :: set_height(const int16_t height) noexcept {
	height_ = height;
}


std::unique_ptr<GameObject> RectangleCreator::create_game_object() const {
	return std::make_unique<Rectangle>();
}
