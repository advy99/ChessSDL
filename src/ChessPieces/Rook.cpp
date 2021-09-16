#include "ChessPieces/Rook.hpp"

Rook :: Rook(const Turn is_white, const Vector2D & position)
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

	std::pair<int32_t, int32_t> min_max_x = std::minmax(new_position.get_x(), position_in_board_.get_x());
	std::pair<int32_t, int32_t> min_max_y = std::minmax(new_position.get_y(), position_in_board_.get_y());

	bool no_pieces = true;

	int32_t i = min_max_x.first + 1;
	while ( i < min_max_x.second && no_pieces) {
		no_pieces = pieces[i][position_in_board_.get_y()] == nullptr;

		i++;
	}

	i = min_max_y.first + 1;
	while ( i < min_max_y.second && no_pieces) {
		no_pieces = pieces[position_in_board_.get_x()][i] == nullptr;

		i++;
	}


	return no_pieces;
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
