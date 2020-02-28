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
    Stronghold* stronghold = new Stronghold(string1, k);
    players[i].addStronghold(stronghold);//Function addStronghold() here adds the Stronghold of each player
    players[i].giveMoney(); //Gives starting money to the player
    for (int j=0; j<4; j++)
      players[i].DrawProvince();
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
  battlePhase* battle = new battlePhase();
  economyPhase* economy = new economyPhase();
  finalPhase* final = new finalPhase();
  bool game_finished = false;
  cout << endl;
  int i=0;
  while (game_finished == false){
    if (i!=0)
      cout << "//////////////////////////////////////////////////NEXT ROUND//////////////////////////////////////////////////////" << endl;

    //Starting Phase
    cout << "//////////////////////////////////////////////////Starting Phase//////////////////////////////////////////////////" << endl;
    for (int i=0; i<k; i++){
      cout << "Player" << i+1 << ":" << endl;
      start->untapEverything(players[i]);
      start->drawFateCard(players[i]);
      start->revealProvinces(players[i]);
      start->printHand(players[i]);
      start->printProvinces(players[i]);
      cout << endl;
    }
    cout << "Continuing to next round..." << endl;

    //Equip phase
    cout << "//////////////////////////////////////////////////Equip Phase//////////////////////////////////////////////////" << endl;
    for (int i=0; i<k; i++){
      cout << "Player" << i+1 << "'s turn:" << endl;
      equip->Equip(players[i], i+1);
      cout << endl;
    }
    cout << "Continuing to next round..." << endl;

    //Battle phase
    cout << "/////////////////////////////////////////////////Battle Phase////////////////////////////////////////////////////" << endl;
      for (int i=0; i<k; i++){
      cout << "Player" << i+1 << "'s turn:" << endl;
      battle->Battle(players[i], players, k);
    }
    cout << "Continuing to next round..." << endl;

    //Economy phase
    cout << "//////////////////////////////////////////////////Economy Phase//////////////////////////////////////////////////" << endl;
    for (int i=0; i<k; i++){
      cout << "Player" << i+1 << "'s turn:" << endl;
      economy->Economy(players[i]);
    }
    cout << "Continuing to next round..." << endl;

    /*for (int i=0; i<k-1; i++)
      for (int j=0; j<4; j++)
        players[i].deleteProvince(0);*/

    //Final phase
    cout << "//////////////////////////////////////////////////Final Phase//////////////////////////////////////////////////" << endl;
    final->discardSurplusFateCards(players, k);
    final->printHand(players, k);
    final->printProvinces(players, k);
    final->printHoldings(players, k);
    final->printArena(players, k);
    game_finished = final->checkWinningCondition(players, k);
    i++;
  }
}
