#ifndef PAWN_HPP_INCLUDED
#define PAWN_HPP_INCLUDED

#include "ChessPieces/ChessPiece.hpp"

class Pawn : public ChessPiece {
	protected:
		bool goes_up_in_board_;
		bool pawn_moved_from_original_position_ = false;

	public:

		Pawn() = default;
		Pawn(const Turn is_white, const Vector2D & position, const bool goes_up_in_board);
		virtual ~Pawn(){};
		virtual void draw();
		virtual void update();
		virtual void load(const LoaderParams * params);

		virtual bool is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const;
		virtual bool no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const;
		virtual void set_position_in_board(const Vector2D & pos);
};



#endif
