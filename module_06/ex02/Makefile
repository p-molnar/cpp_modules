NAME	:=	identifier
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=	
INCLUDE	=	include/
SRC		=	main.cpp												\
			generate.cpp											\
			identify.cpp											\


OBJ		=	$(addprefix obj/, $(SRC:.cpp=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o:	src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) -c $(CPPFLAGS) -o $@ $^

-include $(SRC:.cpp=.d)

clean:	
	rm -rf obj

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re