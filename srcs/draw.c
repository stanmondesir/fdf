#include "../incl/fdf.h"



void draw_line(t_fdf fdf, Pixel start, Pixel end)
{
	Pixel delta;
	Pixel slope;
	int err;
	int e2;

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	slope.x = start.x < end.x ? 1 : -1;
	slope.y = start.y < end.y ? 1 : -1;
	err = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (1)
	{
		mlx_pixel_put(fdf.mlx, fdf.win, start.x, start.y, 6345184);
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
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

int get_spacing(t_map *map)
{
	int height;
	int width;
	int spacing;

	height = get_height(map);
	width = map->row.len;
	spacing = 1920/width - 24;
	printf("SPACING : %d\n", spacing);
	printf("width : %d\n", width);

	return (spacing);
}

Pixel	get_pixel(t_map *map, int x, int y, int offset)
{
	Pixel point;
	int i;
	t_map *cpy;
	static int spacing;

	if (spacing == 0)
		spacing = get_spacing(map);
	i = 0;
	cpy = map;
	point.x = (x * spacing);
	point.y = (y * spacing);
	while (i < y)
	{
		cpy = cpy->next;
		i++;
	}
	point.z = cpy->row.content[x] * 5;
	iso(&point.x, &point.y, point.z);
	point.color = get_color(16777215 - (point.z * pow(75, 3)));
	point.x += offset + 1;
	point.y += 0;
	return (point);
}

void put_grid(t_fdf fdf, t_map *map)
{
	int x;
	int y;
	Pixel curr;
	Pixel next;
	Pixel bottom;
	t_map *head;
	int offset;
	Pixel off_point;

	head = map;
	y = 0;
	off_point = get_pixel(head, 0, get_height(map) - 1, 0);
	offset = abs(off_point.x);
	while (map != NULL)
	{
		x = 0;
		while (x < map->row.len)
		{
			curr = get_pixel(head, x, y, offset);
			next = get_pixel(head, x + 1, y, offset);
			if (map->next != NULL)
				bottom = get_pixel(head, x, y + 1, offset);
			if (map->next == NULL)
			{
				if (x != map->row.len - 1)
					draw_line(fdf, curr, next);
			}
			else if (x == map->row.len - 1)
				draw_line(fdf, curr, bottom);
			else
			{
				draw_line(fdf, curr, next);
				draw_line(fdf, curr, bottom);
			}
			x++;
		}
		y++;
		map = map->next;
	}
}
