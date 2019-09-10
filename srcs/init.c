#include "../incl/fdf.h"

t_fdf	*init_fdf(char *map_path)
{
	t_fdf *fdf;
	Pixel off_point;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	printf("Initializing FDF\n");
	fdf->map = read_map(map_path);
    fdf->mlx = mlx_init();
	fdf->win_width = 1920;
	fdf->win_height = 1080;
	fdf->spacing = 20;
	off_point = get_pixel(fdf, 0, get_height(fdf->map) - 1);
	fdf->x_offset += abs(off_point.x);
	fdf->y_offset = 0;
	fdf->win_name = map_path;
	printf("Creating fdf->win\n");
	printf("Window Width : %d\nWindow Height :%d\nWindow Name : %s\n", fdf->win_width, fdf->win_height, fdf->win_name);
    fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, fdf->win_name);
	printf("FDF initialized\n");
	return (fdf);
}
