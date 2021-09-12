#include "ChessPieces/Pawn.hpp"

Pawn :: Pawn(const bool is_white, const Vector2D & position, const bool goes_up_in_board)
				:ChessPiece(is_white, position), goes_up_in_board_(goes_up_in_board)
{
}


bool Pawn :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;

	int32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	int32_t distance_in_y = position_in_board_.get_y() - new_position.get_y();

	// TODO: Check for:
	// - can move en passsant

	int32_t num_squares = 1;

	if (!pawn_moved_from_original_position_){
		num_squares = 2;
	}

	// last check: cannot eat in the opening if the pawn moves two squares
	bool x_movement_is_correct = distance_in_x == 0 || (distance_in_x == 1 && check_if_enemy_in_position(new_position, pieces) && distance_in_y == 1);

	if (goes_up_in_board_) {
		is_valid = distance_in_y <= -num_squares && x_movement_is_correct;
	} else {
		is_valid = distance_in_y <= num_squares && x_movement_is_correct;
	}

	// if the position is valid and the movement is vertical, check if there is another piece
	if (is_valid && distance_in_x == 0) {
		// the pawn cannot eat in vertical
		is_valid = !check_if_enemy_in_position(new_position, pieces);
	} 

	return is_valid;

}

void Pawn :: load(const LoaderParams * params){
	ChessPiece::load(params);
}

void Pawn :: update() {
	ChessPiece::update();	
}

void Pawn :: draw() {
	ChessPiece::draw();
}


