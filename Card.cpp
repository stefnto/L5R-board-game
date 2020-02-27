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

GreenCard::~GreenCard(){}

void GreenCard::EnableEffectBonus(){
  int bonus;
  cout << "Press 1 to upgrade attack, 0 to upgrade defense:";
  cin >> bonus;
  if (bonus==1)
    attackBonus += effectBonus;
  else if (bonus==0)
      defenseBonus += effectBonus;
  cout << "effectBonus has been applied!\n";
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

BlackCard::~BlackCard(){}

void BlackCard::Reveal(){
  isRevealed = true;
}

int BlackCard::Revealed(){
  if (isRevealed==true)
    return 1;
  else return 0;
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

int GreenCard::getAttackBonus(){
  return attackBonus;
}

int GreenCard::getDefenseBonus(){
  return defenseBonus;
}

int GreenCard::getEffectBonus(){
  return effectBonus;
}

int BlackCard::getInitialDefense(){return 0;} //is not used

void BlackCard::setInitialDefense(int num){}
//new function
bool Card::istapped(){
  return isTapped;
}

int GreenCard::GetDurability(){return 0;} //is not used

void GreenCard::durability_loss(){}
