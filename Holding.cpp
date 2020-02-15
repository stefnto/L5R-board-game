#include "Holding.hpp"

Holding::Holding(){}

GiftsandFavour::GiftsandFavour(std::string name){
  this->name = name;
  cost = 2;
  harvestValue = 2;
}

Plain::Plain(std::string name){
  this->name = name;
  cost = 2;
  harvestValue = 2;
}

Farmland::Farmland(std::string name){
  this->name = name;
  cost = 3;
  harvestValue = 4;
}

Mine::Mine(std::string name){
  this->name = name;
  cost = 5;
  harvestValue = 3;
}

GoldMine::GoldMine(std::string name){
  this->name = name;
  cost = 7;
  harvestValue = 5;
}

CrystalMine::CrystalMine(std::string name){
  this->name = name;
  cost = 12;
  harvestValue = 6;
}

Stronghold::Stronghold(std::string name){
  honour = 5;
  initialDefense = 5;
  money = 5;
}
