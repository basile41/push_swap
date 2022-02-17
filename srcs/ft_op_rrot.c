/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_rrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:38:34 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/17 15:59:02 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack *a)
{
	ft_rrotate(a);
	ft_putendl("rra");
}

void	ft_rrb(t_stack *b)
{
	ft_rrotate(b);
	ft_putendl("rrb");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rrotate(a);
	ft_rrotate(b);
	ft_putendl("rrr");
}
