////////////////CARD////////////////////////
#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <iostream>
#include <string>
#include <vector>
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
     void unTapp();
     void Tapp();
     std::string getName();
     int getCost();
};

class GreenCard : public Card{
  protected:
    int attackBonus;
    int defenseBonus;
    int minimumHonour;
    std::string cardText;
    int effectBonus;
    int effectCost;
    bool isFollower;
    bool isItem;
  public:
    GreenCard();
    // ~GreenCard();
    void EnableEffectBonus();
    int type(); //return 0 if card is follower, 1 if card is item
    int getMinHonour();
    int getEffectCost();
};

class BlackCard: public Card{
  protected:
    bool isRevealed;
  public:
    BlackCard();
    // ~BlackCard();
    void Reveal();
    void Hide();
};

#endif
