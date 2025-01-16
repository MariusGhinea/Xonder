#include <iostream>
//#include <stdio.h>
#include <string>
#include "items.h"

InputDigit::InputDigit(std::string outputTextArray[4], int checkArray[4]) {

	setOutputTextArray(outputTextArray);

	setCheckArray(checkArray);
}

int InputDigit::getDigit(int textArrayIndex, int startPosition, int endPosition) {

	char theDigitChar;

	int theDigitInt;

	std::string inputString;

	std::string outputText = outputTextArray[textArrayIndex];


	while (true) {

		inputString.clear();

		std::cout << outputText;

		std::getline(std::cin, inputString);


		if (inputString.length() == 1) {

			theDigitChar = inputString[0];

			std::cout << std::endl;

			theDigitInt = int(theDigitChar) - '0';

			for (int i = startPosition; i < endPosition + 1; i++) {

				if (checkArray[i] == theDigitInt) {

					return (theDigitInt);
				}
			}
		}
	}
}

void InputDigit::setOutputTextArray(std::string newOutputTextArray[4]) {

	for (int i = 0; i < 4; i++) {

		outputTextArray[i] = newOutputTextArray[i];
	}
}

void InputDigit::setCheckArray(int newCheckArray[4]) {

	for (int i = 0; i < 4; i++) {

		checkArray[i] = newCheckArray[i];
	}
}



InputChar::InputChar(std::string outputTextArray[4], char checkArray[4]) {

	setOutputTextArray(outputTextArray);
	
	setCheckArray(checkArray);
}

int InputChar::getChar(int textArrayIndex, int startPosition, int endPosition) {

	char theDigitChar;

	std::string inputString;

	std::string outputText = outputTextArray[textArrayIndex];

	while (true) {

		inputString.clear();

		std::cout << outputText;

		std::getline(std::cin, inputString);


		if (inputString.length() == 1) {

			theDigitChar = inputString[0];

			std::cout << std::endl;

			for (int i = startPosition; i < endPosition + 1; i++) {

				if (checkArray[i] == theDigitChar) {

					return (theDigitChar);
				}
			}
		}
	}
}

void InputChar::setOutputTextArray(std::string newOutputTextArray[4]) {

	for (int i = 0; i < 4; i++) {

		outputTextArray[i] = newOutputTextArray[i];
	}
}

void InputChar::setCheckArray(char newCheckArray[4]) {

	for (int i = 0; i < 4; i++) {

		checkArray[i] = newCheckArray[i];
	}
}