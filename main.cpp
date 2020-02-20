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
  GameBoard game(2);
  game.gameplay(2);
//   Player* arr = game.get_players();
//
//   for (int i=0; i<5; i++)
//     cout << arr[i].getStrongholdHonour() << " ";
// cout << endl;
}
