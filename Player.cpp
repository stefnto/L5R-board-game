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
}

void Player::addHolding(Holding& holding){
  holdings.push_back(holding);
}


void Player::addStronghold(Stronghold*& stronghold){
  this->stronghold = stronghold;
}

void Player::GetProvince(){
  provinces.push_back(deck->getLastBlackCard());
  deck->deleteLastBlackCard();
}
