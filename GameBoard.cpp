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
}

void GameBoard::initializeGameBoard(int k){ //k is the number of the players
  players = new Player[k];
   for (int i=0; i<k; i++){
    for (int j=0; j<4; j++)//4 GreenCards are drawn from each player at the start of the game
      players[i].GetGreenCard();
    string string1 = "Player" + to_string(i+1) + " Stronghold";
    Stronghold* stronghold = new Stronghold(string1, k);
    players[i].addStronghold(stronghold);//Function addStronghold() here adds the Stronghold of each player
    players[i].giveMoney(); //Gives starting money to the player
    for (int j=0; j<4; j++)
      players[i].GetProvince();
  }
  sortplayers(k); //sorts players in descending order
  cout << k << " players are playing the game!" << endl;
}

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


Player* GameBoard::get_players(){
  return players;
}

void GameBoard::gameplay(int k){
  startingPhase* start = new startingPhase();
  equipPhase* equip = new equipPhase();
  cout << endl;
  for (int i=0; i<k; i++){
  //Starting Phase
    start->untapEverything(players[i]);
    start->drawFateCard(players[i]);
    start->revealProvinces(players[i]);
    start->printHand(players[i]);
    start->printProvinces(players[i]);
  //Equip phase
    equip->Equip(players[i]);
  //Battle phase


  cout << endl;
 }
}
