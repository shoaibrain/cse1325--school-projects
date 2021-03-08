CXXFLAGS = --std=c++17

all: smart

debug: CXXFLAGS += -g
debug: smart

smart: main.o person.o parent.o student.o *.h
	$(CXX) $(CXXFLAGS) main.o person.o parent.o student.o  -o smart
	
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

person.o: person.cpp *.h
	$(CXX) $(CXXFLAGS) person.cpp -c -o person.o

parent.o: parent.cpp *.h
	$(CXX) $(CXXFLAGS) parent.cpp -c -o parent.o

student.o: student.cpp *.h
	$(CXX) $(CXXFLAGS) student.cpp -c -o student.o
	
clean: 
	rm -f *.o*.gch a.out smart
