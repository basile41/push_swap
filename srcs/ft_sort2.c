/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:18:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/23 17:55:19 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_elem *head)
{
	t_elem	*curr;

	curr = head->next;
	while (curr != head)
	{
		if (curr->value < curr->prev->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	ft_is_consec(t_stack *a)
{
	if ((a->head->index == 0 && a->head->prev->index == a->imax)
		|| a->head->index == a->head->prev->index + 1)
		return (1);
	return (0);
}

int	ft_is_pushable(t_stack *a, t_elem *b)
{
	if (a->head->value == a->lowest
		&& (b->value < a->lowest || b->value > a->highest))
		return (1);
	if (b->index < a->head->index && b->index > a->head->prev->index)
		return (1);
	return (0);
}

int	ft_get_pushable(t_stack *a, t_stack b, void (*f)(t_stack*))
{
	int		i;

	i = 0;
	while (ft_is_pushable(a, b.head) == 0)
	{
		f(&b);
		i++;
	}
	return (i);
}

void	ft_do_op(t_stack *a, t_stack *b, t_op *op)
{
	if (op->a > 0 && op->b > 0)
		while (ft_min(op->a, op->b))
			ft_rr((op->a--, op->b--, a), b);
	if (op->a < 0 && op->b < 0)
		while (ft_max(op->a, op->b))
			ft_rrr((op->a++, op->b++, a), b);
	while (op->a > 0)
		ft_ra((op->a--, a));
	while (op->a < 0)
		ft_rra((op->a++, a));
	while (op->b > 0)
		ft_rb((op->b--, b));
	while (op->b < 0)
		ft_rrb((op->b++, b));
	ft_pa(a, b);
}
