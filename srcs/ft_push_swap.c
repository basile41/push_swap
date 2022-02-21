/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/21 16:35:37 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_push_swap(t_stack *a, t_stack *b)
{
	ft_set_index(a);
	ft_sort(a, b);
	ft_aff_stack(a);
	return (1);
}
