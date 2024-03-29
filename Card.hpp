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
enum Cards{PERSONALITY = 1, HOLDING, FOLLOWER, ITEM};

class Card{
  protected:
    std::string name;
    int cost;
    bool isTapped;
   public:
     Card();
    //~Card();
     void unTapp();
     void Tapp();
     bool istapped();//new function
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
    virtual ~GreenCard();
    void EnableEffectBonus();
    int getMinHonour();
    int getEffectCost();
    int getType();
    int getAttackBonus();
    int getDefenseBonus();
    int getEffectBonus();
    virtual void durability_loss();
    virtual int GetDurability();
};

class BlackCard: public Card{
  protected:
    bool isRevealed;
    bool isHolding;
    bool isPersonality;
  public:
    BlackCard();
    virtual ~BlackCard();
    void Reveal();
    int Revealed(); //returns 1 if card is revealed
    void Hide();
    int getType();
    virtual int getInitialDefense();
    virtual void setInitialDefense(int);
};

#endif