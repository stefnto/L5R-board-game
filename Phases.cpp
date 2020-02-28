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
    player.unTappStronghold();
}


void startingPhase::printHand(Player& player){
  cout << "Printing hand: ";
  player.printhand();
}

void equipPhase::Equip(Player& player, int i){
  if (player.GetPersonSize()!= 0){
    cout << "Army: ";
    player.printPersonalities();
    int n1=1, n2;
    while (n1!=0){
      cout << "Money = " << player.getMoney() << endl;
      cout << "Available Green cards: ";
      player.printhand();
      cout << "Choose a Green Card to buy(writing the number of its place in the order shown, from 1 to " << player.GetHandSize() << ",0 to exit):";
      cin >> n1;
      if (n1!=0){
        cout << "Choose personality to apply the Green Card to(1 to " << player.GetPersonSize() << "):";
        cin >> n2;
        player.BuyGreenCard(n1-1, n2-1);
      }
    }
  }
  else
    cout << "Player" << i << " has no active Personalities" << endl;
}


void battlePhase::Battle(Player& player, Player* players, int k){ //k is the size of players' array
  if (player.GetPersonSize()!= 0){ //player has army
    bool battle;
    cout << "Army: ";
    player.printPersonalities();
    Defend(player);
    cout << "Do you want to attack a player(1-yes 0-no)?";
    cin >> battle;
    if (battle==true){
      Attack(player, players, k);
    }
  } else
      cout << "Player cannot start a battle due to lack of active Personalities" << endl;
  cout << endl;
}

void battlePhase::Attack(Player& player, Player* players, int k){
  AttackPrepare(player);
  int attack, province;
  bool attack_done = false;
  while (attack_done==false){ //loop needed if player choses to attack himself by mistake
    cout << "Choose which player to attack(from 1 to " << k << "):" << endl;
    for (int i=0; i<k; i++){
      cout << "Player" << i+1 << " provinces: ";
      players[i].printprovinces();
    }
    cin >> attack;
    if (&player != &players[attack-1]){ //player cannot attack himself
      attack_done = true;
      cout << "Choose which province of the player to attack(from 1 to " << players[attack-1].GetProvinceSize() << ")" << endl;
      players[attack-1].printprovinces();
      cin >> province;
      BlackCard* black = players[attack-1].GetProvince(province-1);
      //int result = 0;
      int result = player.getOverallAttack() - (players[attack-1].getOverallDefense() + black->getInitialDefense());
      //cout << "result = " << result << " amuna eparxias = " << black->getInitialDefense() << endl << endl;
      if (result>black->getInitialDefense()){ //attacking player wins!
        players[attack-1].deleteProvince(province-1); //deletes attacked province
        players[attack-1].loseDefendingPersonalities(); //deletes defending personalities of attack province
      }
      else{
        if(result > 0){ //bullet 1
          players[attack-1].loseDefendingPersonalities();
          cout << endl;
          player.loseChosenAttackingPersonalities(result);
          player.itemloseDurability();
          player.personloseHonour(); //personalities that were attacking and lost but survived
        }
        else if(result == 0){ //draw
          players[attack-1].loseDefendingPersonalities();
          player.loseAttackingPersonalities();
        }
        else if (result < 0){ //bullet 3
           player.loseAttackingPersonalities();
           cout << endl;
           players[attack-1].loseChosenDefendingPersonalities(result);
         }
      }
    } else cout << "Player cannot attack himself" << endl;
  }
}

void battlePhase::AttackPrepare(Player& player){
  int n1;
  cout << "Army: ";
  player.printPersonalities();
  cout << "Choose a personality(from 1 to " <<  player.GetPersonSize() << ", 0 to exit):";
  cin >> n1;
  while (n1!=0){
    if ((player.getactivePersonalities().at(n1-1)).istapped() == false){//if this specific personality was not picked before in battle
      player.setTapped(n1-1, 1); //now it is tapped and we cannot use it again in this round
      //player.setOverallAttack(25);
      player.setOverallAttack((player.getactivePersonalities().at(n1-1)).getBonusAttack()); //the overall combat attack of the attacking personalities
    }
    else
      cout << "This card has been picked again in battle in this round!!!\n";
    cout << "Do you want to choose another personality to attack(0 to exit)?\n";
    cout << "Army: ";
    player.printPersonalities();
    cin >> n1;
  }
  cout << "The overall attack is: " << player.getOverallAttack() << endl;
}

void battlePhase::Defend(Player& player){
  int n1;
    cout << "Choose a personality to use for defense(from 1 to " <<  player.GetPersonSize() << ", 0 to exit):";
    cin >> n1;
    while (n1!=0){
      if ((player.getactivePersonalities().at(n1-1)).istapped() == false){//if this specific personality was not picked before in battle
        player.setTapped(n1-1, 0); //now it is tapped and we cannot use it again in this round
        player.setOverallDefense((player.getactivePersonalities().at(n1-1)).getBonusDefense()); //the overall defense from the defending personalities
      }
      else
        cout << "This card has been picked again in battle in this round!!!\n";
      cout << "Do you want to choose another personality to defend(0 to exit)?\n";
      cout << "Army: ";
      player.printPersonalities();
      cin >> n1;
    }
    cout << "The overall defense is: " << player.getOverallDefense() << endl;

}


void economyPhase::Economy(Player& player){
  cout << "Printing provinces: " ;
  player.printprovinces();
  bool buy;
  int n1;
  cout << "Do you want to buy a BlackCard(1-yes 0-no)?";
  cin >> buy;
  if (buy==true){
    cout << "Money = " << player.getMoney() << endl;
    cout << "Choose a card to buy(writing the number of its place in the order shown, from 1 to 4, 0 to exit):";
    cin >> n1;
    while (n1!=0){
      player.BuyProvince(n1-1);
      cout << "Money = " << player.getMoney() << ", buy another card(0 to exit)?" << endl;
      player.printprovinces();
      cin >> n1;
    }
  }
  cout << endl;
}

void finalPhase::discardSurplusFateCards(Player* players, int k){
  int card;
  for (int i=0; i<k; i++){
    if (players[i].GetHandSize() > MAX_CARDS_INHAND){
      cout << "Player" << i+1 << "'s turn:" << endl;
      while (players[i].GetHandSize() > MAX_CARDS_INHAND){
        cout << "Choose " << players[i].GetHandSize() - MAX_CARDS_INHAND << " card(s) to discard(1 to " << players[i].GetHandSize() << ")" << endl;
        players[i].printhand();
        cin >> card;
        players[i].deletefromHand(card-1);
        cout << "Card discarded" << endl;
      }
    }
    else cout << "Player" << i+1 << " has no cards to discard" << endl;
  }
  cout << endl;
}

void finalPhase::printHand(Player* players, int k){
  for (int i=0; i<k; i++){
    cout << "Player" << i+1 << "'s hand: ";
    players[i].printhand();
  }
  cout << endl;
}


void finalPhase::printProvinces(Player* players, int k){
  for (int i=0; i<k; i++){
    cout << "Player" << i+1 << "'s provinces: ";
    players[i].printprovinces();
  }
  cout << endl;
}


void finalPhase::printHoldings(Player* players, int k){
  for (int i=0; i<k; i++){
    cout << "Player" << i+1 << "'s holdings: ";
    players[i].printholdings();
  }
  cout << endl;
}

void finalPhase::printArena(Player* players, int k){
  for (int i=0; i<k; i++){
    cout << "Player" << i+1 << "'s army: ";
    players[i].printPersonalitieswithAttack();
    players[i].printFollowersandItems();
  }
}

bool finalPhase::checkWinningCondition(Player* players, int k){
  int p[k];
  int num=0; //checks how many players have 0 provinces left
  int winner;
  for (int i=0; i<k; i++){
    p[i] = players[i].GetProvinceSize();
  }

  for (int i=0; i<k; i++){
    if (p[i] == 0)
      num++;
    else winner = i+1;
  }
  if (num == k-1){
    cout << "Winner of the game is Player" << winner << ", congratulations!!" << endl;
    return true;
  }
  else{
      cout << "No winner yet" << endl;
      return false;
    }
}
