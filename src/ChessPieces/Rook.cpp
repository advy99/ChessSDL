#include "ChessPieces/Rook.hpp"

Rook :: Rook(const bool is_white, const Vector2D & position)
				:ChessPiece(is_white, position){
}

bool Rook :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;

	uint32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	uint32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	is_valid = (distance_in_x == 0 && distance_in_y != 0) ||
				  (distance_in_x != 0 && distance_in_y == 0);

	// if the position is valid, check if there is another piece
	if (is_valid) {
		is_valid = pieces[new_position.get_x()][new_position.get_y()] == nullptr || check_if_enemy_in_position(new_position, pieces);
	} 

	if (is_valid) {
		is_valid = no_pieces_in_path(new_position,pieces);
	}

	return is_valid;

}


bool Rook :: no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool result = true;


	int32_t distance_in_x = position_in_board_.get_x() - new_position.get_x();
	int32_t distance_in_y = position_in_board_.get_y() - new_position.get_y();

	// if x distance is 0, we are in the same row, move is horizontal
	if (distance_in_x == 0) {
		// we are moving to the right
		if (distance_in_y < 0) {
			
		} else {

		}

	} else {
		if ( distance_in_x < 0) {

		} else {

		}	
	}


	return result;
}

void Rook :: load(const LoaderParams * params){
	ChessPiece::load(params);
}

void Rook :: update() {
	ChessPiece::update();	
}

void Rook :: draw() {
	ChessPiece::draw();
}


