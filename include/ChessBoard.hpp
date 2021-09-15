#ifndef CHESSBOARD_H_INCLUDED
#define CHESSBOARD_H_INCLUDED

#include "SDLGameObject.hpp"
#include "GameObjectFactory.hpp"
#include "Figures/Rectangle.hpp"
#include "ChessPieces/ChessPiece.hpp"
#include <vector>

class ChessBoard : public SDLGameObject {
	private:
		static const Color position_color_black_;
		static const Color position_color_white_;
		static const Color edge_color_;

		Rectangle edge_;
		std::vector< std::vector< std::unique_ptr<ChessPiece> > > pieces_;
		std::vector< std::vector<std::unique_ptr<Rectangle> > > positions_;

		void create_board();
		void initialize_pieces();

		Vector2D calculate_board_position(const Vector2D & position) const;
		Vector2D calculate_real_position(const Vector2D & position) const;

		std::unique_ptr<Vector2D> piece_selected_ = nullptr;

	public:
		static const uint32_t NUM_ROWS ;
		static const uint32_t NUM_COLS ;
		static const uint32_t POSITION_WIDTH ;
		static const uint32_t POSITION_HEIGHT ;

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
