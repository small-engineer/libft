NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined

BUILD_DIR = build
INCL_DIR = include
SRC_DIRS = general ft_printf gnl

FT_PRINTF_SRCS = ft_printf.c \
                 ft_putchar.c \
                 ft_putnbr.c \
                 ft_putnbr_base.c \
                 ft_putstr.c \
                 help.c
GENERAL_SRCS = ft_atoi.c \
               ft_bzero.c \
               ft_calloc.c \
               ft_isalnum.c \
               ft_isalpha.c \
               ft_isascii.c \
               ft_isdigit.c \
               ft_isprint.c \
               ft_itoa.c \
               ft_lstadd_back.c \
               ft_lstadd_front.c \
               ft_lstclear.c \
               ft_lstdelone.c \
               ft_lstiter.c \
               ft_lstlast.c \
               ft_lstmap.c \
               ft_lstnew.c \
               ft_lstsize.c \
               ft_memchr.c \
               ft_memcmp.c \
               ft_memcpy.c \
               ft_memmove.c \
               ft_memset.c \
               ft_putchar_fd.c \
               ft_putendl_fd.c \
               ft_putnbr_fd.c \
               ft_putstr_fd.c \
               ft_split.c \
               ft_strchr.c \
               ft_strdup.c \
               ft_striteri.c \
               ft_strjoin.c \
               ft_strlcat.c \
               ft_strlcpy.c \
               ft_strlen.c \
               ft_strmapi.c \
               ft_strncmp.c \
               ft_strnstr.c \
               ft_strrchr.c \
               ft_strtrim.c \
               ft_substr.c \
               ft_tolower.c \
               ft_toupper.c
GNL_SRCS = get_next_line.c \
           get_next_line_utils.c

SRCS = $(addprefix ft_printf/, $(FT_PRINTF_SRCS)) \
       $(addprefix general/, $(GENERAL_SRCS)) \
       $(addprefix gnl/, $(GNL_SRCS))
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

INCL = -I$(INCL_DIR)

RESET = \033[0m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)[BUILD] Creating archive: $(NAME)$(RESET)"
	@ar rcs $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.c
	@echo "$(BLUE)[BUILD] Compiling: $<$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCL)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

clean:
	@echo "$(RED)[CLEAN] Removing build directory$(RESET)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(RED)[FCLEAN] Removing $(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
