#ifndef _HOLDING_H
#define _HOLDING_H

#include "Card.hpp"

class Holding: public BlackCard{
  protected:
    int harvestValue;
    Holding* upperHolding;
    Holding* subHolding;
  public:
    Holding();
    // ~Holding();
};

class Plain : public Holding{
  public:
    Plain(std::string);
    // ~Plain();
};

class Mine : public Holding{
  public:
    Mine(std::string);
    // ~Mine();
};

class GoldMine : public Holding{
  public:
    GoldMine(std::string);
    // ~GoldMine();
};

class CrystalMine : public Holding{
  public:
    CrystalMine(std::string);
    // ~Crystal_Mine();
};

class Farmland : public Holding{
  public:
    Farmland(std::string);
    // ~Farmland();
};

class GiftsandFavour : public Holding{
  public:
    GiftsandFavour(std::string);
    // ~GiftsandFavour();
};

class Stronghold : public Holding{
  private:
    int honour;
    int money;
    int initialDefense;
  public:
    Stronghold(std::string);
    // ~Stronghold();
};

#endif
