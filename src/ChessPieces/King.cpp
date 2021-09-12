#include "ChessPieces/King.hpp"

King :: King(const bool is_white, const Vector2D & position)
				:ChessPiece(is_white, position){
}

bool King :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;


	uint32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	uint32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	is_valid = distance_in_x <= 1 && distance_in_y <= 1;
	

	// if the position is valid, check if there is another piece
	if (is_valid) {
		is_valid = check_if_enemy_in_position(new_position, pieces);
	} 

	return is_valid;

}


void King :: load(const LoaderParams * params){
	ChessPiece::load(params);
}

void King :: update() {
	ChessPiece::update();	
}

void King :: draw() {
	ChessPiece::draw();
}


