#ifndef GAMEOBJECTFACTORY_H_INCLUDED
#define GAMEOBJECTFACTORY_H_INCLUDED

#include <string>
#include <map>
#include <memory>
#include "GameObject.hpp"

class BaseCreator {
	private:

	public:
		virtual std::unique_ptr<GameObject> create_game_object () const = 0;
		virtual ~BaseCreator() {}

};


class GameObjectFactory {
	private:
		static std::map<std::string, std::unique_ptr<BaseCreator> > creators;

	public:

		~GameObjectFactory();
		static bool register_type(const std::string type_id,  std::unique_ptr<BaseCreator> creator);
		static std::unique_ptr<GameObject> create(const std::string type_id);

};



#endif
