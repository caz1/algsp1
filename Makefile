SHELL = /bin/sh
CC = g++
EX1SRC = ex1/src
EX2SRC = ex2/src
CFLAGS = -std=c++11

default: string num
	
string:  $(EX1SRC)/stringSort.h $(EX1SRC)/stringSort.cpp $(EX1SRC)/main.cpp
	${CC} ${CFLAGS} -o $@ $^


num: $(EX2SRC)/main.cpp $(EX2SRC)/numSort.h $(EX2SRC)/numSort.cpp
	$(CC) -o $@ $^ $(CFLAGS)

run:
	./string
	./num
.PHONY: clean
clean:
	-rm -f num string
