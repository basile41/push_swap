/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:32:30 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/11 17:42:44 by bregneau         ###   ########.fr       */
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

//A supprimer
void	ft_aff_stack(t_stack *stack)
{
	t_elem	*curr;
	int		i;

	i = 0;
	curr = stack->head;
	ft_printf("size = %d\n", stack->size);
	while (i < stack->size)
	{
		ft_printf("index : %d \tvalue : %d\n",curr->index, curr->value);
		curr = curr->next;
		i++;
	}
	ft_putendl("");
}
