CXX			= clang++
CPPFLAGS	= -Wall -Wextra -Werror
RM			= rm -rf

STDFLAG		= -std=c++11

NAME		= ex07

SRC			= main.cpp
OBJDIR		= ./obj_files/
OBJ			= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))
DFILES		= $(OBJ:.o=.d)


all: mkdir_obj $(NAME)

$(OBJDIR)%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(STDFLAG) -c $< -o $@ -MMD -O2

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

mkdir_obj:
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DFILES)

.PHONY:	all clean fclean re
