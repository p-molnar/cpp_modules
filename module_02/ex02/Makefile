NAME	:=	operators
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98 -g
CPPFLAGS+=	-I$(INCLUDE)
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	main.cpp					\
			Fixed.cpp					\
			Fixed_toFixedPoint.cpp		\
			Fixed_toFloat.cpp			\
			Fixed_toInt.cpp				\
			Fixed_logical_operators.cpp	\
			Fixed_arithmetic_operators.cpp	\
			Fixed_decrement_operators.cpp	\
			Fixed_increment_operators.cpp	\
			Fixed_min.cpp	\
			Fixed_max.cpp	\

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