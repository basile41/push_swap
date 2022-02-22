/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:57:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/22 20:17:21 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_sort_3(t_stack *a)
{
	if (a->size > 3)
		return ;
	if (a->head->value > a->head->next->value
		&& a->head->value > a->head->prev->value)
		ft_ra(a);
	if (a->head->next->value > a->head->prev->value
		&& a->head->next->value > a->head->prev->value)
		ft_rra(a);
	if (a->head->value > a->head->next->value)
		ft_sa(a);
}

void	ft_push_inf_n(t_stack *a, t_stack *b, int n)
{
	t_elem	*min;

	while (b->size < n && a->size > 3)
	{
		min = a->head;
		while (min->value != a->lowest)
			min = min->next;
		//ft_aff_stack(a);
		if (ft_is_sorted(min))
			return ;
		if (a->head->index <= n)
			ft_pb(a, b);
		else
			ft_ra(a);
		if (b->head && a->head->index == a->head->next->index + 1
			&& b->head->index == b->head->next->index - 1)
			ft_ss(a, b);
	}
}

int	ft_is_consec(t_stack *a)
{
	if ((a->head->index == 0 && a->head->prev->index == a->imax)
		|| a->head->index == a->head->prev->index + 1)
		return (1);
	return (0);
}

int	ft_is_pushable(t_stack *a, t_elem *b)
{
	if (a->head->value == a->lowest
		&& (b->value < a->lowest || b->value > a->highest))
		return (1);
	if (b->index < a->head->index && b->index > a->head->prev->index)
		return (1);
	return (0);
}

int	ft_get_pushable(t_stack *a, t_stack b, void (*f)(t_stack*))
{
	int		i;

	i = 0;
	while (ft_is_pushable(a, b.head) == 0)
	{
		f(&b);//rotate or rrotate
		i++;
	}
	return (i);
}

void	ft_do_op(t_stack *a, t_stack *b, t_op *op)
{
	//ft_printf("a = %d, b = %d, min = %d\n", op->a, op->b, op->min);
	if (op->a > 0 && op->b > 0)
		while (ft_min(op->a, op->b))
			ft_rr((op->a--, op->b--, a), b);
	if (op->a < 0 && op->b < 0)
		while (ft_max(op->a, op->b))
			ft_rrr((op->a++, op->b++, a), b);
	while (op->a > 0)
		ft_ra((op->a--, a));
	while (op->a < 0)
		ft_rra((op->a++, a));
	while (op->b > 0)
		ft_rb((op->b--, b));
	while (op->b < 0)
		ft_rrb((op->b++, b));
	ft_pa(a, b);
	//ft_aff_stack(b);
	//ft_aff_stack(a);
}

void	ft_insert_cheapest(t_stack *a, t_stack *b)
{
	t_elem	*head;
	int		i;
	int		j;
	t_op	op;

	op.a = a->size;
	op.b = b->size;
	op.min = op.a + op.b;
	head = a->head;
	i = 0;
	while (i < a->size / 2 && i < op.min)
	{
		while (ft_is_consec(a))
			ft_rotate((i++, a));
		j = ft_get_pushable(a, *b, ft_rotate);
		if (ft_max(i, j) < op.min)
		{
			op.min = ft_max(i, j);
			op.a = i;
			op.b = j;
		}
		ft_rotate((i++, a));
	}
	a->head = head;
	i = 0;
	while (i < a->size / 2 && i < op.min)
	{
		while (ft_is_consec(a))
			ft_rrotate((i++, a));
		j = ft_get_pushable(a, *b, ft_rrotate);
		if (ft_max(i, j) < op.min)
		{
			op.min = ft_max(i, j);
			op.a = -i;
			op.b = -j;
		}
		ft_rrotate((i++, a));
	}
	a->head = head;
	i = 0;
	while (i < a->size / 2 && i < op.min)
	{
		while (ft_is_consec(a))
			ft_rotate((i++, a));
		j = ft_get_pushable(a, *b, ft_rrotate);
		if (i + j < op.min)
		{
			op.min = i + j;
			op.a = i;
			op.b = -j;
		}
		ft_rotate((i++, a));
	}
	a->head = head;
	i = 0;
	while (i < a->size / 2 && i < op.min)
	{
		while (ft_is_consec(a))
			ft_rrotate((i++, a));
		j = ft_get_pushable(a, *b, ft_rotate);
		if (i + j < op.min)
		{
			op.min = i + j;
			op.a = -i;
			op.b = j;
		}
		ft_rrotate((i++, a));
	}
	a->head = head;
	ft_do_op(a, b, &op);
}

void	ft_final_rot(t_stack *a, t_stack copy)
{
	int	i;

	i = 0;
	while (copy.head->index != 0)
		ft_rotate((i++, &copy));
	if (a->size - i < i)
		while (i++ < a->size)
			ft_rra(a);
	else
		while (i--)
			ft_ra(a);
}

void	ft_sort(t_stack *a, t_stack *b)
{
	// if (ft_is_sorted(a->head))
	// 	return ;
	if (a->size > 25)
		ft_push_inf_n(a, b, a->size / 2);
	ft_push_inf_n(a, b, (a->imax + 1));
	ft_sort_3(a);
	while (b->head)
		ft_insert_cheapest(a, b);
	ft_final_rot(a, *a);
}
