#ifndef _HOLDING_H
#define _HOLDING_H

#include "Card.h"

class Holding: public BlackCard{
  private:
    int harvestValue;
    Holding* upperHolding;
    Holding* subHolding;
  public:
    Holding();
    ~Holding();
};

class Plain : public Holding{
  public:
    Plain();
    ~Plain();
};

class Mine : public Holding{
  public:
    Mine();
    ~MiINE();
};

class Gold_Mine : public Holding{
  public:
    Gold_Mine();
    ~Gold_Mine();
};

class Crystal_Mine : public Holding{
  public:
    Crystal_Mine();
    ~Crystal_Mine();
};

class Farmland : public Holding{
  public:
    Farmland();
    ~Farmland();
};

class GiftsandFavour: public Holding{
  public:
    GiftsandFavour();
    ~GiftsandFavour();
};

class Stronghold : public Holding{
  private:
    int honour;
    int money;
    int initialDefense;
  public:
    Stronghold();
    ~Stronghold();
};

#endif
