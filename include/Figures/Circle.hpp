#ifndef CIRCLE_HPP
#define CIRCLE_HPP 

#include "Figures/sdl_headers.hpp"
#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"
#include "Figures/Color.hpp"

class Circle : public SDLGameObject {
	private:

	public:
		Circle() = default;
		Circle(const int16_t x, const int16_t y, const int16_t radius_in_px, 
				 const Color & color = {255, 255, 255, 255});

		virtual ~Circle();
		virtual void draw()  override;
		virtual void update()  override;
		virtual void load(const LoaderParams * params);

		int16_t radius_in_px () const noexcept;

		void set_radius_in_px(const int16_t radius) noexcept;


};

class CircleCreator : public BaseCreator {

	public:
		std::unique_ptr<GameObject> create_game_object() const;

};

#endif 
