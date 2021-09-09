#include "Level.hpp"

Level::~Level() {
}

std::vector<Tileset> * Level::get_tilesets() {
	return &tilesets_;
}

std::vector<Layer> * Level::get_layers() {
	return &layers_;
}

void Level::update() {
	for ( unsigned i = 0; i < layers_.size(); i++ ) {
		layers_[i].update();
	}
}



void Level::render() {
	for ( unsigned i = 0; i < layers_.size(); i++ ) {
		layers_[i].render();
	}
}
