CC = cc

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

INCLUDE_PATH = includes/push_swap.h

SRCS = srcs/aux.c srcs/getters.c srcs/main.c srcs/sort_big.c srcs/sort_hundred.c \
srcs/sort_ten.c srcs/sort_three.c srcs/sort.c srcs/utils.c srcs/ft_atoi.c \
srcs/ft_calloc.c srcs/ft_memcpy.c srcs/ft_memset.c srcs/ft_split.c \
operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c

OBJ = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

test:
	@printf "$(OBJ)"

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm:
	norminette $(INCLUDE_PATH) srcs/ operations/
