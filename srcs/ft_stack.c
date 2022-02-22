/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:03:04 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/22 14:06:02 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack *stack)
{
	if (stack->head)
		stack->head = stack->head->next;
}

void	ft_rrotate(t_stack *stack)
{
	if (stack->head)
		stack->head = stack->head->prev;
}

void	ft_add_back(t_stack *stack, t_elem *elem)
{
	if (elem == NULL)
		return ;
	if (stack->size == 0)
	{
		elem->prev = elem;
		elem->next = elem;
		stack->head = elem;
	}
	else
	{
		elem->prev = stack->head->prev;
		elem->next = stack->head;
		stack->head->prev->next = elem;
		stack->head->prev = elem;
	}
	stack->size++;
	if (stack->size == 1)
	{
		stack->highest = elem->value;
		stack->lowest = elem->value;
	}
	if (elem->value > stack->highest)
		stack->highest = elem->value;
	if (elem->value < stack->lowest)
		stack->lowest = elem->value;
}

void	ft_add_front(t_stack *stack, t_elem *elem)
{
	ft_add_back(stack, elem);
	ft_rrotate(stack);
}

int	ft_add_new_elem(t_stack *stack, int value)
{
	t_elem	*elem;

	elem = ft_calloc(1, sizeof(*elem));
	if (elem == NULL)
		return (0);
	elem->value = value;
	ft_add_back(stack, elem);
	return (1);
}
