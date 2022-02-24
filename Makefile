# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 19:09:54 by bregneau          #+#    #+#              #
#    Updated: 2022/02/24 21:41:23 by bregneau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CHECKER			=	checker

LIBFT_PATH		=	./libft/
SRCS_PATH		=	./srcs/
OBJS_PATH		=	./objs/

INC				=	-I $(addprefix $(LIBFT_PATH),.)\
					-I ./includes

SRCS			= 	ft_parsing.c \
					ft_stack.c \
					ft_stack2.c \
					ft_utils.c \
					ft_op_swap.c \
					ft_op_push.c \
					ft_op_rot.c \
					ft_op_rrot.c \
					ft_set_index.c \
					ft_sort.c \
					ft_sort2.c \
					ft_sort3.c \

SRCS_NAME		=	push_swap.c

SRCS_CHECKER	=	checker.c \
					get_next_line.c

OBJS			=	$(addprefix $(OBJS_PATH),$(SRCS:.c=.o))

OBJS_NAME		=	$(addprefix $(OBJS_PATH),$(SRCS_NAME:.c=.o)) \
					$(OBJS)
					
OBJS_CHECKER		=	$(addprefix $(OBJS_PATH),$(SRCS_CHECKER:.c=.o)) \
					$(OBJS)

LIBFT			=	$(addprefix $(LIBFT_PATH),libft.a)

LIBS			=	-Llibft -lft

CC				=	cc
CFLAGS			=	-MMD -Wall -Wextra -Werror -g3 $(INC)

all:				$(NAME) $(CHECKER)

$(OBJS_PATH)%.o:	$(SRCS_PATH)%.c
					@mkdir -p $(OBJS_PATH)
					@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(LIBFT) $(OBJS_NAME)
					$(CC) $(OBJS_NAME) $(LIBS) -o $(NAME)
					
bonus:				$(CHECKER)

$(CHECKER):			$(LIBFT) $(OBJS_CHECKER)
					$(CC) $(OBJS_CHECKER) $(LIBS) -o $(CHECKER)

$(LIBFT):	
					@echo "Compiling libft..."
					@make -C $(LIBFT_PATH)
					@make clean -C $(LIBFT_PATH)

clean:		
					rm -rf $(OBJS_PATH)

fclean:				clean
					rm -f $(LIBFT) $(NAME) $(CHECKER)

re:					fclean all

.PHONY:				all bonus clean fclean re
