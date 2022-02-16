/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:57:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/16 18:34:31 by bregneau         ###   ########.fr       */
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

void	ft_sort_2(t_stack *a)
{
	if (a->head->value > a->head->next->value)
		ft_sa(a);
}

void	ft_sort_3(t_stack *a)
{
	if (a->head->value > a->head->next->value
		&& a->head->value > a->head->prev->value)
		ft_ra(a);
	if (a->head->next->value > a->head->prev->value
		&& a->head->next->value > a->head->prev->value)
		ft_rra(a);
	if (a->head->value > a->head->next->value)
		ft_sa(a);
}

void	ft_push_inf_n(t_stack *a, t_stack *b, int n)
{
	t_elem	*curr;

	while (b->size < n)
	{
		curr = a->head;
		if (curr->index < n)
			ft_pb(a, b);
		else
			ft_ra(a);
	}
}

void	ft_insert(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		if (b->head->index < a->head->index
			&& (b->head->index > a->head->prev->index
				|| a->head->prev->index == (a->size + b->size -1)))
			ft_pa(a, b);
		else
			ft_ra(a);
	}
	while (a->head->index != 0)
	{
		ft_rra(a);
	}
}

void	ft_sort(t_stack *a, t_stack *b)
{
	// ft_push_inf_n(a, b, a->size / 2);
	ft_push_inf_n(a, b, (a->size + b->size - 3));
	ft_sort_3(a);
	ft_insert(a, b);
}
