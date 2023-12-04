NAME	:=	btc
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98 -g
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=	-fsanitize=address
INCLUDE	=	include/
SRC		=	main.cpp													\
			utils.cpp													\
			BitcoinExchange.cpp											\
			BitcoinExchange_loadExchangeData.cpp						\
			ExchangeDate.cpp											\
			AValue.cpp													\
			ExchangeRate.cpp											\
			HoldingValue.cpp											\

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