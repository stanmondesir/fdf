#include "../incl/fdf.h"

t_fdf	*init_fdf(char *map_path)
{
	t_fdf *fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	fdf->map = read_map(map_path);
    fdf->mlx = mlx_init();
	fdf->win_width = 1920;
	fdf->win_height = 1080;
	fdf->spacing = 4;
	fdf->amplify = 0;
	fdf->mode = 0;
	fdf->x = 0;
	fdf->y = 0;
	fdf->x_offset += abs(get_offset(fdf, fdf->map));
	fdf->y_offset = 0;
	fdf->win_name = map_path;
    fdf->win = mlx_new_window(fdf->mlx, fdf->win_width, fdf->win_height, fdf->win_name);
	return (fdf);
}
