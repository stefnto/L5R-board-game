#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

GameBoard::GameBoard(int k){
  cout << "GameBoard created!\n";
  cout << "Players created"<< endl;
  initializeGameBoard(k);
}

GameBoard::~GameBoard(){
  cout << "GameBoard to be destroyed!\n";
}

void GameBoard::initializeGameBoard(int k){ //k is the number of the players
    Player* player= new Player();
    players.push_back(*player);
}


int main(void){
  GameBoard game(3);
}
