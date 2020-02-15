#include "Personality.hpp"

Personality::Personality(){
  isDead = 0 //the card is alive
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
