#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include "Card.h"
#include "Player.h"

class GameBoard{
  private:
    Player* players;
  public:
    GameBoard();
    ~GameBoard();
    void initializeGameBoard(int);
};


#endif
