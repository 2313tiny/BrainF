SOURCES := main.cpp
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))


all: comp run
comp:$(OBJECTS)
	@clear 
	@g++ -g $(OBJECTS) -o smd

main.o:
	@g++ -c -g  main.cpp -o main.o -std=c++11

run:
	@./smd
	@ctags -R .
clean:
	rm smd *.o *.dep tags
