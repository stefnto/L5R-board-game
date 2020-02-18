#include "Phases.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;

void startingPhase::drawFateCard(Player& player){
  player.GetGreenCard();
}

void startingPhase::revealProvinces(Player& player){
  player.RevealPro();
}

void startingPhase::printProvinces(Player& player){
  cout << "Printing provinces: " ;
  player.printprovinces();
}

void startingPhase::untapEverything(Player& player){
    player.unTappHoldings();
    player.unTappPersonalities();
    player.unTappProvinces();
    cout << "Player's cards were untapped" << endl;
}


void startingPhase::printHand(Player& player){
  cout << "Printing hand: ";
  player.printhand();
}
