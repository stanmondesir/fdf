/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <smondesi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:23:11 by smondesi          #+#    #+#             */
/*   Updated: 2019/10/01 17:03:47 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

int		get_offset(t_fdf *fdf, t_map *map)
{
	t_row	*cpy;
	int		y;
	t_pixel	off_point;

	cpy = map->row;
	y = 0;
	while (cpy != NULL)
	{
		y++;
		if (cpy->next == NULL)
			break ;
		cpy = cpy->next;
	}
	off_point = get_pixel(fdf, cpy, 0, y);
	return (off_point.x);
}

int		get_int_color(int red, int green, int blue)
{
	return ((red & 0x0ff) << 16) | ((green & 0x0ff) << 8) | (blue & 0x0ff);
}

float	get_rad(int deg)
{
	float rad;

	rad = deg * M_PI / 180;
	return (rad);
}
