#ifndef STATEPARSER_H_INCLUDED
#define STATEPARSER_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "GameObject.hpp"
#include "tinyxml2.h"

class StateParser {
	private:
		static void parse_objects(tinyxml2::XMLElement * state,
								std::vector<std::unique_ptr<GameObject> > & objects);

	public:
		static bool parse_state(const char * state_file, const std::string & state_id,
							 std::vector<std::unique_ptr<GameObject> > & objects);

};



#endif
