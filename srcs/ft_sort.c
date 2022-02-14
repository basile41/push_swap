/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:57:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/14 17:12:35 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_is_sorted(t_stack *stack)
{
	t_elem	*next;

	next = stack->head->next;
	while (next != stack->head)
	{
		
	}
}

void	ft_sort_2(t_stack *a)
{
	if (a->head->index == 1)
		ft_putendl("sa");
}

void	ft_sort_3(t_stack *a)
{
	if (a->head->index == 2)
		ft_ra(a);
	if (a->head->next->index == 2)
		ft_rra(a);
	if (a->head->index == 1)
		ft_sa(a);
}

void	ft_insert(t_stack *a, t_stack *b)
{
	
}

void	ft_push_half

void	ft_sort(t_stack *a, t_stack *b)
{
	int	med;

	med = a->size / 2;
	if (a->size > 7)
	{
		ft_push_med()
	}
}
