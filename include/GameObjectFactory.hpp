#ifndef GAMEOBJECTFACTORY_H_INCLUDED
#define GAMEOBJECTFACTORY_H_INCLUDED

#include <string>
#include <map>
#include "GameObject.hpp"

class BaseCreator {
	private:

	public:
		virtual GameObject * create_game_object () const = 0;
		virtual ~BaseCreator() {}

};


class GameObjectFactory {
	private:
		static std::map<std::string, BaseCreator *> creators;

	public:

		~GameObjectFactory();
		static bool register_type(const std::string type_id,  BaseCreator * creator);
		static GameObject * create(const std::string type_id);

};



#endif
