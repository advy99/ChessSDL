#ifndef MENUBUTTON_H_INCLUDED
#define MENUBUTTON_H_INCLUDED

#include <functional>
#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"

class MenuButton : public SDLGameObject {
	private:
		enum class button_state{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};

		std::function<void()> callback_;
		int callback_id_;

		bool button_released_ = false;

	public:
		MenuButton();

		virtual void draw();
		virtual void update();
		virtual void load(const LoaderParams * params);

		void set_callback( const std::function<void()> & function );
		int get_callback_id() const;

};


class MenuButtonCreator : public BaseCreator {

	public:
		std::unique_ptr<GameObject> create_game_object() const;

};

#endif
