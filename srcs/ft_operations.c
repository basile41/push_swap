/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:50:51 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/10 20:39:09 by bregneau         ###   ########.fr       */
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
