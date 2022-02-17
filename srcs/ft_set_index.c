/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:03:16 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/17 18:04:56 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_elem	*ft_get_next_min(t_stack *stack, int n)
{
	int		min;
	t_elem	*elem;
	t_elem	*curr;

	elem = stack->head;
	curr = stack->head->next;
	min = INT_MAX;
	if (stack->head->value > n)
		min = stack->head->value;
	while (curr != stack->head)
	{
		if (curr->value < min && curr->value > n)
		{
			min = curr->value;
			elem = curr;
		}
		curr = curr->next;
	}
	return (elem);
}

void	ft_set_index(t_stack *stack)
{
	t_elem	*elem;
	int		i;

	elem = ft_get_next_min(stack, INT_MIN);
	elem->index = 0;
	i = 1;
	while (i < stack->size)
	{
		elem = ft_get_next_min(stack, elem->value);
		elem->index = i;
		i++;
	}
	stack->imax = i - 1;
}
