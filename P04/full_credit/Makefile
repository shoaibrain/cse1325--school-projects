CXXFLAGS = --std=c++17

fraction: main.o fraction.o *.h
	$(CXX) $(CXXFLAGS) main.o fraction.o -o fraction
test: test.o fraction.o *.h
		$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

fraction.o: fraction.cpp *.h
	-$(CXX) $(CXXFLAGS) -c fraction.cpp -o fraction.o


clean:
	rm -f *.o *.gch ~* a.out test fraction

