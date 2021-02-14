CXXFLAGS = --std=c++17


all: card deck

card.o: card.cpp *.h
	-$(CXX) $(CXXFLAGS) -c card.cpp -o card.o

deck.o: deck.cpp *.h
	-$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
clean:
	rm -f *.o *.gch *~ a.out cards