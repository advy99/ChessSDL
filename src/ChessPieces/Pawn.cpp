#include "Pawn.hpp"



bool Pawn :: is_valid_move(const Vector2D & new_position) const {
	bool is_valid;

	int32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	int32_t distance_in_y = position_in_board_.get_y() - new_position.get_y();

	// TODO: Check for:
	// - enemies
	// - can move en passsant

	int32_t num_squares = 1;

	if (!pawn_moved_from_original_position_){
		num_squares = 2;
	}

	if (goes_up_in_board_) {
		is_valid = distance_in_x == -num_squares;
	} else {
		is_valid = distance_in_x == num_squares;
	}

	return is_valid;

}



