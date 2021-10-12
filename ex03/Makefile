NAME		= ex03

CC			= g++
CFLAGS		= -std=c++17
CFILES		= main Hash_table Substr
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(CFILES)))
SRC_DIR		= ./srcs/
OBJ			= $(SRC:.cpp=.o)
HEADER		= ./includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(addsuffix .o, $(basename $<)) -I $(HEADER)

clean:
	@rm -rf */*.o
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
