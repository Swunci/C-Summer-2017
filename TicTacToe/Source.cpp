#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

// prints the specified board out to console
void printBoard(std::string board[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << board[i][j];
		}
		std::cout << "\n";
	}
}

// checks the specified board for 3 X's or 3 O's in a row
bool checkForWinner(std::string board[5][5]) {
	if ((board[0][0] == board[0][2] && board[0][2] == board[0][4]) && 
	    (board[0][2] == " X " || board[0][2] == " O ")) {
		return true;
	}
	else if ((board[2][0] == board[2][2] && board[2][2] == board[2][4]) && 
		 (board[2][2] == " X " || board[2][2] == " O ")) {
		return true;
	}
	else if ((board[4][0] == board[4][2] && board[4][2] == board[4][4]) && 
		 (board[4][2] == " X " || board[4][2] == " O ")) {
		return true;
	}
	else if ((board[0][0] == board[2][0] && board[2][0] == board[4][0]) && 
		 (board[2][0] == " X " || board[2][0] == " O ")) {
		return true;
	}
	else if ((board[0][2] == board[2][2] && board[2][2] == board[4][2]) && 
		 (board[2][2] == " X " || board[2][2] == " O ")) {
		return true;
	}
	else if ((board[0][4] == board[2][4] && board[2][4] == board[4][4]) && 
		 (board[2][4] == " X " || board[2][4] == " O ")) {
		return true;
	}
	else if (((board[0][0] == board[2][2] && board[2][2] == board[4][4]) || 
		  (board[4][0] == board[2][2] && board[2][2] == board[0][4])) && 
		  (board[2][2] == " X " || board[2][2] == " O ")) {
		return true;
	}
	else {
		return false;
	}
}

// Asks the user to input the row number they wish to place their X or O
int rowNum(std::string board[5][5]) {
	std::string input;
	int row;
	bool validRow = false;
	do {
		std::cout << "Enter row: ";
		getline(std::cin, input);
		if (input == "1") {
			row = 0;
			validRow = true;
		}
		else if (input == "2") {
			row = 2;
			validRow = true;
		}
		else if (input == "3") {
			row = 4;
			validRow = true;
		}
		else {
			std::cout << "Invalid row.\n";
		}
	} while (validRow == false);
	return row;
}

// Asks the user to input the column number they wish to place their X or O
int columnNum(std::string board[5][5]) {
	std::string input;
	int column;
	bool validColumn = false;
	do {
		std::cout << "Enter column: ";
		getline(std::cin, input);
		if (input == "1") {
			column = 0;
			validColumn = true;
		}
		else if (input == "2") {
			column = 2;
			validColumn = true;
		}
		else if (input == "3") {
			column = 4;
			validColumn = true;
		}
		else {
			std::cout << "Invalid column.\n";
		}
	} while (validColumn == false);
	return column;
}

// Checks for any potential 3 X's in a row so that the computer's next move would be to block it with a O
bool checkForTwoX(int position[2], std::string board[5][5]) {
	if (board[0][0] == "   " && ((board[0][2] == " X " && board[0][4] == " X ") || 
				    (board[2][0] == " X " && board[4][0] == " X ") || 
				    (board[2][2] == " X " && board[4][4] == " X "))) 
	{
		position[0] = 0;
		position[1] = 0;
		return true;
	}
	else if (board[0][2] == "   " && ((board[0][0] == " X " && board[0][4] == " X ") || 
					  (board[2][2] == " X " && board[4][2] == " X "))) 
	{
		position[0] = 0;
		position[1] = 2;
		return true;
	}
	else if (board[0][4] == "   " && ((board[0][0] == " X " && board[0][2] == " X ") || 
					  (board[2][4] == " X " && board[4][4] == " X ") || 
					  (board[4][0] == " X " && board[2][2] == " X "))) 
	{
		position[0] = 0;
		position[1] = 4;
		return true;
	}
	else if (board[2][0] == "   " && ((board[0][0] == " X " && board[4][0] == " X ") || 
					  (board[2][2] == " X " && board[2][4] == " X "))) 
	{
		position[0] = 2;
		position[1] = 0;
		return true;
	}
	else if (board[2][4] == "   " && ((board[2][0] == " X " && board[2][2] == " X ") || 
					  (board[0][4] == " X " && board[4][4] == " X "))) 
	{
		position[0] = 2;
		position[1] = 4;
		return true;
	}
	else if (board[4][0] == "   " && ((board[0][0] == " X " && board[2][0] == " X ") || 
					  (board[4][2] == " X " && board[4][4] == " X ") || 
					  (board[2][2] == " X " && board[0][4] == " X "))) 
	{
		position[0] = 4;
		position[1] = 0;
		return true;
	}
	else if (board[4][2] == "   " && ((board[4][0] == " X " && board[4][4] == " X ") || 
					  (board[0][2] == " X " && board[2][2] == " X "))) 
	{
		position[0] = 4;
		position[1] = 2;
		return true;
	}
	else if (board[4][4] == "   " && ((board[4][0] == " X " && board[4][2] == " X ") || 
					  (board[0][4] == " X " && board[2][4] == " X ") || 
					  (board[0][0] == " X " && board[2][2] == " X "))) 
	{
		position[0] = 4;
		position[1] = 4;
		return true;
	}
	else {
		return false;
	}
}

// Checks for any potential 3 O's in a row so that the computer's next move would win the game
bool checkForTwoO(int position[2], std::string board[5][5]) {
	if (board[0][0] == "   " && ((board[0][2] == " O " && board[0][4] == " O ") || 
				    (board[2][0] == " O " && board[4][0] == " O ") || 
				    (board[2][2] == " O " && board[4][4] == " O "))) {
		position[0] = 0;
		position[1] = 0;
		return true;
	}
	else if (board[0][2] == "   " && ((board[0][0] == " O " && board[0][4] == " O ") || 
					  (board[2][2] == " O " && board[4][2] == " O "))) {
		position[0] = 0;
		position[1] = 2;
		return true;
	}
	else if (board[0][4] == "   " && ((board[0][0] == " O " && board[0][2] == " O ") || 
					  (board[2][4] == " O " && board[4][4] == " O ") || 
					  (board[4][0] == " O " && board[2][2] == " O "))) {
		position[0] = 0;
		position[1] = 4;
		return true;
	}
	else if (board[2][0] == "   " && ((board[0][0] == " O " && board[4][0] == " O ") || 
					  (board[2][2] == " O " && board[2][4] == " O "))) {
		position[0] = 2;
		position[1] = 0;
		return true;
	}
	else if (board[2][4] == "   " && ((board[2][0] == " O " && board[2][2] == " O ") || 
					  (board[0][4] == " O " && board[4][4] == " O "))) {
		position[0] = 2;
		position[1] = 4;
		return true;
	}
	else if (board[4][0] == "   " && ((board[0][0] == " O " && board[2][0] == " O ") || 
					  (board[4][2] == " O " && board[4][4] == " O ") || 
					  (board[2][2] == " O " && board[0][4] == " O "))) {
		position[0] = 4;
		position[1] = 0;
		return true;
	}
	else if (board[4][2] == "   " && ((board[4][0] == " O " && board[4][4] == " O ") || 
					  (board[0][2] == " O " && board[2][2] == " O "))) {
		position[0] = 4;
		position[1] = 2;
		return true;
	}
	else if (board[4][4] == "   " && ((board[4][0] == " X " && board[4][2] == " X ") || 
					  (board[0][4] == " X " && board[2][4] == " X ") || 
					  (board[0][0] == " X " && board[2][2] == " X "))) {
		position[0] = 4;
		position[1] = 4;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	
	// game loop
	bool play = true;
	while (play == true) {
		
		srand(time(NULL));
		std::string choice;
		bool isValidChoice = false;
		int turnCounter = 0;
		int row;
		int column;
		bool pvp = false;
		bool pvc = false;
		bool player1Turn;
		bool player2Turn;
		bool computerTurn;
		std::string board[5][5] = {
		{ "   ", "|", "   ", "|", "   " },
		{ "---", "+", "---", "+", "---" },
		{ "   ", "|", "   ", "|", "   " },
		{ "---", "+", "---", "+", "---" },
		{ "   ", "|", "   ", "|", "   " } };

		std::cout << "Tic Tac Toe\n";
		std::cout << "Enter 1 for player vs player or enter 2 for player vs computer: ";
		getline(std::cin, choice);
		
		// Ask user for input until valid choice is inputted
		do {
			if (choice == "1") {
				pvp = true;
				player1Turn = true;
				player2Turn = false;
				isValidChoice = true;
			}
			else if (choice == "2") {
				pvc = true;
				player1Turn = true;
				computerTurn = false;
				isValidChoice = true;
			}
			else {
				std::cout << "Invalid choice. Please enter 1 for player vs player or enter 2 for player for computer: ";
				getline(std::cin, choice);
			}
		} while (isValidChoice == false);

		printBoard(board);
		
		// Player vs Player
		while (pvp == true) {
			turnCounter++;
			if (turnCounter > 9) {
				std::cout << "Tie.\n";
				pvp = false;
			}
			
			// Player 1's turn
			else if (player1Turn == true) {
				bool validMove = false;
				// Ask for user to input a valid row and column 
				do {
					row = rowNum(board);
					column = columnNum(board);
					if (board[row][column] == "   ") {
						board[row][column] = " X ";
						printBoard(board);
						validMove = true;
						player1Turn = false;
						player2Turn = true;
						if (checkForWinner(board)) {
							pvp = false;
							std::cout << "Player 1 wins.\n";
						}
					}
					else {
						std::cout << "Invalid move.\n";
					}
				} while (validMove == false);
			}
			// Player 2's turn
			else if (player2Turn == true) {
				bool validMove = false;
				// Ask for user to input a valid row and column 
				do {
					row = rowNum(board);
					column = columnNum(board);
					if (board[row][column] == "   ") {
						board[row][column] = " O ";
						printBoard(board);
						validMove = true;
						player2Turn = false;
						player1Turn = true;
						if (checkForWinner(board)) {
							pvp = false;
							std::cout << "Player 2 wins.\n";
						}
					}
					else {
						std::cout << "Invalid move.\n";
					}
				} while (validMove == false);
			}
		}

		// Player vs Computer
		int position[2];
		bool easy = false;
		bool hard = false;
		if (pvc == true) {

			std::string difficulty;
			bool isValidChoice = false;

			std::cout << "Enter 1 for easy mode or enter 2 for hard mode: ";
			getline(std::cin, difficulty);
			do {
				if (difficulty == "1") {
					easy = true;
					isValidChoice = true;
				}
				else if (difficulty == "2") {
					hard = true;
					isValidChoice = true;
				}
				else {
					std::cout << "Invalid choice. Please enter 1 for easy mode or enter 2 for hard mode: ";
					getline(std::cin, difficulty);
				}
			} while (isValidChoice == false);
		}

		while (pvc == true) {
			turnCounter++;
			if (turnCounter > 9) {
				std::cout << "Tie.\n";
				pvc = false;
			}
			else if (player1Turn == true) {
				bool validMove = false;
				do {
					row = rowNum(board);
					column = columnNum(board);
					if (board[row][column] == "   ") {
						board[row][column] = " X ";
						printBoard(board);
						validMove = true;
						player1Turn = false;
						computerTurn = true;
						if (checkForWinner(board)) {
							pvc = false;
							std::cout << "Player 1 wins.\n";
						}
					}
					else {
						std::cout << "Invalid move.\n";
					}
				} while (validMove == false);
			}
			// Computer making random moves
			else if (computerTurn == true && easy == true) {
				int rowIndex;
				int columnIndex;
				bool validMove = false;
				do {
					row = rand() % 3 + 1;
					column = rand() % 3 + 1;

					if (row == 1) {
						rowIndex = 0;
					}
					else if (row == 2) {
						rowIndex = 2;
					}
					else if (row == 3) {
						rowIndex = 4;
					}
					if (column == 1) {
						columnIndex = 0;
					}
					else if (column == 2) {
						columnIndex = 2;
					}
					else if (column == 3) {
						columnIndex = 4;
					}
					if (board[rowIndex][columnIndex] == "   ") {
						board[rowIndex][columnIndex] = " O ";
						std::cout << "Row: " << row << "\nColumn: " << column << "\n";
						printBoard(board);
						validMove = true;
						computerTurn = false;
						player1Turn = true;
						if (checkForWinner(board)) {
							pvc = false;
							std::cout << "Computer wins.\n";
						}
					}
				} while (validMove == false);
			}
			// Computer playing to win/tie
			else if (computerTurn == true && hard == true) {
				int rowIndex;
				int columnIndex;
				bool validMove = false;
				do {
					// Computer's first turn
					if (turnCounter == 2) {
						// Computer will always place O in the middle first if it is available
						if (board[2][2] == "   ") {
							board[2][2] = " O ";
							std::cout << "Row: 2\nColumn: 2\n";
							printBoard(board);
							validMove = true;
							computerTurn = false;
							player1Turn = true;
						}
						// Else it will place a O in a random corner
						else {
							int corner = rand() % 4;
							if (corner == 0) {
								board[0][0] = " O ";
								std::cout << "Row: 1\nColumn: 1\n";
								printBoard(board);
								validMove = true;
								computerTurn = false;
								player1Turn = true;
							}
							else if (corner == 1) {
								board[0][4] = " O ";
								std::cout << "Row: 1\nColumn: 3\n";
								printBoard(board);
								validMove = true;
								computerTurn = false;
								player1Turn = true;
							}
							else if (corner == 2) {
								board[4][0] = " O ";
								std::cout << "Row: 3\nColumn: 1\n";
								printBoard(board);
								validMove = true;
								computerTurn = false;
								player1Turn = true;
							}
							else {
								board[4][4] = " O ";
								std::cout << "Row: 3\nColumn: 3\n";
								printBoard(board);
								validMove = true;
								computerTurn = false;
								player1Turn = true;
							}
						}
					}
					// Computer's turns after the first
					else {	
						// Check for if the computer can win this turn
						if (checkForTwoO(position, board)) {
							board[position[0]][position[1]] = " O ";
							if (position[0] == 0) {
								row = 1;
							}
							else if (position[0] == 2) {
								row = 2;
							}
							else if (position[0] == 4) {
								row = 3;
							}
							if (position[1] == 0) {
								column = 1;
							}
							else if (position[1] == 2) {
								column = 2;
							}
							else if (position[1] == 4) {
								column = 3;
							}
							std::cout << "Row: " << row << "\nColumn: " << column << "\n";
							printBoard(board);
							validMove = true;
							computerTurn = false;
							player1Turn = true;
							if (checkForWinner(board)) {
								pvc = false;
								std::cout << "Computer wins.\n";
							}
						}
						// Else check if the player is about to win and if they are, block it with an O
						else if (checkForTwoX(position, board)) {
							board[position[0]][position[1]] = " O ";
							if (position[0] == 0) {
								row = 1;
							}
							else if (position[0] == 2) {
								row = 2;
							}
							else if (position[0] == 4) {
								row = 3;
							}
							if (position[1] == 0) {
								column = 1;
							}
							else if (position[1] == 2) {
								column = 2;
							}
							else if (position[1] == 4) {
								column = 3;
							}
							std::cout << "Row: " << row << "\nColumn: " << column << "\n";
							printBoard(board);
							validMove = true;
							computerTurn = false;
							player1Turn = true;
							if (checkForWinner(board)) {
								pvc = false;
								std::cout << "Computer wins.\n";
							}
						}
						// If neither side can win, just randomly place an O in a corner if possible
						else {
							bool emptyCorner = false;
							if (board[0][0] == "   " ||
							    board[0][4] == "   " ||
							    board[4][0] == "   " ||
							    board[4][4] == "   ") 
							{
								emptyCorner = true;
							}
							// If there are any empty corners, place it randomly in one of them
							if (emptyCorner) {
								bool validCorner = false;
								do {
									int corner = rand() % 4;
									if (corner == 0 && board[0][0] == "   ") {
										board[0][0] = " O ";
										std::cout << "Row: 1\nColumn: 1\n";
										printBoard(board);
										validMove = true;
										computerTurn = false;
										player1Turn = true;
										validCorner = true;
									}
									else if (corner == 1 && board[0][4] == "   ") {
										board[0][4] = " O ";
										std::cout << "Row: 1\nColumn: 3\n";
										printBoard(board);
										validMove = true;
										computerTurn = false;
										player1Turn = true;
										validCorner = true;
									}
									else if (corner == 2 && board[4][0] == "   ") {
										board[4][0] = " O ";
										std::cout << "Row: 3\nColumn: 1\n";
										printBoard(board);
										validMove = true;
										computerTurn = false;
										player1Turn = true;
										validCorner = true;
									}
									else if (corner == 3 && board[4][4] == "   ") {
										board[4][4] = " O ";
										std::cout << "Row: 3\nColumn: 3\n";
										printBoard(board);
										validMove = true;
										computerTurn = false;
										player1Turn = true;
										validCorner = true;
									}
								} while (validCorner == false);
							}
							
							// Else place the O randomly somewhere
							else {
								row = rand() % 3 + 1;
								column = rand() % 3 + 1;

								if (row == 1) {
									rowIndex = 0;
								}
								else if (row == 2) {
									rowIndex = 2;
								}
								else if (row == 3) {
									rowIndex = 4;
								}
								if (column == 1) {
									columnIndex = 0;
								}
								else if (column == 2) {
									columnIndex = 2;
								}
								else if (column == 3) {
									columnIndex = 4;
								}
								if (board[rowIndex][columnIndex] == "   ") {
									board[rowIndex][columnIndex] = " O ";
									std::cout << "Row: " << row << "\nColumn: " << column << "\n";
									printBoard(board);
									validMove = true;
									computerTurn = false;
									player1Turn = true;
									if (checkForWinner(board)) {
										pvc = false;
										std::cout << "Computer wins.\n";
									}
								}
							}
						}
					}
				} while (validMove == false);
			}
		}

		std::cout << "Enter 1 to play again or enter anything else to quit: ";
		std::string playOrQuit;
		getline(std::cin, playOrQuit);
		if (playOrQuit != "1") {
			return 0;
		}
	}
}
