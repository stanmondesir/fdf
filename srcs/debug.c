/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <smondesi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:23:42 by smondesi          #+#    #+#             */
/*   Updated: 2019/10/01 15:52:55 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	print_array(int *array, int size)
{
	int i;

	i = 0;
	ft_putchar('[');
	while (i < size)
	{
		ft_putnbr(array[i]);
		if (i < size - 1)
			ft_putstr(", ");
		i++;
	}
	ft_putendl("]");
}

void	print_map(t_row *row)
{
	t_row *cpy;

	cpy = row;
	while (cpy != NULL)
	{
		print_array(cpy->content, cpy->len);
		cpy = cpy->next;
	}
}
