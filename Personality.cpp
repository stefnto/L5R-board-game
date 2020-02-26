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

int Personality::getDefense(){
  return defense;
}

int Personality::getAttack(){
  return attack;
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
