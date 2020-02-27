#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include "Card.hpp"

class Item: public GreenCard{
  protected:
    int durability;
  public:
    Item();
    // ~Item();
    void durability_loss();
    //void detach();
    int GetDurability();
};

class Katana : public Item{
  public:
    Katana(std::string);
    // ~Katana();
};

class Spear : public Item{
  public:
    Spear(std::string);
    // ~Spear();
};

class Bow : public Item{
  public:
    Bow(std::string);
    // ~Bow();
};

class Ninjato : public Item{
  public:
    Ninjato(std::string);
    // ~Ninjato();
};

class Wakizashi : public Item{
  public:
     Wakizashi(std::string);
     // ~Wakizashi();
};

#endif
