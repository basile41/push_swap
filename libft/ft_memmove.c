/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:04:21 by bregneau          #+#    #+#             */
/*   Updated: 2021/11/29 11:31:14 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (!dst && !src)
		return (NULL);
	tmp1 = (unsigned char *)src;
	tmp2 = (unsigned char *)dst;
	i = 0;
	if (tmp1 > tmp2)
	{
		while (i < len)
		{
			tmp2[i] = tmp1[i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			tmp2[len] = tmp1[len];
	}
	return (dst);
}
