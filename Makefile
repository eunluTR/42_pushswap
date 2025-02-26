NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I includes

SRC_DIR		= src
UTILS_DIR	= utils

SRC_FILES	= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/init.c \
			  $(SRC_DIR)/basic_sort.c \
			  $(SRC_DIR)/radix_sort.c \
			  $(UTILS_DIR)/basics.c \
			  $(UTILS_DIR)/check_args.c \
			  $(UTILS_DIR)/error.c \
			  $(UTILS_DIR)/free.c \
			  $(UTILS_DIR)/index.c \
			  $(UTILS_DIR)/linked_list.c \
			  $(UTILS_DIR)/split.c \
			  $(UTILS_DIR)/putnbr.c \
			  $(UTILS_DIR)/swap.c \
			  $(UTILS_DIR)/push.c \
			  $(UTILS_DIR)/rotate.c \
			  $(UTILS_DIR)/reverse_rotate.c \

OBJ_FILES	= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
