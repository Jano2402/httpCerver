CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = server

SRC = src/main.c src/server.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
