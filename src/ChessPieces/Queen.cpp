#include "ChessPieces/Queen.hpp"

Queen :: Queen(const bool is_white, const Vector2D & position)
				:ChessPiece(is_white, position){
}

bool Queen :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;

	uint32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	uint32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	is_valid = (distance_in_x == 0 && distance_in_y != 0) ||
				  (distance_in_x != 0 && distance_in_y == 0) ||
				  distance_in_x == distance_in_y;


	// if the position is valid, check if there is another piece
	if (is_valid) {
		is_valid = pieces[new_position.get_x()][new_position.get_y()] == nullptr || check_if_enemy_in_position(new_position, pieces);
	} 


	return is_valid;

}

void Queen :: load(const LoaderParams * params){
	ChessPiece::load(params);
}

void Queen :: update() {
	ChessPiece::update();	
}

void Queen :: draw() {
	ChessPiece::draw();
}



