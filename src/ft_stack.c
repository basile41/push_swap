/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:19:58 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/29 15:36:37 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}

int	ft_add_new_elem(t_stack *stack, int value)
{
	t_elem	*elem;

	elem = ft_calloc(1, sizeof(*elem));
	if (elem == NULL)
		return (0);
	elem->value = value;
	ft_add_elem(stack, elem);
	return (1);
}

void	ft_add_elem(t_stack *stack, t_elem *elem)
{
	if (stack->size == 0)
	{
		elem->prev = elem;
		elem->next = elem;
	}
	else
	{
		elem->next = stack->head;
		elem->prev = stack->head->prev;
		stack->head->prev->next = elem;
		stack->head->next->prev = elem;
	}
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

ft_free_stack(t_stack *stack)
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
