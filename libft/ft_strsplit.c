/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:07:03 by sdelvenn          #+#    #+#             */
/*   Updated: 2019/01/15 11:03:37 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_len(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static int	count_words(char const *str, char c)
{
	int wordscount;
	int i;

	i = 0;
	wordscount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && i != 0)
		{
			if (str[i - 1] != c)
				wordscount++;
		}
		i++;
	}
	if (str[i - 1] != c)
		wordscount++;
	return (wordscount);
}

static char	**free_array(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**split(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!(words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(words[j] = ft_strnew(word_len(&s[i], c))))
				return (free_array(words, i));
			k = -1;
			while (s[i] != c && s[i] != '\0')
				words[j][++k] = s[i++];
			j++;
		}
		else
			i++;
	}
	words[j] = NULL;
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;

	if (s != NULL)
	{
		if ((res = split(s, c)))
			return (res);
	}
	return (NULL);
}
