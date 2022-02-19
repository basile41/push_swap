/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:02:56 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/19 22:37:19 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	str_count(char *str, char c);

int	ft_put_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_check_errors(int size, char **strs)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!ft_isint(strs[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**ft_split_arg(int *size, char *arg)
{
	*size = str_count(arg, ' ');
	return (ft_split(arg, ' '));
}

int	ft_fill_stack(int size, char **strs, t_stack *stack)
{
	int	*tab;
	int	i;
	int	j;

	tab = ft_calloc(size, sizeof(*tab));
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(strs[i]);
		j = 0;
		while (j < i)
			if (tab[i] == tab[j++])
				size = 0;
		ft_add_new_elem(stack, tab[i]);
		i++;
	}
	free(tab);
	return (size);
}

int	ft_parse_args(int argc, char **argv, t_stack *stack)
{
	int		size;
	char	**strs;

	size = argc - 1;
	if (argc == 2)
	{
		strs = ft_split_arg(&size, argv[1]);
		if (!ft_check_errors(size, strs) || size == 0)
			size = 0;
		size = ft_fill_stack(size, strs, stack);
		ft_free_strs(strs);
		return (size);
	}
	if (!ft_check_errors(size, argv + 1))
		return (0);
	return (ft_fill_stack(size, argv + 1, stack));
}
