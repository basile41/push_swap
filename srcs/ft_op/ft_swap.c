/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:44:45 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/11 19:43:31 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sa(t_stack *a)
{
	ft_swap(a);
	ft_putendl("sa");
}

void	ft_sa(t_stack *b)
{
	ft_swap(b);
	ft_putendl("sb");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putendl("ss");
}
