#ifndef _PHASES_HPP_
#define _PHASES_HPP_

#include "DeckBuilder.hpp"
#include "Player.hpp"
#include "Card.hpp"

class startingPhase{
  public:
    void untapEverything(Player&);
    void drawFateCard(Player&);
    void revealProvinces(Player&);
    void printHand(Player&);
    void printProvinces(Player&);
};

class equipPhase{
  public:
    void Equip(Player&);
    void BuyAndPlace(Player&);
};

class battlePhase{
  public:
    void Battle();
    void attack();
    void defend();
};

class economyPhase{

};

class finalPhase{
  public:
    void discardSurplusFateCards();
    void printGameStatistics();
    void printHand();
    void printProvinces();
    void printArena();
    void printHoldings();
};

#endif
