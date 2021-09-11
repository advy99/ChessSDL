#include "ChessBoard.hpp"
#include "InputHandler.hpp"
#include "Game.hpp"

ChessBoard::ChessBoard(  ):SDLGameObject(){}

#include <iostream>
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
	
	Color edge_color(82, 63, 55, 255);


	edge_ = Rectangle(position_.get_x(), position_.get_y(), width_, height_, edge_color);
}

void ChessBoard::draw(){
	SDLGameObject::draw();

	/* std::cout << static_cast<uint32_t>(edge_.get_color().red()) << "\t" << static_cast<uint32_t>(edge_.get_color().green()) 
				 << "\t" << static_cast<uint32_t>(edge_.get_color().blue()) << "\t" << static_cast<uint32_t>(edge_.get_color().alpha()) << std::endl << std::endl; */
	edge_.draw();
	for (auto & rectangle_row : positions_) {
		for (auto & rectangle : rectangle_row) {
			rectangle->draw();
		}
	}
		
	/* for (auto & piece : pieces_) {
		piece->draw();
	} */

}

void ChessBoard::update() {
	SDLGameObject::update();

	/* for (auto & piece : pieces_) {
		piece->update();
	} */
}

void ChessBoard::load(const LoaderParams * params) {
	SDLGameObject::load(params);

	create_board();
}


std::unique_ptr<GameObject> ChessBoardCreator::create_game_object() const {
	return std::make_unique<ChessBoard>();
}




const uint32_t ChessBoard :: NUM_ROWS = 8;
const uint32_t ChessBoard :: NUM_COLS = 8;
const uint32_t ChessBoard :: POSITION_WIDTH = 50;
const uint32_t ChessBoard :: POSITION_HEIGHT = 50;



