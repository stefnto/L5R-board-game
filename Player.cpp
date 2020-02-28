#include "Player.hpp"
#include "TypeConverter.hpp"

using namespace std;

Player::Player():numberOfProvinces(4), isDead(0)
  { //money to be changed
  deck = new DeckBuilder();
  deck->createFateDeck();
  deck->createDynastyDeck();
  overallAttack = 0; //we initiallize it
  overallDefense = 0;
  //isDead = 0; //he's alive
}

Player::~Player(){
  std::cout << "Player destroyed\n";
  delete deck;
}

void Player::GetGreenCard(){
  hand.push_back(deck->getLastGreenCard());
  deck->deleteLastGreenCard();
}

void Player::addHolding(Holding& holding){
  holdings.push_back(holding);
}

void Player::addStronghold(Stronghold*& stronghold){
  this->stronghold = stronghold;
}

void Player::printholdings(){
  for (unsigned int i=0; i<holdings.size(); i++){
    cout << holdings[i].getName() << "(" << holdings[i].getharvestValue() << ")" << " | ";
    if (activePersonalities[i].istapped()==false)
      cout << "(UnT) | ";
    else cout  << "(T) | ";
  }
  cout << endl;
}

void Player::DrawProvince(){
  BlackCard* black = deck->getLastBlackCard();//
  provinces.push_back(black);
  giveInitialDefense(black);
  deck->deleteLastBlackCard();
}

int Player::getStrongholdHonour(){
  return stronghold->getHonour();
}

void Player::RevealPro(){
  for (unsigned int i=0; i<provinces.size(); i++)
    provinces[i]->Reveal();
}

void Player::printprovinces(){
  for (unsigned int i=0; i<provinces.size(); i++){
    cout << provinces[i]->getName() << "(" << provinces[i]->getCost() << ")";
    if (provinces[i]->Revealed()==1)
      cout << "(R) | ";
    else cout << "(NR) | ";
  }
  cout << endl;
}

void Player::unTappHoldings(){
  for (unsigned int i=0; i<holdings.size(); i++){
    holdings[i].unTapp();
  }
}

void Player::unTappPersonalities(){
  for (unsigned int i=0; i<activePersonalities.size(); i++){
    activePersonalities[i].unTapp();
  }
}

void Player::unTappProvinces(){
  for (unsigned int i=0; i<provinces.size(); i++){
    provinces[i]->unTapp();
  }
}

void Player::unTappStronghold(){
  stronghold->unTapp();
}

void Player::printhand(){
  for (unsigned int i=0; i< hand.size(); i++){
    cout << hand[i]->getName() << "(" << hand[i]->getCost() << ")" << " | ";
  }
  cout << endl;
}

void Player::printPersonalities(){
  if (activePersonalities.size()!= 0){
    for (unsigned int i=0; i<activePersonalities.size(); i++){
      cout << activePersonalities[i].getName();
      if (activePersonalities[i].istapped()==false)
        cout << "(UnT) | ";
      else cout  << "(T) | ";
    }
    cout << endl;
  }
  else
    cout << "Player has no active Personalities" << endl;
}

void Player::printPersonalitieswithAttack(){
  if (activePersonalities.size()!= 0){
    for (unsigned int i=0; i<activePersonalities.size(); i++){
      cout << activePersonalities[i].getName();
      if (activePersonalities[i].istapped()==false)
        cout << "(UnT)";
      else cout  << "(T)";
      cout << "(AT=" << activePersonalities[i].getAttack() << ") | ";
    }
    cout << endl;
  }
  else
    cout << "Player has no active Personalities" << endl;
}

void Player::printFollowersandItems(){
  for (unsigned int i=0; i<activePersonalities.size(); i++){
    activePersonalities[i].printFollower();
    activePersonalities[i].printItem();
  }
  cout << endl;
}

int Player::GetPersonSize(){
  return activePersonalities.size();
}

int Player::GetHandSize(){
  return hand.size();
}

void Player::deletefromHand(int pos){
  hand.erase(hand.begin()+pos);
}

int Player::GetProvinceSize(){
  return numberOfProvinces;
}

void Player::BuyGreenCard(int n1, int n2){
  int type, honour, minHon; //minHon is minimumHonour
  if (money >= hand[n1]->getCost()){
    type = hand[n1]->getType();
    honour = activePersonalities[n2].getHonour();
    minHon = hand[n1]->getMinHonour();
    if (type==FOLLOWER){ //means card is a Follower
      if (honour >= minHon){
        money = money - hand[n1]->getCost();
        this->EnableBonus(hand[n1], n2);
        activePersonalities[n2].getFollower(hand[n1]); //adds to followers of personality
        cout << "Follower added to active Personality\n" << endl;
        hand.erase(hand.begin()+n1); //erases from the hand
      } else cout << "Unefficient personality honour" << endl;
    } else if (type==ITEM){//means card is an item
      if (honour >= minHon){
        money = money - hand[n1]->getCost();
        this->EnableBonus(hand[n1], n2);
        activePersonalities[n2].getItem(hand[n1]); //adds to items of personality
        cout << "Item added to active Personality\n" << endl;
        hand.erase(hand.begin()+n1); //erases from the hand
      } else cout << "Unefficient personality honour" << endl;
    }
  }
  else{
    cout << "Not enough money to buy this card" << endl;
    Harvest(hand[n1]->getCost() - money);
  }
}

int Player::getMoney(){
  return money;
}

void Player::giveMoney(){
  this->money = stronghold->getMoney();
}

void Player::giveInitialDefense(BlackCard*& black){
    int num = this->stronghold->getInitialDefense();
    black->setInitialDefense(num);
}

void Player::EnableBonus(GreenCard*& card, int n2){ //activePersonalities[n2] is the Personality that's to get the bonuses
  int enable;
  cout << "Enable GreenCard's bonus effects(+" << card->getEffectBonus() << ")?(type 1 for yes, 0 for no)" << "(cost=" << card->getEffectCost() << ")";
  cout << "(current money = " << this->getMoney() << "):" << endl;
  cin >> enable;
  cout << endl;
  if (enable==1){
      if (money >= card->getEffectCost()){
          money = money - card->getEffectCost();
          card->EnableEffectBonus();
      } else
          cout << "effectBonus cannot be applied due to money inefficiency!\n";
  } else
      cout << "effectBonus won't be enabled" << endl;
}

void Player::BuyProvince(int n1){
  TypeConverter converter;
  BlackCard* black = provinces[n1];
  Personality* person;
  Holding* holding;
  int revealed = black->Revealed();
  if (revealed ==1){
    converter.getCorrectType(black, &person, &holding);
    if (person!=NULL){ //card bought was a personality
      if (money >= person->getCost()){ //player can buy the personality
        money = money - person->getCost();
        activePersonalities.emplace_back(*person);
        provinces.erase(provinces.begin()+n1); //erases from the provinces
        this->DrawProvince(); //gets another province (not revealed)
        cout << "Personality card bought" << endl;
      } else cout << "Not enough money to buy this card" << endl;
    } else if (holding!=NULL){ //card bought was a holding
      if (money >= holding->getCost()){ //player can buy the holding
        money = money - holding->getCost();
        holdings.emplace_back(*holding);//new holding placed at the end of the vector
        provinces.erase(provinces.begin()+n1); //erases from the provinces
        this->DrawProvince(); //gets another province (not revealed)
        cout << "Holding card bought" << endl;
        cout << "We are searching the case of a chain creation\n"; //checking for chain
        if (holdings[holdings.size()-1].getMine() == true){ //holding is a mine
          for (unsigned int i=0; i<holdings.size()-1; i++){
            if(holdings[i].getGoldMine() == true){
              Chain(&holdings[holdings.size()-1], &holdings[i]);
              break; //if we form the chain then we don't have to search for other holdings
            }
          }
        }
        else if(holdings[holdings.size()-1].getGoldMine() == true){ //holding is a gold mine
          for (unsigned int i=0; i<holdings.size()-1; i++){
            static int a = 0, b = 0;
            if(holdings[i].getMine() == true && a == 0){
              Chain(&holdings[i], &holdings[holdings.size()-1]);
              a++; //used as flag to not do more than 1 bindings
            }
            else if(holdings[i].getCrystalMine() == true && b == 0){
              Chain(&holdings[holdings.size()-1], &holdings[i]);
              b++; //used as flag to not do more than 1 bindings
            }
          }
       }
       else if(holdings[holdings.size()-1].getCrystalMine() == true){ //holding is a crystal mine
         for (unsigned int i=0; i<holdings.size()-1; i++){
           if(holdings[i].getGoldMine() == true){
             Chain(&holdings[i], &holdings[holdings.size()-1]);
             break; //if we form the chain then we don't have to search for other holdings
           }
         }
       }
       cout << "No chain creation could be made" << endl;
      } else cout << "Not enough money to buy this card" << endl;
    }
  } else cout << "Card is not revealed-cannot be bought this round" << endl;
}

//new functions
vector<Personality> Player::getactivePersonalities(){
  return activePersonalities;
}

void Player::setOverallAttack(int num){
  overallAttack += num;
}

void Player::setOverallDefense(int num){
  overallDefense += num;
}

int Player::getOverallAttack(){
  return overallAttack;
}

int Player::getOverallDefense(){
  return overallDefense;
}

void Player::setTapped(int pos, int type){
  activePersonalities[pos].Tapp();
  if (type==0) //defending personality
    activePersonalities[pos].Defending();
  else if (type==1) //attacking personality
    activePersonalities[pos].Attacking();
}

BlackCard* Player::GetProvince(int province){
  return provinces[province];
}

void Player::deleteProvince(int pos){
  numberOfProvinces--;
  provinces.erase(provinces.begin()+pos);
  cout << "Province was destroyed" << endl;
}

void Player::loseDefendingPersonalities(){
  vector<Personality>::iterator it = activePersonalities.begin();
  int k = 0;
  for (unsigned int i=0; i<activePersonalities.size(); i++){
    if (activePersonalities[i].isDefending() == true){ //trwei edw segmetation
      activePersonalities.erase(activePersonalities.begin()+i);
      k++;
    }
  }
  if (k!=0)
    cout << "Defending Personalities killed" << endl;
  else cout << "No defending personalities to be killed" << endl;
}

void Player::loseAttackingPersonalities(){
  int k = 0;
  for (unsigned int i=0; i<activePersonalities.size(); i++){
    if (activePersonalities[i].isAttacking() == true){
      activePersonalities.erase(activePersonalities.begin()+i);
      k++;
    }
  }
    cout << "Attacking Personalities killed" << endl;
}

void Player::loseChosenAttackingPersonalities(int result){
  cout << "Attacker needs to sacrifice an amount of personalities and/or followers with at least overall attack: " << result << endl;
  int loop = result;
  int h, l, n1, n2;
  do{
    if (activePersonalities.empty() == true){
      cout << "There are no personalities left\n";
      break;
    }
    cout << endl;
    cout << "Personalities: ";
    this->printPersonalitieswithAttack();
    cout << endl;
    for (unsigned int i=0; i<activePersonalities.size(); i++)
      activePersonalities[i].printFollower();
    cout << "Do you want to sacrifice a follower or a personality?(type 0 for follower, 1 for personality)\n";
    cin >> l;
    if (l == 0){
      cout << "Choose the personality where the follower you want is(1 to " << GetPersonSize() << "):";
      cin >> n1;
      if (activePersonalities[n1-1].getFollower().empty() == true){
        cout << "There are no followers left\n";
        continue;
      }
      cout << "Choose the follower to sacrifice(1 to " << activePersonalities[n1-1].getFollowerSize() << "):\n";
      cin >> n2;
      deleteFollower(n1-1, n2-1);
      loop -= activePersonalities[n1-1].getFollowerAttack(n2-1);
    }
    else if(l == 1){
      cout << "Choose a personality to sacrifice(1 to " << GetPersonSize() << "):\n";
      cin >> h;
      activePersonalities.erase(activePersonalities.begin() + h-1);
      loop -= activePersonalities[h-1].getAttack();
    }
  }while (loop > 0);
  cout << "All the appropriate sacrifices have been made!\n";
}

void Player::loseChosenDefendingPersonalities(int result){
  cout << "Defender needs to sacrifice an amount of personalities and/or followers with at least overall attack: " << result << endl;
  int loop = result;
  int h, l, n1, n2;
  do{
    if (activePersonalities.empty() == true){
      cout << "There are no personalities left\n";
      break;
    }
    cout << endl;
    cout << "Personalities: ";
    this->printPersonalitieswithAttack();
    cout << endl;
    for (unsigned int i=0; i<activePersonalities.size(); i++)
      activePersonalities[i].printFollower();
    cout << "Do you want to sacrifice a follower or a personality?(type 0 for follower, 1 for personality)\n";
    cin >> l;
    if (l == 0){
      cout << "Choose the personality where the follower you want is(1 to " << GetPersonSize() << "):";
      cin >> n1;
      if (activePersonalities[n1-1].getFollower().empty() == true){
        cout << "There are no followers left\n";
        continue;
      }
      cout << "Choose the follower to sacrifice(1 to " << activePersonalities[n1-1].getFollowerSize() << "):\n";
      cin >> n2;
      deleteFollower(n1-1, n2-1);
      loop -= activePersonalities[n1-1].getFollowerAttack(n2-1);
    }
    else if(l == 1){
      cout << "Choose a personality to sacrifice(1 to " << GetPersonSize() << "):\n";
      cin >> h;
      activePersonalities.erase(activePersonalities.begin() + h-1);
      loop -= activePersonalities[h-1].getAttack();
    }
  }while (loop > 0);
  cout << "All the appropriate sacrifices have been made!\n";
}

void Player::deleteFollower(int pos1, int pos2){
  activePersonalities[pos1].detachFollower(pos2);
}

void Player::itemloseDurability(){
  for (unsigned int i=0; i<activePersonalities.size(); i++)
    activePersonalities[i].lose_durability();
}

void Player::personloseHonour(){
  for (unsigned int i=0; i<activePersonalities.size(); i++){
    if (activePersonalities[i].getHonour()==0){
      cout << activePersonalities[i].getName() << " performed Seppuku" << endl;
      activePersonalities.erase(activePersonalities.begin()+i); //personality performs Seppuku
    }
    else
      activePersonalities[i].lose_honour(); //else person loses honour
  }
}

void Player::Harvest(int diff){
  int loop = diff;
  int k, n1;
  do{
    cout << "We get into harvest!\n";
    if (holdings.empty() == true && stronghold->istapped() == true){
      cout << "You cannot get money!\n";
      break;
    }
    cout << "Holdings: ";
    this->printholdings();
    cout << "Do you want to get harvest from a holding or the stronghold?(type 0 for holding, 1 for stronghold)\n";
    cin >> k;
    if (k == 0){
      if(holdings.empty() == true){
        cout << "There are no holdings!\n";
        continue;
      }
      cout << "Choose the holding you want to get the harvestValue(1 to " << holdings.size() << "):";
      cin >> n1;
      loop -= holdings[n1-1].getharvestValue();
      money = holdings[n1-1].getharvestValue() - diff;
    }
    else if(k==1){
      if(stronghold->istapped() == true){
        cout << "You cannot get money from the stronghold\n";
        continue;
      }
      stronghold->Tapp();
      loop -= stronghold->getMoney();
      money = stronghold->getMoney() - diff;
      cout << "You got money from stronghold!\n";
    }
  }while(loop > 0);
}

void Player::Chain(Holding* h1, Holding* h2){
  if(h1->getMine() == true && h2->getGoldMine() == true){
    h1->setupperHolding(h2);
    h2->setsubHolding(h1);
    h1->setharvestValue(2);
    if (h2->getupperHolding() == NULL){ //if goldmine doesnt have an upperHolding(CrystalMine)
      h2->setharvestValue(4);
      cout << "A chain between a Mine and a GoldMine has been created!\n";
    }
    else{
      h2->setharvestValue(10);
      h2->setCrystalHarvestValue(15);
      cout << "The chain has been completed!\n";
    }
  }
  else if(h1->getGoldMine() == true && h2->getCrystalMine()){
    h1->setupperHolding(h2);
    h2->setsubHolding(h1);
    if (h1->getsubHolding() == NULL){ //if goldmine doesnt have an upperHolding(CrystalMine)
      h1->setharvestValue(5);
      h2->setharvestValue(6);
      cout << "A chain between a CrystalMine and a GoldMine has been created!\n";
    }
    else{
      h1->setharvestValue(10);
      h2->setharvestValue(18);
      cout << "The chain has been completed!\n";
    }
  }
}
