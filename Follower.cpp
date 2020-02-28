#include "Follower.hpp"

Follower::Follower(){
  GreenCard::isFollower = true;
}

Footsoldier::Footsoldier(std::string name){ //xreiazomaste kai deytero orisma to opoio tha einai enumeration opws leei sthn 3.1
  this->name = name;
  cost = 0;
  attackBonus = 2;
  defenseBonus = 0;
  minimumHonour = 1;
  effectBonus = 1;
  effectCost = 2;
}

Archer::Archer(std::string name){
  this->name = name;
  cost = 0;
  attackBonus = 0;
  defenseBonus = 2;
  minimumHonour = 1;
  effectBonus = 1;
  effectCost = 2;
}

Sieger::Sieger(std::string name){
  this->name = name;
  cost = 5;
  attackBonus = 3;
  defenseBonus = 3;
  minimumHonour = 2;
  effectBonus = 2;
  effectCost = 3;
}

Cavalry::Cavalry(std::string name){
  this->name = name;
  cost = 3;
  attackBonus = 4;
  defenseBonus = 2;
  minimumHonour = 3;
  effectBonus = 3;
  effectCost = 4;
}

Atakebune::Atakebune(std::string name){
  this->name = name;
  cost = 3;
  attackBonus = 2;
  defenseBonus = 4;
  minimumHonour = 3;
  effectBonus = 3;
  effectCost = 4;
}

Bushido::Bushido(std::string name){
  this->name = name;
  cost = 8;
  attackBonus = 8;
  defenseBonus = 8;
  minimumHonour = 6;
  effectBonus = 3;
  effectCost = 8;
}
