#ifndef _FOLLOWER_H_
#define _FOLLOWER_H_

#include "Card.h"

class Follower: public GreenCard{
  private:
  public:
    Follower();
    ~Follower();
};

class Footsoldier : public Follower{
  public:
    Footsoldier();
    ~Footsoldier();
};

class Archer : public Follower{
  public:
    Archer();
    ~Archer();
};

class Cavalry : public Follower{
  public:
    Cavalry();
    ~Cavalry();
};

class Bushido : public Follower{
  public:
    Bushido();
    ~Bushido();
};

class Sieger : public Follower{
  public:
    Sieger();
    ~Sieger();
};

class Naval : public Follower{ // IS ATAKEBUNE
  public:
    Naval();
    ~Naval();
};

#endif
