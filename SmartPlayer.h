/*
 * ComputerPlayer.h
 *
 *  Created on: 10/04/2021
 *      Author: Navid
 */

#ifndef SMARTPLAYER_H_
#define SMARTPLAYER_H_

using namespace std;

class SmartPlayer: public Player {
public:
    SmartPlayer(int c, string name = "Smart Player") :
            Player(c, name) {
    }
    bool getMove(Board*, int &x, int &y);
};


bool SmartPlayer::getMove(Board *board, int &x, int &y) {
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

#endif /* SMARTPLAYER_H_ */
