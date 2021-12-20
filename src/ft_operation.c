/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:00 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/20 16:31:31 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *s)
{
	int tmp;

	if (s->size >= 2)
	{
		tmp = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = tmp;
	}
}

void	ft_push(t_stack *src, t_stack *dst)
{
	ft_memmove(dst->stack + 1, dst->stack, dst->size);
	dst->stack[0] = src->stack[0];
	ft_memmove(src->stack, src->stack + 1, src->size);
	src->size--;
	dst->size++;
}

void	ft_rotate(t_satck *s)
{
	int	tmp;

	tmp = s->stack[0];
	ft_memmove(s->stack, s->stack + 1, s->size);
	s->stack[s->size - 1] = tmp;
}

void	ft_rev_rot(t_stack)
{
	int tmp;

	tmp = s->stack[s->size - 1];
	ft_memmove(s->stack + 1, s->stack, s->size - 1);
	s->stack[0] = tmp;
}
