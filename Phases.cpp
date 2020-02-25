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
    cout << "Do you want to attack a player?(1-yes 0-no)";
    cin >> battle;
    if (battle==true){
      Attack(player);
      Defend(player);
    }
  } else
      cout << "Player cannot start a battle due to lack of active Personalities" << endl;
}

void battlePhase::Attack(Player& player){
  bool choose;
  int n1;
  cout << "Do you want to pick a Personality to attack?(1-yes 0-no)";
  cin >> choose;
  if (choose == true){
    cout << "Choose a personality(from 1 to " <<  player.GetPersonSize() << ", 0 to exit):";
    cin >> n1;
    while (n1!=0){
      Personality* per =  new Personality(player.getactivePersonalities().at(n1-1));
      if (per->istapped() == false){//if this specific personality was not picked before in battle
        player.setTapped(n1-1); //now it is tapped and we cannot use it again in this round
        player.setOverallAttack(per->getAttack()); //the overall combat attack of the player
      }
      else
        cout << "This card has been picked again in battle in this round!!!\n";
      delete per;
      cout << "Do you want to choose another personality to attack?\n";
      player.printPersonalities();
      cin >> n1;
    }
    cout << "The overall attack is: " << player.getOverallAttack() << endl;
  }
}

void battlePhase::Defend(Player& player){
  bool choose;
  int n1;
  cout << "Do you want to pick a Personality to defend?(1-yes 0-no)";
  cin >> choose;
  if (choose == true){
    cout << "Choose a personality(from 1 to " <<  player.GetPersonSize() << ", 0 to exit):";
    cin >> n1;
    while (n1!=0){
      Personality* per =  new Personality(player.getactivePersonalities().at(n1-1));
      if (per->istapped() == false){//if this specific personality was not picked before in battle
        player.setTapped(n1-1); //now it is tapped and we cannot use it again in this round
        player.setOverallDefense(per->getDefense()); //the overall combat attack of the player
      }
      else
        cout << "This card has been picked again in battle in this round!!!\n";
      delete per;
      cout << "Do you want to choose another personality to defend?\n";
      player.printPersonalities();
      cin >> n1;
    }
    cout << "The overall defense is: " << player.getOverallDefense() << endl;
  }
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
    cout << "Choose a card to buy(writing the number of its place in the order shown, from 1 to 4, 0 to exit):";
    cin >> n1;
    while (n1!=0){
      player.BuyProvince(n1-1);
      cout << "Money = " << player.getMoney() << ", buy another card?" << endl;
      player.printprovinces();
      cin >> n1;
    }
  } else
      cout << "Continuing to next round" << endl;
}
