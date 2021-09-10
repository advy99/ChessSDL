#include "ObjectLayer.hpp"


ObjectLayer::~ObjectLayer(){

}


void ObjectLayer::update() {
	for ( unsigned i = 0; i < game_objects_.size(); i++ ) {
		game_objects_[i]->update();
	}
}


void ObjectLayer::render() {
	for ( unsigned i = 0; i < game_objects_.size(); i++ ) {
		game_objects_[i]->draw();
	}
}

std::vector<std::unique_ptr<GameObject> > * ObjectLayer::get_game_objects() {
	return &game_objects_;
}
