#ifndef OBJECTLAYER_H_INCLUDED
#define OBJECTLAYER_H_INCLUDED

#include "Layer.hpp"
#include "GameObject.hpp"
#include <vector>
#include <memory>

class ObjectLayer : public Layer {
	private:
		std::vector<std::unique_ptr<GameObject> > game_objects_;

	public:
		virtual ~ObjectLayer();
		virtual void update();
		virtual void render();
		std::vector<std::unique_ptr<GameObject> > * get_game_objects();

};


#endif
