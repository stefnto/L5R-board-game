#include "Personality.hpp"

using namespace std;

Personality::Personality(){
  isDead = 0; //the card is alive
  BlackCard::isPersonality=true;
  defending = false;
  attacking = false;
}

void Personality::getFollower(GreenCard*& card){
  if (follower.size() < MAX_FOLLOWERS)
    follower.emplace_back(card); //adds GreenCard to the Followers list
  else
    cout << "Personality has maximum followers" << endl;
}

void Personality::getItem(GreenCard*& card){
  if (item.size() < MAX_ITEMS)
    item.emplace_back(card); //adds GreenCard to the Items list
  else
    cout << "Personality has maximum items" << endl;
}

int Personality::getHonour(){
  return honour;
}

int Personality::getAttack(){
  return attack;
}

int Personality::getDefense(){
  return defense;
}

Attacker::Attacker(std::string name){
  this->name = name;
  cost = 5;
  attack = 3;
  defense = 2;
  honour = 2;
}

Defender::Defender(std::string name){
  this->name = name;
  cost = 5;
  attack = 2;
  defense = 3;
  honour = 2;
}

Shogun::Shogun(std::string name){
  this->name = name;
  cost = 15;
  attack = 10;
  defense = 5;
  honour = 8;
}

Chancellor::Chancellor(std::string name){
  this->name = name;
  cost = 15;
  attack = 5;
  defense = 10;
  honour = 8;
}

Champion::Champion(std::string name){
  this->name = name;
  cost = 30;
  attack = 20;
  defense = 20;
  honour = 12;
}

int Personality::getBonusDefense(){
  int defense_from_followers=0, defense_from_items=0;

  for (unsigned int i=0; i<follower.size(); i++){
    defense_from_followers += follower[i]->getDefenseBonus();
  }
  for (unsigned int i=0; i<item.size(); i++){
    defense_from_items += item[i]->getDefenseBonus();
  }
  return defense + defense_from_followers + defense_from_items;
}

int Personality::getBonusAttack(){
  int attack_from_followers=0, attack_from_items=0;

  for (unsigned int i=0; i<follower.size(); i++){
    attack_from_followers += follower[i]->getAttackBonus();
  }
  for (unsigned int i=0; i<item.size(); i++){
    attack_from_items += item[i]->getAttackBonus();
  }
  return attack + attack_from_followers + attack_from_items;
}

void Personality::Defending(){
  defending = true;
}

void Personality::Attacking(){
  attacking = true;
}

void Personality::unTapp(){
  Card::isTapped = false;
  defending = false;
  attacking = false;
}

bool Personality::isDefending(){
  return defending;
}

bool Personality::isAttacking(){
  return attacking;
}

int Personality::getFollowerSize(){
  return follower.size();
}

void Personality::detachFollower(int pos){
  follower.erase(follower.begin() + pos);
}

int Personality::getFollowerAttack(int pos){
  return follower[pos]->getAttackBonus();
}

vector<GreenCard *> Personality::getFollower(){
  return follower;
}

void Personality::printFollower(){
  cout << this->getName() << "'s followers: ";
  for (unsigned int i=0; i<follower.size(); i++){
    cout << follower[i]->getName() << "(AT=" <<follower[i]->getAttackBonus() << ") | " ;
  }
  cout << endl;
}

void Personality::setInitialDefense(int num){
   initialDefense = num;
}

int Personality::getInitialDefense(){
  return initialDefense;
}

void Personality::lose_durability(){
  for (unsigned int i=0; i<item.size(); i++){
    if (item[i]->GetDurability() == 0){
      detach(i); //item is destroyed
    }
    else
      item[i]->durability_loss(); //else loses durability
  }
}

void Personality::detach(int i){
  item.erase(item.begin()+i);
  cout << item[i]->getName() << " detached" << endl;
}

void Personality::lose_honour(){
  honour--;
  cout << this->getName() << " lost a point of honour" << endl;
}
