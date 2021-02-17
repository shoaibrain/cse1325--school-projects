CXXFLAGS = --std=c++17

all: deck

deck: main.o deck.o card.o hintcard.o *.h
	$(CXX) $(CXXFLAGS) main.o deck.o card.o hintcard.o -o deck

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
gate.o: deck.cpp *.h
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
and.o: card.cpp *.h
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o
	

clean:
	rm -f *.o *.gch ~* a.out deck
