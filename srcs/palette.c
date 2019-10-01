/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <smondesi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:46:34 by smondesi          #+#    #+#             */
/*   Updated: 2019/10/01 14:46:46 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	set_color(t_fdf *fdf, int *color, int z)
{
	double percentage;

	if (z >= 0)
		percentage = (double)z / (double)fdf->map->max_height;
	else
		percentage = (double)z / (double)fdf->map->min_height;
	if (fdf->palette == 0)
	{
		if (z == 0)
			*color = get_int_color(0, 255, 0);
		else if (z < 0)
			*color = get_int_color(0, 255 * (1.0 - percentage), 255);
		else
			*color = get_int_color(255 * (percentage), 255 *
				(1.0 - percentage), 0);
	}
	else if (fdf->palette == 1)
	{
		*color = get_int_color(255 *
				(1.0 - percentage), 255 * (percentage), 255);
	}
}
