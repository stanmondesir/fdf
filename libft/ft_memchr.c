/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:43:56 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/23 13:49:56 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scpy;
	unsigned char	ccpy;
	size_t			i;

	i = 0;
	scpy = (unsigned char *)s;
	ccpy = (unsigned char)c;
	while (i < n)
	{
		if (scpy[i] == ccpy)
			return (scpy + i);
		i++;
	}
	return (NULL);
}
