/*
 * BaseBoard.h
 *
 *  Created on: 21/02/2021
 *      Author: dongmo
 */

#ifndef BOARD_H_
#define BOARD_H_

#include<iostream>
#include<list>
#include <iterator>
#include <algorithm>
#include <stack>
#include <vector>
#include "myStack.h"

class Board {
private:
	int turn;
	int **grid;
    list<int> emptyCells;
    stack<int> neighbourCells;
    int boardSize;
    int bCells;
public:
	Board(int bs) {
		boardSize = bs;
		bCells = boardSize*boardSize;
		grid = new int*[boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = 0;
			}
		turn = 1;
	}

	virtual ~Board() {

		for (int i = 0; i < boardSize; i++)
			delete[] grid[i];

		delete[] grid;
	}

	Board(Board &cboard) {
		boardSize = cboard.getBoardSize();

		grid = new int*[boardSize];
		for (int i = 0; i < boardSize; i++)
			grid[i] = new int[boardSize];

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++)
				grid[i][j] = 0;

		for (int i = 0; i < boardSize; i++)
			for (int j = 0; j < boardSize; j++) {
				grid[i][j] = cboard.getGrid(i, j);
			}

		turn = cboard.getTurn();
	}

	int getBoardSize() {
		return boardSize;
	}

	int getGrid(int x, int y) {
		return grid[x][y];
	}

	int getTurn() {
		return turn;
	}
    void makeEmptyCellList();

	void printConnectedNeighbours();

    list<int> getEmptyCells() {
        return emptyCells;
    }
    /*
    vector <int> getVisited(){
        return visited;
    }
    stack<int> getNeighbourCells(){
        return  neighbourCells;
    }
*/
	bool validInput(int, int);

	bool addMove(int playerType, int x, int y);

    stack<int> getConnectedNeighbours(int playerType, int x, int y);

	bool boardStatus (int x, int y);
    bool visited(int m, vector<int> v);
    //bool isVisited(int move, list <int> visited1);
    //bool checkWinningStatus(int playerType);

	int checkWinningStatus(int playerType) {
        if (playerType == 1){
            for (int j=0; j < boardSize; j++){
                for (int i =0; i < boardSize; i++){
                    if (grid[i][j] != playerType)
                        break;
                    if ( i == boardSize-1 && grid[i][j] == playerType){
                        return 1;
                    }
                }
            }
        }
        else {
            for (int j=0; j < boardSize; j++){
                for (int i =0; i < boardSize; i++){
                    if (grid[j][i] != playerType)
                        break;
                    if ( i == boardSize-1 && grid[i][j] == playerType){
                        return -1;
                    }
                }
            }
        }
        return 0;
	}
	    void printBoard();
};

bool Board::visited(int m, vector<int> v){
    int item = m;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == m)
        return true;
    }

    return false;
}

bool Board::validInput(int x, int y) {
	if (x < 0 || y < 0 || x >= boardSize || y >= boardSize) {
		cout << "Move (" << x + 1 << ", " << y + 1 << ") out of range!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}

	return true;
}

bool Board::addMove(int playerType, int x, int y) {
    //Move counter for efficiency
    int mCounter =0;
	if (playerType != turn) {
		cout << "It is not the player's turn!" << endl;
		return false;
	}

	if (grid[x][y] != 0) {
		cout << "Invalid move. The cell has been occupied." << endl;
		return false;
	}
	grid[x][y] = playerType;
    mCounter++;

    boardStatus(x, y);
    getConnectedNeighbours(playerType, x, y);
    printConnectedNeighbours();

	turn = -1 * turn;
	return true;
}

stack<int> Board::getConnectedNeighbours(int playerType, int x, int y){
    stack<int> neighbourCells;
    int mC;
    //stack<int> neighbourCells;
    if ( x-1 >= 0 && y >= 0 && y < boardSize && grid[x-1][y] == playerType) {
        mC = (x-1) * boardSize + y;
        neighbourCells.push(mC);
    }
    if ( x-1 >= 0 && y+1 < boardSize && x-1 < boardSize && grid[x-1][y+1] == playerType) {
        mC = (x-1) * boardSize + (y+1);
        neighbourCells.push(mC);
    }

    if ( x < boardSize && y-1 >= 0 && y-1 < boardSize && grid[x][y-1] == playerType) {
        mC = x * boardSize + (y-1);
        neighbourCells.push(mC);
    }
    if ( x >= 0 && y+1 < boardSize && x < boardSize && grid[x][y+1] == playerType) {
        mC = (x) * boardSize + (y+1);
        neighbourCells.push(mC);
    }

    if ( x+1 >= 0 && x+1 < boardSize && y-1 >= 0 && grid[x+1][y-1] == playerType) {
        mC = (x+1) * boardSize + (y-1);
        neighbourCells.push(mC);
    }
    if ( x+1 >= 0 && x+1 < boardSize && y >= 0 && grid[x+1][y] == playerType ) {
        mC = (x+1) * boardSize + y;
        neighbourCells.push(mC);
    }

    return neighbourCells;
}

bool Board::boardStatus (int x, int y){
    // recently fulled cell get removed from the list
    int rFC = x*boardSize+y;
    emptyCells.remove(rFC);
    if (emptyCells.empty()) {
        return true;
    }
}
/*
 */

void Board::makeEmptyCellList(){
        for (int fxt = 0; fxt < bCells; fxt++) {
            emptyCells.push_back(fxt);
            //int t = fxt+1;
            //visited.push_back(t);
        }

}
void Board::printConnectedNeighbours() {
    if (neighbourCells.empty())
        std::cout << "there are no connected cells!" << endl;
    else {
        std::cout << "Connected cells are: ";
        while (!neighbourCells.empty()) {
            int w = neighbourCells.top();
            cout << w << "  ";
            neighbourCells.pop();
        }
        cout << endl;
    }
}

void Board::printBoard() {
	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		if (j < 9)
			cout << j + 1 << "   ";
		else
			cout << j + 1 << "  ";
	}
	cout << endl;

	cout << "   ";
	for (int j = 0; j < boardSize; j++) {
		cout << "----";
	}
	cout << endl;

	for (int i = 0; i < boardSize; i++) {
		for (int k = 0; k < i; k++)
			cout << "  ";

		if (i < 9)
			cout << " " << i + 1 << " ";
		else
			cout << i + 1 << " ";

		for (int j = 0; j < boardSize; j++) {
			if (grid[i][j] == 0) {
				if (j == 0) {
					cout << "|   |";
				} else {
					cout << "   |";
				}
			} else if (grid[i][j] == 1) {
				if (j == 0) {
					cout << "| H |";
				} else {
					cout << " H |";
				}
			} else {
				if (j == 0) {
					cout << "| * |";
				} else {
					cout << " * |";
				}
			}
		}
		cout << endl;
	}

	for (int k = 0; k <= boardSize; k++)
		cout << "  ";

	for (int j = 0; j < boardSize; j++) {
		cout << "----";
	}

	cout << endl;
	cout << endl;
}

#endif /* BOARD_H_ */
