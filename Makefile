CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
SRC = src/principal.c src/tabuleiro.c src/pecas.c src/jogo.c
OBJ = $(SRC:.c=.o)
TARGET = jogo_de_xadrez

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
