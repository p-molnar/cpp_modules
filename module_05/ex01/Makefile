NAME	:=	Form
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	main.cpp										\
			Bureaucrat/Bureaucrat.cpp						\
			Bureaucrat/Bureaucrat_getters.cpp				\
			Bureaucrat/Bureaucrat_grade_ops.cpp				\
			Bureaucrat/Bureaucrat_signForm.cpp				\
			Bureaucrat/Bureaucrat_GradeTooHighException.cpp	\
			Bureaucrat/Bureaucrat_GradeTooLowException.cpp	\
			Form/Form_beSigned.cpp							\
			Form/Form_getters.cpp							\
			Form/Form.cpp									\
			Form/Form_GradeTooHighException.cpp				\
			Form/Form_GradeTooLowException.cpp				\
			Form/Form_FormAlreadySignedException.cpp		\

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