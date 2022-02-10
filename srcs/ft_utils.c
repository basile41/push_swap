/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:43:30 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/10 17:49:36 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (*s == '\0')
		return (0);
	while (*s)
		if (ft_isdigit(*s++) == 0)
			return (0);
	return (1);
}
