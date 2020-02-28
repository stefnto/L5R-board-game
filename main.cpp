#include <iostream>
#include "Card.hpp"
#include "DeckBuilder.hpp"
#include "Follower.hpp"
#include "GameBoard.hpp"
#include "Holding.hpp"
#include "Item.hpp"
#include "Personality.hpp"
#include "Player.hpp"
#include <ctime>
// #include "TypeConverter.hpp"

using namespace std;

int main(void){
srand(time(NULL));
  cout << "When printing personalities (UnT) means that the card is untapped, (T) that it's tapped" << endl;
  cout << "When printing provinces, first the cost of the province is displayed,\n"
          "then (R) means that it's revealed, (NR) that it's not revealed" << endl;
  int players = 3;
  GameBoard game(players);
  game.gameplay(players);
//   Player* arr = game.get_players();
//
//   for (int i=0; i<5; i++)
//     cout << arr[i].getStrongholdHonour() << " ";
// cout << endl;
}