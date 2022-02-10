/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/10 20:55:09 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_aff_stack(t_stack *stack);

int	ft_push_swap(t_stack *a, t_stack *b)
{

	ft_aff_stack(a);
	ft_aff_stack(b);
	ft_rotate(b);
	ft_push(a, b);
	ft_push(a, b);
	ft_aff_stack(a);
	ft_aff_stack(b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (1);
}
