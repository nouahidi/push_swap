NAME = push_swap
NAME_B = my_checker
SRC = main.c ft_atoi.c  fonction_list.c insta.c instb.c \
	push_swap.c push_swap_util.c sort_3.c list_numbering.c push_100.c max_before_max.c esp.c
BNS = get_next_line.c get_next_line_util.c my_checker.c ft_atoi.c  fonction_list.c insta.c instb.c \
	push_swap.c push_swap_util.c sort_3.c list_numbering.c push_100.c max_before_max.c esp.c instb_bon.c insta_bon.c str_cmp.c read_inp.c
INC = push_swap.h
OBJ = $(SRC:.c=.o)
BON_OBJ = $(BNS:.c=.o)
CC = cc -g
CFLAGS = -Wall -Werror -Wextra 
RM = rm -f

all: $(NAME)

bonus : $(NAME_B)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -g

$(NAME_B):$(BON_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -g

%.o:%.c $(INC)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJ) $(BON_OBJ)

fclean:clean
	$(RM) $(NAME) $(BON_OBJ)

re:fclean all