CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings

CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = LcsSimulation.o LcsSeekerPartOne.o LcsSeekerPartTwo.o LcsTool.o

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf
	$(RM) *.o *.gc* main LcsPartOneTest
