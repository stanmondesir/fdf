/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:27:30 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/23 14:39:19 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*strcpy;

	i = 0;
	if (!(strcpy = (char *)malloc(sizeof(char) * ((ft_strlen(s1) + 1)))))
		return (NULL);
	while (s1[i])
	{
		strcpy[i] = s1[i];
		i++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}
