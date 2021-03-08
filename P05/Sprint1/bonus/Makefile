CXXFLAGS = --std=c++17

all: smart

debug: CXXFLAGS += -g
debug: smart

smart: cli.o person.o parent.o student.o *.h
	$(CXX) $(CXXFLAGS) cli.o person.o parent.o student.o  -o smart
	
cli.o: cli.cpp *.h
	$(CXX) $(CXXFLAGS) cli.cpp -c -o cli.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) person.cpp -c -o person.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) parent.cpp -c -o parent.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) student.cpp -c -o student.o
	
clean: 
	rm -f *.o*.gch a.out smart
