CC = clang
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

LIB = libmx.a

all: $(LIB)

$(LIB): $(OBJ)
	@ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(LIB)


