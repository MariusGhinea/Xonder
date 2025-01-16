#include <iostream>
#include <string>
#include "items.h"

GameRules::GameRules(std::string textContent[10], int boardSize, char boardFillersArray[8], int boardCursorIndex, char checkArrayChar[4], std::string outputTextArray[4], std::string leftOffset)
	: board(boardSize, boardFillersArray, boardCursorIndex), inputChar(outputTextArray, checkArrayChar){

	setTextContent(textContent);

	setLeftOffset(leftOffset);
}

void GameRules::setTextContent(std::string newTextContent[10]) {

	for (int i = 0; i < 10; i++) {

		textContent[i] = newTextContent[i];
	}
}

void GameRules::setLeftOffset(std::string newLeftOffset) {

	leftOffset = newLeftOffset;
}

bool GameRules::display() {

	std::cout << textContent[0] << std::endl << std::endl;

	std::cout << textContent[1] << std::endl << std::endl << std::endl;

	std::cout << "					      " << "Turn: 1" << std::endl << std::endl;

	std::cout << "			  " << "Left Player" << " Hits: 0" << "          " << "Right Player" << " Hits: 0" << std::endl << std::endl;

	board.boardDraw(leftOffset);

	std::cout << std::endl << std::endl;

	std::cout << textContent[2] << std::endl << std::endl;

	std::cout << textContent[3] << std::endl << std::endl;

	board.setCursorIndex(2);

	std::cout << "					      " << "Turn: 1" << std::endl << std::endl;

	std::cout << "			  " << "Left Player" << " Hits: 0" << "          " << "Right Player" << " Hits: 0" << std::endl << std::endl;

	board.boardDraw(leftOffset);

	std::cout << std::endl << std::endl;

	std::cout << textContent[4] << std::endl << std::endl;

	board.setCursorIndex(3);

	std::cout << "					      " << "Turn: 2" << std::endl << std::endl;

	std::cout << "			" << "The Dice gives a 1." << std::endl << std::endl;

	std::cout << "			  " << "Left Player" << " Hits: 1" << "          " << "Right Player" << " Hits: 0" << std::endl << std::endl;

	board.boardDraw(leftOffset);

	std::cout << std::endl << std::endl;

	std::cout << textContent[5] << std::endl << std::endl;

	char answer = inputChar.getChar(0, 2, 3);

	if (answer == 'y') {

		return true;
	}
	else {

		std::system("cls");

		display();
	}
}

void GameRules::checkObj() {

	std::cout << leftOffset;
}