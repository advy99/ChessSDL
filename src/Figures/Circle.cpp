#include "Figures/Circle.hpp"
#include "Game.hpp"

Circle :: ~Circle(){}


Circle :: Circle(const int16_t x, const int16_t y, const int16_t radius_in_px, 
					  const Color & color) {
	std::unique_ptr<LoaderParams> params = std::make_unique<LoaderParams>(x, y, radius_in_px, 0, "", "", 0, 0, 0, color.get_color(), SDL_FLIP_NONE);
	load(params.get());
}

void Circle :: load(const LoaderParams * params) {
	SDLGameObject::load(params);	
}

void Circle :: draw()  {
	filledCircleColor(Game::get_renderer(), position_.get_x(), position_.get_y(), width_, color_.get_color());
}

void Circle :: update(){}

std::unique_ptr<GameObject> CircleCreator::create_game_object() const {
	return std::make_unique<Circle>();
}
