#include "../incl/fdf.h"


void reload(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->vprwv == 1)
		mlx_put_image_to_window(fdf->mlx, fdf->win , fdf->bg, 0, 0);

	put_grid(fdf);
}

int give_up(void)
{
	system("pkill afplay");
    exit(1);
	return (0);
}


int key_press(int key, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (key == 83)
		fdf->mode = 0;
	else if (key == 84)
		fdf->mode = 1;
	else if (key == 18)
		fdf->palette = 0;
	else if (key == 19)
		fdf->palette = 1;
	reload(fdf);
	return (0);
}

int key_hold(int key, void *param)
{
	t_fdf *fdf;

	fdf = param;
	printf("key = %d\n", key);
	if (key == 53)
		give_up();
	if (key == UP_ARROW)
	{
		fdf->lol_y += 10;
		fdf->y_offset -= 10;
	}
	if (key == DOWN_ARROW)
	{
		fdf->lol_y -= 10;
		fdf->y_offset += 10;
	}
	if (key == LEFT_ARROW)
	{
		fdf->lol_x += 10;
		fdf->x_offset -= 10;
	}
	if (key == RIGHT_ARROW)
	{
		fdf->lol_x -= 10;
		fdf->x_offset += 10;
	}
	if (key == 14)
		fdf->cos += 10;
	if (key == 12)
		fdf->cos += 10;
	if (key == 6)
		fdf->sin += 10;
	if (key == 8)
		fdf->sin -= 10;
	if (key == 69)
		fdf->amplify += 1;
	if (key == 78)
		fdf->amplify -= 1;
	reload(fdf);
	return (0);
}

int mouse_press(int button, int x, int y, void *param)
{
	int test;
	t_fdf *fdf;

	fdf = param;
	test = x;
	test = y;
	if (button == 4)
		fdf->spacing += 1;
	else if (button == 5)
	{
		if (fdf->spacing > 1)
			fdf->spacing -= 1;
	}
	reload(fdf);
	return (0);
}

<<<<<<< HEAD
=======
char *data_bg(t_fdf *fdf, char *image_data)
{
	int y;
	int x;
	int i;

	y = 0;
	while (y < fdf->win_height)
	{
		x = 0;
		while (x < fdf->win_width)
		{
			i = (x * 4 + 4 * fdf->win_width * y);
			image_data[i] = 101;
			image_data[i + 1] = 30;
			image_data[i + 2] = 73;
			x++;
		}
		y++;
	}
	return (image_data);
}

void	ft_background(t_fdf *fdf)
{
	int bpp;
	int size_line;
	int endian;
	int width;
	int height;
	char *image_data;
	// char *image_data_1;

	fdf->bg = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	// fdf->bg_1 = mlx_new_image(fdf->mlx, fdf->win_width, fdf->win_height);
	image_data = mlx_get_data_addr(fdf->bg, &bpp, &size_line, &endian);
	// image_data_1 = mlx_get_data_addr(fdf->bg_1, &bpp, &size_line, &endian);
	// image_data_1 = data_bg(fdf, image_data_1);
	mlx_put_image_to_window(fdf->mlx, fdf->win , fdf->bg_1, 0, 0);
	fdf->bg = mlx_xpm_file_to_image(fdf->mlx, "fdf_bg.xpm", &width, &height);
}
>>>>>>> 9d8d5d3faa4c60b39c05b0b31875dec416561ff1

int main(int argc, char **argv)
{
	t_fdf *fdf;

    if (argc != 2)
    {
        ft_putendl("USAGE : ./fdf [fdf file]");
        return (0);
    }
	fdf = init_fdf(argv[1]);
	printf("PRINT FDF : map_height : %d\n", fdf->map->height);
	//mlx_string_put(fdf->mlx, fdf->win, 0, 0, 6345184, "TEST");
	//mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	//draw_line(fdf, test1, test2);``
	//vprwv(fdf);
	printf("Rendering fdf\n");
<<<<<<< HEAD
=======
	system("afplay hello.mp3&");
	ft_background(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win , fdf->bg, 50, 50);
>>>>>>> 9d8d5d3faa4c60b39c05b0b31875dec416561ff1
	put_grid(fdf);
	printf("%s\n", "FDF Rendered");
	mlx_hook(fdf->win, 17, 0, give_up, 0);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 2, 0, key_hold, fdf);
	// mlx_hook(fdf->win, )
	mlx_key_hook(fdf->win, key_press, fdf);
    mlx_loop(fdf->mlx);
    return (0);
}
