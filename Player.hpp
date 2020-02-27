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
    int overallAttack; //changes every round
    int overallDefense; //changes every round
  public:
      Player();
      ~Player();
      void GetGreenCard();
      void addHolding(Holding&);
      void addStronghold(Stronghold*&);
      void DrawProvince(); //play gets a province from dynasty deck
      DeckBuilder* GetDeck();
      int getStrongholdHonour();
      void RevealPro();
      void printprovinces();
      void unTappHoldings();
      void unTappPersonalities();
      void unTappProvinces();
      void printhand();
      void printPersonalities();
      void printPersonalitieswithAttack();
      int GetPersonSize(); //returns activePersonalities' vector size
      int GetHandSize(); //returns number of GreenCards in hand
      int GetProvinceSize(); //returns number of provinces
      void BuyGreenCard(int, int); //used in equipPhase
      int getMoney();
      void giveMoney();
      void EnableBonus(GreenCard*&, int );
      void giveInitialDefense(BlackCard*&);
      void BuyProvince(int); //used in economyPhase
      std::vector<Personality> getactivePersonalities();
      void setOverallAttack(int);
      void setOverallDefense(int);
      int getOverallAttack();
      int getOverallDefense();
      void setTapped(int, int);
      BlackCard* GetProvince(int);
      void deleteProvince(int);
      void loseDefendingPersonalities();
      void loseAttackingPersonalities();
      void loseChosenAttackingPersonalities(int);
      void deleteFollower(int, int);
};


#endif
