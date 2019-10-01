/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smondesi <smondesi@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:23:39 by smondesi          #+#    #+#             */
/*   Updated: 2019/10/01 17:36:48 by smondesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

t_pixel		get_delta(t_pixel start, t_pixel end)
{
	t_pixel delta;

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	return (delta);
}

t_pixel		get_slope(t_pixel start, t_pixel end)
{
	t_pixel slope;

	slope.x = start.x < end.x ? 1 : -1;
	slope.y = start.y < end.y ? 1 : -1;
	return (slope);
}

void		draw_line(t_fdf *fdf, t_pixel start, t_pixel end)
{
	t_pixel	delta;
	t_pixel	slope;
	t_pixel	current;
	int		err;
	int		e2;

	delta = get_delta(start, end);
	slope = get_slope(start, end);
	current = start;
	err = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, current.x, current.y,
						get_color(current, start, end, delta));
		if (current.x == end.x && current.y == end.y)
			break ;
		e2 = err;
		if (e2 > -delta.x)
		{
			err -= delta.y;
			current.x += slope.x;
		}
		if (e2 < delta.y)
		{
			err += delta.x;
			current.y += slope.y;
		}
	}
}

static void	iso(int *x, int *y, int z, t_fdf *fdf)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(get_rad(fdf->cos));
	*y = -z + (previous_x + previous_y) * sin(get_rad(fdf->sin));
}

static void	parallel(int *x, int *y, int z)
{
	int		previous_x;
	int		previous_y;
	float	cte;

	cte = 0.9;
	previous_x = *x;
	previous_y = *y;
	*x = previous_x + cte * z;
	*y = previous_y + (cte / 2) * z;
}

t_pixel		get_pixel(t_fdf *fdf, t_row *row, int x, int y)
{
	t_pixel	point;
	int		i;

	i = 0;
	point.x = (x * fdf->spacing);
	point.y = (y * fdf->spacing);
	point.z = row->content[x] * fdf->amplify;
	if (fdf->mode == 0)
		iso(&point.x, &point.y, point.z, fdf);
	else if (fdf->mode == 1)
		parallel(&point.x, &point.y, point.z);
	set_color(fdf, &point.color, row->content[x]);
	point.x += fdf->x_offset;
	point.y += fdf->y_offset;
	return (point);
}

void		put_grid(t_fdf *fdf)
{
	t_pixel curr;
	t_pixel next;
	t_pixel bottom;
	t_row	*cpy;

	cpy = fdf->map->row;
	fdf->y = 0;
	while (cpy != NULL)
	{
		fdf->x = 0;
		while (fdf->x < cpy->len)
		{
			curr = get_pixel(fdf, cpy, fdf->x, fdf->y);
			if (fdf->x + 1 < cpy->len)
				next = get_pixel(fdf, cpy, fdf->x + 1, fdf->y);
			if (cpy->next != NULL)
				bottom = get_pixel(fdf, cpy->next, fdf->x, fdf->y + 1);
			if (cpy->next == NULL && (fdf->x != cpy->len - 1))
				draw_line(fdf, curr, next);
			else if (fdf->x == cpy->len - 1)
				draw_line(fdf, curr, bottom);
			else
			{
				draw_line(fdf, curr, next);
				draw_line(fdf, curr, bottom);
			}
			fdf->x++;
		}
		fdf->y++;
		cpy = cpy->next;
	}
}
