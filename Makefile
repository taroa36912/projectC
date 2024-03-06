CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =

SRC_FILES = life1.c life2.c life3.c life4.c life5.c life6.c Jyanken.c minigame.c all_player_minigame.c main.c
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))
EXECUTABLE = play

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
	rm -f $(EXECUTABLE)
