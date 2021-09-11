#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

class Player : public SDLGameObject {
	private:
		void handle_input();

	public:
		Player();

		virtual void load(const LoaderParams * params);

		virtual void draw();
		virtual void update();

};

class PlayerCreator : public BaseCreator {

	public:
		std::unique_ptr<GameObject> create_game_object() const;

};

#endif
