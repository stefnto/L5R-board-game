#ifndef _FOLLOWER_HPP_
#define _FOLLOWER_HPP_

#include "Card.hpp"

class Follower: public GreenCard{
  public:
    Follower();
    // ~Follower();
};

class Footsoldier : public Follower{
  public:
    Footsoldier(std::string);
    // ~Footsoldier();
};

class Archer : public Follower{
  public:
    Archer(std::string);
    // ~Archer();
};

class Cavalry : public Follower{
  public:
    Cavalry(std::string);
    // ~Cavalry();
};

class Bushido : public Follower{
  public:
    Bushido(std::string);
    // ~Bushido();
};

class Sieger : public Follower{
  public:
    Sieger(std::string);
    // ~Sieger();
};

class Atakebune : public Follower{ // IS ATAKEBUNE
  public:
    Atakebune(std::string);
    // ~Naval();
};

#endif
