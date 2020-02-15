#include "GameBoard.h"

Gameboard::Gameboard(){
  cout << "GameBoard created!\n";
}

GameBoard::GameBoard(){
  cout << "GameBoard to be destroyed!\n";
  delete players[];
}

void GameBoard::initializeGameBoard(int k){ //k is the number of the players
  players = new Player[k];
}
