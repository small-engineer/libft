CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
TEST_SRC_DIR = $(TEST_DIR)/tests-src
INCLUDE_DIR = include
SRCS = $(shell find $(SRC_DIR) -name "*.c")
HEADERS = $(shell find $(INCLUDE_DIR) -name "*.h")

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

copy-src:
	@echo "Copying source files and headers to $(TEST_SRC_DIR)..."
	@mkdir -p $(TEST_SRC_DIR)
	@cp $(SRCS) $(TEST_SRC_DIR)/
	@cp $(HEADERS) $(TEST_SRC_DIR)/

test: $(NAME) copy-src
	@echo "Running tests in $(TEST_DIR)..."
	@$(MAKE) -C $(TEST_DIR)

clean:
	@rm -rf $(OBJ_DIR) $(TEST_SRC_DIR) test.out

fclean: clean
	@rm -f $(NAME)

re: fclean all

