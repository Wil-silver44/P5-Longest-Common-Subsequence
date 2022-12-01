CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings

CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = LcsSeekerPartOne.o

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

LcsPartOneTest: LcsPartOneTest.cpp LcsSeekerPartOne.o
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -rf *.dSYM
		$(RM) *.o *.gc* main