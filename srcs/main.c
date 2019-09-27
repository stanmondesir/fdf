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
		fdf->y_offset -= 10;
	if (key == DOWN_ARROW)
		fdf->y_offset += 10;
	if (key == LEFT_ARROW)
		fdf->x_offset -= 10;
	if (key == RIGHT_ARROW)
		fdf->x_offset += 10;
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
