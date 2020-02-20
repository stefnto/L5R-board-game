#include "Item.hpp"

Item::Item(){
  GreenCard::isItem = true;
}

Katana::Katana(std::string name){
  this->name = name;
  cost = 0;
  attackBonus = 2;
  defenseBonus = 0;
  minimumHonour = 1;
  effectBonus = 1;
  effectCost = 2;
  durability = 3;
}

Spear::Spear(std::string name){
  this->name = name;
  cost = 0;
  attackBonus = 0;
  defenseBonus = 2;
  minimumHonour = 1;
  effectBonus = 1;
  effectCost = 2;
  durability = 3;
}

Bow::Bow(std::string name){
  this->name = name;
  cost = 2;
  attackBonus = 2;
  defenseBonus = 2;
  minimumHonour = 2;
  effectBonus = 3;
  effectCost = 4;
  durability = 5;
}

Ninjato::Ninjato(std::string name){
  this->name = name;
  cost = 4;
  attackBonus = 3;
  defenseBonus = 3;
  minimumHonour = 3;
  effectBonus = 2;
  effectCost = 2;
  durability = 4;
}

Wakizashi::Wakizashi(std::string name){
  this->name = name;
  cost = 8;
  attackBonus = 5;
  defenseBonus = 5;
  minimumHonour = 3;
  effectBonus = 3;
  effectCost = 3;
  durability = 8;
}
