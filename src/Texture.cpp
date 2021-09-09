#include "Texture.hpp"

#include <iostream>


Texture :: ~Texture(){
	SDL_DestroyTexture(texture_);

}


bool Texture :: load(const std::string & file, const std::string & id,
									 SDL_Renderer * g_renderer){

	bool success = true;

	SDL_Surface * asset_surface = IMG_Load(file.c_str());

	if (asset_surface != nullptr) {
		SDL_Texture * texture;
		texture = SDL_CreateTextureFromSurface(g_renderer, asset_surface);

		SDL_FreeSurface(asset_surface);

		if (texture != nullptr){
			texture_ = texture;
			texture_id_ = id;
		} else {
			std::cerr << "Failed to load texture "  << std::endl;
			std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
			success = false;
		}

	} else {
		std::cerr << "Failed to load surface from " << file << std::endl;
		std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}




void Texture :: draw(const int X, const int Y,
								  const int WIDTH, const int HEIGHT,
								  SDL_Renderer * g_renderer,
								  const SDL_RendererFlip FLIP){
	SDL_Rect source_rect;
	SDL_Rect dest_rect;

	source_rect.x = 0;
	source_rect.y = 0;
	source_rect.w = dest_rect.w = WIDTH;
	source_rect.h = dest_rect.h = HEIGHT;

	dest_rect.x = X;
	dest_rect.y = Y;

	SDL_RenderCopyEx(g_renderer, texture_,
						  &source_rect, &dest_rect,
						  0, 0, FLIP);

}


void Texture :: draw_frame(const int X, const int Y,
										 	 const int WIDTH, const int HEIGHT,
										 	 const int CURRENT_ROW, const int CURRENT_FRAME,
										 	 SDL_Renderer * g_renderer,
										 	 const SDL_RendererFlip FLIP){
	SDL_Rect source_rect;
	SDL_Rect dest_rect;

	source_rect.x = WIDTH * CURRENT_FRAME;
	source_rect.y = HEIGHT * (CURRENT_ROW - 1);
	source_rect.w = dest_rect.w = WIDTH;
	source_rect.h = dest_rect.h = HEIGHT;

	dest_rect.x = X;
	dest_rect.y = Y;

	SDL_RenderCopyEx(g_renderer, texture_,
						  &source_rect, &dest_rect,
						  0, 0, FLIP);

}



void Texture :: draw_tile( const int MARGIN,
										const int SPACING, const int X, const int Y,
										const int WIDTH, const int HEIGHT,
										const int CURRENT_ROW, const int CURRENT_FRAME,
										SDL_Renderer * renderer) {
	SDL_Rect src_rect;
	SDL_Rect dest_rect;

	src_rect.x = MARGIN + (SPACING + WIDTH) * CURRENT_FRAME;
	src_rect.y = MARGIN + (SPACING + HEIGHT) * CURRENT_ROW;
	src_rect.w = dest_rect.w = WIDTH;
	src_rect.h = dest_rect.h = HEIGHT;

	dest_rect.x = X;
	dest_rect.y = Y;

	SDL_RenderCopyEx(renderer, texture_, &src_rect, &dest_rect,
						  0, 0, SDL_FLIP_NONE);
}

std::string Texture :: get_texture_id() const {
	return texture_id_;
}

