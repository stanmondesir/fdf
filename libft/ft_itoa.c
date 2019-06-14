/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:57:20 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/28 10:33:13 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nblen(long nb)
{
	int len;

	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static int	is_negative(long nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;
	int		sign;

	len = 0;
	sign = 0;
	nbr = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	if ((sign = is_negative(nbr)))
		nbr = -nbr;
	len += nblen(nbr) + sign;
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (sign)
		str[0] = '-';
	while (len-- > sign)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
