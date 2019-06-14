/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelvenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:12:28 by sdelvenn          #+#    #+#             */
/*   Updated: 2018/11/28 10:03:41 by sdelvenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*newmem;

	newmem = (void *)malloc(size);
	if (!newmem)
		return (NULL);
	ft_memset(newmem, 0, size);
	return (newmem);
}
