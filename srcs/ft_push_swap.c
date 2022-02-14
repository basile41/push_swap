/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/14 16:33:56 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_aff_stack(t_stack *stack);

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

void ft_sort_7(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		if (a->head->index > 2)
			ft_pb(a, b);
		else
			ft_ra(a);
	}
	ft_sort_3(a);
}

int	ft_push_swap(t_stack *a, t_stack *b)
{
	ft_set_index(a);
	if (a->size > 6)
	{
		ft_sort(a, b);
	}
	return (1);
}
