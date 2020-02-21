CXX = g++
CXXFLAGS = -Wall -g -std=c++0x

objects=main.o Card.o DeckBuilder.o Follower.o GameBoard.o Holding.o Item.o Personality.o Player.o Phases.o TypeConverter.o

project : $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o project

main.o : Card.hpp DeckBuilder.hpp Follower.hpp GameBoard.hpp Holding.hpp Item.hpp Personality.hpp Player.hpp Phases.hpp TypeConverter.hpp

clean :
	rm project $(objects)