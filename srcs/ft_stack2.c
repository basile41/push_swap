/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:32:30 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/10 20:56:31 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		ft_printf(" %d\n", curr->value);
		curr = curr->next;
		i++;
	}
	ft_putendl("");
}
