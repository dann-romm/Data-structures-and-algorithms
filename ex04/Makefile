NAME		= ex04

CCP			= g++
CFLAGS		= -std=c++17
CFILES		= main b_tree queue
SRC			= $(addprefix $(SRC_DIR), $(addsuffix .cpp, $(CFILES)))
SRC_DIR		= ./srcs/
OBJ			= $(SRC:.cpp=.o)
HEADER		= ./includes/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CCP) $(CFLAGS) $(OBJ) -o $@

%.o : %.cpp $(HEADER)
	$(CCP) $(CFLAGS) -c $< -o $(addsuffix .o, $(basename $<)) -I $(HEADER)

clean:
	@rm -rf */*.o
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
