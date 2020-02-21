#include "Card.hpp"
#include <string>

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
  // if(player.getMoney() >= effectCost){
  //   attackBonus += effectBonus;
  //   player.getMoney() -= effectCost;
  //   cout << "effectBonus has been applied!\n";
  // }
  // else
  //   cout << "effectBonus cannot be applied!\n";
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
