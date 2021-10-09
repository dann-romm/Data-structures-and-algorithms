NAME = ex03

CC = g++
CFLAGS = 
CFILES = main.cpp Hash_table.cpp Substr.cpp
# CFILES = main.cpp
SRC = $(addprefix $(SRC_DIR), $(CFILES))
SRC_DIR = ./srcs/
OBJ = $(SRC:.cpp=.o)
HEADER = ./includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(addsuffix .o, $(basename $<)) -I $(HEADER)

clean:
	@rm -rf */*.o
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
