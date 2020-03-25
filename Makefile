NAME = lemin

SRC = main.c

INC = ./lem_in.h -I ./libftprintf/includes

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

LIB = ./libftprint/libftprintf.a

all: $(NAME)
	$(NAME): $(OBJ)
		gcc $(FLAGS) $(INC) $(OBJ) $(LIB) -o $(NAME)
clean:
	rm (OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

