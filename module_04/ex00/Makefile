NAME	:=	polymorphism
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	main.cpp													\
			Animal/Animal.cpp											\
			Animal/Animal_makeSound.cpp									\
			Animal/Animal_getType.cpp									\
			WrongAnimal/WrongAnimal.cpp									\
			WrongAnimal/WrongAnimal_makeSound.cpp						\
			WrongAnimal/WrongAnimal_getType.cpp							\
			Cat/Cat.cpp													\
			Cat/Cat_makeSound.cpp										\
			WrongCat/WrongCat.cpp										\
			WrongCat/WrongCat_makeSound.cpp								\
			Dog/Dog.cpp													\
			Dog/Dog_makeSound.cpp										\

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