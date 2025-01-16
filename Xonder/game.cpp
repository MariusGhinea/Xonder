#include <iostream>
#include <string>
#include <time.h>
//#include <stdio.h> deprecated, covered by iostream
//#include <stdlib.h> better use namespace std::
#include "game.h"

Game::Game(std::string gameName, std::string copyrightData, int maxScore, std::string playerOneName, std::string playerTwoName, std::string outputTextArray[4],
		int boardSize, char boardFillersArray[7], int boardCursorIndex, int checkArrayInt[4], char checkArrayChar[4], std::string leftOffset)
	: board(boardSize, boardFillersArray, boardCursorIndex), inputDigit(outputTextArray, checkArrayInt), inputChar(outputTextArray, checkArrayChar) {

	setGameName(gameName);

	setCopyrightData(copyrightData);

	setMaxScore(maxScore);

	setPlayerOneName(playerOneName);

	setPlayerTwoName(playerTwoName);

	setLeftOffset(leftOffset);
}

void Game::setGameName(std::string newGameName) {

	gameName = newGameName;
}

void Game::setCopyrightData(std::string newCopyrightData) {

	copyrightData = newCopyrightData;
}

void Game::setMaxScore(int newMaxScore) {

	maxScore = newMaxScore;
}

void Game::setPlayerOneName(std::string newPlayerOneName) {

	playerOneName = newPlayerOneName;
}

void Game::setPlayerTwoName(std::string newPlayerTwoName) {

	playerTwoName = newPlayerTwoName;
}

void Game::setLeftOffset(std::string newLeftOffset) {

	leftOffset = newLeftOffset;
}

std::string Game::getPlayerOneName() {

	return(playerOneName);
}

std::string Game::getPlayerTwoName() {

	return(playerTwoName);
}

std::string Game::getGameName() {

	return(gameName);
}

int Game::getMaxScore() {

	return(maxScore);
}

bool Game::gameLoop() {

	int turnIndex = 1;

	int hitsOne = 0;//how many times Player One has hit Player Two; if it amounts to maxScore, Player One wins

	int hitsTwo = 0;

	bool gameHasEnded = false;

	char playerOneDirection;

	char playerTwoDirection;

	int playerOneMove;

	int playerTwoMove;

	int playerOneSignedMove;

	int playerTwoSignedMove;

	int sumMove;

	char playerOneXORapproval;

	char playerTwoXORapproval;

	int diceChoices[3] = { 0, -1, 1 };

	int diceRoll = -4;

	char oneMoreMatch;

	std::string winnerName = "";

	std::srand(time(NULL));

	std::system("cls");


	while (winnerName == "") {

		//page header

		std::cout << "                    " << gameName << std::endl << std::endl;

		if(turnIndex == 1){ std::cout << copyrightData << std::endl << std::endl;}

		std::cout << leftOffset << leftOffset << leftOffset << "Turn: " << turnIndex << std::endl << std::endl;

		std::cout << playerOneName << " Hits: " << hitsOne << " / " << maxScore << "          " << playerTwoName << " Hits: " << hitsTwo << " / " << maxScore << std::endl << std::endl;

		board.boardDraw(leftOffset);

		std::cout << std::endl << std::endl;

		if (diceRoll != -4) {

			std::cout << "The Dice gives a " << diceRoll << std::endl << std::endl;

			diceRoll = -4;
		}
		else {

			if (turnIndex != 1) {

				std::cout << "The Dice was not rolled." << std::endl << std::endl;
			}
		}


		//getting moves phase

		//Player One
		std::cout << playerOneName << " actions:" << std::endl;

		playerOneDirection = inputChar.getChar(0, 0, 1);

		std::cout << std::endl;

		playerOneMove = inputDigit.getDigit(1, 0, 3);

		std::system("cls");

		//page header
		std::cout << "                    " << gameName << std::endl << std::endl;

		std::cout << leftOffset << leftOffset << leftOffset << "Turn: " << turnIndex << std::endl << std::endl;

		std::cout << playerOneName << " Hits: " << hitsOne << " / " << maxScore << "          " << playerTwoName << " Hits: " << hitsTwo << " / " << maxScore << std::endl << std::endl;

		board.boardDraw(leftOffset);

		std::cout << std::endl << std::endl;

		//playerTwo
		std::cout << playerTwoName << " actions:" << std::endl;

		playerTwoDirection = inputChar.getChar(0, 0, 1);

		std::cout << std::endl;

		playerTwoMove = inputDigit.getDigit(1, 0, 3);

		std::cout << std::endl << std::endl;


		//calc overall move

		switch (playerOneDirection) {

		case '-':

			playerOneSignedMove = playerOneMove * -1;

			break;

		case '+':

			playerOneSignedMove = playerOneMove;
		}

		switch (playerTwoDirection) {

		case '-':

			playerTwoSignedMove = playerTwoMove * -1;

			break;

		case '+':

			playerTwoSignedMove = playerTwoMove;
		}

		sumMove = playerOneSignedMove + playerTwoSignedMove;

		board.setCursorIndex(board.getCursorIndex() + sumMove);

		std::system("cls");


		//page header
		std::cout << "                    " << gameName << std::endl << std::endl;

		std::cout << leftOffset << leftOffset << leftOffset << "Turn: " << turnIndex << std::endl << std::endl;

		std::cout << playerOneName << " Hits: " << hitsOne << " / " << maxScore << "          " << playerTwoName << " Hits: " << hitsTwo << " / " << maxScore << std::endl << std::endl;

		board.boardDraw(leftOffset);

		std::cout << std::endl << std::endl;


		//XORoll approvement phase

		//Player One
		std::cout << playerOneName << " dice roll approvement";

		std::cout << std::endl;

		playerOneXORapproval = inputChar.getChar(2, 2, 3);

		std::system("cls");

		//page header
		std::cout << "                    " << gameName << std::endl << std::endl;

		std::cout << leftOffset << leftOffset << leftOffset << "Turn: " << turnIndex << std::endl << std::endl;

		std::cout << playerOneName << " Hits: " << hitsOne << " / " << maxScore << "          " << playerTwoName << " Hits: " << hitsTwo << " / " << maxScore << std::endl << std::endl;

		board.boardDraw(leftOffset);

		std::cout << std::endl << std::endl;


		//Player Two
		std::cout << playerTwoName << " dice roll approvement";

		std::cout << std::endl;

		playerTwoXORapproval = inputChar.getChar(2, 2, 3);

		std::cout << std::endl << std::endl;

		std::system("cls");


		//XORoll phase assesment

		if ((playerOneXORapproval == 'y' && playerTwoXORapproval == 'n') || (playerOneXORapproval == 'n' && playerTwoXORapproval == 'y')) {

			//dice roll and move if roll = +/- 1
			diceRoll = diceChoices[std::rand() % 3];

			board.setCursorIndex(board.getCursorIndex() + diceRoll);
		}


		//cursor position assesment

		if (board.getCursorIndex() == 3 || board.getCursorIndex() == 7) {

			switch (board.getCursorIndex()) {

			case 3:

				hitsOne++;

				if (hitsOne == maxScore) {

					winnerName = playerOneName;
				}

				break;

			case 7:

				hitsTwo++;

				if (hitsTwo == maxScore) {

					winnerName = playerTwoName;
				}
			}

			if (winnerName != "") {

				//page header
				std::cout << "                    " << gameName << std::endl << std::endl;

				std::cout << leftOffset << leftOffset << leftOffset << "Turn: " << turnIndex << std::endl << std::endl;

				std::cout << playerOneName << " Hits: " << hitsOne << " / " << maxScore << "          " << playerTwoName << " Hits: " << hitsTwo << " / " << maxScore << std::endl << std::endl;

				board.boardDraw(leftOffset);

				std::cout << std::endl << std::endl;

				if (diceRoll != -4) {

					std::cout << "The Dice gives a " << diceRoll << std::endl << std::endl;
				}

				std::cout << winnerName << " is the winner!";

				std::cout << std::endl << std::endl;

				oneMoreMatch = inputChar.getChar(3, 2, 3);

				if (oneMoreMatch == 'y') {

					board.setCursorIndex(1);

					gameLoop();
				}
				else {

					return true;
				}
			}
			else {

				turnIndex++;

				std::system("cls");
			}
		}
		else {

			turnIndex++;

			std::system("cls");
		}
	}
}