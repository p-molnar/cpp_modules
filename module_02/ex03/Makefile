NAME	:=	point_in_triangle
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98 
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/ 
INCLUDE	+=	../ex02/include
SRC		=	main.cpp										\
			fixed/Fixed.cpp									\
			fixed/Fixed_toFixedPoint.cpp					\
			fixed/Fixed_toFloat.cpp							\
			fixed/Fixed_toInt.cpp							\
			fixed/Fixed_printBin.cpp						\
			fixed/Fixed_logical_operators.cpp				\
			fixed/Fixed_arithmetic_operators.cpp			\
			fixed/Fixed_decrement_operators.cpp				\
			fixed/Fixed_increment_operators.cpp				\
			fixed/Fixed_min.cpp								\
			fixed/Fixed_max.cpp								\
			fixed/Fixed_abs.cpp								\
			point/Point.cpp									\
			triangle/Triangle.cpp							\
			triangle/Triangle_Area.cpp						\

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