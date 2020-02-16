#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include "Card.hpp"
#include "Player.hpp"

class GameBoard{
  private:
    std::vector<Player> players;
  public:
    GameBoard(int);
    ~GameBoard();
    void initializeGameBoard(int);
    void printGameStatistics();
};

#endif
