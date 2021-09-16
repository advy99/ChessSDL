#include "ChessPieces/Pawn.hpp"

Pawn :: Pawn(const Turn is_white, const Vector2D & position, const bool goes_up_in_board)
				:ChessPiece(is_white, position), goes_up_in_board_(goes_up_in_board)
{
}

bool Pawn :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;

	//REMEMBER DISTANCES ARE X VERTICAL AND Y HORIZONTAL, not like SDL
	int32_t distance_in_x = position_in_board_.get_x() - new_position.get_x();
	int32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	// TODO: Check for:
	// - can move en passsant

	int32_t num_squares = 1;

	if (!pawn_moved_from_original_position_){
		num_squares = 2;
	}

	// last check: cannot eat in the opening if the pawn moves two squares
	bool vertical_movement_is_correct = distance_in_y == 0 ||
													(distance_in_y == 1 && check_if_enemy_in_position(new_position, pieces) && std::abs(distance_in_x) == 1);

	if (goes_up_in_board_) {
		is_valid = distance_in_x <= num_squares && distance_in_x > 0 && vertical_movement_is_correct;
	} else {
		is_valid = distance_in_x >= -num_squares && distance_in_x < 0 && vertical_movement_is_correct;
	}

	// if the position is valid and the movement is vertical, check if there is another piece
	if (is_valid && distance_in_y == 0) {
		// the pawn cannot eat in vertical
		is_valid = no_pieces_in_path(new_position, pieces);
	}

	return is_valid;

}

bool Pawn :: no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool no_pieces = true;

	int32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());

	no_pieces = pieces[new_position.get_x()][new_position.get_y()] == nullptr;

	if (no_pieces && distance_in_x != 1) {
		if (goes_up_in_board_ ){
			no_pieces = pieces[new_position.get_x() + 1][new_position.get_y()] == nullptr;
		} else{
			no_pieces = pieces[new_position.get_x() - 1][new_position.get_y()] == nullptr;
		}
	}

	return no_pieces;
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

void Pawn :: set_position_in_board(const Vector2D & pos) {
	pawn_moved_from_original_position_ = true;
	ChessPiece::set_position_in_board(pos);
}
