#pragma once
#include <string>
#include "items.h"

class Game {

public:

	Game(std::string gameName, std::string copyrightData, int maxScore, std::string playerOneName, std::string playerTwoName, std::string outputTextArray[4],
			int boardSize, char boardFillersArray[7], int boardCursorIndex, int checkArrayInt[4], char checkArrayChar[4], std::string leftOffset);

	void setGameName(std::string);

	void setCopyrightData(std::string);

	void setMaxScore(int);

	void setPlayerOneName(std::string);

	void setPlayerTwoName(std::string);

	void setLeftOffset(std::string);

	bool gameLoop();

	std::string getPlayerOneName();

	std::string getPlayerTwoName();

	std::string getGameName();

	int getMaxScore();

private:

	std::string gameName;

	std::string copyrightData;

	int maxScore;

	std::string playerOneName;

	std::string playerTwoName;

	std::string leftOffset;

	GameBoard board;

	InputDigit inputDigit;

	InputChar inputChar;
};
