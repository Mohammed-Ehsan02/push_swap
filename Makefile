# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhan <mkhan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 17:06:53 by amalbrei          #+#    #+#              #
#    Updated: 2022/08/12 14:48:08 by mkhan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	test.c ft_split.c ft_atois.c

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap

all:			$(NAME)

$(NAME):		
				$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
