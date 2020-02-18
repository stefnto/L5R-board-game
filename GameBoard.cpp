#include "GameBoard.hpp"
#include "Player.hpp"
#include "Holding.hpp"
#include <algorithm> //to use sort()

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
  srand(time(NULL));
  players = new Player[k];
  for (int i=0; i<k; i++){
    for (int j=0; j<4; j++)//4 GreenCards are drawn from each player at the start of the game
      players[i].GetGreenCard();
    string string1 = "Player" + to_string(i+1) + " Stronghold";
    cout << string1 << endl;
    Stronghold* stronghold = new Stronghold(string1, k);
    players[i].addStronghold(stronghold);//Function addStronghold() here adds the Stronghold of each player
    for (int j=0; j<4; j++)
      players[i].GetProvince();
  }
  sortplayers(k);  
  cout << k << " players are playing the game!" << endl;
}

void GameBoard::gameplay(){}

void GameBoard::sortplayers(int num){
  for (int i=0; i<num; i++){
    int n1 =  players[i].getStrongholdHonour();
    for (int j=i+1; j<num; j++){
      int n2 = players[j].getStrongholdHonour();
      if (n2 >= n1){
        Player *player1 = new Player(players[j]);
        players[j] = players[i];
        players[i] = *player1;
      }
    }
  }
}
