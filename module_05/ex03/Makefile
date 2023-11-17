NAME	:=	intern
CC		:=	c++
CPPFLAGS?=	-Wall -Werror -Wextra -pedantic-errors -std=c++98
CPPFLAGS+=	$(addprefix -I, $(INCLUDE))
CPPFLAGS+=	-MMD -MP
LDFLAGS	?=
INCLUDE	=	include/
SRC		=	main.cpp													\
			Bureaucrat/Bureaucrat.cpp									\
			Bureaucrat/Bureaucrat_getters.cpp							\
			Bureaucrat/Bureaucrat_grade_ops.cpp							\
			Bureaucrat/Bureaucrat_signForm.cpp							\
			Bureaucrat/Bureaucrat_executeForm.cpp						\
			Bureaucrat/Bureaucrat_GradeTooHighException.cpp				\
			Bureaucrat/Bureaucrat_GradeTooLowException.cpp				\
			AForm/AForm.cpp												\
			AForm/AForm_beSigned.cpp									\
			AForm/AForm_getters.cpp										\
			AForm/AForm_setters.cpp										\
			AForm/AForm_validateForExecution.cpp						\
			AForm/AForm_GradeTooHighException.cpp						\
			AForm/AForm_GradeTooLowException.cpp						\
			AForm/AForm_FormAlreadySignedException.cpp					\
			AForm/AForm_FormNotSignedException.cpp						\
			ShrubberyCreationForm/ShrubberyCreationForm.cpp				\
			ShrubberyCreationForm/ShrubberyCreationForm_execute.cpp		\
			RobotomyRequestForm/RobotomyRequestForm.cpp					\
			RobotomyRequestForm/RobotomyRequestForm_execute.cpp			\
			PresidentialPardonForm/PresidentialPardonForm.cpp			\
			PresidentialPardonForm/PresidentialPardonForm_execute.cpp	\
			Intern/Intern.cpp											\
			Intern/Intern_makeForm.cpp									\
			Intern/Intern_getForms.cpp									\
			Intern/Intern_NoFormFoundException.cpp						\

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