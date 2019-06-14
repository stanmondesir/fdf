/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trmapi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:48:19 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/28 10:21:58 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	int				s_len;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		s_len = ft_strlen(s);
		if (!(new_str = (char *)malloc(sizeof(char) * (s_len + 1))))
			return (NULL);
		new_str[s_len] = '\0';
		while (s[i])
		{
			new_str[i] = (*f)(i, s[i]);
			i++;
		}
		return (new_str);
	}
	return (NULL);
}
