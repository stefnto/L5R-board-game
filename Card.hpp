////////////////CARD////////////////////////
#ifndef _CARD_H_
#define _CARD_H_

#include <string>
//apo 3.1 ayta ta enumerations tha xreiastoun
enum Personalities{ATTACKER, DEFENDER, SHOGUN, CHANCELLOR, CHAMPION};
enum Holdings{PLAIN, MINE, GOLD_MINE, CRYSTAL_MINE, FARMS, SOLO, STRONGHOLD};
enum Followers{FOOTSOLDIER, ARCHER, SIEGER, CAVALRY, NAVAL, BUSHIDO};
enum Items{KATANA, SPEAR, BOW, NINJATO, WAKIZASHI};

class Card{
  protected:
    std::string name;
    int cost;
    bool isTapped;
   public:
     Card();
     // ~Card();
};

class GreenCard : public Card{
  protected:
    int attackBonus;
    int defenseBonus;
    int minimumHonour;
    std::string cardText;
    int effectBonus;
    int effectCost;
  public:
    GreenCard();
    // ~GreenCard();
    void EnableEffectBonus(int);
};

class BlackCard: public Card{
  protected:
    bool isRevealed;
  public:
    BlackCard();
    // ~BlackCard();
};

#endif
