#include "ChessBoard.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"
#include "ChessPieces/Pawn.hpp"
#include "ChessPieces/Rook.hpp"
#include "ChessPieces/Knight.hpp"
#include "ChessPieces/Bishop.hpp"
#include "ChessPieces/Queen.hpp"
#include "ChessPieces/King.hpp"

ChessBoard::ChessBoard(  ):SDLGameObject(){}

void ChessBoard :: create_board(){
	Color black(118, 50, 39, 255);
	Color white(202, 156, 104, 255);

	Color actual_color = white;

	int x_pos = position_.get_x() + POSITION_WIDTH / 4;
	int y_pos = position_.get_y() + POSITION_HEIGHT / 4;
	
	bool position_is_white = true;
	positions_.resize(NUM_ROWS);
	for (uint32_t i = 0; i < NUM_ROWS; i++) {

		for (uint32_t j = 0; j < NUM_COLS; j++) {
			
			if (position_is_white) {
				actual_color = white;
			} else {
				actual_color = black;
			}

			positions_[i].push_back(std::make_unique<Rectangle>(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, actual_color.get_color()));

			position_is_white = !position_is_white;

			x_pos += POSITION_WIDTH;

		}

		position_is_white = !position_is_white;
		y_pos += POSITION_HEIGHT;
		x_pos = position_.get_x() + POSITION_WIDTH / 4;
	}

	// multiply by for the edges
	width_ = 2 * (POSITION_WIDTH / 4) + POSITION_WIDTH * NUM_ROWS;
	height_ = 2 * (POSITION_HEIGHT / 4) + POSITION_HEIGHT * NUM_COLS;
	


	edge_ = Rectangle(position_.get_x(), position_.get_y(), width_, height_, edge_color_);
}

void ChessBoard::draw(){
	SDLGameObject::draw();

	edge_.draw();

	for (auto & rectangle_row : positions_) {
		for (auto & rectangle : rectangle_row) {
			rectangle->draw();
		}
	}
		
	for (auto & piece_row : pieces_) {
		for (auto & piece : piece_row){
			if (piece != nullptr) {
				piece->draw();
			}
		}
	}

}

void ChessBoard::update() {
	SDLGameObject::update();

	for (auto & piece_row : pieces_) {
		for (auto & piece : piece_row){
			if (piece != nullptr) {
				piece->update();
			}
		}
	}
}

void ChessBoard::load(const LoaderParams * params) {
	SDLGameObject::load(params);

	create_board();
	initialize_pieces();
}


void ChessBoard :: initialize_pieces(){

	int x_pos = position_.get_x() + POSITION_WIDTH / 4;
	int y_pos = position_.get_y() + POSITION_HEIGHT / 4;
	bool is_white = false;
	std::unique_ptr<LoaderParams> params;
	
	
	pieces_.resize(NUM_ROWS);
	for (auto & piece_row : pieces_) {
		piece_row.resize(NUM_COLS);
	}
	
	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_rook", "assets/black_rook.png", 1));
	pieces_[0][0] = std::make_unique<Rook>(is_white, Vector2D(0, 0));
	pieces_[0][0]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_knight", "assets/black_knight.png", 1));
	pieces_[0][1] = std::make_unique<Knight>(is_white, Vector2D(0, 1));
	pieces_[0][1]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_bishop", "assets/black_bishop.png", 1));
	pieces_[0][2] = std::make_unique<Bishop>(is_white, Vector2D(0, 2));
	pieces_[0][2]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_queen", "assets/black_queen.png", 1));
	pieces_[0][3] = std::make_unique<Queen>(is_white, Vector2D(0, 3));
	pieces_[0][3]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_king", "assets/black_king.png", 1));
	pieces_[0][4] = std::make_unique<King>(is_white, Vector2D(0, 4));
	pieces_[0][4]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_bishop", "assets/black_bishop.png", 1));
	pieces_[0][5] = std::make_unique<Bishop>(is_white, Vector2D(0, 5));
	pieces_[0][5]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_knight", "assets/black_knight.png", 1));
	pieces_[0][6] = std::make_unique<Knight>(is_white, Vector2D(0, 6));
	pieces_[0][6]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_rook", "assets/black_rook.png", 1));
	pieces_[0][7] = std::make_unique<Rook>(is_white, Vector2D(0, 7));
	pieces_[0][7]->load(params.get());
	x_pos = position_.get_x() + POSITION_WIDTH / 4;

	y_pos += POSITION_HEIGHT;
	for (uint32_t j = 0; j < NUM_COLS; j++) {

		params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "black_pawn", "assets/black_pawn.png", 1));
		pieces_[1][j].reset(new Pawn(is_white, Vector2D(1, j), false));
		pieces_[1][j]->load(params.get());

		x_pos += POSITION_WIDTH;
	}

	is_white = false;
	y_pos = position_.get_y() + POSITION_HEIGHT / 4;
	y_pos += 6 * POSITION_HEIGHT;
	x_pos = position_.get_x() + POSITION_WIDTH / 4;



	for (uint32_t j = 0; j < NUM_COLS; j++) {

		params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_pawn", "assets/white_pawn.png", 1));
		pieces_[6][j].reset(new Pawn(is_white, Vector2D(6, j), true));
		pieces_[6][j]->load(params.get());

		x_pos += POSITION_WIDTH;
	}

	x_pos = position_.get_x() + POSITION_WIDTH / 4;
	y_pos += POSITION_HEIGHT;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_rook", "assets/white_rook.png", 1));
	pieces_[7][0] = std::make_unique<Rook>(is_white, Vector2D(7, 0));
	pieces_[7][0]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_knight", "assets/white_knight.png", 1));
	pieces_[7][1] = std::make_unique<Knight>(is_white, Vector2D(7, 1));
	pieces_[7][1]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_bishop", "assets/white_bishop.png", 1));
	pieces_[7][2] = std::make_unique<Bishop>(is_white, Vector2D(7, 2));
	pieces_[7][2]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_queen", "assets/white_queen.png", 1));
	pieces_[7][3] = std::make_unique<Queen>(is_white, Vector2D(7, 3));
	pieces_[7][3]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_king", "assets/white_king.png", 1));
	pieces_[7][4] = std::make_unique<King>(is_white, Vector2D(7, 4));
	pieces_[7][4]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_bishop", "assets/white_bishop.png", 1));
	pieces_[7][5] = std::make_unique<Bishop>(is_white, Vector2D(7, 5));
	pieces_[7][5]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_knight", "assets/white_knight.png", 1));
	pieces_[7][6] = std::make_unique<Knight>(is_white, Vector2D(7, 6));
	pieces_[7][6]->load(params.get());
	x_pos += POSITION_WIDTH;

	params.reset(new LoaderParams(x_pos, y_pos, POSITION_WIDTH, POSITION_HEIGHT, "white_rook", "assets/white_rook.png", 1));
	pieces_[7][7] = std::make_unique<Rook>(is_white, Vector2D(7, 7));
	pieces_[7][7]->load(params.get());
	x_pos = position_.get_x() + POSITION_WIDTH / 4;


}







std::unique_ptr<GameObject> ChessBoardCreator::create_game_object() const {
	return std::make_unique<ChessBoard>();
}


const Color ChessBoard :: position_color_black_(118, 50, 39, 255);
const Color ChessBoard :: position_color_white_(202, 156, 104, 255);
const Color ChessBoard :: edge_color_(82, 63, 55, 255);

const uint32_t ChessBoard :: NUM_ROWS = 8;
const uint32_t ChessBoard :: NUM_COLS = 8;
const uint32_t ChessBoard :: POSITION_WIDTH = 50;
const uint32_t ChessBoard :: POSITION_HEIGHT = 50;



