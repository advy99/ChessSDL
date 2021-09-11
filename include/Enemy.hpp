#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

class Enemy : public SDLGameObject {
	private:

	public:
		Enemy();
		virtual void load(const LoaderParams * params);
		virtual void draw();
		virtual void update();

};


class EnemyCreator : public BaseCreator {

	public:
		std::unique_ptr<GameObject> create_game_object() const;

};


#endif
