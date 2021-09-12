#include "ChessPieces/Knight.hpp"

Knight :: Knight(const bool is_white, const Vector2D & position)
				:ChessPiece(is_white, position){
}

bool Knight :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;

	uint32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	uint32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	is_valid = (distance_in_x == 2 && distance_in_y == 1) ||
				  (distance_in_x == 1 && distance_in_y == 2);
	

	
	// if the position is valid, check if there is another piece
	if (is_valid) {
		is_valid = check_if_enemy_in_position(new_position, pieces);
	} 

	return is_valid;

}

void Knight :: load(const LoaderParams * params){
	ChessPiece::load(params);
}

void Knight :: update() {
	ChessPiece::update();	
}

void Knight :: draw() {
	ChessPiece::draw();
}


