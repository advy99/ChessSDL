#ifndef OBJECTLAYER_H_INCLUDED
#define OBJECTLAYER_H_INCLUDED

#include "Layer.hpp"
#include "GameObject.hpp"
#include <vector>

class ObjectLayer : public Layer {
	private:
		std::vector<GameObject> game_objects_;

	public:
		virtual ~ObjectLayer();
		virtual void update();
		virtual void render();
		std::vector<GameObject> * get_game_objects();

};


#endif
