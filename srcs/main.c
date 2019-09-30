#include "../incl/fdf.h"

int give_up(void *param)
{
	t_fdf *fdf;

	fdf = param;
	if (fdf->vprwv == 1)
		system("pkill afplay");
    exit(1);
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
	printf("Rendering fdf\n");
	put_grid(fdf);
	printf("%s\n", "FDF Rendered");
	mlx_hook(fdf->win, 17, 0, give_up, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 2, 0, key_hold, fdf);
	mlx_key_hook(fdf->win, key_press, fdf);
    mlx_loop(fdf->mlx);
    return (0);
}
