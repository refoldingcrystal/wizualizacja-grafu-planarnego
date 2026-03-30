CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lm

SRC_DIR = src
OBJ_DIR = obj
BIN = program

SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)

test_tutte: all
	./$(BIN) tests/example_graph -va tutte -o graph_1.out
	python3 visualize.py tests/example_graph graph_1.out

.PHONY: all clean test