#ifndef TILELAYER_H_INCLUDED
#define TILELAYER_H_INCLUDED

#include "Layer.hpp"
#include "Level.hpp"
#include "Vector2D.hpp"
#include <vector>

class TileLayer : public Layer {
	private:
		int num_cols;
		int num_rows;
		int tile_size;

		Vector2D position;
		Vector2D velocity;

		const std::vector<Tileset> tilesets;

		std::vector<std::vector<int> > tile_ids;

	public:
		TileLayer(const int TILE_SIZE, const std::vector<Tileset> tilesets);

		virtual void update();
		virtual void render();

		void set_tile_ids(const std::vector<std::vector<int> > & data);
		void set_tile_size(const int SIZE);

		Tileset get_tileset(const int TILE_ID) const;
};

#endif
