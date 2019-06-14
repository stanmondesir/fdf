/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:31:11 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/28 10:17:20 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	int					i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst > src)
	{
		len--;
		while ((int)len >= 0)
		{
			d[len] = s[len];
			len--;
		}
		return (d);
	}
	while (i < (int)len)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
