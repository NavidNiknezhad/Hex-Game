/*
 * HexGame.h
 *
 *  Created on: 21/02/2021
 *      Author: dongmo
 */

#ifndef HEXGAME_H_
#define HEXGAME_H_

class HexGame {
private:
	Board *board;
	Player *player[2];
public:
	HexGame(Board *b, Player *p1, Player *p2) {
		board = b;
		player[0] = p1;
		player[1] = p2;
	}

	void play();
};

void HexGame::play() {
	int won = 0;
	bool isBoardFull = false;
	board->printBoard();
	board -> makeEmptyCellList();

	while (!won) {

		int playerType = board->getTurn();
		int playerIndex = (playerType == player[0]->getType()) ? 0 : 1;
		int x = -1;
		int y = -1;

		if (!player[playerIndex]->getMove(board, x, y)) {
			cout << "No available move" << endl;
			return;
		}

		cout << player[playerIndex]->getPlayerName() << " plays " << " ("
				<< x + 1 << ", " << y + 1 << "):" << endl;

		if (!board->addMove(playerType, x, y))
			return;

		board->printBoard();
		//int i =0;
        //if (i >= (board->getBoardSize()*2)-1)

        won = board->checkWinningStatus(playerType);

        //i++;
        if(won == playerType)
        	cout << player[playerIndex]->getPlayerName() << " player wins!" << endl;

        isBoardFull = board->boardStatus(x, y);
        if ( won != playerType && isBoardFull == true){
            cout << "the board is full" << endl;
            return;
        }

	}
}

#endif /* HEXGAME_H_ */
