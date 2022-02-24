/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:32:30 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/24 22:01:09 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_elem	*elem;

	if (stack->size < 2)
		return ;
	elem = stack->head;
	ft_sup_first_elem(stack);
	ft_rotate(stack);
	ft_add_front(stack, elem);
	ft_rrotate(stack);
}

void	ft_push(t_stack *src, t_stack *dst)
{
	t_elem	*elem;

	if (src->size < 1)
		return ;
	elem = src->head;
	ft_sup_first_elem(src);
	ft_add_front(dst, elem);
}

void	ft_set_min_max(t_stack *stack)
{
	t_elem	*curr;

	stack->highest = stack->head->value;
	stack->lowest = stack->head->value;
	curr = stack->head->next;
	while (curr != stack->head)
	{
		if (curr->value > stack->highest)
			stack->highest = curr->value;
		if (curr->value < stack->lowest)
			stack->lowest = curr->value;
		curr = curr->next;
	}
}

void	ft_sup_first_elem(t_stack *stack)
{
	int		value;

	value = stack->head->value;
	if (stack->size == 1)
		ft_bzero(stack, sizeof(*stack));
	if (stack->size == 0)
		return ;
	stack->head->next->prev = stack->head->prev;
	stack->head->prev->next = stack->head->next;
	stack->head = stack->head->next;
	stack->size--;
	if (value == stack->highest || value == stack->lowest)
		ft_set_min_max(stack);
}

void	ft_free_stack(t_stack *stack)
{
	t_elem	*elem;

	while (stack->size)
	{
		elem = stack->head;
		ft_sup_first_elem(stack);
		free(elem);
	}
	stack->head = NULL;
	stack->size = 0;
}
