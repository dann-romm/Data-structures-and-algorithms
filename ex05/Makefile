NAME		= ex05

CCP			= g++
CFLAGS		= -std=c++20
CFILES		= main graph
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

ds_store:
	@rm -rf ../.DS_Store
	@rm -rf ../ex01/.DS_Store
	@rm -rf ../ex02/.DS_Store
	@rm -rf ../ex03/.DS_Store
	@rm -rf ../ex04/.DS_Store
	@rm -rf ../ex05/.DS_Store

fclean: clean
	@rm -rf $(NAME)

re: fclean all
