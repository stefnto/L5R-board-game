#include "Card.hpp"

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

GreenCard::GreenCard(){} //we dont need to write anything because the stats are different in each type

void GreenCard::EnableEffectBonus(int){

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
