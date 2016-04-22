/************************************************************
* Name:  Joe Gramuglia                                      *
* Project : Canoga                                          *
* Class : OPL                                               *
* Date : 9/25/2015                                          *
*************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <list>

using namespace std;

class Board {
private:
	// Variable to hold the human's board
	vector<bool> humanBoard;
	// Variable to hold the computer's board
	vector<bool> computerBoard;

public:
	Board() {}

	Board(int size) {
		humanBoard.resize(size);
		computerBoard.resize(size);
	}

	/***********************************************************************
	Function Name: setSize
	Purpose: To set the size of the board
	Parameters:
		size, an integer. The size of the board
	Return Value: none
	Local Variables: none
	Algorithm:
		1) Resize the human's board to size
		2) Resize the computer's board to size
	Assistance Received: none
	***********************************************************************/
	void setSize(int size) {
		humanBoard.resize(size);
		computerBoard.resize(size);
	}

	/***********************************************************************
	Function Name: setSubBoard
	Purpose: To set a sub-board
	Parameters:
		human, a boolean. True to use the human board
		subBoard, vector of booleans. The new board
		Return Value: none
	Local Variables: none
	Algorithm:
		1) If human, set human's sub-board to subBoard
		2) Else, set computer's sub-board to subBoard
	Assistance Received: none
	***********************************************************************/
	void setSubBoard(bool human, vector<bool> subBoard) {
		if (human) {
			humanBoard = subBoard;
		}
		else {
			computerBoard = subBoard;
		}
	}

	/***********************************************************************
	Function Name: isCovered
	Purpose: To check if a square on the board is covered
	Parameters:
		human, a boolean. True to use the human board
		square, an integer. The square to check
		Return Value: True if square is covered
	Local Variables: none
	Algorithm:
		1) If human, return value at square on human's board
		2) Else, return value at square on computer's board
	Assistance Received: none
	***********************************************************************/
	bool isCovered(bool human, int square) {
		if (human) {
			return humanBoard[square];
		}
		else {
			return computerBoard[square];
		}
	}

	/***********************************************************************
	Function Name: cover
	Purpose: To cover a square
	Parameters:
		human, a boolean. True to use the human board
		square, an integer. The square to cover
	Return Value: none
	Local Variables: none
	Algorithm:
		1) If human, set square on human's board to true
		2) Else, set square on computer's board to true
	Assistance Received: none
	***********************************************************************/
	void cover(bool human, int square) {
		if (human) {
			humanBoard[square] = true;
		}
		else {
			computerBoard[square] = true;
		}
	}

	/***********************************************************************
	Function Name: uncover
	Purpose: To uncover a square
	Parameters:
		human, a boolean. True to use the human board
		square, an integer. The square to cover
	Return Value: none
	Local Variables: none
	Algorithm:
		1) If human, set square on human's board to false
		2) Else, set square on computer's board to false
	Assistance Received: none
	***********************************************************************/
	void uncover(bool human, int square) {
		if (human) {
			humanBoard[square] = false;
		}
		else {
			computerBoard[square] = false;
		}
	}

	/***********************************************************************
	Function Name: allCovered
	Purpose: To easily check if an entire board is covered
	Parameters:
		human, a boolean. True to use the human board
	Return Value: True if entire board is covered
	Local Variables:
		i, an integer used to count loops
	Algorithm:
		1) If human, check each square on human's board
		2) Else, check each square on computer's board
	Assistance Received: none
	***********************************************************************/
	bool allCovered(bool human) {
		if (human) {
			for (int i = 0; i < humanBoard.size(); i++) {
				if (humanBoard[i] == false) {
					return false;
				}
			}
			return true;
		}
		else {
			for (int i = 0; i < computerBoard.size(); i++) {
				if (computerBoard[i] == false) {
					return false;
				}
			}
			return true;
		}
	}

	/***********************************************************************
	Function Name: allUncovered
	Purpose: To easily check if an entire board is uncovered
	Parameters:
		human, a boolean. True to use the human board
	Return Value: True if entire board is uncovered
	Local Variables:
		i, an integer used to count loops
	Algorithm:
		1) If human, check each square on human's board
		2) Else, check each square on computer's board
	Assistance Received: none
	***********************************************************************/
	bool allUncovered(bool human) {
		if (human) {
			for (int i = 0; i < humanBoard.size(); i++) {
				if (humanBoard[i] == true) {
					return false;
				}
			}
			return true;
		}
		else {
			for (int i = 0; i < computerBoard.size(); i++) {
				if (computerBoard[i] == true) {
					return false;
				}
			}
			return true;
		}
	}

	/***********************************************************************
	Function Name: getSubBoard
	Purpose: To returns a sub-board
	Parameters:
		human, a boolean. True to use the human board
	Return Value: The human's/computer's board
	Local Variables: none
	Algorithm:
		1) If human, return human's board
		2) Else, return computer's board
	Assistance Received: none
	***********************************************************************/
	vector<bool> getSubBoard(bool human) {
		if (human) {
			return humanBoard;
		}
		else {
			return computerBoard;
		}
	}

	/***********************************************************************
	Function Name: is7UpCovered
	Purpose: To check if square 7-n are covered
	Parameters:
		human, a boolean. True to use the human board
	Return Value: True if squares 7-n are covered
	Local Variables: none
	Algorithm:
		1) If human, check if human's 7-n are covered
		2) Else, check if computer's 7-n are covered
	Assistance Received: none
	***********************************************************************/
	bool is7UpCovered(bool human) {
		if (human) {
			for (int i = 6; i < humanBoard.size(); i++) {
				if (!humanBoard[i]) {
					return false;
				}
			}
			return true;
		}
		else {
			for (int i = 6; i < computerBoard.size(); i++) {
				if (!computerBoard[i]) {
					return false;
				}
			}
			return true;
		}
	}
};

class BoardView {
public:
	Board board;

	BoardView() {}

	BoardView(int size) {
		board = Board::Board(size);
	}

	/***********************************************************************
	Function Name: displayBoard
	Purpose: To display the entire boards
	Parameters: none
	Return Value: none
	Local Variables:
		humanBoard, vector of booleans. Refers to the human's board
		computerBoard, vector of booleans. Refers to the computer's board
	Algorithm:
		1) Print the human's board
		2) Print the computer's board
	Assistance Received: none
	***********************************************************************/
	void displayBoard() {
		vector<bool> humanBoard = board.getSubBoard(true);
		vector<bool> computerBoard = board.getSubBoard(false);

		cout << "Human's Board:    ";
		for (int i = 0; i < humanBoard.size(); i++) {
			if (humanBoard[i] == false) {
				cout << " " << i + 1;
			}
			else {
				cout << " *";
			}
		}
		cout << endl;

		cout << "Computer's Board: ";
		for (int i = 0; i < computerBoard.size(); i++) {
			if (computerBoard[i] == false) {
				cout << " " << i + 1;
			}
			else {
				cout << " *";
			}
		}
		cout << endl;
	}
};

class Player {
private:
	bool cover = false;
	vector<vector<int>> coverMoves;
	vector<vector<int>> uncoverMoves;

public:
	Player() {}

	/***********************************************************************
	Function Name: evaluateMoves
	Purpose: To calculate and store all possible moves for this turn
	Parameters:
		cover, boolean. Use to find all cover/uncover moves
		subBoard, vector of boolean. The sub-board to evaluate
		rollTotal, an integer. The amount of pips rolled this turn
		currentSquare, an integer. The square to evaluate on
		combination, vector of integers. A potential combination of moves
	Return Value: none
	Local Variables:
		sum, an integer. Holds the sum of the numbers in combination
		remainder, an integer. The remaining amount of pips to be used
	Algorithm:
		1) if the currentSquare is bigger than the total, return
		2) if the currentSquare is bigger than the size of the board, return
		3) if the currentSquare is covered already, return
		4) Add the currentSquare to the combination
		5) Get the sum
		6) Get the remainder
		7) if remainder = 0, add the combination to the coverMoves/uncoverMoves vector and return
		8) if remainder < 0, return
		9) if rollTotal is bigger than subBoard size, use the board size to recurse
		10) else, use the rollTotal to recurse
	Assistance Received: none
	***********************************************************************/
	void evaluateMoves(bool cover, vector<bool> subBoard, int rollTotal, int currentSquare, vector<int> combination) {
		if (cover) {
			if (currentSquare + 1 > rollTotal) {
				return;
			}
			if (currentSquare > subBoard.size() - 1) {
				return;
			}
			if (subBoard[currentSquare]) {
				return;
			}
			combination.push_back(currentSquare);

			int sum = 0;
			for (int i = 0; i < combination.size(); i++) {
				sum += combination[i] + 1;
			}

			int remainder = rollTotal - sum;
			if (remainder == 0) {
				coverMoves.push_back(combination);
				return;
			}
			if (remainder < 0) {
				return;
			}

			// remainder > 0

			if (rollTotal > subBoard.size()) {
				while (currentSquare + 1 <= subBoard.size()) {
					currentSquare++;
					evaluateMoves(cover, subBoard, rollTotal, currentSquare, combination);
				}
			}
			else {
				while (currentSquare + 1 <= rollTotal) {
					currentSquare++;
					evaluateMoves(cover, subBoard, rollTotal, currentSquare, combination);
				}
			}
		}
		else {
			if (currentSquare + 1 > rollTotal) {
				return;
			}
			if (currentSquare > subBoard.size() - 1) {
				return;
			}
			if (!subBoard[currentSquare]) {
				return;
			}
			combination.push_back(currentSquare);

			int sum = 0;
			for (int i = 0; i < combination.size(); i++) {
				sum += combination[i] + 1;
			}

			int remainder = rollTotal - sum;
			if (remainder == 0) {
				uncoverMoves.push_back(combination);
				return;
			}
			if (remainder < 0) {
				return;
			}

			// remainder > 0

			if (rollTotal > subBoard.size()) {
				while (currentSquare + 1 <= subBoard.size()) {
					currentSquare++;
					evaluateMoves(cover, subBoard, rollTotal, currentSquare, combination);
				}
			}
			else {
				while (currentSquare + 1 <= rollTotal) {
					currentSquare++;
					evaluateMoves(cover, subBoard, rollTotal, currentSquare, combination);
				}
			}
		}
	}

	/***********************************************************************
	Function Name: findBestMove
	Purpose: To find the best move
	Parameters:
		myBoard, vector of boolean. The board I am using
		theirBoard, vector of boolean. The board the opponent is using
	Return Value: The combination of squares to cover/uncover
	Local Variables:
		coverScore, an integer. Abstract score if you covered
		uncoverScore, an integer. Abstract score if you uncovered
	Algorithm:
		1) Calculate the coverScore
		2) Calculate the uncoverScore
		3) if coverScore < uncoverScore, cover
		4) else, uncover
	Assistance Received: none
	***********************************************************************/
	vector<int> findBestMove(vector<bool> myBoard, vector<bool> theirBoard) {
		int coverScore = 0;
		int uncoverScore = 0;
		for (int i = 0; i < myBoard.size(); i++) {
			if (myBoard[i]) {
				coverScore += i;
			}
		}
		for (int i = 0; i < theirBoard.size(); i++) {
			if (!theirBoard[i]) {
				uncoverScore += i;
			}
		}

		if (coverScore < uncoverScore) {
			if (coverMoves.size() == 0) {
				if (uncoverMoves.size() == 0) {
					return {};
				}
				cover = false;
				return uncoverMoves[uncoverMoves.size() - 1];
			}
			cover = true;
			return coverMoves[coverMoves.size() - 1];
		}
		else {
			if (uncoverMoves.size() == 0) {
				if (coverMoves.size() == 0) {
					return{};
				}
				cover = true;
				return coverMoves[coverMoves.size() - 1];
			}
			cover = false;
			return uncoverMoves[uncoverMoves.size() - 1];
		}
	}

	/***********************************************************************
	Function Name: displayMoves
	Purpose: To display all the cover/uncover moves
	Parameters:
		cover, boolean. To display cover/uncover moves
	Return Value: none
	Local Variables:
		i, an integer used to count loops
	Algorithm:
		1) if cover, loop through and print the coverMoves
		2) else, loop through and print the uncoverMoves
	Assistance Received: none
	***********************************************************************/
	void displayMoves(bool cover) {
		if (cover) {
			cout << "Cover Moves: {";
			for (int i = 0; i < coverMoves.size(); i++) {
				cout << " {";
				for (int j = 0; j < coverMoves[i].size(); j++) {
					cout << " " << coverMoves[i][j] + 1;
				}
				cout << " }";
			}
			cout << " }" << endl;
		}
		else {
			cout << "Uncover Moves: {";
			for (int i = 0; i < uncoverMoves.size(); i++) {
				cout << " {";
				for (int j = 0; j < uncoverMoves[i].size(); j++) {
					cout << " " << uncoverMoves[i][j] + 1;
				}
				cout << " }";
			}
			cout << " }" << endl;
		}
	}

	/***********************************************************************
	Function Name: resetMoves
	Purpose: To reset the moves vectors
	Parameters: none
	Return Value: none
	Local Variables: none
	Algorithm:
		1) emtpy the coverMoves and uncoverMoves vectors
	Assistance Received: none
	***********************************************************************/
	void resetMoves() {
		coverMoves.clear();
		uncoverMoves.clear();
	}

	/***********************************************************************
	Function Name: displayMove
	Purpose: To display an individual move
	Parameters:
		move, vector of integer. The move to display
		cover, boolean. To display cover/uncover move
	Return Value: none
	Local Variables:
		i, an integer used to count loops
	Algorithm:
		1) loop through the move and print each one
	Assistance Received: none
	***********************************************************************/
	void displayMove(vector<int> move, bool cover) {
		if (cover) {
			cout << "Cover: {";
		}
		else {
			cout << "Uncover: {";
		}
		for (int i = 0; i < move.size(); i++) {
			cout << " " << move[i] + 1;
		}
		cout << " }" << endl;
	}

	/***********************************************************************
	Function Name: getMoves
	Purpose: To easily get a moves list
	Parameters:
		cover, boolean. To return cover/uncover move
	Return Value: The list of possible cover/uncover moves
	Local Variables: none
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	vector<vector<int>> getMoves(bool cover) {
		if (cover) {
			return coverMoves;
		}
		else {
			return uncoverMoves;
		}
	}

	/***********************************************************************
	Function Name: setCover
	Purpose: To set a value that determines of the best move is to cover or uncover
	Parameters:
		c, boolean. To use cover/uncover move
	Return Value: none
	Local Variables: none
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	void setCover(bool c) {
		cover = c;
	}

	/***********************************************************************
	Function Name: getCover
	Purpose: To return if the best move is a cover or uncover move
	Parameters: none
	Return Value: True if to best move is to cover
	Local Variables: none
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	bool getCover() {
		return cover;
	}
};

class Computer : public Player {
public:
	Computer() {}

	/***********************************************************************
	Function Name: takeTurn
	Purpose: To take the computer's turn
	Parameters:
		humanBoard, vector of boolean. The human's board
		computerBoard, vector of boolean. The computer's board
		totalRolled, an integer. The number of pips rolled
		canWin, boolean. Can't uncover if true
	Return Value: The turn the computer wants to make
	Local Variables:
		i, an integer used to count loops
		best, vector of integers. Holds the best move
	Algorithm:
		1) Find all the cover moves
		2) Find all the uncover moves
		3) Display all the moves
		4) Find the best move
		5) Display the best move
		6) Return the best move
	Assistance Received: none
	***********************************************************************/
	vector<int> takeTurn(vector<bool> humanBoard, vector<bool> computerBoard, int totalRolled, bool canWin) {
		resetMoves();
		cout << "\n--------------------------" << endl;
		cout << "Computer's Turn: Rolled " << totalRolled << endl;
		for (int i = 0; i < computerBoard.size(); i++) {
			evaluateMoves(true, computerBoard, totalRolled, i, {});
		}
		if (canWin) {
			for (int i = 0; i < humanBoard.size(); i++) {
				evaluateMoves(false, humanBoard, totalRolled, i, {});
			}
		}
		displayMoves(true);
		displayMoves(false);
		vector<int> best = findBestMove(computerBoard, humanBoard);
		cout << "Best ";
		displayMove(best, getCover());
		return best;
	}
};

class Human : public Player {
public:
	Human() {}

	/***********************************************************************
	Function Name: takeTurn
	Purpose: To take the human's turn
	Parameters:
		humanBoard, vector of boolean. The human's board
		computerBoard, vector of boolean. The computer's board
		totalRolled, an integer. The number of pips rolled
		canWin, boolean. Can't uncover if true
	Return Value: The turn the human wants to make
	Local Variables:
		i, an integer used to count loops
		best, vector of integers. Holds the best move
	Algorithm:
		1) Find all the cover moves
		2) Find all the uncover moves
		3) Display all the moves
		4) Wait for move
		5) Return the chosen move
	Assistance Received: none
	***********************************************************************/
	vector<int> takeTurn(vector<bool> humanBoard, vector<bool> computerBoard, int totalRolled, bool canWin) {
		resetMoves();
		cout << "\n-----------------------" << endl;
		cout << "Human's Turn: Rolled " << totalRolled << endl;
		if (canWin) {
			for (int i = 0; i < computerBoard.size(); i++) {
				evaluateMoves(false, computerBoard, totalRolled, i, {});
			}
		}
		for (int i = 0; i < humanBoard.size(); i++) {
			evaluateMoves(true, humanBoard, totalRolled, i, {});
		}

		int number;
		int optionSize = displayOptions(getMoves(true), getMoves(false));
		if (optionSize > 0) {
			do {
				cout << "Enter a number: ";
				cin >> number;
				if (number > optionSize || number < 0) {
					cout << "Invalid option." << endl;
				}
				if (number == 0) {
					cout << "Hint: ";
					vector<int> best = findBestMove(humanBoard, computerBoard);
					displayMove(best, getCover());
				}
			} while (number > optionSize || number < 1);
			vector<int> move;
			if (number > getMoves(true).size()) {
				setCover(false);
				move = getMoves(false)[number - getMoves(true).size() - 1];
			}
			else {
				setCover(true);
				move = getMoves(true)[number - 1];
			}
			return move;
		}
		return{};
	}

	/***********************************************************************
	Function Name: displayOptions
	Purpose: To display the human's options
	Parameters:
		coverMoves, vector of vector of integers. The possible cover moves
		uncoverMoves, vector of vector of integers. The possible uncover moves
	Return Value: The amount of options displayed
	Local Variables:
		i, an integer. used to count loops
		counter, an integer. holds the number of options
	Algorithm:
		1) Display hint
		2) Display cover moves
		3) Display uncover moves
	Assistance Received: none
	***********************************************************************/
	int displayOptions(vector<vector<int>> coverMoves, vector<vector<int>> uncoverMoves) {
		int counter = 0;
		cout << counter << ") Hint" << endl;
		for (int i = 0; i < coverMoves.size(); i++) {
			counter++;
			cout << counter << ") ";
			displayMove(coverMoves[i], true);
		}
		for (int i = 0; i < uncoverMoves.size(); i++) {
			counter++;
			cout << counter << ") ";
			displayMove(uncoverMoves[i], false);
		}
		return counter;
	}
};

#include <time.h>

class Game {
private:
	BoardView view;
	Human human;
	Computer computer;
	int winner = 0;
	bool canWin = false;
	int humanScore = 0;
	int computerScore = 0;
	bool firstTurn;
	bool nextTurn;
	int humanTotal = 0;
	int computerTotal = 0;
	list<int> dieRolls;

public:
	Game() {}

	Game(int humans, int computers, int previousHumanScore, int previousComputerScore, bool previousFirst) {
		string line;
		ifstream myfile("dieRolls.txt");
		if (myfile.is_open())
		{
			cout << "Die Rolls: ";
			while (getline(myfile, line))
			{
				for (int i = 0; i < line.size(); i++) {
					if (line[i] >= 49 && line[i] <= 54) {
						cout << line[i] << ' ';
						dieRolls.push_back(line[i] - 48);
					}
				}
			}
			cout << endl;
			
			myfile.close();
		}
		else {
			cout << "Unable to read file.";
		}
		

		humanTotal = humans;
		computerTotal = computers;
		int size;
		do {
			cout << "Enter the board size(9-11): ";
			cin >> size;
			if (size > 11 || size < 9) {
				cout << "Invalid size." << endl;
			}
		} while (size > 11 || size < 9);
		view.board.setSize(size);

		if (previousHumanScore > previousComputerScore) {
			if (previousFirst) {
				int sum = 0;
				while (previousHumanScore != 0) {
					sum += previousHumanScore % 10;
					previousHumanScore /= 10;
				}
				while (sum > size) {
					sum -= size;
				}
				view.board.cover(false , sum-1);
			}
			else {
				int sum = 0;
				while (previousHumanScore != 0) {
					sum += previousHumanScore % 10;
					previousHumanScore /= 10;
				}
				while (sum > size) {
					sum -= size;
				}
				view.board.cover(true, sum - 1);
			}
		}
		if (previousHumanScore < previousComputerScore) {
			if (previousFirst) {
				int sum = 0;
				while (previousComputerScore != 0) {
					sum += previousComputerScore % 10;
					previousComputerScore /= 10;
				}
				while (sum > size) {
					sum -= size;
				}
				view.board.cover(false, sum - 1);
			}
			else {
				int sum = 0;
				while (previousComputerScore != 0) {
					sum += previousComputerScore % 10;
					previousComputerScore /= 10;
				}
				while (sum > size) {
					sum -= size;
				}
				view.board.cover(true, sum - 1);
			}
		}

		srand(time(NULL));
		int humanRoll;
		int computerRoll;
		do {
			humanRoll = rollDie() + rollDie();
			computerRoll = rollDie() + rollDie();
			cout << "\nHuman's Roll: " << humanRoll << endl;
			cout << "Computer's Roll: " << computerRoll << endl;
		} while (humanRoll == computerRoll);


		if (humanRoll > computerRoll) {
			cout << "Human goes first." << endl;
			firstTurn = true;
		}
		else {
			cout << "Computer goes first." << endl;
			firstTurn = false;
		}
		beginTurns(firstTurn);
	}

	Game(vector<bool> hBoard, vector<bool> cBoard, int hScore, int cScore, bool fTurn, bool nTurn) {
		view.board.setSubBoard(true, hBoard);
		view.board.setSubBoard(false, cBoard);
		humanTotal = hScore;
		computerTotal = cScore;
		firstTurn = fTurn;
		nextTurn = nTurn;
		canWin = true;

		string line;
		ifstream myfile("dieRolls.txt");
		if (myfile.is_open())
		{
			cout << "Die Rolls: ";
			while (getline(myfile, line))
			{
				for (int i = 0; i < line.size(); i++) {
					if (line[i] >= 49 && line[i] <= 54) {
						cout << line[i] << ' ';
						dieRolls.push_back(line[i] - 48);
					}
				}
			}
			cout << endl;

			myfile.close();
		}
		else {
			cout << "Unable to read file.";
		}

		beginTurns(nTurn);
	}

	/***********************************************************************
	Function Name: beginTurns
	Purpose: To go through the turns of the game
	Parameters:
		humanFirst, boolean. True if human goes first
	Return Value: The amount of options displayed
	Local Variables:
		save, an integer. Holder for yes/no  option
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	void beginTurns(bool humanFirst) {
		if (humanFirst) {
			while (winner == 0) {
				humanTurn();
				canWin = true;
				nextTurn = false;
				int save;
				do {
					cout << "Save Game?" << endl;
					cout << "0) Yes" << endl;
					cout << "1) No" << endl;
					cin >> save;
					if (save > 1 || save < 0) {
						cout << "Invalid Option." << endl;
					}
				} while (save > 1 || save < 0);
				if (save == 0) {
					saveGame(humanTotal, computerTotal);
				}
				if (winner != 0) {
					break;
				}
				computerTurn();
				nextTurn = true;
				do {
					cout << "Save Game?" << endl;
					cout << "0) Yes" << endl;
					cout << "1) No" << endl;
					cin >> save;
					if (save > 1 || save < 0) {
						cout << "Invalid Option." << endl;
					}
				} while (save > 1 || save < 0);
				if (save == 0) {
					saveGame(humanTotal, computerTotal);
				}
			}
		}
		else {
			while (winner == 0) {
				computerTurn();
				canWin = true;
				nextTurn = true;
				int save;
				do {
					cout << "Save Game?" << endl;
					cout << "0) Yes" << endl;
					cout << "1) No" << endl;
					cin >> save;
					if (save > 1 || save < 0) {
						cout << "Invalid Option." << endl;
					}
				} while (save > 1 || save < 0);
				if (save == 0) {
					saveGame(humanTotal, computerTotal);
				}
				if (winner != 0) {
					break;
				}
				humanTurn();
				nextTurn = false;
				do {
					cout << "Save Game?" << endl;
					cout << "0) Yes" << endl;
					cout << "1) No" << endl;
					cin >> save;
					if (save > 1 || save < 0) {
						cout << "Invalid Option." << endl;
					}
				} while (save > 1 || save < 0);
				if (save == 0) {
					saveGame(humanTotal, computerTotal);
				}
			}
		}
		if (winner == 1) {
			cout << "Human wins the game." << endl;
		}
		if (winner == 2) {
			cout << "Computer wins the game." << endl;
		}
		calcScores();
	}

	/***********************************************************************
	Function Name: humanTurn
	Purpose: To take the human's turn
	Parameters: none
	Return Value: none
	Local Variables:
		humanMove, vector of integers. Holds the human's move
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	void humanTurn() {
		vector<int> humanMove;
		do {
			cout << endl;
			view.displayBoard();
			int roll;
			if (view.board.is7UpCovered(true)) {
				int option;
				do {
					cout << "Roll Options:" << endl;
					cout << "-------------" << endl;
					cout << "1) Roll Die" << endl;
					cout << "2) Roll Dice" << endl << endl;
					cout << "Enter option: " << endl;
					cin >> option;
				} while (option > 2 && option < 1);
				if (option == 1) {
					roll = rollDie();
				}
				else {
					roll = rollDie() + rollDie();
				}
			}
			else {
				roll = rollDie() + rollDie();
			}
			humanMove = human.takeTurn(view.board.getSubBoard(true), view.board.getSubBoard(false), roll, canWin);
			if (humanMove.size() == 0) {
				cout << "Human's Turn Over." << endl;
				cout << "------------------" << endl;
				break;
			}
			bool coverHumanBoard = human.getCover();
			if (coverHumanBoard) {
				for (int i = 0; i < humanMove.size(); i++) {
					view.board.cover(true, humanMove[i]);
				}
			}
			else {
				for (int i = 0; i < humanMove.size(); i++) {
					view.board.uncover(false, humanMove[i]);
				}
			}
			if ((view.board.allCovered(true) || view.board.allUncovered(false)) && canWin == true) {
				winner = 1;
				cout << endl;
				view.displayBoard();
				break;
			}
		} while (humanMove.size() != 0);
	}

	/***********************************************************************
	Function Name: computerTurn
	Purpose: To take the computer's turn
	Parameters: none
	Return Value: none
	Local Variables:
		computerMove, vector of integers. Holds the computer's move
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	void computerTurn() {
		vector<int> computerMove;
		do {
			cout << endl;
			view.displayBoard();
			int roll;
			if (view.board.is7UpCovered(false)) {
				roll = rollDie();
			}
			else {
				roll = rollDie() + rollDie();
			}
			computerMove = computer.takeTurn(view.board.getSubBoard(true), view.board.getSubBoard(false), roll, canWin);
			if (computerMove.size() == 0) {
				cout << "Computer's Turn Over." << endl;
				cout << "---------------------" << endl;
				break;
			}
			bool coverHumanBoard = computer.getCover();
			if (coverHumanBoard) {
				for (int i = 0; i < computerMove.size(); i++) {
					view.board.cover(false, computerMove[i]);
				}
			}
			else {
				for (int i = 0; i < computerMove.size(); i++) {
					view.board.uncover(true, computerMove[i]);
				}
			}
			if ((view.board.allCovered(false) || view.board.allUncovered(true)) && canWin == true) {
				winner = 2;
				cout << endl;
				view.displayBoard();
				break;
			}
			int wait;
			cin >> wait;
		} while (computerMove.size() != 0);
	}

	/***********************************************************************
	Function Name: rollDie
	Purpose: To generate random numbers between 1-6
	Parameters: none
	Return Value: A number between 1-6
	Local Variables:
		roll, an integer. Holds the die roll
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	int rollDie() {
		int roll;
		if (!dieRolls.empty()) {
			roll = dieRolls.front();
			dieRolls.pop_front();
		}
		else {
			roll = rand() % 6 + 1;
		}
		return roll;
	}

	/***********************************************************************
	Function Name: getWinner
	Purpose: To find out who is the winner
	Parameters: none
	Return Value: 0 if no winner. 1 if human wins. 2 if computer wins
	Local Variables: none
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	int getWinner() {
		if (winner == 1) {
			return true;
		}
		else {
			return false;
		}
	}
	/***********************************************************************
	Function Name: calcScores
	Purpose: To find out who is the winner
	Parameters: none
	Return Value: none
	Local Variables:
		score, an integer. Holds the score
		i, an integer. used to count loops
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	void calcScores() {
		int score = 0;
		if (winner == 1) {
			if (view.board.allCovered(true)) {
				for (int i = 0; i < view.board.getSubBoard(false).size(); i++) {
					if (!view.board.isCovered(false, i)) {
						score += i + 1;
					}
				}
				humanScore = score;
			}
			else {
				for (int i = 0; i < view.board.getSubBoard(true).size(); i++) {
					if (view.board.isCovered(true, i)) {
						score += i + 1;
					}
				}
				humanScore = score;
			}
		}
		if (winner == 2) {
			if (view.board.allCovered(false)) {
				for (int i = 0; i < view.board.getSubBoard(true).size(); i++) {
					if (!view.board.isCovered(true, i)) {
						score += i + 1;
					}
				}
				computerScore = score;
			}
			else {
				for (int i = 0; i < view.board.getSubBoard(false).size(); i++) {
					if (view.board.isCovered(false, i)) {
						score += i + 1;
					}
				}
				computerScore = score;
			}
		}
	}

	/***********************************************************************
	Function Name: getScore
	Purpose: To easily get the score
	Parameters:
		humans, boolean. For human/computer score
	Return Value: human/computer score
	Local Variables: none
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	int getScore(bool humans) {
		if (humans) {
			return humanScore;
		}
		else {
			return computerScore;
		}
	}

	/***********************************************************************
	Function Name: saveGame
	Purpose: To save the game
	Parameters:
		humanScore, an integer. The human's score
		computerScore, an integer. The computer's score
	Return Value: none
	Local Variables:
		gameFile, ofstream.
		rawtime, time_t.
		... etc
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	void saveGame(int humanScore, int computerScore) {
		ofstream gameFile;
		if (gameFile.is_open()) {
			// Save game by time 
			time_t rawtime;
			struct tm timeinfo;
			char buffer[80];

			time(&rawtime);
			localtime_s(&timeinfo, &rawtime);
			strftime(buffer, 80, "Game%m-%d-%Y-%H-%M-%S.txt", &timeinfo);
			cout << "Game saved as " << buffer << endl;
			gameFile.open(buffer);
			gameFile << "Computer:\n"
				<< "\tSquares:";
			for (int i = 0; i < view.board.getSubBoard(false).size(); i++) {
				if (view.board.getSubBoard(false)[i]) {
					gameFile << " *";
				}
				else {
					gameFile << " " << i;
				}
			}
			gameFile << "\n\tScore: " << computerScore << "\n"
				<< "\n"
				<< "Human:\n"
				"\tSquares:";
			for (int i = 0; i < view.board.getSubBoard(true).size(); i++) {
				if (view.board.getSubBoard(true)[i]) {
					gameFile << " *";
				}
				else {
					gameFile << " " << i;
				}
			}
			gameFile << "\n\tScore: " << humanScore << "\n"
				<< "\n"
				<< "First Turn: ";
			if (firstTurn) {
				gameFile << "Human";
			}
			else {
				gameFile << "Computer";
			}
			gameFile << "\n"
				<< "Next Turn: ";
			if (nextTurn) {
				gameFile << "Human";
			}
			else {
				gameFile << "Computer";
			}
			gameFile.close();
		}
		else {
			cout << "Unable to open file" << endl;
		}
	}

	/***********************************************************************
	Function Name: setTotals
	Purpose: To easily set the totals of each player
	Parameters:
		humans, an integer. The human's score
		computers, an integer. The computer's score
	Return Value: none
	Local Variables: none
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	void setTotals(int humans, int computers) {
		humanTotal = humans;
		computerTotal = computers;
	}

	/***********************************************************************
	Function Name: getFirstTurn
	Purpose: To get the who has the first turn
	Parameters: none
	Return Value: True for human went first. True for computer went first. 
	Local Variables: none
	Algorithm: none
	Assistance Received: none
	***********************************************************************/
	bool getFirstTurn() {
		return firstTurn;
	}
};

class Tournament {
private:
	int humanScore = 0;
	int computerScore = 0;
	bool handicap = false;
	Game game;
	vector<bool> humanBoard;
	vector<bool> computerBoard;
	int previousHumanScore = 0;
	int previousComputerScore = 0;
	bool previousFirstTurn;

public:
	Tournament() {
		bool exit = false;
		while (!exit) {
			if (!handicap) {
				game = Game::Game(humanScore, computerScore, 0, 0, false);
			}
			else {
				game = Game::Game(humanScore, computerScore, previousHumanScore, previousComputerScore, previousFirstTurn);
			}

			previousHumanScore = game.getScore(true);
			previousComputerScore = game.getScore(false);
			previousFirstTurn = game.getFirstTurn();

			cout << "Human's Scored " << previousHumanScore << " Points." << endl;
			cout << "Computer's Scored " << previousComputerScore << " Points." << endl;
			cout << endl;

			humanScore += previousHumanScore;
			computerScore += previousComputerScore;

			cout << "Human's Total Score: " << humanScore << endl;
			cout << "Computer's Total Score:  " << computerScore << endl;
			cout << endl;

			int play;
			do {
				cout << "Continue?" << endl;
				cout << "0) Yes" << endl;
				cout << "1) No" << endl;
				cin >> play;
				if (play > 1 || play < 0) {
					cout << "Invaild Option." << endl;
				}
			} while (play > 1 || play < 0);
			if (play == 1) {
				exit = true;
			}
			else {
				handicap = true;
			}
		}
		if (humanScore == computerScore) {
			cout << "The tournamnet is a draw." << endl;
		}
		if (humanScore > computerScore) {
			cout << "Human wins the tournament." << endl;
		}
		if (humanScore < computerScore) {
			cout << "Computer wins the tournament." << endl;
		}
	}

	Tournament(vector<bool> hBoard, vector<bool> cBoard, int hScore, int cScore, bool fTurn, bool nTurn) {
		Game game(hBoard, cBoard, hScore, cScore, fTurn, nTurn);
		previousHumanScore = game.getScore(true);
		previousComputerScore = game.getScore(false);
		previousFirstTurn = fTurn;

		cout << "Human's Scored " << previousHumanScore << " Points." << endl;
		cout << "Computer's Scored " << previousComputerScore << " Points." << endl;
		cout << endl;

		humanScore += previousHumanScore;
		computerScore += previousComputerScore;

		cout << "Human's Total Score: " << humanScore << endl;
		cout << "Computer's Total Score:  " << computerScore << endl;
		cout << endl;

		int play;
		do {
			cout << "Continue?" << endl;
			cout << "0) Yes" << endl;
			cout << "1) No" << endl;
			cin >> play;
			if (play > 1 || play < 0) {
				cout << "Invaild Option." << endl;
			}
		} while (play > 1 || play < 0);
		if (play == 0) {
			handicap = true;
			game = Game::Game(humanScore, computerScore, previousHumanScore, previousComputerScore, previousFirstTurn);
		}
		if (humanScore == computerScore) {
			cout << "The tournamnet is a draw." << endl;
		}
		if (humanScore > computerScore) {
			cout << "Human wins the tournament." << endl;
		}
		if (humanScore < computerScore) {
			cout << "Computer wins the tournament." << endl;
		}
	}
};

int main() {
	int option;
	do {
		cout << "Canoga" << endl;
		cout << "------------" << endl;
		cout << "0) New Game" << endl;
		cout << "1) Load Game" << endl;
		cout << "2) Exit Game" << endl;
		cout << "Enter Option: ";
		cin >> option;
	} while (option > 2 || option < 0);
	if (option == 0) {
		Tournament();
	}
	if (option == 1) {
		string fileName;
		cout << "Enter the file name: ";
		cin >> fileName;
		string line;
		ifstream gamefile(fileName + ".txt");
		if (gamefile.is_open())
		{
			vector<bool> computerBoard;
			vector<bool> humanBoard;
			int computerScore = 0;
			int humanScore = 0;
			bool firstTurn;
			bool nextTurn;

			int count = 0;
			while (getline(gamefile, line))
			{
				if (count == 1) {
					for (int i = 0; i < line.size(); i++) {
						if (line[i] >= 49 && line[i] <= 57  && line[i - 1] == ' ' || line[i] == '*') {
							if (line[i] == '*') {
								computerBoard.push_back(true);
							}
							else {
								computerBoard.push_back(false);
							}
						}
					}
				}
				if (count == 2) {
					for (int i = 0; i < line.size(); i++) {
						if (line[i] >= 48 && line[i] <= 57) {
							computerScore += line[i] - 48;
							computerScore *= 10;
						}
					}
					computerScore /= 10;
				}
				if (count == 5) {
					for (int i = 0; i < line.size(); i++) {
						if (line[i] >= 49 && line[i] <= 57 && line[i - 1] == ' ' || line[i] == '*') {
							if (line[i] == '*') {
								humanBoard.push_back(true);
							}
							else {
								humanBoard.push_back(false);
							}
						}
					}
				}
				if (count == 6) {
					for (int i = 0; i < line.size(); i++) {
						if (line[i] >= 48 && line[i] <= 57) {
							humanScore += line[i] - 48;
							humanScore *= 10;
						}
					}
					humanScore /= 10;
				}

				if (count == 8) {
					for (int i = 0; i < line.size(); i++) {
						if (line[i] == 'C') {
							firstTurn = false;
							break;
						}
						if (line[i] == 'H') {
							firstTurn = true;
							break;
						}
					}
				}
				if (count == 9) {
					for (int i = 0; i < line.size(); i++) {
						if (line[i] == 'C') {
							nextTurn = false;
							break;
						}
						if (line[i] == 'H') {
							nextTurn = true;
							break;
						}
					}
				}
				count++;
			}
			gamefile.close();

			Tournament(humanBoard, computerBoard, humanScore, computerScore, firstTurn, nextTurn);
		}

		else cout << "Unable to open file";
	}
	if (option == 2) {
		cout << "Exiting Game..." << endl;
	}

	return 0;
}