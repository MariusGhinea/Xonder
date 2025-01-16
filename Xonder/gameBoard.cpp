#include <iostream>
#include "items.h"

GameBoard::GameBoard(int boardDim, char fillersArray[8], int cursorIndex) {

	setBoardDim(boardDim);

	setDrawChars(fillersArray);

	setCursorIndex(cursorIndex);
}

void GameBoard::setBoardDim(int newDim) {

	boardDim = newDim;
}

void GameBoard::setDrawChars(char newFillersArray[8]) {

	for (int i = 0; i < 8; i++) {

		drawChars[i] = newFillersArray[i];
	}
}

void GameBoard::setCursorIndex(int newCursorIndex) {

	if (newCursorIndex < 0) {

		cursorIndex = 8 + newCursorIndex;
	}
	else if (newCursorIndex > 7) {

		cursorIndex = newCursorIndex - 8;
	}
	else {

		cursorIndex = newCursorIndex;
	}
}

void GameBoard::boardDraw(std::string leftOffset) {

	bool moveOn = true;

	int maskArray[8][2] = { {0, 0},/*socket top left*/

										{(boardDim - 1) / 2, 0},/*socket*/

										{boardDim - 1, 0},/*socket*/

										{boardDim - 1, (boardDim - 1) / 2},/*right player socket*/

										{boardDim - 1, boardDim - 1},/*socket bottom right*/

										{(boardDim - 1) / 2, boardDim - 1},/*socket*/

										{0, boardDim - 1},/*socket*/

										{0, (boardDim - 1) / 2}/*left player socket*/

	};



	for (int j = 0; j < boardDim; j++) {

		std::cout << leftOffset;

		for (int i = 0; i < boardDim; i++) {

			for (int k = 0; k < 8; k++) {

				if (i == maskArray[k][0] && j == maskArray[k][1]) {

					if (k == cursorIndex) {

						if (i == boardDim - 1) {

							std::cout << drawChars[6] << std::endl;
						}
						else {

							std::cout << drawChars[6];
						}
					}
					else {

						if (k == 0 || k == 6) {

							std::cout << drawChars[3];
						}

						if (k == 1 || k == 5) {

							std::cout << drawChars[7];
						}

						if (k == 2 || k == 4) {

							std::cout << drawChars[3] << std::endl;
						}

						if (k == 3) {

							std::cout << drawChars[4] << std::endl;
						}

						if (k == 7) {

							std::cout << drawChars[5];
						}
					}

					moveOn = false;
				}
			}

			if (moveOn) {

				if (j == 0) {

					std::cout << drawChars[1] << drawChars[1];

					moveOn = false;
				}

				if (j == boardDim - 2 && i != 0 && i != boardDim - 1) {

					if (i == (boardDim - 1) / 2) {

						std::cout << ' ';
					}
					else {

						std::cout << drawChars[1] << drawChars[1];
					}

					moveOn = false;
				}

				if (i == 0) {

					std::cout << drawChars[2];

					moveOn = false;
				}

				if (i == boardDim - 1) {

					std::cout << drawChars[2] << std::endl;

					moveOn = false;
				}
			}

			if (moveOn) {

				if (i == boardDim - 2 && j != boardDim -1) {

					std::cout << drawChars[0];
				}
				else {

					std::cout << drawChars[0] << drawChars[0];
				}
			}

			moveOn = true;
		}
	}
}

int GameBoard::getCursorIndex() {

	return(cursorIndex);
}