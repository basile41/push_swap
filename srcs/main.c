/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:28:17 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/19 22:36:04 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	ft_bzero(&a, sizeof(a));
	ft_bzero(&b, sizeof(b));
	if (argc > 1)
	{
		if (ft_parse_args(argc, argv, &a) == 0)
		{
			ft_free_stack(&a);
			return (ft_put_error());
		}
		ft_push_swap(&a, &b);
		ft_free_stack(&a);
		ft_free_stack(&b);
		return (0);
	}
	return (0);
}
