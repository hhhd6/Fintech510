# gaussian: main.cpp solver.hpp
# 	g++ -ggdb3 -std=c++17 -I ../eigen_library main.cpp -o gaussian

# clean:
# 	rm gaussian
# 	rm -rf *.dSYM


CXX = g++
# Try multiple common Eigen include paths
CXXFLAGS = -std=c++11 -Wall \
           -I/opt/homebrew/include/eigen3 \
           -I/usr/local/include/eigen3 \
           -I/usr/include/eigen3 \
           -I$(HOME)/homebrew/include/eigen3 \
           -I/opt/local/include/eigen3

gaussian: main.o
	$(CXX) main.o -o gaussian

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o gaussian

.PHONY: clean
