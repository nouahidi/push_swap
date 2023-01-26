NAME = push_swap
SRC = main.c ft_atoi.c  fonction_list.c ft_putnbr.c insta.c instb.c \
	push_swap.c push_swap_util.c sort_3.c list_numbering.c push_100.c
INC = push_swap.h
OBJ = $(SRC:.c=.o)
CC = cc -g
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -g

%.o:%.c $(INC)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re:fclean all