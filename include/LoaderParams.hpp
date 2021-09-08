#ifndef LOADERPARAMS_H_INCLUDED
#define LOADERPARAMS_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>

class LoaderParams {
	private:

		int x_pos_;
		int y_pos_;


		int width_;
		int height_;

		std::string texture_id_;

		int num_frames_;
		int callback_id_;
		int anim_speed_;

		SDL_RendererFlip flip_;

	public:
		LoaderParams(const int X, const int Y, const int WIDTH, const int HEIGHT,
						 const std::string id, const int NUM_FRAMES,
						 const int CALLBACK_ID = 0, const int ANIM_SPEED = 0,
						 const SDL_RendererFlip flip = SDL_FLIP_NONE);

		int get_x() const;
		int get_y() const;
		int get_width() const;
		int get_height() const;
		std::string get_texture_id() const;

		SDL_RendererFlip get_flip() const;
		int get_anim_speed() const;
		int get_callback_id() const;
		int get_num_frames() const;


};


#endif
