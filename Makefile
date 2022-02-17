# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 19:09:54 by bregneau          #+#    #+#              #
#    Updated: 2022/02/17 12:17:09 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	srcs/main.c \
				srcs/ft_parsing.c \
				srcs/ft_stack.c \
				srcs/ft_stack2.c \
				srcs/ft_utils.c \
				srcs/ft_push_swap.c \
				srcs/ft_op/ft_swap.c \
				srcs/ft_op/ft_push.c \
				srcs/ft_op/ft_rot.c \
				srcs/ft_op/ft_rrot.c \
				srcs/ft_sort.c

OBJS		= $(SRCS:.c=.o)

LIB			= ./libft/libft.a

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I./includes

NAME		= push_swap

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIB) $(OBJS)
			$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

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
