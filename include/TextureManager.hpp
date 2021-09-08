#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager {
	private:
		std::map<std::string, SDL_Texture *> texture_map_;


	public:
		
		~TextureManager();


		bool load(const std::string file, const std::string id,
					 SDL_Renderer * g_renderer);

		void draw(const std::string id, const int X, const int Y,
					 const int WIDTH, const int HEIGHT,
					 SDL_Renderer * g_renderer,
					 const SDL_RendererFlip flip = SDL_FLIP_NONE);

		void drawFrame(const std::string id, const int X, const int Y,
							const int WIDTH, const int HEIGHT,
							const int CURRENT_ROW, const int CURRENT_FRAME,
							SDL_Renderer * g_renderer,
							const SDL_RendererFlip flip = SDL_FLIP_NONE);

		void clearFromTextureMap(const std::string id);

		void drawTile(const std::string id, const int MARGIN, const int SPACING,
						  const int X, const int Y, const int WIDTH, const int HEIGHT,
						  const int CURRENT_ROW, const int CURRENT_FRAME,
						  SDL_Renderer * renderer);


};


#endif
