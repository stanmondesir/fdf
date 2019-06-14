/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:07:10 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/28 10:38:59 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		ch;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == ch)
			return (&d[i + 1]);
		i++;
	}
	return (NULL);
}
