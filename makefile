
CXX = g++
CXXFLAGS = -Wall -g -std=c++0x

objects=main.o Card.o DeckBuilder.o Follower.o GameBoard.o Holding.o Item.o Personality.o Player.o

project : $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o project

main.o : Card.hpp DeckBuilder.hpp Follower.hpp GameBoard.hpp Holding.hpp Item.hpp Personality.hpp Player.hpp

clean :
	rm project $(objects)