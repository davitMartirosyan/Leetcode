SRC = $(wildcard *.c)
BUILD = $(SRC:.c=)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(BUILD)

$(BUILD): % : %.c
	$(CC) $(CFLAGS) $< -lm -o $@

clean:
	rm -rf $(BUILD)