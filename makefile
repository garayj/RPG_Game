CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors

SRC = main.cpp Map.cpp Space.cpp Grass.cpp

HEADERS = Space.hpp Map.hpp Grass.hpp

OBJS = main.o Map.o Space.o Grass.o

test:${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o test


${OBJS}:${SRCS} 
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm ${OBJS} test

