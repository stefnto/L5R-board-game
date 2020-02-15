#ifndef _PHASES_H_
#define _PHASES_H_

class startingPhase{
  public:
    void untapEverything();
    void drawFateCard();
    void revealProvinces();
    void printHand();
    void printProvinces();
};

class equipPhase{
  public:

};

class battlePhase{

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
