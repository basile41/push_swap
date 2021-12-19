# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 19:09:54 by bregneau          #+#    #+#              #
#    Updated: 2021/12/14 19:37:53 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=

OBJS		= $(SRCS:.c=o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

NAME		= push_swap

all:		$(NAME)

$(NAME)		$(OBJ)
			$(MAKE) -C ./libft
			cp ./libft/libft.a $(NAME)
			ar rcs $(AME) $(OBJS)

clean:		$(MAKE) clean -C ./libft
			$(RM) $(OBJ)

fclean:		clean
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME) ./libft/libft.a

re:			fclean $(NAME)

.PHONY:		all clean fclean re
