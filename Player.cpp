#include "Player.hpp"
#include "TypeConverter.hpp"

using namespace std;

Player::Player():numberOfProvinces(4), isDead(0)
  { //money to be changed
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
    cout << provinces[i]->getName() << "(" << provinces[i]->getCost() << ")" << " | ";
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
  // if (black->getType() == PERSONALITY){
    int num = this->stronghold->getInitialDefense();
    black->setInitialDefense(num);
  // }
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

void Player::BuyProvince(int n1){
  TypeConverter converter;
  BlackCard* black = provinces[n1];
  Personality* person;
  Holding* holding;
  int revealed = black->Revealed();
  if (revealed ==1){
    converter.getCorrectType(black, &person, &holding);
    if (person!=NULL){
      if (money >= person->getCost()){ //player can buy the personality
        money = money - person->getCost();
        activePersonalities.emplace_back(*person);
        provinces.erase(provinces.begin()+n1); //erases from the provinces
        this->GetProvince(); //gets another province (not revealed)
        cout << "Personality card bought" << endl;
      } else cout << "Not enough money to buy this card" << endl;
    } else if (holding!=NULL){
      if (money >= holding->getCost()){ //player can buy the holding
        money = money - holding->getCost();
        holdings.emplace_back(*holding);
        provinces.erase(provinces.begin()+n1); //erases from the provinces
        this->GetProvince(); //gets another province (not revealed)
        cout << "Holding card bought" << endl;
      } else cout << "Not enough money to buy this card" << endl;
    }
  } else cout << "Card is not revealed-cannot be bought this round" << endl;
}
void Player::discardfromHand(int discard){
  hand.erase(hand.begin()+discard);
}
