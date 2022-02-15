/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/15 21:01:09 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_aff_stack(t_stack *stack);
void	ft_sort_2(t_stack *a);
void	ft_sort_3(t_stack *a);


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
}

int	ft_push_swap(t_stack *a, t_stack *b)
{
	ft_set_index(a);
	ft_sort(a, b);
	return (1);
}
