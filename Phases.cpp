#include "Phases.hpp"
#include "Player.hpp"
#include "GameBoard.hpp"
#include <algorithm>

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

void equipPhase::Equip(Player& player){
  if (player.GetPersonSize()!= 0){
    cout << "Available Green cards: ";
    player.printhand();
    cout << "Army: ";
    player.printPersonalities();
    BuyAndPlace(player);
  }
  else
    cout << "Player has no active Personalities" << endl;
}

void equipPhase::BuyAndPlace(Player& player){
  int n1, n2;
  cout << "Choose a Green Card to buy(writing the number of its place in the order shown, 1 to " << player.GetHandSize() << "):";
  cin >> n1;
  cout << "Choose personality to apply the Green Card to(1 to " << player.GetPersonSize() << "):";
  cin >> n2;
  player.BuyGreenCard(n1-1, n2-1);

}
