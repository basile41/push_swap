/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:19:58 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/29 14:40:23 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

void	ft_add_new_elem(t_stack *stack, int value)
{
	t_elem	*elem;

	elem = malloc(sizeof(*elem));
	if (elem == NULL)
		return ;
	elem->value = value;
	ft_add_elem(stack, elem);
}

void	ft_add_elem(t_stack *stack, t_elem *elem)
{
	elem->next = stack->head;
	elem->prev = stack->head->prev;
	stack->head->prev->next = elem;
	stack->head->next->prev = elem;
	stack->head = elem;
	stack->size++;
}

void	ft_sup_first_elem(t_stack *stack)
{
	if (stack->size)
	{
		stack->head->next->prev = stack->head->prev;
		stack->head->prev->next = stack->head->next;
		stack->head = stack->head->next;
		stack->size--;
	}
}
