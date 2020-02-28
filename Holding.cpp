#include "Holding.hpp"
#include <ctime>
#include <cstdlib>

Holding::Holding(){
  BlackCard::isHolding=true;
  upperHolding = nullptr;
  subHolding = nullptr;
}

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
  isMine = true;
  isGoldMine = false;
  isCrystalMine = false;
  subHolding = NULL; // remains empty
  upperHolding = NULL;
}

GoldMine::GoldMine(std::string name){
  this->name = name;
  cost = 7;
  harvestValue = 5;
  isMine = false;
  isGoldMine = true;
  isCrystalMine = false;
  subHolding = NULL;
  upperHolding = NULL;
}

CrystalMine::CrystalMine(std::string name){
  this->name = name;
  cost = 12;
  harvestValue = 6;
  isMine = false;
  isGoldMine = false;
  isCrystalMine = true;
  upperHolding = NULL; //empty
  subHolding = NULL;
}

Stronghold::Stronghold(std::string name,int k){
  honour = rand()%k;
  initialDefense = 5;
  money = 7;
}

int Stronghold::getHonour(){
  return honour;
}

int Stronghold::getMoney(){
  return money;
}

int Stronghold::getInitialDefense(){
  return initialDefense;
}

void Holding::setInitialDefense(int num){
   initialDefense = num;
}

int Holding::getInitialDefense(){
  return initialDefense;
}

int Holding::getharvestValue(){
  return harvestValue;
}

void Holding::setharvestValue(int num){
  harvestValue += num;
}

void Holding::setupperHolding(Holding* h){
  upperHolding = h;
}

void Holding::setsubHolding(Holding* h){
  subHolding = h;
}

Holding* Holding::getupperHolding(){
  return upperHolding;
}

Holding* Holding::getsubHolding(){
  return subHolding;
}

void Holding::setCrystalHarvestValue(int num){
  upperHolding->setharvestValue(num);
}

int Holding::getUpperHarvestValue(){
  return upperHolding->getharvestValue();
}

bool Holding::getMine(){
  return isMine;
}

bool Holding::getGoldMine(){
  return isGoldMine;
}

bool Holding::getCrystalMine(){
  return isCrystalMine;
}
