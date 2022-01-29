/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:31:00 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/29 12:18:59 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_elem	*tmp;
	t_elem	*e1;
	t_elem	*e2;

	e1 = stack->head;
	e2 = stack->head->next;
	tmp->prev = e1->prev;
	tmp->next = e1->next;
	e1->prev = e2->prev;
	e1->next = e2->next;
	e2->prev = tmp->prev;
	e2->next = tmp->next;

}

void	ft_push()
{
}

void	ft_rotate()
{
}

void	ft_rev_rot()
{
}