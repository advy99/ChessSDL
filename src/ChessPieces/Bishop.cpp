#include "ChessPieces/Bishop.hpp"


Bishop :: Bishop(const Turn is_white, const Vector2D & position)
				:ChessPiece(is_white, position){
}


bool Bishop :: is_valid_move(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool is_valid;


	uint32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	uint32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	is_valid = distance_in_x == distance_in_y;

	// if the position is valid, check if there is another piece
	if (is_valid) {
		is_valid = pieces[new_position.get_x()][new_position.get_y()] == nullptr || check_if_enemy_in_position(new_position, pieces);
	}

	if (is_valid) {
		is_valid = no_pieces_in_path(new_position,pieces);
	}

	return is_valid;

}

bool Bishop :: no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool no_pieces = true;

	std::pair<int32_t, int32_t> min_max_x = std::minmax(new_position.get_x(), position_in_board_.get_x());
	std::pair<int32_t, int32_t> min_max_y = std::minmax(new_position.get_y(), position_in_board_.get_y());

	int32_t i = min_max_x.first + 1;
	int32_t j = min_max_y.first + 1;
	while ( i < min_max_x.second && no_pieces) {
		no_pieces = pieces[i][j] == nullptr;

		i++;
		j++;
	}

	return no_pieces;

}


void Bishop :: load(const LoaderParams * params){
	ChessPiece::load(params);
}

void Bishop :: update() {
	ChessPiece::update();
}

void Bishop :: draw() {
	ChessPiece::draw();
}
