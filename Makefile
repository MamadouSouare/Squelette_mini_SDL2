
CC 	= gcc
SRC 	= main.c 
DEST 	= bin\prog
ERROR_FLAGS = -Wall -Wextra 
SDL2_FLAGS = -I include -L lib -lmingw32 -lSDL2main -lSDL2

cmp:
	$(CC) $(SRC) -o $(DEST) $(SDL2_FLAGS)

run:
	.\$(DEST)

clean:
	rm -rf bin/*.exe

all: cmp run
