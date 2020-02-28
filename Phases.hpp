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
    void Equip(Player&, int);
};

class battlePhase{
  public:
    void Battle(Player&, Player*, int);
    void Attack(Player&, Player*, int);
    void AttackPrepare(Player&);
    void Defend(Player&);
};

class economyPhase{
  public:
    void Economy(Player&);
};

class finalPhase{
  public:
    void discardSurplusFateCards(Player*, int);
    //void printGameStatistics(Player*, int); //prints how many provinces each player has left after the end of every round
    void printHand(Player*, int);
    void printProvinces(Player*, int);
    void printArena(Player*, int);
    void printHoldings(Player*, int);
};

#endif
