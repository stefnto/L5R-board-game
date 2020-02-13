class Player{
  private:
    GreenCard* fateDeck;
    GreenCard* hand;
    BlackCard* dynastyDeck;
    int numberOfProvinces;
    //oi eparxies einai mayres kartes 
  public:
      Player(); //numberOfProvinces initially is 4
      ~Player();
};
