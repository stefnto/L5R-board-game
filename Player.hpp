#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "DeckBuilder.hpp"
#include <vector>
#include <list>

class Player{
  private:
    DeckBuilder* deck;
    std::vector<GreenCard *> hand;
    std::vector<Holding> holdings;
    std::vector<Personality> activePersonalities;
    int numberOfProvinces;
    bool isDead;
    Stronghold* stronghold;
    std::vector<BlackCard *> provinces;
    int money; //to be changed
  public:
      Player();
      ~Player();
      void GetGreenCard();
      void addHolding(Holding&);
      void addStronghold(Stronghold*&);
      void GetProvince();
      DeckBuilder* GetDeck();
      int getStrongholdHonour();
      void RevealPro();
      void printprovinces();
      void unTappHoldings();
      void unTappPersonalities();
      void unTappProvinces();
      void printhand();
      void printPersonalities();
      int GetPersonSize(); //returns activePersonalities' vector size
      int GetHandSize();
      void BuyGreenCard(int, int);
      int getMoney();
};


#endif
