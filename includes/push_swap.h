/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:03:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/24 20:40:24 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include "libft.h"
# include <limits.h>

typedef struct s_elem	t_elem;
struct s_elem
{
	int		value;
	int		index;
	t_elem	*prev;
	t_elem	*next;
};

typedef struct s_stack
{
	t_elem	*head;
	int		size;
	int		imax;
	int		highest;
	int		lowest;
}	t_stack;

typedef struct s_op
{
	int		a;
	int		b;
	int		min;
}	t_op;

typedef void			(*t_f)(t_stack *);

int		ft_push_swap(t_stack *a, t_stack *b);

//parsing
int		ft_parse_args(int argc, char **argv, t_stack *stack);
int		ft_check_errors(int argc, char **argv);
int		ft_put_error(void);

//Operations
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

//ft_stack
int		ft_add_new_elem(t_stack *stack, int value);
void	ft_add_back(t_stack *stack, t_elem *elem);
void	ft_add_front(t_stack *stack, t_elem *elem);
void	ft_rotate(t_stack *stack);
void	ft_rrotate(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_push(t_stack *src, t_stack *dst);
void	ft_sup_first_elem(t_stack *stack);
void	ft_free_stack(t_stack *stack);

//ft_set_index
void	ft_set_index(t_stack *stack);

//ft_sort
void	ft_sort(t_stack *a, t_stack *b);
int		ft_is_sorted(t_elem *head);
void	ft_insert_cheapest(t_stack *a, t_stack *b);
void	ft_push_inf_n(t_stack *a, t_stack *b, int n);
int		ft_is_consec(t_stack *a);
int		ft_get_pushable(t_stack *a, t_stack b, void (*f)(t_stack*));
void	ft_do_op(t_stack *a, t_stack *b, t_op *op);

//ft_utils
int		ft_isint(char *s);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

void	ft_aff_stack(t_stack *stack); //       A supprimer

//GNL
char	*get_next_line(int fd);

#endif
