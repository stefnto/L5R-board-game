#ifndef _PERSONALITY_HPP_
#define _PERSONALITY_HPP_

#include "Card.hpp"
#include "Follower.hpp"
#include "Item.hpp"

class Personality: public BlackCard{
  protected:
    int attack;
    int defense;
    int honour;
    bool isDead;
    Follower* follower;
    Item* item;
  public:
    Personality();
    // ~Personality();
};

class Attacker : public Personality{
  public:
    Attacker(std::string);
    // ~Attacker();
};

class Defender : public Personality{
  public:
    Defender(std::string);
    // ~Defender();
};

class Champion : public Personality{
  public:
    Champion(std::string);
    // ~Champion();
};

class Chancellor : public Personality{
  public:
    Chancellor(std::string);
    // ~Chancellor();
};

class Shogun : public Personality{
  public:
    Shogun(std::string);
    // ~Shogun();
};

#endif
