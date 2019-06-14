/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:12:44 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/28 10:20:26 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		s_len;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s_len = ft_strlen(s);
		if (!(new_str = (char *)malloc(sizeof(char) * (s_len + 1))))
			return (NULL);
		new_str[s_len] = '\0';
		while (s[i])
		{
			new_str[i] = (*f)(s[i]);
			i++;
		}
		return (new_str);
	}
	return (NULL);
}
