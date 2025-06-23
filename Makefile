# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apylypen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 20:50:40 by apylypen          #+#    #+#              #
#    Updated: 2024/03/18 20:50:42 by apylypen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS	= philo.c help.c utils.c itoa.c
OBJS	= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Project compiled"

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@echo " Object files deleted"

fclean: clean
	$(RM) $(NAME)
	@echo "Project cleaned"

clear:
	clear

re: clear fclean all
	@echo "Project cleaned and recompiled"

.PHONY: all clean fclean re
