/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:28:17 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/19 12:21:56 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void aff(int *a)
{
	while (*a)
	{
		printf("%d\n", *a++);
	}
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;

	if (argc > 1)
	{
		a = ft_parse_args(argc, argv);
		if (!a)
			return (ft_put_error());
		b = ft_calloc(argc, sizeof(*b));
aff(a);
		free(a);
		free(b);
		return (0);
	}
	return (ft_put_error());
}
