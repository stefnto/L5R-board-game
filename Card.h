////////////////CARD////////////////////////
#ifndef _CARD_H_
#define _CARD_H_

class Card{
  private:
    std::string name;
    int cost;
    bool isTapped;
   public:
     Card();
     ~Card();
};

class GreenCard : public Card{
  private:
    int attackBonus;
    int defenceBonus;
    int minimumHonour;
    std::string cardText;
    int effectBonus;
    int effectCost;
  public:
    GreenCard();
    ~GreenCard();
    void EnableEffectBonus(int);
};

class BlackCard: public Card{
private:
 bool isRevealed;
public:
 BlackCard();
 ~BlackCard();
}


#endif
