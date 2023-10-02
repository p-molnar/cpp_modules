NAME	:=	account
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	-I$(INCLUDE)
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	Account.cpp				\
			tests.cpp	
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
	rm -f $(NAME).log

re:	fclean all

test:
	make all
	./$(NAME) > $(NAME).log
	vimdiff 19920104_091532.log $(NAME).log
	rm -f $(NAME).log

.PHONY:	all clean fclean re test