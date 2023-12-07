CC		= g++
CFLAGS  = --std=c++23 -Wall -Werror -pedantic
HEADERS = # insert headers
PROGRAM = main

OBJDIRE := Object
SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, $(OBJDIRE)/%.o, $(SOURCES))

$(OBJDIRE)/%.o: %.cpp $(HEADERS)
				mkdir -p $(OBJDIRE)
				$(CC) $(CFLAGS) -c $< -o $@

.PHONY: 		all clean

all: 			$(PROGRAM)

$(PROGRAM):		$(OBJECTS) 
				$(CC) $(CFLAGS) -o $@ $^
%.o:			%.cpp $(HEADERS)
				$(CC) $(CFLAGS) -c $<
clean:
				rm -r $(OBJDIRE) $(PROGRAM)