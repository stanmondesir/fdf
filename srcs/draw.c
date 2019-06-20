#include "../incl/fdf.h"

void draw_line(t_fdf fdf, Pixel start, Pixel end)
{
	int x,y,dx,dy,dx1,dy1,px,py,xe,ye;
	dx = end.x - start.x;
	dy = end.y - start.y;
	dx1 = abs(dx);
	dy1 = abs(dy);
	px = 2 * dy1 - dx1;
	py = 2 * dx1 - dy1;
	if (dy1<=dx1)
	{
		if (dx>=0)
		{
			x= start.x;
			y= start.y;
			xe= end.x;
		}
		else
		{
			x = end.x;
			y = end.y;
			xe = start.x;
		}
		mlx_pixel_put(fdf.mlx, fdf.win, x, y, 16777215);
		while(x<xe)
		{
			x++;
			if(px<0)
				px=px+2*dy1;
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
					y=y+1;
				else
					y=y-1;
				px=px+2*(dy1-dx1);
			}
			mlx_pixel_put(fdf.mlx, fdf.win, x, y, 16777215);
		}
	}
	else
	{
		if(dy>=0)
		{
			x = start.x;
			y = start.y;
			ye = end.y;
		}
		else
		{
			x = end.x;
			y = end.y;
			ye = start.y;
		}
		mlx_pixel_put(fdf.mlx, fdf.win, x, y, 16777215);
		while(y<ye)
		{
			y++;
			if(py<=0)
				py=py+2*dx1;
			else
			{
				if((dx<0 && dy<0) || (dx>0 && dy>0))
					x=x+1;
				else
					x=x-1;
				py=py+2*(dx1-dy1);
			}
			mlx_pixel_put(fdf.mlx, fdf.win, x, y, 16777215);
		}
	}
}

/*
x formula : X Offset + (X position * Spacing value)
y formula : Y offset + (Y position * Spacing value) - (Height * Height amplifier)
*/
//With rotate
/*
void put_grid(t_fdf fdf, t_map *map)
{
	int i;
	int j = 0;
	int off_x = 400;
	int off_y = 400;
	int space = 12;

	while (map != NULL)
	{
		i = 0;
		while (i < map->row.len)
		{
			//If we are at the end of the row
			if (i == map->row.len - 1 && map->next != NULL)
			{
				draw_line(fdf, off_x + ((i-j)*space), off_y + ((j+i)*space) - (map->row.content[i] * 3), off_x + ((i - j - 1)*space), off_y + ((j+i + 1)*space) - (map->next->row.content[i] * 3), 16777215 - map->next->row.content[i] * 50);
				//Only join with the bottom point
			}
			//If we are on the last row
			else if (map->next == NULL)
			{
				if (i == map->row.len - 1)
					return ;
				draw_line(fdf, off_x + ((i-j)*space), off_y + ((j+i)*space) - (map->row.content[i] * 3), off_x + ((i+1 - j)*space), off_y + ((j+i + 1)*space) - (map->row.content[i + 1] * 3), 16777215);
				//Only join with right point, don't do it for the last one
			}
			else
			{
				printf("Start : (%d, %d)\n", off_x + (i*space), off_y + (j*space) - (map->row.content[i] * 3));
				printf("End : (%d, %d)\n", off_x + ((i+1)*space), off_y + (j*space) - (map->row.content[i + 1] * 3));
				//Connect current point with the next point
				draw_line(fdf, off_x + ((i-j)*space), off_y + ((j+i)*space) - (map->row.content[i] * 3), off_x + ((i+1 - j)*space), off_y + ((j+i + 1)*space) - (map->row.content[i + 1] * 3), 16777215);
				//Connect current point with the bottom point
				draw_line(fdf, off_x + ((i-j)*space), off_y + ((j+i)*space) - (map->row.content[i] * 3), off_x + ((i - j - 1)*space), off_y + ((j+i + 1)*space) - (map->next->row.content[i] * 3), 16777215 - map->next->row.content[i] * 50);
				//draw_line(fdf, off_x + (i*space), off_y + (j*space), off_x + ((i+1)*space), off_y + (j*space));
			}
			//mlx_pixel_put(fdf.mlx, fdf.win, off_x + (i*space), off_y + (j*space) - (map->row.content[i] * 3), 16777215 - map->row.content[i] * 50);
			i++;
		}
		j++;
		map = map->next;
	}
}
*/

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

Pixel	get_pixel(t_map *map, int x, int y)
{
	Pixel point;
	int i;
	t_map *cpy;

	i = 0;
	cpy = map;
	point.x = (x * SPACING) + 600;
	point.y = (y * SPACING) - 250 ;
	//printf("Get pixel : x : %d y : %d\n",x, y);
	//printf("After iso : x : %d y : %d\n",point.x, point.y);
	while (i < y)
	{
		cpy = cpy->next;
		i++;
	}
	point.z = cpy->row.content[x] * 2;
	iso(&point.x, &point.y, point.z);
	point.color = get_color(16777215 - (point.z * pow(75, 3)));
	//printf("cccccc : x : %d y : %d\n",point.x, point.y);
	return (point);
}

//Without Rotate
void put_grid(t_fdf fdf, t_map *map, Image *img)
{
	int x;
	int y = 0;
	Pixel curr;
	Pixel next;
	Pixel bottom;
	t_map *head;

	head = map;
	if (img->ptr != NULL)
	while (map != NULL)
	{
		x = 0;
		while (x < map->row.len)
		{

			curr = get_pixel(head, x, y);
			next = get_pixel(head, x + 1, y);
			if (map->next != NULL)
				bottom = get_pixel(head, x, y + 1);

			//If we are on the last row
			if (map->next == NULL)
			{
				//printf("%d | %d\n", x, map->row.len);
				printf("Start (Current) : (%d, %d)\n", curr.x, curr.y);
				printf("End (Next) : (%d, %d)\n", next.x, next.y);
				printf("x : %d\n", x);
				if (x != map->row.len - 1)
				{
					printf("yes\n");
					draw_line(fdf, curr, next);
				}
				//Only join with right point, don't do it for the last one
			}

			//If we are at the end of the row
			else if (x == map->row.len - 1)
			{
				printf("Start (Current) : (%d, %d)\n", curr.x, curr.y);
				printf("End (Bottom) : (%d, %d)\n", bottom.x, bottom.y);
				draw_line(fdf, curr, bottom);
				//Only join with the bottom point
			}

			else
			{
				printf("Start (Current) : (%d, %d)\n", curr.x, curr.y);
				printf("End (Next) : (%d, %d)\n", next.x, next.y);
				//Connect current point with the next point
				draw_line(fdf, curr, next);
				printf("Start (Current) : (%d, %d)\n", curr.x, curr.y);
				printf("End (Bottom) : (%d, %d)\n", bottom.x, bottom.y);
				//Connect current point with the bottom point
				draw_line(fdf, curr, bottom);
				//draw_line(fdf, off_x + (i*space), off_y + (j*space), off_x + ((i+1)*space), off_y + (j*space));
			}
			//mlx_pixel_put(fdf.mlx, fdf.win, off_x + (i*space), off_y + (j*space) - (map->row.content[i] * 3), 16777215 - map->row.content[i] * 50);
			x++;
		}
		y++;
		map = map->next;
	}
}
