#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;

GameBoard::GameBoard(int k){
  cout << "GameBoard created!" << endl;
  initializeGameBoard(k);
}

GameBoard::~GameBoard(){
  cout << "GameBoard to be destroyed!\n";
}

void GameBoard::initializeGameBoard(int k){ //k is the number of the players
  players = new Player[k];
  /*vector<Player>::iterator it;
  it = players.begin();
  cout << players.size() << endl;*/
  //players.emplace_back();
  //players.emplace_back();
  /*players.emplace_back();
  for (int i=0; i<2; i++){
    players.emplace(it+i);
  }
  cout << players.size() << endl;*/
}
