#include "LevelParser.hpp"
#include "Game.hpp"
#include "TileLayer.hpp"
#include "sstream"
#include "ObjectLayer.hpp"

std::unique_ptr<Level> LevelParser::parse_level(const char * level_file){
	tinyxml2::XMLDocument level_document;
	level_document.LoadFile(level_file);


	std::unique_ptr<Level> level = std::make_unique<Level>();


	tinyxml2::XMLElement * root = level_document.RootElement();

	tile_size = root->IntAttribute("tilewidth");
	width = root->IntAttribute("width");
	height = root->IntAttribute("height");

	for ( tinyxml2::XMLElement * element = root->FirstChildElement();
			element != nullptr;
			element = element->NextSiblingElement() ) {

		if ( element->Value() == std::string("tileset") ) {

			parseTilesets(element, level->getTilesets() );

		} else if ( element->Value() == std::string("properties") ) {

			for ( tinyxml2::XMLElement * property = element->FirstChildElement();
					property != nullptr;
					property = property->NextSiblingElement() ){
				parseTextures(property);
			}

		} else if ( element->Value() == std::string("layer") ) {

			parseTileLayer(element, level->getLayers(), level->getTilesets());

		} else if ( element->Value() == std::string("objectgroup") ) {

			parseObjectLayer(element, level->getLayers());

		}
	}




	return std::move(level);

}


void LevelParser::parseTilesets(tinyxml2::XMLElement * tile_element,
										  std::vector<Tileset> * tilesets){

	const char * element_source = tile_element->FirstChildElement()->
											Attribute("source");
	const char * element_name = tile_element->Attribute("name");

	TextureManager::getInstance()->load(element_source, element_name,
													Game::getInstance()->getRenderer());

	Tileset tileset;

	tileset.width = tile_element->FirstChildElement()->IntAttribute("width");
	tileset.height = tile_element->FirstChildElement()->IntAttribute("height");

	tileset.first_grid_id = tile_element->IntAttribute("firstgrid");
	tileset.tile_width = tile_element->IntAttribute("tilewidth");
	tileset.tile_height = tile_element->IntAttribute("tileheight");
	tileset.spacing = tile_element->IntAttribute("spacing");
	tileset.margin = tile_element->IntAttribute("margin");
	tileset.name = tile_element->Attribute("name");

	tileset.num_columns = tileset.width / (tileset.tile_width + tileset.spacing);

	tilesets->push_back(tileset);

}


void LevelParser::parseTileLayer(tinyxml2::XMLElement * tile_element,
											std::vector<Layer *> * layers,
											const std::vector<Tileset> * tilesets){
	TileLayer * tile_layer = new TileLayer(tile_size, *tilesets);

	std::vector<std::vector<int> > data;

	std::string ids;

	tinyxml2::XMLElement * data_node;


	for ( tinyxml2::XMLElement * element = tile_element->FirstChildElement();
			element != nullptr;
			element = element->NextSiblingElement() ) {
		if ( element->Value() == std::string("data") ) {
			data_node = element;
		}
	}

	for ( tinyxml2::XMLNode * element = data_node->FirstChild();
			element != nullptr;
			element = element->NextSibling() ) {
		tinyxml2::XMLText * text = element->ToText();
		ids = text->Value();
	}



	std::vector<int> layer_row(width);

	for ( int i = 0; i < height; i++ ){
		data.push_back(layer_row);
	}

	std::istringstream iss(ids);

	for ( int i = 0; i < height; i++ ) {
		for (int j = 0; j < width; j++){
			std::string value;
			getline(iss, value, ',');
			data[i][j] = atoi(value.c_str());
		}
	}

	tile_layer->setTileIDs(data);
	layers->push_back(tile_layer);

}


void LevelParser::parseTextures( tinyxml2::XMLElement * root ) {
	TextureManager::getInstance()->load(root->Attribute("value"),
													root->Attribute("name"),
													Game::getInstance()->getRenderer());
}


void LevelParser::parseObjectLayer( tinyxml2::XMLElement * root,
												std::vector<Layer *> * layers){
	ObjectLayer * object_layer = new ObjectLayer();

	for ( tinyxml2::XMLElement * element = root->FirstChildElement();
			element != nullptr;
			element = element->NextSiblingElement() ) {

		if ( element->Value() == std::string("object") ) {

			int num_frames = 1, width = 0, height = 0, callback_id = 0, anim_speed = 0;
			std::string texture_id;

			int x = element->IntAttribute("x");
			int y = element->IntAttribute("y");

			GameObject * game_object = GameObjectFactory::getInstance()->create(
														element->Attribute("type"));

			for ( tinyxml2::XMLElement * properties = element->FirstChildElement();
					properties != nullptr;
					properties = properties->NextSiblingElement() ) {

				if ( properties->Value() == std::string("properties") ) {

					for ( tinyxml2::XMLElement * pro = properties->FirstChildElement();
							pro != nullptr;
							pro = pro->NextSiblingElement() ) {

						if ( pro->Value() == std::string("property") ) {

							if ( pro->Attribute("name") == std::string("num_frames") ){
								num_frames = pro->IntAttribute("value");

							} else if ( pro->Attribute("name") ==
											std::string("texture_height") ) {
								height = pro->IntAttribute("value");

							} else if ( pro->Attribute("name") ==
											std::string("texture_width") ){
								width = pro->IntAttribute("value");

							} else if ( pro->Attribute("name") ==
											std::string("texture_id") ){
								texture_id = pro->Attribute("value");

							} else if ( pro->Attribute("name") ==
											std::string("callback_id")	){
								callback_id = pro->IntAttribute("value");

							} else if ( pro->Attribute("name") ==
											std::string("anum_speed") ){
								anim_speed = pro->IntAttribute("value");

							}




						}
					}
				}
			}

			LoaderParams * params = new LoaderParams(x, y, width, height,
																  texture_id, num_frames,
																  callback_id, anim_speed);

			game_object->load(params);
			object_layer->getGameObjects()->push_back(game_object);

			delete params;

		}
	}

	layers->push_back(object_layer);
}
