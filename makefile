CC = gcc
CFLAGS = -Wall

SRC = $(shell find ./src -name '*.c')

all: slate

slate:
	mkdir -p bin
	${CC} ${CFLAGS} -o bin/slate ${SRC}
	
clean:
	rm -rf bin
