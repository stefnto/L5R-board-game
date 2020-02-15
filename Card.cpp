#include "Card.hpp"

Card::Card(){
  isTapped = 0; //the card is untapped
}

GreenCard::GreenCard(){} //we dont need to write anything because the stats are different in each type

void GreenCard::EnableEffectBonus(){

}

BlackCard::BlackCard(){
  isRevealed = 0; //the card is hidden
}
