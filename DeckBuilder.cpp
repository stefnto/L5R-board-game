#include "DeckBuilder.hpp"

using namespace std;

DeckBuilder::DeckBuilder()
{
	black = new list<BlackCard *>();
	green = new list<GreenCard *>();
	//srand(unsigned(time(NULL)));
}

DeckBuilder::~DeckBuilder()
{
	std::list<BlackCard *>::iterator it;
	std::list<GreenCard *>::iterator it2;
	for (it = black->begin(); it != black->end(); it++)
	{
		black->remove((*it));
		delete *it;
		it = black->begin();
	}
	for (it2 = green->begin(); it2 != green->end(); it2++)
	{
		green->remove((*it2));
		delete *it2;
		it2 = green->begin();
	}
	delete black;
	delete green;
}

list<GreenCard *> *DeckBuilder::createFateDeck()
{
	int i;
	for (i = 0; i < NO_FOOTSOLDIER; i++)
		green->push_back(new Footsoldier("Peasants"));
	for (i = 0; i < NO_ARCHER; i++)
		green->push_back(new Archer("Elite Troops"));
	for (i = 0; i < NO_SIEGER; i++)
		green->push_back(new Sieger("Immortal Bushi"));
	for (i = 0; i < NO_CAVALRY; i++)
		green->push_back(new Cavalry("Unicorn Horses"));
	for (i = 0; i < NO_NAVAL; i++)
		green->push_back(new Atakebune("Yomi Ships"));
	for (i = 0; i < NO_BUSHIDO; i++)
		green->push_back(new Bushido("7 Samurai"));

	for (i = 0; i < NO_KATANA; i++)
		green->push_back(new Katana("Daijtso"));
	for (i = 0; i < NO_BOW; i++)
		green->push_back(new Bow("Yumi"));
	for (i = 0; i < NO_SPEAR; i++)
		green->push_back(new Spear("Kama"));
	for (i = 0; i < NO_NINJATO; i++)
		green->push_back(new Ninjato("Butterfly Dagger"));
	for (i = 0; i < NO_WAKIZASHI; i++)
		green->push_back(new Wakizashi("Kusanagi"));

	deckShuffler(green);

	return green;
}

std::list<BlackCard *> *DeckBuilder::createDynastyDeck()
{
	int i;
	//Create Personalities
	//NO_DEFENSIVE 10
	for (i = 0; i < NO_DEFENSIVE; i++)
		black->push_back(new Defender("Footsoldiers"));
	//NO_ATTACKING 10
	for (i = 0; i < NO_ATTACKING; i++)
		black->push_back(new Attacker("Steadfast bushi"));
	//NO_SHOGUN	2
	black->push_back(new Shogun("Akodo Kaneka"));
	black->push_back(new Shogun("Isawa Shi en"));
	//NO_CHANCELLOR 2
	black->push_back(new Chancellor("Hida Shozen"));
	black->push_back(new Chancellor("Mirimuto Enishi"));
	//NO_CHAMPION 1
	black->push_back(new Champion("Hida Kisada"));
	//Create holdings
	for (i = 0; i < NO_PLAIN; i++)
		black->push_back(new Plain("Rice Fields"));
	for (i = 0; i < NO_FARMS; i++)
		black->push_back(new Farmland("Fish Farms"));
	for (i = 0; i < NO_MINE; i++)
		black->push_back(new Mine("Ashio Copper Mine"));
	for (i = 0; i < NO_GOLD_MINE; i++)
		black->push_back(new GoldMine("Konomai Gold Mine"));
	for (i = 0; i < NO_CRYSTAL_MINE; i++)
		black->push_back(new CrystalMine("Ichinokawa Crystal Mine"));
	for (i = 0; i < NO_SOLO; i++)
		black->push_back(new GiftsandFavour("Gifts and Favors"));
	
	deckShuffler(black);
	
	return black;
}

void DeckBuilder::deckShuffler(std::list<BlackCard *> *black)
{
	std::vector<BlackCard *> vect;
	std::list<BlackCard *>::iterator it;
	for (it = black->begin(); it != black->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	black->clear();

	std::vector<BlackCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		black->push_back((*it2));
}

void DeckBuilder::deckShuffler(std::list<GreenCard *> *green)
{
	std::vector<GreenCard *> vect;
	std::list<GreenCard *>::iterator it;
	for (it = green->begin(); it != green->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	green->clear();

	std::vector<GreenCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		green->push_back((*it2));
}

GreenCard* DeckBuilder::getLastGreenCard(){
	return green->back();
}

void DeckBuilder::deleteLastGreenCard(){
	green->pop_back();
}

BlackCard* DeckBuilder::getLastBlackCard(){
	return black->back();
}

void DeckBuilder::deleteLastBlackCard(){
	black->pop_back();
}