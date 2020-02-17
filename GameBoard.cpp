#include "GameBoard.hpp"
#include "Player.hpp"
#include "Holding.hpp"

using namespace std;

GameBoard::GameBoard(int k){
  cout << "GameBoard created!" << endl;
  initializeGameBoard(k);
}

GameBoard::~GameBoard(){
  cout << "GameBoard to be destroyed!\n";
  delete []players;
}

void GameBoard::initializeGameBoard(int k){ //k is the number of the players
  players = new Player[k];
  for (int i=0; i<k; i++){
    for (int j=0; j<4; j++)//4 GreenCards are drawn from each player at the start of the game
      players[i].GetGreenCard();
    string string1 = "Player" + to_string(i+1) + " Stronghold";
    Holding* stronghold = new Stronghold(string1);
    players[i].addHolding(*stronghold);//Function addHolding() here adds the Stronghold of each player
  }
  cout << k << " players are playing the game!" << endl;
}

void GameBoard::gameplay(){}
