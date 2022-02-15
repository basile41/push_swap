/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:57:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/15 19:16:29 by bregneau         ###   ########.fr       */
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

	curr = NULL;
	while (get_next(a->head, curr))
	{
		if (curr->index < n)
			ft_pb(a, b);
	}
}


void	ft_sort(t_stack *a, t_stack *b)
{
	int	med;

	med = a->size / 2;
	if (a->size > 7)
	{
		ft_push_med()
	}
}
