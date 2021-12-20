# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 19:09:54 by bregneau          #+#    #+#              #
#    Updated: 2021/12/20 15:34:13 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	./src/main.c \
				./src/parsing.c

OBJS		= $(SRCS:.c=.o)

LIB			= ./libft/libft.a

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -c -I./includes

NAME		= push_swap

all:		$(NAME)

.o:			
			$(CC) $(CFLAGS) $< -o ${<.c=.o}

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			$(CC) $(LIB) $(OBJS) -o $(NAME)

clean:		
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft

fclean:		clean
			$(RM) $(LIB) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
