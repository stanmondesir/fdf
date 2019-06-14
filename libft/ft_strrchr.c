/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:08:18 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/23 14:26:29 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tosearch;
	char	tofind;
	char	*lastfound;
	int		i;

	tosearch = (char *)s;
	tofind = (char)c;
	lastfound = NULL;
	i = 0;
	while (tosearch[i])
	{
		if (tosearch[i] == tofind)
			lastfound = tosearch + i;
		i++;
	}
	if (tosearch[i] == tofind)
		lastfound = tosearch + i;
	return (lastfound);
}
