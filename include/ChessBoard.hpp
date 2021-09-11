#ifndef CHESSBOARD_H_INCLUDED
#define CHESSBOARD_H_INCLUDED

#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"
#include "Figures/Rectangle.hpp"
#include <vector>

class ChessBoard : public SDLGameObject {
	private:

		Rectangle edge_;
		// std::vector<std::unique_ptr<ChessPiece> > pieces_;
		std::vector< std::vector<std::unique_ptr<Rectangle> > > positions_;

		void create_board();

	public:
		static const uint32_t NUM_ROWS = 8;
		static const uint32_t NUM_COLS = 8;
		static const uint32_t POSITION_WIDTH = 50;
		static const uint32_t POSITION_HEIGHT = 50;

		ChessBoard();

		virtual void load(const LoaderParams * params);

		virtual void draw();
		virtual void update();

};

class ChessBoardCreator : public BaseCreator {

	public:
		std::unique_ptr<GameObject> create_game_object() const;

};

#endif
