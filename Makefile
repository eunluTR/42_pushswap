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
			  $(UTILS_DIR)/sort_utils.c \

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

test2:				$(NAME)	
					$(eval ARG = $(shell for i in $$(shuf -i 0-10000 -n 2); do echo $$(($$i - 5000)); done))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell for i in $$(shuf -i 0-10000 -n 3); do echo $$(($$i - 5000)); done))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test4:				$(NAME)	
					$(eval ARG = $(shell for i in $$(shuf -i 0-10000 -n 4); do echo $$(($$i - 5000)); done))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell for i in $$(shuf -i 0-10000 -n 5); do echo $$(($$i - 5000)); done))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell for i in $$(shuf -i 0-10000 -n 100); do echo $$(($$i - 5000)); done))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell for i in $$(shuf -i 0-10000 -n 500); do echo $$(($$i - 5000)); done))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re test2 test3 test5 test100 test500
