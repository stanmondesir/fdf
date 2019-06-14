/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:11:11 by sdelvenn          #+#    #+#             */
/*   Updated: 2019/01/03 13:47:41 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL &&
			(new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		while (s1[i])
		{
			new_str[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			new_str[i + j] = s2[j];
			j++;
		}
		return (new_str);
	}
	return (NULL);
}
