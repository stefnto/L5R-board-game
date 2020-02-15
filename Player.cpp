#include "Player.h"
#include "DeckBuilder.hpp"

Player::Player(){
  cout << "Player created\n";
  numberOfProvinces = 4;
  deck = new DeckBuilder();
  deck.createFateDeck();
  deck.createDynastyDeck();    //θα χρειαστει επισης να χρησιμοποιησουμε τις συναρτησεις shuffle μεσα στις create
  //επειδη εχουν σαν ορισμα τα private μελη του deckbuilder
}

Player::~Player(){
  cout << "Player destroyed\n";
  delete deck;
}
