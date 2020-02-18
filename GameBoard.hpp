#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include "Card.hpp"
#include "Player.hpp"
#include "Phases.hpp"

class GameBoard{
  private:
    Player* players;
  public:
    GameBoard(int);
    ~GameBoard();
    void initializeGameBoard(int);
    void printGameStatistics();
    void gameplay(int);
    void sortplayers(int);
    Player* get_players();
};

#endif
