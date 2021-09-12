#ifndef CHESSPIECE_HPP_INCLUDED
#define CHESSPIECE_HPP_INCLUDED


#include "SDLGameObject.hpp"

class ChessPiece : public SDLGameObject {
	protected:
		Vector2D position_in_board_;
	
	public:
		ChessPiece();

		virtual ~ChessPiece();
		virtual void draw();
		virtual void update();

		// we never will load a piece, this will be handled by the board
		virtual void load(const LoaderParams * params) = delete;

		virtual bool is_valid_move(const Vector2D & new_position) const = 0;

};


#endif
