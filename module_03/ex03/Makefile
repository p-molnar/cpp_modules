NAME	:=	diamondtrap	
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	main.cpp													\
			ClapTrap/ClapTrap.cpp										\
			ClapTrap/ClapTrap_attack.cpp								\
			ClapTrap/ClapTrap_beRepaired.cpp							\
			ClapTrap/ClapTrap_takeDamage.cpp							\
			ClapTrap/ClapTrap_getters.cpp								\
			ClapTrap/ClapTrap_setters.cpp								\
			ClapTrap/ClapTrap_utility.cpp								\
			ScavTrap/ScavTrap_attack.cpp								\
			ScavTrap/ScavTrap_guardGate.cpp								\
			ScavTrap/ScavTrap.cpp										\
			FragTrap/FragTrap.cpp										\
			FragTrap/FragTrap_highFivesGuys.cpp							\
			DiamondTrap/DiamondTrap.cpp									\
			DiamondTrap/DiamondTrap_whoAmI.cpp							\

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