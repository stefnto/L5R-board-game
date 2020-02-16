#include "Player.hpp"
#include <vector>

Player::Player(){
  std::cout << "Player created\n";
  numberOfProvinces = 4;
  deck = new DeckBuilder();
  deck->createFateDeck();
  deck->createDynastyDeck();    //θα χρειαστει επισης να χρησιμοποιησουμε τις συναρτησεις shuffle μεσα στις create
  //επειδη εχουν σαν ορισμα τα private μελη του deckbuilder
}

Player::~Player(){
  std::cout << "Player destroyed\n";
  delete deck;
}


void Player::GetGreenCard(){
  hand.push_back(deck->getLastGreenCard());
  deck->deleteLastGreenCard();
}
