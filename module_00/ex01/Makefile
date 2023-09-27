NAME	:=	phonebook
CC		:=	c++
CFLAGS	?=	-I$(INCLUDE) -Wall -Werror -Wextra -pedantic-errors -std=c++17
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	main.cpp	\
			utils.cpp
OBJ		=	$(addprefix obj/, $(SRC:.cpp=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o:	src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $^

clean:	
	rm -rf obj

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re