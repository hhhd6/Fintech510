CPPFLAGS = -Wall -Werror -std=c++11 -pedantic -ggdb3
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp, %.o, $(SRCS))
PROGRAM=circles

$(PROGRAM): $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS)

%.o: %.cpp point.hpp circle.hpp
	g++ -c $(CPPFLAGS) $<

clean:
	rm -f $(OBJS) $(PROGRAM) *~