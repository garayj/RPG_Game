CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors

#Credit: I learned how to use the wildcard and patsubst functions from GNU make manual as well as this stackoverflow question:
	
# https://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in
	
HEADERS =  $(wildcard *.hpp)

SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp, %.o, ${SRCS})

greendragon: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o greendragon 

${OBJS}:${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

zip:
	zip -D FinalProject_Garay_Jose.zip ${HEADERS} ${SRCS} Reflection.pdf makefile

clean:
	rm ${OBJS} greendragon 

