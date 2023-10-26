NAME	:=	abstract_class	
CC		:=	g++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	main.cpp													\
			Brain/Brain.cpp												\
			Animal/Animal.cpp											\
			Animal/Animal_getType.cpp									\
			Cat/Cat.cpp													\
			Cat/Cat_makeSound.cpp										\
			Cat/Cat_deepCopy.cpp										\
			Cat/Cat_getters.cpp										\
			Dog/Dog.cpp													\
			Dog/Dog_makeSound.cpp										\
			Dog/Dog_deepCopy.cpp										\
			Dog/Dog_getters.cpp										\

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