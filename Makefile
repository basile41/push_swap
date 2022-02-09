# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 19:09:54 by bregneau          #+#    #+#              #
#    Updated: 2022/02/09 15:38:49 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# srcs/parsing.c \#
SRCS		= 	srcs/main.c \
				srcs/ft_stack.c

OBJS		= $(SRCS:.c=.o)

LIB			= ./libft/libft.a

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I./includes

NAME		= push_swap

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIB) $(OBJS)
			$(CC) $(LIB) $(OBJS) -o $(NAME)

$(LIB):	
			@echo "Compiling libft..."
			@make -C libft
			@make clean -C libft

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(LIB) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
