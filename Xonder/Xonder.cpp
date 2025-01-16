// Xonder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "items.h"
#include "game.h"

int optionsMenu(std:: string gameName, std::string rulesOutputTextArray[4], int textIndex, char checkCharArray[4], int startPosition, int endPosition, int maxScore);

int setMaximumScore(std::string gameName, std::string rulesOutputTextArray[4], int textIndex, int checkIntArray[4], int startPosition, int endPosition);

int main()
{
    //game init
    int boardDim = 19;

    char fillerCharsArray[8] = { ' ', '_', '|', 'o', 'R', 'L', 'X', '-'};

    int cursorIndex = 1;

    int checkDigitsArray[4] = { 0, 1, 2, 3 };

    char checkCharsArray[4] = { '-', '+', 'y', 'n' };

    std::string outputTextArray[4] = {"Set the direction (-/+): ", "Set the number of positions to move (0/1/2/3): ", "Do you want to roll the dice (y/n)? ", "Play another match (y/n)? "};

    std::string gameName = "XORdenberg";

    std::string copyrightData = "(c)2024 Ghinea Marius Mihai, leftclickghinea.ro. Some rights reserved.";

    std::string playerOneName = "Left Player";

    std::string playerTwoName = "Right Player";

    int maxScore = 1;

    std::string leftOffset = "       ";

    //rules init
    std::string rulesTextContent[10] = {

        "                                          " + gameName + " Rules",

        gameName + " is a game of rock, paper, scissors played as a Skandenberg with numbers and an XOR dice roll twist.",

        gameName + " is a game played between two players, on a board in the shape of a square. At each corner \nof the square and at the middle of each side of the square there is a base, for a total \nof 8 bases. The base at the middle of the left side of the square is the home base of \nthe Left Player, and the base at the middle of the right side of the square is the home base \nof the Right Player. At the beginning of the game an <X> symbol is placed on the base at the \nmiddle of the top side of the square. The X can be moved from base to base. The primary objective \nof each player is to place the X on the other's player home base - and this is called a <hit>. \nThe winner is the player who manages to land a number of hits equal to the maximum score set \nfor the current match.",

        "Each turn has two phases. In the first phase of a turn, each player is asked to set a direction \nand a number of positions to move. Each such setting must be a secret, one player must not see what \nsettings the other player makes. After both players have made their settings, the numbers are added and the result is \nused to move the X. For example, if the Left Player sets the direction to < - > and the numbers of \nposition to move to 2, and the Right Player decides for < + > as direction and 3 as number of positions \nto move, then -2 is added to +3 and the result is +1. This means that the X is moved \none position in the clockwise direction. < - > means a move in the counterclockwise direction. The number \nis the number of positions to move the X in the respective direction.",

        "Now comes the second phase of a turn. Each player is asked if they want to roll the dice. The answers, \nonce again, must be secret, one player must not see what the other player decides. If the answers are different, \nand only if the answers are different from each other, a dice is rolled and a number is randomly chosen \nfrom the -1, 0 and 1 values. If the players give the same answer, < y > and < y >, or < n > and < n >, \nno dice is rolled and the position of the X resulted in the first phase of the turn remains unaltered.\nBut if the players give different answers, such as < y > and < n >, the dice is rolled and the result is used \nto move the X: one position counterclockwise for -1, one position clockwise for +1 and no move for 0.",

        "The winner is the first player to land a number of hits on the other's player home base \nequal to the maximum score set for the current match.",

        "",

        "",

        "",

        ""
    };

    int rulesBoardSize = 15;

    int rulesBoardCursorIndex = 1;

    std::string rulesOutputTextArray[4] = { "Return to game options? (y/n): ", "Which one will it be: 1, 2 or 3? ", "Set maximum score for the current match: ", ""};

    std::string rulesLeftOffset = "                                     ";

    //options menu init
    char checkCharsOptionsArray[4] = { '1', '2', '3', ' ' };

    char optionsAnswer;

    int maxScoreAnswer;

    bool exitPush = false;


    GameRules rules(rulesTextContent, rulesBoardSize, fillerCharsArray, rulesBoardCursorIndex, checkCharsArray, rulesOutputTextArray, rulesLeftOffset);

    Game xordenberg(gameName, copyrightData, maxScore, playerOneName, playerTwoName, outputTextArray, boardDim, fillerCharsArray, cursorIndex, checkDigitsArray, checkCharsArray, leftOffset);


    while (!exitPush) {

        std::system("cls");

        optionsAnswer = optionsMenu(gameName, rulesOutputTextArray, 1, checkCharsOptionsArray, 0, 2, xordenberg.getMaxScore());

        switch (optionsAnswer) {

        case '1':

            std::system("cls");

            rules.display();

            break;

        case '2':

            std::system("cls");

            maxScoreAnswer = setMaximumScore(gameName, rulesOutputTextArray, 2, checkDigitsArray, 1, 3);

            xordenberg.setMaxScore(maxScoreAnswer);

            break;

        case '3':

            exitPush = xordenberg.gameLoop();

            break;
        }
    }

    std::cout << std::endl << std::endl << "Thank you for playing " + gameName << std::endl << std::endl;
}


int optionsMenu(std::string gameName, std::string rulesOutputTextArray[4], int textIndex, char checkCharArray[4], int startPosition, int endPosition, int maxScore) {

    char answer;

    InputChar question(rulesOutputTextArray, checkCharArray);


    std::cout << "                                          " + gameName + " Options" << std::endl << std::endl;

    std::cout << "1. Read game manual" << std::endl << std::endl;

    std::cout << "2. Set maximum score (currently " << maxScore << ")" << std::endl << std::endl;

    std::cout << "3. Play game" << std::endl << std::endl << std::endl;

    answer = question.getChar(textIndex, startPosition, endPosition);

    std::cout << std::endl << std::endl << std::endl;

    return answer;
}


int setMaximumScore(std::string gameName, std::string rulesOutputTextArray[4], int textIndex, int checkIntArray[4], int startPosition, int endPosition) {

    int answer;

    InputDigit question(rulesOutputTextArray, checkIntArray);

    std::cout << "                                          " + gameName + " Score Options" << std::endl << std::endl;

    answer = question.getDigit(textIndex, startPosition, endPosition);

    return answer;
}