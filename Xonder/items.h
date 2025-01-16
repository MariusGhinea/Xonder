#pragma once
#include <string>

class GameBoard {

	public:

		GameBoard(int, char fillersArray[8], int);

		void setDrawChars(char fillersArray[8]);

		void setBoardDim(int);

		void boardDraw(std::string);

		void setCursorIndex(int);

		int getCursorIndex();



	private:

		int boardDim;

		char drawChars[8];

		int cursorIndex;
};


class InputDigit {

	public:

		InputDigit(std::string outputTextArray[4], int newCheckArray[4]);

		void setCheckArray(int newCheckArray[4]);

		void setOutputTextArray(std::string outputTextArray[4]);

		int getDigit(int textArrayIndex, int, int);

	private:

		std::string outputTextArray[4];

		int checkArray[4];
};


class InputChar {

public:

	InputChar(std::string outputTextArray[4], char newCheckArray[4]);

	void setCheckArray(char newCheckArray[4]);

	void setOutputTextArray(std::string outputTextArray[4]);

	int getChar(int textArrayIndex, int, int);

private:

	std::string outputTextArray[4];

	char checkArray[4];
};


class GameRules {

public:

	GameRules(std::string textContent[10], int boardSize, char boardFillersArray[8], int boardCursorIndex, char checkArrayChar[4], std::string outputTextArray[4], std::string leftOffset);

	void setTextContent(std::string textContent[10]);

	void setLeftOffset(std::string leftOffset);

	bool display();

	void checkObj();

private:

	std::string textContent[10];

	std::string leftOffset;

	GameBoard board;

	InputChar inputChar;
};
