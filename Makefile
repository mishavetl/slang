FLAGS=-g -Wall

all:
	mkdir -p bin
	gcc src/main.c src/console.c -o bin/slang

clean:
	rm -rf bin
