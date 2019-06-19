#include "../incl/fdf.h"

int give_up(void *param)
{
	(void)param;
    exit(1);
	return (0);
}

int exit_fdf(int Key, void *param)
{
    (void)param;
	if (Key == 53)
	   give_up(param);
    else if (Key == 12)
        ft_putchar('q');
	return (0);
}

/*
x formula : X Offset + (X position * Spacing value)
y formula : Y offset + (Y position * Spacing value) - (Height * Height amplifier)
*/

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

int main(int argc, char **argv)
{
    t_fdf fdf;
	t_map *map;

    (void)argv;
    if (argc != 2)
    {
        ft_putendl("USAGE : ./fdf [fdf file]");
        return (0);
    }
	map = read_map(argv[1]);
	print_map(map);
    fdf.mlx = mlx_init();
    fdf.win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	fdf.img = create_img(500, 500, fdf.mlx);
;
	mlx_string_put(fdf.mlx, fdf.win, 0, 0, 6345184, "TEST");
	//mlx_put_image_to_window(fdf.mlx, fdf.win, fdf.img.ptr, 0, 0);
	draw_line(fdf,1000, 1000, 600, 1500, 165785);
	put_grid(fdf, map);
    mlx_hook(fdf.win, 17, 0, give_up, 0);
    mlx_key_hook(fdf.win, exit_fdf, 0);
    mlx_loop(fdf.mlx);
    return (0);
}
