#include "TileLayer.hpp"
#include "Game.hpp"
#include <iostream>


TileLayer::TileLayer(const int TILE_SIZE, const std::vector<Tileset> TILESETS)
							:tile_size(TILE_SIZE), tilesets(TILESETS){
	position = Vector2D(0,0);
	velocity = Vector2D(0,0);

	num_cols = (Game::width() / tile_size);
	num_rows = (Game::height() / tile_size);

}


void TileLayer::set_tile_ids(const std::vector<std::vector<int> > & data) {
	tile_ids = data;
}


void TileLayer::set_tile_size(const int SIZE) {
	tile_size = SIZE;
}

Tileset TileLayer::get_tileset(const int TILE_ID) const {
	bool found = false;
	Tileset tileset;

	for ( unsigned i = 0; i < tilesets.size() && !found; i++ ) {

		if ( i + 1 < tilesets.size() - 1){

			if ( TILE_ID >= tilesets[i].first_grid_id &&
				  TILE_ID < tilesets[i + 1].first_grid_id	) {
				found = true;
				tileset = tilesets[i];
			}

		} else {

			found = true;
			tileset = tilesets[i];
		}

	}

	if ( !found ) {
		std::cerr << "WARNING: Tileset not found: returning empty tileset" << std::endl;
	}

	return tileset;
}

void TileLayer::update(){
	position += velocity;
	// velocity.setX(1);
}

void TileLayer::render() {
	int x = 0;
	int y = 0;
	int x2 = 0;
	int y2 = 0;

	x = position.getX() / tile_size;
	y = position.getY() / tile_size;

	x2 = int(position.getX()) % tile_size;
	y2 = int(position.getY()) % tile_size;

	for ( int i = 0; i < num_rows; i++ ) {
		for ( int j = 0; j <= num_cols && j < (int) tile_ids[i].size(); j++ ) {
			int id = tile_ids[i + y][j + x];

			if ( id != 0 ) {
				Tileset tileset = get_tileset(id);

				id--;

				tileset.texture.draw_tile(
								tileset.margin, tileset.spacing,
								(j * tile_size) - x2,
								(i * tile_size) - y2,
								tile_size, tile_size,
								(id - tileset.first_grid_id) / tileset.num_columns,
								(id - tileset.first_grid_id) % tileset.num_columns,
								Game::get_renderer());

			}

		}
	}

}
