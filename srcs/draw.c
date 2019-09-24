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

static void parallel(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;
	float cte;

	cte = 0.9;
	previous_x = *x;
	previous_y = *y;
	*x = previous_x + cte * z;
	*y = previous_y - (cte/2) * z;
}

Pixel	get_pixel(t_fdf *fdf, t_row *row,int x, int y)
{
	Pixel point;
	int i;

	i = 0;
	point.x = (x * fdf->spacing);
	point.y = (y * fdf->spacing);
	point.z = row->content[x] * fdf->amplify;
	if (fdf-> mode == 0)
		iso(&point.x, &point.y, point.z);
	else if (fdf -> mode == 1)
		parallel(&point.x, &point.y, point.z);
	point.color = get_color(16777215 - (point.z * pow(75, 3)));
	point.x += fdf->x_offset;
	point.y += fdf->y_offset;
	return (point);
}

void put_grid(t_fdf *fdf)
{
	Pixel curr;
	Pixel next;
	Pixel bottom;
	t_row *cpy;

	cpy = fdf->map->row;
	fdf->y = 0;
	while (cpy != NULL)
	{
		fdf->x = 0;
		while (fdf->x < cpy->len)
		{
			curr = get_pixel(fdf, cpy, fdf->x, fdf->y);
			if (fdf->x + 1< cpy->len)
				next = get_pixel(fdf, cpy, fdf->x + 1, fdf->y);
			if (cpy->next != NULL)
				bottom = get_pixel(fdf, cpy->next, fdf->x, fdf->y + 1);
			if (cpy->next == NULL)
			{
				if (fdf->x != cpy->len - 1)
					draw_line(fdf, curr, next);
			}
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
