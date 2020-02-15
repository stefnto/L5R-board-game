#ifndef _ITEM_H_
#define _ITEM_H_

#include "Card.hpp"

class Item: public GreenCard{
  protected:
    int durability;
  public:
    Item();
    // ~Item();
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
