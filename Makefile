FLAGS=-g -Wall

all:
	mkdir -p bin
	gcc -g src/main.c src/console.c src/formatutils.c src/parser.c lib/io.c src/utils.c lib/standart.c -o bin/slang

clean:
	rm -rf bin
