#include "../incl/fdf.h"

int		get_offset(t_fdf *fdf, t_map *map)
{
	t_row *cpy;
	int 	y;
	Pixel off_point;

	cpy = map->row;
	y = 0;
	while (cpy != NULL)
	{
		y++;
		if (cpy->next == NULL)
			break;
		cpy = cpy->next;
	}
	off_point = get_pixel(fdf, cpy, 0, y);
	return(off_point.x);
}

Color get_color(int int_color)
{
	Color 	color;

	color.b =  int_color & 255;
	color.g = (int_color >> 8) & 255;
	color.r = (int_color >> 16) & 255;

	return (color);
}

float	get_rad(int deg)
{
	float rad;

	rad = deg * M_PI / 180;
	return (rad);
}
