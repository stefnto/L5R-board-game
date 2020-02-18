#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "DeckBuilder.hpp"
#include <vector>
#include <list>

class Player{
  private:
    Stronghold* stronghold;
    DeckBuilder* deck;
    std::vector<GreenCard *> hand;
    std::vector<Holding> holdings;
    std::vector<Personality> activePersonalities;
    std::vector<BlackCard *> provinces;
    int numberOfProvinces;
    bool isDead;
    //oi eparxies einai mayres kartes
  public:
      Player(); //numberOfProvinces initially is 4
      ~Player();
      void GetGreenCard();
      void addHolding(Holding&);
      void addStronghold(Stronghold*&);
      void GetProvince();
      int getStrongholdHonour();
};

#endif
