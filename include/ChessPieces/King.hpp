#ifndef KING_HPP_INCLUDED
#define KING_HPP_INCLUDED

#include "ChessPieces/ChessPiece.hpp"

class King : public ChessPiece {
	protected:

	public:

		King() = default;
		King(const bool is_white, const Vector2D & position);
		virtual ~King(){};
		virtual void draw();
		virtual void update();
		virtual void load(const LoaderParams * params);

		virtual bool is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const;
		virtual bool no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const;
};

#endif
