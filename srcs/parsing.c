/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:02:56 by bregneau          #+#    #+#             */
/*   Updated: 2021/12/18 20:12:03 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	str_count(char *str, char c);

int	ft_put_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	ft_isint(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (*s == '-')
	{
		if (len > 11 || (len == 11 && ft_strncmp(s, "-2147483648", 11) > 0))
			return (0);
		s++;
	}
	else
	{
		if (*s == '+')
			s++;
		len = ft_strlen(s);
		if (len > 10 || (len == 10 && ft_strncmp(s, "2147483647", 11) > 0))
			return (0);
	}
	while (*s)
		if (ft_isdigit(*s++) == 0)
			return (0);
	return (1);
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

int	*ft_atoi_tab(int size, char **strs)
{
	int	*tab;
	int	i;
	int	j;

	tab = ft_calloc(size + 1, sizeof(*tab));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = ft_atoi(strs[i]);
		j = 0;
		while (j < i)
			if (tab[i] == tab[j++])
				return (NULL);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

int	*ft_parse_args(int argc, char **argv)
{
	int		*tab;
	int		size;
	char	**strs;

	size = argc - 1;
	if (argc == 2)
	{
		strs = ft_split_arg(&size, argv[1]);
		if (!ft_check_errors(size, strs) || size == 0)
			return (NULL);
		tab = ft_atoi_tab(size, strs);
		free(strs);
		return (tab);
	}
	if (!ft_check_errors(size, argv + 1))
		return (NULL);
	return (ft_atoi_tab(size, argv + 1));
}
