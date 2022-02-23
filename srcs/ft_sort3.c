/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:27:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/23 17:44:48 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_get_cheapest1(t_stack a, t_stack b, t_op *op)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size / 2 && i < op->min)
	{
		while (ft_is_consec(&a))
			ft_rotate((i++, &a));
		j = ft_get_pushable(&a, b, ft_rotate);
		if (ft_max(i, j) < op->min)
		{
			op->min = ft_max(i, j);
			op->a = i;
			op->b = j;
		}
		ft_rotate((i++, &a));
	}
}

void	ft_get_cheapest2(t_stack a, t_stack b, t_op *op)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size / 2 && i < op->min)
	{
		while (ft_is_consec(&a))
			ft_rrotate((i++, &a));
		j = ft_get_pushable(&a, b, ft_rrotate);
		if (ft_max(i, j) < op->min)
		{
			op->min = ft_max(i, j);
			op->a = -i;
			op->b = -j;
		}
		ft_rrotate((i++, &a));
	}
}

void	ft_get_cheapest3(t_stack a, t_stack b, t_op *op)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size / 2 && i < op->min)
	{
		while (ft_is_consec(&a))
			ft_rotate((i++, &a));
		j = ft_get_pushable(&a, b, ft_rrotate);
		if (i + j < op->min)
		{
			op->min = i + j;
			op->a = i;
			op->b = -j;
		}
		ft_rotate((i++, &a));
	}
}

void	ft_get_cheapest4(t_stack a, t_stack b, t_op *op)
{
	int	i;
	int	j;

	i = 0;
	while (i < a.size / 2 && i < op->min)
	{
		while (ft_is_consec(&a))
			ft_rrotate((i++, &a));
		j = ft_get_pushable(&a, b, ft_rotate);
		if (i + j < op->min)
		{
			op->min = i + j;
			op->a = -i;
			op->b = j;
		}
		ft_rrotate((i++, &a));
	}
}

void	ft_insert_cheapest(t_stack *a, t_stack *b)
{
	t_op	op;

	op.a = a->size;
	op.b = b->size;
	op.min = op.a + op.b;
	ft_get_cheapest1(*a, *b, &op);
	ft_get_cheapest2(*a, *b, &op);
	ft_get_cheapest3(*a, *b, &op);
	ft_get_cheapest4(*a, *b, &op);
	ft_do_op(a, b, &op);
}
