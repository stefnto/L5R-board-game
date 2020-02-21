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
    std::vector<GreenCard *> follower; //max followers 3
    std::vector<GreenCard *> item; //max items 4
  public:
    Personality();
    void getFollower(GreenCard*&); //used in Equip Phase
    void getItem(GreenCard*&);
    int getHonour();
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
