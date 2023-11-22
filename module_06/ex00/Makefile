NAME	:=	converter	
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=	
INCLUDE	=	include/
SRC		=	main.cpp												\
			ScalarConverter_convert.cpp								\
			ScalarConverter_printConversions.cpp					\
			ScalarConverter_InvalidNumericalFormatException.cpp		\
			ScalarConverter_isValidNumericalFormat.cpp				\


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