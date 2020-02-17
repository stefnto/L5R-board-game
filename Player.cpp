#include "Player.hpp"

Player::Player(){
  std::cout << "Player created\n";
  numberOfProvinces = 4;
  deck = new DeckBuilder();
  deck->createFateDeck();
  deck->createDynastyDeck();
  isDead = 0; //he's alive
}

Player::~Player(){
  std::cout << "Player destroyed\n";
  delete deck;
}

void Player::GetGreenCard(){
  hand.push_back(deck->getLastGreenCard());
  deck->deleteLastGreenCard();
}
