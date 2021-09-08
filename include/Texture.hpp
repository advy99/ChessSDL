#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
	private:
		std::string texture_id_;

		SDL_Texture * texture_ = nullptr;


	public:
		
		~Texture();


		bool load(const std::string file, const std::string id,
					 SDL_Renderer * g_renderer);

		void draw(const std::string id, const int X, const int Y,
					 const int WIDTH, const int HEIGHT,
					 SDL_Renderer * g_renderer,
					 const SDL_RendererFlip flip = SDL_FLIP_NONE);

		void draw_frame(const std::string id, const int X, const int Y,
							const int WIDTH, const int HEIGHT,
							const int CURRENT_ROW, const int CURRENT_FRAME,
							SDL_Renderer * g_renderer,
							const SDL_RendererFlip flip = SDL_FLIP_NONE);

		void clear_from_texture_map(const std::string id);

		void draw_tile(const std::string id, const int MARGIN, const int SPACING,
						  const int X, const int Y, const int WIDTH, const int HEIGHT,
						  const int CURRENT_ROW, const int CURRENT_FRAME,
						  SDL_Renderer * renderer);


};


#endif
