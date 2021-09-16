#include "ChessPieces/Queen.hpp"

Queen :: Queen(const Turn is_white, const Vector2D & position)
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

	if (is_valid) {
		is_valid = no_pieces_in_path(new_position,pieces);
	}

	return is_valid;

}

#include <iostream>

bool Queen :: no_pieces_in_path(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool no_pieces = true;

	int32_t distance_in_x = position_in_board_.get_x() - new_position.get_x();
	int32_t distance_in_y = position_in_board_.get_y() - new_position.get_y();

	std::pair<int32_t, int32_t> min_max_x = std::minmax(new_position.get_x(), position_in_board_.get_x());
	std::pair<int32_t, int32_t> min_max_y = std::minmax(new_position.get_y(), position_in_board_.get_y());

	if (std::abs(distance_in_x) != std::abs(distance_in_y)) {
		// check like a rook

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
	} else {
		int32_t vertical_movement = -1;
		int32_t horizontal_movement = -1;

		if (distance_in_x < 0) {
			// going up in the board
			vertical_movement = 1;
		}

		if (distance_in_y < 0) {
			// going left in the board
			horizontal_movement = 1;
		}

		int32_t i = position_in_board_.get_x() + vertical_movement;
		int32_t j = position_in_board_.get_y() + horizontal_movement;
		while ( i != new_position.get_x() && no_pieces) {
			no_pieces = pieces[i][j] == nullptr;

			i += vertical_movement;
			j += horizontal_movement;
		}
	}

	return no_pieces;
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
