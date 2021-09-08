#ifndef STATEPARSER_H_INCLUDED
#define STATEPARSER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "GameObject.hpp"
#include "tinyxml2.h"

class StateParser {
	private:
		void parse_objects(tinyxml2::XMLElement * state,
								std::vector<GameObject> * objects);
		void parse_textures(tinyxml2::XMLElement * state,
								 std::vector<std::string> * texture_ids);

	public:
		bool parse_state(const char * state_file, const std::string state_id,
							 std::vector<GameObject> * objects,
							 std::vector<std::string> * texture_ids);


};



#endif
