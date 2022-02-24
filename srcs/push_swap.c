/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:24:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/24 17:56:35 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		ft_sort(&a, &b);
		ft_free_stack(&a);
		ft_free_stack(&b);
	}
	return (0);
}
