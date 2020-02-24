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
}


void startingPhase::printHand(Player& player){
  cout << "Printing hand: ";
  player.printhand();
}

void equipPhase::Equip(Player& player, int i){
  if (player.GetPersonSize()!= 0){
    cout << "Available Green cards: ";
    player.printhand();
    cout << "Army: ";
    player.printPersonalities();
    BuyAndPlace(player);
  }
  else
    cout << "Player" << i << " has no active Personalities" << endl;
}

void equipPhase::BuyAndPlace(Player& player){
  int n1, n2;
  cout << "Choose a Green Card to buy(writing the number of its place in the order shown, 1 to " << player.GetHandSize() << "):";
  cin >> n1;
  cout << "Choose personality to apply the Green Card to(1 to " << player.GetPersonSize() << "):";
  cin >> n2;
  player.BuyGreenCard(n1-1, n2-1);
}

void battlePhase::Battle(Player& player){
  if (player.GetPersonSize()!= 0){ //player has army
    bool battle;
    player.printPersonalities();
    cout << "Do you want to attack a player?";
    cin >> battle;
    if (battle==true){

    }
  } else
      cout << "Player cannot start a battle due to lack of active Personalities" << endl;
}

void battlePhase::Attack(Player&){

}

void battlePhase::Defend(Player&){

}

void economyPhase::Economy(Player& player){
  cout << "Printing provinces: " ;
  player.printprovinces();
  bool buy;
  int n1;
  cout << "Do you want to buy a BlackCard?(1-yes 0-no)";
  cin >> buy;
  if (buy==true){
    cout << "Money = " << player.getMoney() << endl;
    cout << "Choose a card to buy(writing the number of its place in the order shown, 1 to 4, 0 to exit):";
    cin >> n1;
    while (n1!=0){
      player.BuyProvince(n1-1);
      cout << "Money = " << player.getMoney() << ", buy another card?" << endl;
      player.printprovinces();
      cin >> n1;
    }
  } else
      cout << "Continuing to next player\n" << endl;
}

void finalPhase::discardSurplusFateCards(Player& player){
  if (player.GetHandSize() > MAX_GREEN_CARDS){
    while (player.GetHandSize() <= MAX_GREEN_CARDS){
      cout << "Choose a card to discard" << endl;
      player.printhand();
      int discard;
      cin >> discard;
      player.discardfromHand(discard-1);
    }
  }
}
