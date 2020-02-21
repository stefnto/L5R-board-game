#include "Player.hpp"

using namespace std;

Player::Player():numberOfProvinces(4), isDead(0)
  { //money to be changed
  std::cout << "Player created\n";
  //numberOfProvinces = 4;
  deck = new DeckBuilder();
  deck->createFateDeck();
  deck->createDynastyDeck();
  //isDead = 0; //he's alive
}

Player::~Player(){
  std::cout << "Player destroyed\n";
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
  BlackCard* black = deck->getLastBlackCard();//
  provinces.push_back(black);
  giveInitialDefense(black);
  deck->deleteLastBlackCard();
}

DeckBuilder* Player::GetDeck(){
  return deck;
}

int Player::getStrongholdHonour(){
  return stronghold->getHonour();
}

void Player::RevealPro(){
  for (unsigned int i=0; i<provinces.size(); i++)
    provinces[i]->Reveal();
}

void Player::printprovinces(){
  for (unsigned int i=0; i<provinces.size(); i++){
    cout << provinces[i]->getName() << " | ";
    if (provinces[i]->getType() == PERSONALITY)
      cout << provinces[i]->getDefense() << "| ";
  }
  cout << endl;
}

void Player::unTappHoldings(){
  for (unsigned int i=0; i<holdings.size(); i++){
    holdings[i].unTapp();
  }
}

void Player::unTappPersonalities(){
  for (unsigned int i=0; i<activePersonalities.size(); i++){
    activePersonalities[i].unTapp();
  }
}

void Player::unTappProvinces(){
  for (unsigned int i=0; i<provinces.size(); i++){
    provinces[i]->unTapp();
  }
}

void Player::printhand(){
  for (unsigned int i=0; i< hand.size(); i++){
    cout << hand[i]->getName() << "(" << hand[i]->getCost() << ")" << " | ";
  }
  cout << endl;
}

void Player::printPersonalities(){
  if (activePersonalities.size()!= 0){
    for (unsigned int i=0; i<activePersonalities.size(); i++){
      cout << activePersonalities[i].getName() << " | ";
    }
    cout << endl;
  }
  else
    cout << "Player has no active Personalities" << endl;
}

int Player::GetPersonSize(){
  return activePersonalities.size();
}

int Player::GetHandSize(){
  return hand.size();
}

void Player::BuyGreenCard(int n1, int n2){
  int type, honour, minHon; //minHon is minimumHonour
  if (money >= hand[n1]->getCost()){
    money = money - hand[n1]->getCost();
    type = hand[n1]->getType();
    honour = activePersonalities[n2].getHonour();
    minHon = hand[n1]->getMinHonour();
    if (type==FOLLOWER){ //means card is a Follower
      if (honour >= minHon){
        this->EnableBonus(hand[n1], n2);
        activePersonalities[n2].getFollower(hand[n1]); //adds to followers of personality
        cout << "Follower added to active Personality" << endl;
        hand.erase(hand.begin()+n1); //erases from the hand
      }
    } else if (type==ITEM){//means card is an item
      if (honour >= minHon){
        this->EnableBonus(hand[n1], n2);
        activePersonalities[n2].getItem(hand[n1]); //adds to items of personality
        cout << "Item added to active Personality" << endl;
        hand.erase(hand.begin()+n1); //erases from the hand
      }
    }
  }
}

int Player::getMoney(){
  return money;
}

void Player::giveMoney(){
  this->money = stronghold->getMoney();
}

void Player::giveInitialDefense(BlackCard*& black){
  if (black->getType() == PERSONALITY){
    int num = black->getDefense() + this->stronghold->getInitialDefense();
    black->setDefense(num);
  }
}

void Player::EnableBonus(GreenCard*& card, int n2){ //activePersonalities[n2] is the Personality that's to get the bonuses
  int enable;
  cout << "Enable GreenCard's bonus efects?(type 1 for yes, 0 for no):";
  cin >> enable;
  cout << endl;
  if (enable==1){
      if (money >= card->getEffectCost()){
          card->EnableEffectBonus();
      } else
          cout << "effectBonus cannot be applied due to money inefficiency!\n";
  } else
      cout << "effectBonus won't be enabled" << endl;
}
