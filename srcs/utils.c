#include "../incl/fdf.h"

int 	get_height(t_map *map)
{
	int height;
	t_map *cpy;

	cpy = map;
	height = 0;
	while (cpy != NULL)
	{
		height++;
		cpy = cpy->next;
	}
	return (height);
}

Color get_color(int int_color)
{
	Color 	color;

	color.b =  int_color & 255;
	color.g = (int_color >> 8) & 255;
	color.r = (int_color >> 16) & 255;

	return (color);
}
