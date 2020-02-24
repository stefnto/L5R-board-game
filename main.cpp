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
  int players = 3;
  GameBoard game(players);
  game.gameplay(players);
//   Player* arr = game.get_players();
//
//   for (int i=0; i<5; i++)
//     cout << arr[i].getStrongholdHonour() << " ";
// cout << endl;
}
