CC = cc

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

INCLUDE_PATH = includes/push_swap.h

SRCS = srcs/aux.c srcs/getters.c srcs/main.c srcs/sort_big.c srcs/sort_hundred.c \
srcs/sort_ten.c srcs/sort_three.c srcs/sort.c srcs/utils.c srcs/ft_atoi.c \
srcs/ft_calloc.c srcs/ft_memcpy.c srcs/ft_memset.c srcs/ft_split.c \
operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c

OBJ = aux.o getters.o main.o sort_big.o sort_hundred.o sort_ten.o sort_three.o \
sort.o utils.o ft_atoi.o ft_calloc.o ft_memcpy.o ft_memset.o ft_split.o \
push.o reverse_rotate.o rotate.o swap.o

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ): $(SRCS)
		$(CC) $(FLAGS) -c $(SRCS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

norm:
	norminette $(INCLUDE_PATH) srcs/ operations/
