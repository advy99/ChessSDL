#include "ChessPieces/King.hpp"

King :: King(const Turn is_white, const Vector2D & position)
				:ChessPiece(is_white, position){
}

bool King :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;


	uint32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	uint32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	is_valid = distance_in_x <= 1 && distance_in_y <= 1;


	// if the position is valid, check if there is another piece
	if (is_valid) {
		is_valid = pieces[new_position.get_x()][new_position.get_y()] == nullptr || check_if_enemy_in_position(new_position, pieces);
	}

	if (is_valid) {
		is_valid = no_pieces_in_path(new_position,pieces);
	}

	return is_valid;

}

bool King :: no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool no_pieces = true;

	// if an enemy piece can move to these position is not a valid position
	auto it_row = pieces.begin();
	while ( it_row != pieces.end() && no_pieces) {

		auto it = it_row->begin();
		while ( it != it_row->end() && no_pieces) {
			if ( (*it) != nullptr ){
				if (turn_ != (*it)->get_turn() ){
					no_pieces = !(*it)->is_valid_move(new_position, pieces);
				}
			}

			++it;
		}

		++it_row;
	}

	return no_pieces;

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
