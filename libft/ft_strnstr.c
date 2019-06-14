/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:39:39 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/23 14:48:27 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*to_search;

	i = 0;
	to_search = (char *)haystack;
	if (!needle[i])
		return (to_search);
	while (to_search[i] && i < len)
	{
		j = 0;
		while (to_search[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return (to_search + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
