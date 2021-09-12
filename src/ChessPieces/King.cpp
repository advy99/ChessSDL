#include "King.hpp"


bool King :: is_valid_move(const Vector2D & new_position) const {
	bool is_valid;


	uint32_t distance_in_x = std::abs(position_in_board_.get_x() - new_position.get_x());
	uint32_t distance_in_y = std::abs(position_in_board_.get_y() - new_position.get_y());

	is_valid = distance_in_x <= 1 && distance_in_y <= 1;

	return is_valid;

}
