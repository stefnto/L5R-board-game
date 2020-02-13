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
