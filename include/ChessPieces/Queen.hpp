#ifndef QUEEN_HPP_INCLUDED
#define QUEEN_HPP_INCLUDED

#include "ChessPieces/ChessPiece.hpp"

class Queen : public ChessPiece {
	protected:

	public:

		Queen() = default;
		Queen(const Turn is_white, const Vector2D & position);
		virtual ~Queen(){};
		virtual void draw();
		virtual void update();
		virtual void load(const LoaderParams * params);

		virtual bool is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const;
		virtual bool no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const;
};



#endif
