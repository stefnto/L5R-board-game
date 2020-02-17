#include "Player.hpp"

Player::Player(){
  //std::cout << "Player created\n";
  numberOfProvinces = 4;
  deck = new DeckBuilder();
  deck->createFateDeck();
  deck->createDynastyDeck();
  isDead = false; //he's alive
}

Player::~Player(){
  //std::cout << "Player destroyed\n";
  delete deck;
}

void Player::GetGreenCard(){
  hand.push_back(deck->getLastGreenCard());
  deck->deleteLastGreenCard();
  //std::cout << "GreenCard gotten" << std::endl;
}

void Player::addHolding(Holding& stronghold){
  holdings.push_back(stronghold);
}
