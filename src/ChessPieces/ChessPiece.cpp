#include "ChessPiece.hpp"


bool ChessPiece :: is_white_piece() const{
	return is_white_piece_;
}

Vector2D ChessPiece :: get_position_in_board() const {
	return position_in_board_;
}

bool ChessPiece :: check_if_enemy_in_position(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const { 
	bool enemy_in_position = false;

	// if there is another piece, the position is valid if is an enemy piece
	if (pieces[new_position.get_x()][new_position.get_y()] != nullptr) {
		enemy_in_position = is_white_piece_ != pieces[new_position.get_x()][new_position.get_y()]->is_white_piece();
	}
	
	return enemy_in_position;
}
