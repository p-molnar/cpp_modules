NAME	:=	megaphone
CC		:=	c++
CFLAGS	?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
LDFLAGS	?=
SRC		=	megaphone.cpp
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