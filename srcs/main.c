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
    mlx_hook(fdf.win, 17, 0, give_up, 0);
    mlx_key_hook(fdf.win, exit_fdf, 0);
    mlx_loop(fdf.mlx);
    return (0);
}
