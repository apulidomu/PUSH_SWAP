# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apulido- <apulido-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 14:03:21 by apulido-          #+#    #+#              #
#    Updated: 2022/02/14 15:42:30 by apulido-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	movements.c			\
			movements2.c		\
			movements3.c		\
			push_swap_utils.c	\
			push_swap_utils2.c	\
			push_swap_utils3.c	\
			push_swap.c			\
			slist.c				\
			slist_utils.c		\
			logic.c				\
			logic_utils.c		\

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS	= -Wall -Werror -Wextra

all		:		$(NAME)

$(NAME)	:	$(OBJS)
				$(CC)	$(OBJS) -o $(NAME) -fsanitize=address

%.o:		%.c
				$(CC) $(SFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re bonus