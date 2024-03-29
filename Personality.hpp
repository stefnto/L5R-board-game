#ifndef _PERSONALITY_HPP_
#define _PERSONALITY_HPP_


#include "Card.hpp"
#include "Follower.hpp"
#include "Item.hpp"

#define MAX_FOLLOWERS 3
#define MAX_ITEMS 4

class Personality: public BlackCard{
  protected:
    int attack;
    int defense;
    int honour;
    bool isDead;
    bool defending;
    bool attacking;
    int initialDefense;
    std::vector<GreenCard *> follower; //max followers 3
    std::vector<GreenCard *> item; //max items 4
  public:
    Personality();
    void getFollower(GreenCard*&); //used in Equip Phase
    void getItem(GreenCard*&);
    int getHonour();
    int getAttack();
    int getDefense();
    void Defending(); //sets the personality to attack
    void Attacking(); //sets the personality to defense
    void unTapp();
    bool isDefending();
    bool isAttacking();
    int getFollowerSize();
    void detachFollower(int);
    int getFollowerAttack(int);
    int getBonusAttack();
    int getBonusDefense();
    std::vector<GreenCard *> getFollower();
    void printFollower();
    void printItem();
    void setInitialDefense(int);
    int getInitialDefense();
    void lose_durability();
    void detach(int);
    void lose_honour();
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
