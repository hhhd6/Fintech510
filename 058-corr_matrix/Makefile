CCFLAGS=--std=c++17 -pedantic -Wall -Werror -ggdb3
correl_matrix: asset.o parse.o main.o
	mkdir -p /autograder/submission
	g++ -o /autograder/submission/correl_matrix $(CCFLAGS) asset.o parse.o main.o
asset.o: asset.cpp asset.hpp
	g++ -c $(CCFLAGS) -o asset.o asset.cpp
parse.o: parse.cpp parse.hpp asset.hpp
	g++ -c $(CCFLAGS) -o parse.o parse.cpp
main.o: main.cpp asset.hpp matrix.hpp
	g++ -c $(CCFLAGS) -o main.o main.cpp

clean:
	rm -f *.o  *~ correl_matrix


