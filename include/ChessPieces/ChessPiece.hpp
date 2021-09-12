#ifndef CHESSPIECE_HPP_INCLUDED
#define CHESSPIECE_HPP_INCLUDED


#include "SDLGameObject.hpp"
#include <vector>
#include <memory>

class ChessPiece : public SDLGameObject {
	protected:
		bool is_white_piece_;
		Vector2D position_in_board_;
	
	public:
		ChessPiece() = default;
		ChessPiece(const bool is_white_piece, const Vector2D & position);

		virtual ~ChessPiece() {};
		virtual void draw();
		virtual void update();

		// we never will load a piece, this will be handled by the board
		virtual void load(const LoaderParams * params);

		virtual bool is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const = 0;

		bool check_if_enemy_in_position(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const;

		bool is_white_piece() const;
		Vector2D get_position_in_board() const;

};


#endif
