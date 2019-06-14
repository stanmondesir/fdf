/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:31:02 by sdelvenn          #+#    #+#             */
/*   Updated: 2019/01/03 13:51:32 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charcheck(char c)
{
	if (c == '\0' || c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

static char	*trim(char const *s)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		if (!(new_str = ft_strnew(0)))
			return (NULL);
		return (new_str);
	}
	while (s[i + j])
		j++;
	while (charcheck(s[i + j]))
		j--;
	if (!(new_str = ft_strnew((j += 1))))
		return (NULL);
	while (j--)
		new_str[j] = s[i + j];
	return (new_str);
}

char		*ft_strtrim(char const *s)
{
	if (s != NULL)
		return (trim(s));
	return (NULL);
}
