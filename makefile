NAME1 = client
NAME2 = server
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
SRC1 = client.c utils.c
SRC2 = server.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)

all: $(NAME1) $(NAME2)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME1): $(OBJ1)
	@$(CC) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	@$(CC) $(OBJ2) -o $(NAME2)

clean:
	@$(RM) *.o
	
fclean: clean
	@$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY : clean fclean re all