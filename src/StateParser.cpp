#include "StateParser.hpp"
#include "Game.hpp"

bool StateParser::parse_state(const char * state_file,
									  const std::string state_id,
									  std::vector<GameObject> & objects,
									  TextureManager & texture_manager){
	tinyxml2::XMLDocument xml_doc;

	bool success;

	success = tinyxml2::XMLError::XML_SUCCESS == xml_doc.LoadFile(state_file);

	if ( success ) {
		tinyxml2::XMLElement * root = xml_doc.RootElement();

		if ( root != nullptr ) {

			tinyxml2::XMLElement * state_root = nullptr;

			for ( tinyxml2::XMLElement * xml_ele = root->FirstChildElement();
					xml_ele != nullptr; xml_ele = xml_ele->NextSiblingElement() ) {
				if ( xml_ele->Value() == state_id ) {
					state_root = xml_ele;
				}
			}

			tinyxml2::XMLElement * texture_root = nullptr;

			for ( tinyxml2::XMLElement * xml_ele = state_root->FirstChildElement();
					xml_ele != nullptr; xml_ele = xml_ele->NextSiblingElement() ) {
				if ( xml_ele->Value() == std::string("TEXTURES" )) {
					texture_root = xml_ele;
				}
			}


			if ( texture_root != nullptr )
				parse_textures(texture_root, texture_manager);


			tinyxml2::XMLElement * object_root = nullptr;

			for ( tinyxml2::XMLElement * xml_ele = state_root->FirstChildElement();
					xml_ele != nullptr; xml_ele = xml_ele->NextSiblingElement() ) {
				if ( xml_ele->Value() == std::string("OBJECTS" )) {
					object_root = xml_ele;
				}
			}

			if ( object_root != nullptr )
				parse_objects(object_root, objects);
		}

	} else {
		std::cerr << xml_doc.ErrorStr() << std::endl;
	}


	return success;
}


void StateParser::parse_textures(tinyxml2::XMLElement * state,
										   TextureManager & texture_manager) {

	for ( tinyxml2::XMLElement * element = state->FirstChildElement();
			element != nullptr; element = element->NextSiblingElement() ){
		std::string file_name_atribbute = element->Attribute("filename");
		std::string id_atribbute = element->Attribute("ID");

		texture_ids->push_back(id_atribbute);
		texture_manager.load(file_name_atribbute, id_atribbute,
									Game::get_renderer());
	}

}

void StateParser::parse_objects(tinyxml2::XMLElement * state,
										 std::vector<GameObject> & objects){

	for ( tinyxml2::XMLElement * element = state->FirstChildElement();
			element != nullptr; element = element->NextSiblingElement() ) {

		int x, y, width, height, num_frames, callback_id, anim_speed;
		std::string texture_id;

		x = element->IntAttribute("x");
		y = element->IntAttribute("y");
		width = element->IntAttribute("width");
		height = element->IntAttribute("height");
		num_frames = element->IntAttribute("num_frames");
		callback_id = element->IntAttribute("callback_id");
		anim_speed = element->IntAttribute("anim_speed");

		texture_id = std::string(element->Attribute("texture_id"));

		LoaderParams * params = new LoaderParams(x, y, width, height, texture_id,
															  num_frames, callback_id,
															  anim_speed);

		// TODO: Fix call to GameObjectFactory, maybe a static method?
		GameObject object = GameObjectFactory::create(
												element->Attribute("type"));
		object->load(params);

		delete params;

		objects->push_back(object);
	}

}
