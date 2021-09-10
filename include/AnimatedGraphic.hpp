#ifndef ANIMATEDGRAPHIC_H_INCLUDED
#define ANIMATEDGRAPHIC_H_INCLUDED

#include "SDLGameObject.hpp"
#include "LoaderParams.hpp"
#include "GameObjectFactory.hpp"

class AnimatedGraphic : public SDLGameObject{
	private:
		int animation_speed_;

	public:
		AnimatedGraphic();

		virtual void draw();
		virtual void update();
		virtual void clean();
		virtual void load(const LoaderParams * params);

};


/* class AnimatedGraphicCreator : public BaseCreator {

	public:
		GameObject * createGameObject() const;

}; */

#endif
