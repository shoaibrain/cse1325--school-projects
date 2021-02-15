CXXFLAGS = --std=c++17
all: deck card
complex: main.o deck.o 
	$(CXX) $(CXXFLAGS) main.o deck.o -o deck

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

complex.o: deck.cpp
	$(CXX) $(CXXFLAGS) -c deck.cpp -o deck.o
	
simple: main.o card.o 
	$(CXX) $(CXXFLAGS) main.o card.o -o card	
	
simple.o: card.cpp
	$(CXX) $(CXXFLAGS) -c card.cpp -o card.o

clean:
	rm -f *.o *.gch a.out  deck card