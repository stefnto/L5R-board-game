class Player{
  private:
    GreenCard* fateDeck;
    GreenCard* hand;
    BlackCard* dynastyDeck;
    int numberOfProvinces;
    Province* provinces; // δεν ειναι φτιαγμενη αυτη η κλαση
  public:
      Player(); //numberOfProvinces initially is 4
      ~Player();
};
