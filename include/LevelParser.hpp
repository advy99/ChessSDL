#ifndef LEVELPARSER_H_INCLUDE
#define LEVELPARSER_H_INCLUDE

#include <memory>
#include "tinyxml2.h"
#include "Level.hpp"

class LevelParser {
	private:

		static int tile_size;
		static int width;
		static int height;


		static void parse_tilesets(tinyxml2::XMLElement * tileset_root,
								 std::vector<Tileset> * tilesets);

		static void parse_tile_layer(tinyxml2::XMLElement * tile_element,
								  std::vector<std::unique_ptr<Layer> > * layers,
								  const std::vector<Tileset> * tilesets);

		static void parse_textures(tinyxml2::XMLElement * root);

		static void parse_object_layer(tinyxml2::XMLElement * object,
									 std::vector<std::unique_ptr<Layer> > * layers);


	public:
		static std::unique_ptr<Level> parse_level(const char * level_file);

};


#endif
