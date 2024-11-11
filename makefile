CC = clang
FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIB_DIR = libmx

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

PATHFINDER = pathfinder

all: $(PATHFINDER)

$(PATHFINDER): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L$(LIB_DIR) -lmx -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MAKE) -C $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR) $(PATHFINDER)


