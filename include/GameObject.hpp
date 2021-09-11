#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.hpp"
#include "LoaderParams.hpp"
#include <string>

class GameObject {
	private:

	protected:
		GameObject() {};


	public:
		virtual void draw() = 0;
		virtual void update() = 0;
		virtual void load(const LoaderParams * params) = 0;

		virtual ~GameObject(){};
};




#endif
