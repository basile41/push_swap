/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:03:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/15 18:59:43 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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
}	t_stack;

int		ft_push_swap(t_stack *a, t_stack *b);

//parsing
int		ft_parse_args(int argc, char **argv, t_stack *stack);
int		ft_check_errors(int argc, char **argv);
int		ft_put_error(void);

// //Operations
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
t_elem	*get_next(t_elem *elem, t_elem *curr);

//ft_sort
int		ft_is_sorted(t_elem *head);

#endif
