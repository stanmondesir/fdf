/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:08:18 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/23 14:14:23 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tosearch;
	char	tofind;
	int		i;

	tosearch = (char *)s;
	tofind = (char)c;
	i = 0;
	while (tosearch[i])
	{
		if (tosearch[i] == tofind)
			return (tosearch + i);
		i++;
	}
	if (tosearch[i] == tofind)
		return (tosearch + i);
	return (NULL);
}
