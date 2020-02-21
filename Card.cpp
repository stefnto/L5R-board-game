#include "Card.hpp"
#include <string>

using namespace std;

Card::Card(){
    unTapp();
   //the card is untapped
}

void Card::unTapp(){
  isTapped = false;
}

void Card::Tapp(){
  isTapped = true;
}

GreenCard::GreenCard(){
  isFollower = false;
  isItem = false;
}

void GreenCard::EnableEffectBonus(){
  int bonus;
  cout << "Press 1 to upgrade attack, 0 to upgrade defense:";
  cin >> bonus;
  if (bonus==1)
    attackBonus += effectBonus;
  else if (bonus==2)
      defenseBonus += effectBonus;
  cout << "effectBonus has been applied!\n";
}

int GreenCard::type(){
    if (isFollower == true)
      return 0;
    else if (isItem == true)
      return 1;
}

int GreenCard::getMinHonour(){
  return minimumHonour;
}

int GreenCard::getEffectCost(){
  return effectCost;
}

BlackCard::BlackCard(){
  Hide(); //the card is hidden
}

void BlackCard::Reveal(){
  isRevealed = true;
}

void BlackCard::Hide(){
  isRevealed = false;
}

std::string Card::getName(){
  return this->name;
}

int Card::getCost(){
  return this->cost;
}

int BlackCard::getType(){
  if (isPersonality == true)
    return PERSONALITY;
  else
    return HOLDING;
}

int GreenCard::getType(){
    if (isFollower == true)
      return FOLLOWER;
    else
      return ITEM;
}

int BlackCard::getDefense(){}
 void BlackCard::setDefense(int num){}
