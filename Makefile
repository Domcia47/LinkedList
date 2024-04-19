CXX := g++
CXXFLAGS := -Wall
LDFLAGS := -s
LDLIBS := -lm

# Lista plików źródłowych i docelowych
SOURCES := LinkedList.cpp Generator.cpp
EXECUTABLES := LinkedList.x Generator.x

# Pliki obiektowe
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean make

all: $(EXECUTABLES)


LinkedList.x: LinkedList.o LinkedList.hpp
Generator.x: Generator.o 

%.o: %.cpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.x: %.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

make: $(OBJECTS) $(EXECUTABLES)

clean:
	$(RM) $(EXECUTABLES) $(OBJECTS)

