#include "../incl/fdf.h"

static void reload(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (fdf->vprwv == 1)
		mlx_put_image_to_window(fdf->mlx, fdf->win , fdf->bg->ptr, 0, 0);

	put_grid(fdf);
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
	else if (key == 9)
		vprwv(fdf);
	reload(fdf);
	return (0);
}

int key_hold(int key, void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (key == 53)
		give_up(fdf);
	else if (key == UP_ARROW)
		fdf->y_offset -= 10;
	else if (key == DOWN_ARROW)
		fdf->y_offset += 10;
	else if (key == LEFT_ARROW)
		fdf->x_offset -= 10;
	else if (key == RIGHT_ARROW)
		fdf->x_offset += 10;
	else if (key == 14)
		fdf->cos += 10;
	else if (key == 12)
		fdf->cos -= 10;
	else if (key == 6)
		fdf->sin += 10;
	else if (key == 8)
		fdf->sin -= 10;
	else if (key == 69)
		fdf->amplify += 1;
	else if (key == 78)
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
