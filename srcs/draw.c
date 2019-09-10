#include "../incl/fdf.h"

Pixel get_delta(Pixel start, Pixel end)
{
	Pixel delta;

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	return (delta);
}

Pixel get_slope(Pixel start, Pixel end)
{
	Pixel slope;

	slope.x = start.x < end.x ? 1 : -1;
	slope.y = start.y < end.y ? 1 : -1;
	return (slope);
}

void draw_line(t_fdf *fdf, Pixel start, Pixel end)
{
	Pixel delta;
	Pixel slope;
	int err;
	int e2;

	delta = get_delta(start, end);
	slope = get_slope(start, end);
	err = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, start.x, start.y, 6345184);
		if (start.x == end.x && start.y == end.y)
		break;
		e2 = err;
		if (e2 > -delta.x)
		{
			err -= delta.y;
			start.x += slope.x;
		}
		if (e2 < delta.y)
		{
			err += delta.x;
			start.y += slope.y;
		}
	}
}

static void iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(get_rad(30));
	*y = -z + (previous_x + previous_y) * sin(get_rad(30));
}

Pixel	get_pixel(t_fdf *fdf, int x, int y)
{
	Pixel point;
	int i;
	t_map *cpy;

	i = 0;
	cpy = fdf->map;
	point.x = (x * fdf->spacing);
	point.y = (y * fdf->spacing);
	while (i < y)
	{
		cpy = cpy->next;
		i++;
	}
	point.z = cpy->row.content[x] * 5;
	iso(&point.x, &point.y, point.z);
	point.color = get_color(16777215 - (point.z * pow(75, 3)));
	point.x += fdf->x_offset;
	point.y += fdf->y_offset;
	return (point);
}

void put_grid(t_fdf *fdf)
{
	int x;
	int y;
	Pixel curr;
	Pixel next;
	Pixel bottom;
	t_map *cpy;

	cpy = fdf->map;
	y = 0;
	while (cpy != NULL)
	{
		x = 0;
		while (x < cpy->row.len)
		{
			curr = get_pixel(fdf, x, y);
			next = get_pixel(fdf, x + 1, y);
			if (cpy->next != NULL)
				bottom = get_pixel(fdf, x, y + 1);
			if (cpy->next == NULL)
			{
				if (x != cpy->row.len - 1)
					draw_line(fdf, curr, next);
			}
			else if (x == cpy->row.len - 1)
				draw_line(fdf, curr, bottom);
			else
			{
				draw_line(fdf, curr, next);
				draw_line(fdf, curr, bottom);
			}
			x++;
		}
		y++;
		cpy = cpy->next;
	}
}
