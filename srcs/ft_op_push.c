/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:34:45 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/17 15:59:22 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	ft_putendl("pa");
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	ft_putendl("pb");
}
