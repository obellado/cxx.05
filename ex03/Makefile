# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obellado <obellado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 18:00:15 by obellado          #+#    #+#              #
#    Updated: 2021/08/09 18:38:48 by obellado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	go

CXX		=	clang++

FLAGCXX =	-Wall -Werror -Wextra

SRCS	=	main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp


OBJS			= $(SRCS:.cpp=.o)

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(FLAGCXX) -o ${NAME} ${OBJS}

%.o:	%.cpp Makefile Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp

		$(CXX) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
