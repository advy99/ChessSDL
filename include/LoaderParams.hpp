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
		std::string texture_path_;

		int num_frames_;
		int callback_id_;
		int anim_speed_;
		uint32_t color_;

		SDL_RendererFlip flip_;

	public:
		LoaderParams(const int X, const int Y, const int WIDTH, const int HEIGHT,
						 const std::string & id, const std::string & path, const int NUM_FRAMES,
						 const int CALLBACK_ID = 0, const int ANIM_SPEED = 0, const uint32_t color = 0x000000FF,
						 const SDL_RendererFlip flip = SDL_FLIP_NONE);

		int get_x() const;
		int get_y() const;
		int get_width() const;
		int get_height() const;
		uint32_t get_color() const;
		std::string get_texture_id() const;
		std::string get_texture_path() const;

		SDL_RendererFlip get_flip() const;
		int get_anim_speed() const;
		int get_callback_id() const;
		int get_num_frames() const;


};


#endif
