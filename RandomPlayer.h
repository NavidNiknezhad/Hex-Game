/*
 * ComputerPlayer.h
 *
 *  Created on: 10/04/2021
 *      Author: Navid
 */

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

using namespace std;

class RandomPlayer: public Player {
public:
    RandomPlayer(int c, string name = "Random Player") :
            Player(c, name) {
    }
    bool getMove(Board*, int &x, int &y);
};


bool RandomPlayer::getMove(Board *board, int &x, int &y) {
    bool flag = false;
    int bs = board->getBoardSize();
    int index = 0;

    while (!flag) {
        index = rand() % board->getEmptyCells().size();
        list<int>::iterator it;
        it = board->getEmptyCells().begin();
        advance(it, index);
        int k = *it; // a random value taken from that list
        x = k / bs;
        y = k % bs;
        flag = board->validInput(x, y);
        if (flag == false)
            cout << "Invalid input! Please input again." << endl;
    }

    return true;
}

#endif /* RANDOMPLAYER_H_ */
