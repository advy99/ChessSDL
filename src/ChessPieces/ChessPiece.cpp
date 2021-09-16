#include "ChessPieces/ChessPiece.hpp"
#include "InputHandler.hpp"
#include "ChessBoard.hpp"

ChessPiece :: ChessPiece(const Turn is_white_piece, const Vector2D & position)
					:turn_(is_white_piece), position_in_board_(position)
{}

bool ChessPiece :: is_white_piece() const{
	return turn_ == Turn::WHITE;
}

Vector2D ChessPiece :: get_position_in_board() const {
	return position_in_board_;
}

void ChessPiece :: set_position_in_board(const Vector2D & pos) {
	position_in_board_ = pos;
}

bool ChessPiece :: check_if_enemy_in_position(const Vector2D & new_position, const std::vector<std::vector<std::unique_ptr<ChessPiece> > > & pieces) const {
	bool enemy_in_position = false;

	// if there is another piece, the position is valid if is an enemy piece
	if (pieces[new_position.get_x()][new_position.get_y()] != nullptr) {
		enemy_in_position = is_white_piece() != pieces[new_position.get_x()][new_position.get_y()]->is_white_piece();
	}

	return enemy_in_position;
}

Turn ChessPiece :: get_turn() const {
	return turn_;
}

void ChessPiece :: load(const LoaderParams * params) {
	SDLGameObject::load(params);
	current_frame_ = 0;
}

void ChessPiece :: update(){
	SDLGameObject::update();
}

void ChessPiece :: draw() {
	SDLGameObject::draw();
}
