#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP 

#include "Figures/sdl_headers.hpp"
#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"
#include "Figures/Color.hpp"

class Rectangle : public SDLGameObject {
	private:

	public:
		Rectangle() = default;
		Rectangle(const int16_t x, const int16_t y, 
					 const int16_t width, const int16_t height,
					 const Color & color = {255, 255, 255, 255});

		virtual ~Rectangle();
		virtual void draw();
		virtual void update();
		virtual void load (const LoaderParams * params);

		int16_t width() const noexcept;
		int16_t height() const noexcept;

		void set_width(const int16_t width) noexcept;
		void set_height(const int16_t height) noexcept;

};

class RectangleCreator : public BaseCreator {

	public:
		std::unique_ptr<GameObject> create_game_object() const;

};

#endif
