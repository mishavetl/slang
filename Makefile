FLAGS=-g -Wall

all:
	mkdir -p bin
	gcc -g -Wall src/main.c src/console.c src/formatutils.c src/parser.c lib/io.c -o bin/slang

clean:
	rm -rf bin
