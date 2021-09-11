#include "GameObjectFactory.hpp"
#include <iostream>

GameObjectFactory::~GameObjectFactory() {
}

bool GameObjectFactory::register_type(const std::string type_id,
												  std::unique_ptr<BaseCreator> creator){
	auto it = creators.find(type_id);

	bool success = true;

	if ( it != creators.end() ) {
		success = false;
	} else {
		creators[type_id] = std::move(creator);
	}

	return success;

}

std::unique_ptr<GameObject> GameObjectFactory::create(const std::string type_id){
	std::unique_ptr<GameObject> created_object = nullptr;

	auto it = creators.find(type_id);

	if ( it == creators.end() ) {
		std::cerr << "ERROR : Could not find type: " << type_id << std::endl;

	} else {
		BaseCreator * new_creator = (*it).second.get();

		created_object = std::move(new_creator->create_game_object());
	}

	return created_object;

}

std::map<std::string, std::unique_ptr<BaseCreator> > GameObjectFactory :: creators;
