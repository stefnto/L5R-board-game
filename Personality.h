#ifndef _PERSONALITY_H_
#define _PERSONALITY_H_

#include "Card.h"


class Personality: public BlackCard{
  private:
    int attack;
    int defence;
    int honour;
    bool isDead;
    Follower* follower;
    Item* item;
  public:
    Personality();
    ~Personality();
};

class Attacker : public Personality{
  public:
    Attacker();
    ~Attacker();
};

class Defender : public Personality{
  public:
    Defender();
    ~Defender();
};

class Champion : public Personality{
  public:
    Champion();
    ~Champion();
};

class Chancellor : public Personality{
  public:
    Chancellor();
    ~Chancellor();
};

class Shogun : public Personality{
  public:
    Shogun();
    ~Shogun();
};

#endif
