CC=g++
CFLAGS=-std=c++11 -Wall -DNDEBUG -O3
DEPS=cal.h

all: test

%.o: %.cpp $(DEPS)
	$(CC) -c $(CFLAGS) -o $@ $< 

test: test.o cal.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm ./*.o ./test



