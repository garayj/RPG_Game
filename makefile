CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
CXXFLAGS += -std=c++0x
INCLUDE:= -I "../inc"
CXXFLAGS += -pedantic-errors

#Credit: I learned how to use the wildcard and patsubst functions from GNU make manual as well as this stackoverflow question:
	
# https://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in

# HERO_HEADERS =  $(wildcard ./hero_srcs/*.hpp)

# HERO_SRCS =  $(wildcard ./hero_srcs/*.cpp)

OBJDIR:= ./obj

HEADDIR:= ./srcs
	
HEADERS =  $(wildcard $(HEADDIR)/*.hpp)

SRCS = $(wildcard $(HEADDIR)/*.cpp)

OBJS = $(patsubst $(HEADDIR)/%.cpp, $(OBJDIR)/%.o, ${SRCS})

greendragon: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o greendragon 

$(OBJDIR)/%.o: $(HEADDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

zip:
	zip -D FinalProject_Garay_Jose.zip ${HEADERS} ${SRCS} Reflection.pdf makefile

clean:
	rm ${OBJS} greendragon 

