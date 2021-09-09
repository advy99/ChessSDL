#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <vector>
#include <string>
#include "Layer.hpp"

struct Tileset {
	int first_grid_id;
	int tile_width;
	int tile_height;
	int spacing;
	int margin;
	int width;
	int height;
	int num_columns;
	std::string name;
	Texture texture;
};

class Level {
	private:
		std::vector<Tileset> tilesets_;
		std::vector<Layer> layers_;

		friend class LevelParser;
		Level() {};

	public:
		~Level();

		void update();
		void render();

		std::vector<Tileset> * get_tilesets();
		std::vector<Layer> * get_layers();

};


#endif
