/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:57:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/23 17:44:12 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_3(t_stack *a)
{
	if (a->size > 3)
		return ;
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
	t_elem	*min;

	while (b->size < n && a->size > 3)
	{
		min = a->head;
		while (min->value != a->lowest)
			min = min->next;
		if (ft_is_sorted(min))
			return ;
		if (a->head->index <= n)
			ft_pb(a, b);
		else
			ft_ra(a);
		if (b->head && a->head->index == a->head->next->index + 1
			&& b->head->index == b->head->next->index - 1)
			ft_ss(a, b);
	}
}

void	ft_final_rot(t_stack *a, t_stack copy)
{
	int	i;

	i = 0;
	while (copy.head->index != 0)
		ft_rotate((i++, &copy));
	if (a->size - i < i)
		while (i++ < a->size)
			ft_rra(a);
	else
		while (i--)
			ft_ra(a);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size > 25)
		ft_push_inf_n(a, b, a->size / 2);
	ft_push_inf_n(a, b, (a->imax + 1));
	ft_sort_3(a);
	while (b->head)
		ft_insert_cheapest(a, b);
	ft_final_rot(a, *a);
}
