#ifndef SDLGAMEOBJECT_H_INCLUDED
#define SDLGAMEOBJECT_H_INCLUDED

#include <string>
#include "GameObject.hpp"
#include "LoaderParams.hpp"
#include "Vector2D.hpp"

#include "SDL2/SDL.h"

class SDLGameObject : public GameObject{
	private:

	protected:
		Vector2D position_;
		Vector2D velocity_;
		Vector2D acceleration_;

		int current_frame_;
		int current_row_;

		int width_;
		int height_;

		SDL_RendererFlip last_flip_;

		std::string texture_id_;

		int num_frames_;

	public:
		//virtual void load(const int X, const int Y, const int WIDTH, const int HEIGHT,
		//			 const std::string id);
		SDLGameObject();

		virtual void draw();
		virtual void update();
		virtual void clean();

		Vector2D get_position() const;
		int get_width() const;
		int get_height() const;

		virtual void load(const LoaderParams * params);



};






#endif
