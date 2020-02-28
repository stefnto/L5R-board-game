#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_

#include "Card.hpp"

class Holding: public BlackCard{
  protected:
    int harvestValue;
    int initialDefense;
    Holding* upperHolding;
    Holding* subHolding;
    bool isMine;
    bool isGoldMine;
    bool isCrystalMine;
  public:
    Holding();
    void setInitialDefense(int);
    int getInitialDefense();
    int getharvestValue();
    void setharvestValue(int);
    void setupperHolding(Holding*);
    void setsubHolding(Holding*);
    void setCrystalHarvestValue(int);
    Holding* getupperHolding();
    Holding* getsubHolding();
    int getUpperHarvestValue();
    bool getMine();
    bool getGoldMine();
    bool getCrystalMine();
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

class Stronghold : public BlackCard{
  private:
    int honour;
    int money;
    int initialDefense;
  public:
    Stronghold(std::string, int);
    // ~Stronghold();
    int getHonour();
    int getMoney();
    int getInitialDefense();
};

#endif
